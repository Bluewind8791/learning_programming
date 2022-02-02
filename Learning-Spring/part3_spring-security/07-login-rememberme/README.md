# 로그인을 지원하기 위한 필터들

## 스프링이 지원하는 로그인 방식들

- 스프링은 아래와 같은 로그인 방식들을 지원한다.

![LoginProc](https://bluewind8791.github.io/assets/image/7-user-login.png)

- 스프링의 인증 처리는 session 과는 별도로 동작하도록 설계되어 있다. 그래서 session 을 사용하건 사용하지 않건 같은 authentication 과 AuthenticationProvider 를 사용할 수 있다.

![springAuthProc](https://bluewind8791.github.io/assets/image/7-spring-authentication.png)

- 스프링의 인증을 유지시켜주기 위해서는 session 을 이용하는것이 편리하다. 
- 이후 인증은 서버가 메모리를 소모해서 session 객체를 가지고 유지시켜주는 작업을 하도록 할 수 있다. 
- 세션은 브라우저의 쿠키에 JSESSIONID 를 심어놓고 브라우저와 서버가 이 값을 주고받으면서 session 을 보장받을 수 있다.

- 그런데 서버의 세션 정책과 스프링의 인증 체계가 서로 맞물려 동작하도록 하려면 SecurityContextPersistenceFilter 와 RememberMeAuthenticationFilter, AnonymousAuthenticationFilter 등과 같이 인증을 보조해주는 다른 필터들의 도움을 받아야 한다.

---

## **SecurityContextPersistenceFilter**

- SecurityContextRepository 에 저장된 SecurityContext 를 Request 의 LocalThread 에 넣어주었다가 뻇는 역할을 한다. 
- doFilter 메소드를 따라가보면 알 수 있다.
- session 에 SecurityContext 를 보관했다가 다음 request 에서 넣어준다.

![SecurityContextPersistenceFilter](https://bluewind8791.github.io/assets/image/7-securitycontext-persistence-filter.png)

좀 더 정확하게 보기 위하여 SecurityContextPersistenceFilter 안에서의 동작을 보면

1. request와 response 를 holder 에 담아서 `SecurityContext` 를 repository 에서 가져온다
2. `HttpSessionSecurityContextRepository`(HttpSession 에 SecurityContext 를 저장하는 Repository) 로 들어와서 
3. context 를 session 으로 부터 읽어낸다.
  - httpSession 안에 csrf 토큰값과 security context 값이 들어가 있다.
4. context 를 꺼내와서 `SecurityContextHolder` 에 배치를 해주고나서
5. 정상적인 필터 안쪽으로 request를 타서 서비스를 진행한다
6. 그 이후에는 finally 에서 언제나 `securityContextHolder` 에서 clear 해주는 코드를 동작한다.
7. 메인 페이지로 이동한다.

---

## **RememberMeAuthenticationFilter**

- 인증 정보를 session 관리하는 경우, session timeout 이 발생하게 되면, remember-me cookie 를 이용하여 로그인을 기억했다가 자동으로 재로그인 시켜주는 기능.

![RememberMeAuthFilter](https://bluewind8791.github.io/assets/image/7-remember-me-filter.png)

  - key : Hash 암/복호화에 사용할 키 값
  - token-validity-seconds : 토큰 유효 기간
  - authentication-success-handler-ref : 핸들러를 커스터마이징 했다면 로그인 성공 후 수행할 logic
  - user-service-ref : UserDetailsService 를 커스터마이징 했을 경우 주입

- session 은 같은 사용자라고 할지라도 다른곳에서 로그인하면 다른 session 을 가지고 있다.

- 세션이 만료되어있는지를 알기위해서 servlet listener 에 HttpSessionEventPublisher 를 등록하여 listener 를 달아줄 수 있다.

```java
@Bean
public ServletListenerRegistrationBean<HttpSessionEventPublisher> httpSessionEventPublisher() {
  return new ServletListenerRegistrationBean<HttpSessionEventPublisher>(new HttpSessionEventPublisher() {

    @Override
    public void sessionCreated(HttpSessionEvent event) {
      super.sessionCreated(event);
      System.out.printf("==> [%s] Session created %s \n", LocalDateTime.now(), event.getSession().getId());
    }

    @Override
    public void sessionDestroyed(HttpSessionEvent event) {
      super.sessionDestroyed(event);
      System.out.printf("==> [%s] Session destroyed %s \n", LocalDateTime.now(), event.getSession().getId());
    }

    @Override
    public void sessionIdChanged(HttpSessionEvent event, String oldSessionId) {
      super.sessionIdChanged(event, oldSessionId);
      System.out.printf("==> [%s] Session Id changed %s:%s \n", LocalDateTime.now(),  oldSessionId, event.getSession().getId());
    }
  });
}
```

- **TokenBasedRememberMeServices** (token based)

  - format : 아이디:만료시간:Md5Hex / 서버->(아이디:만료시간:비밀번호:인증키)
  - 만약 user 가 password 를 바꾼다면 토큰은 사용 불가
  - 기본 유효기간은 14일이며 설정에서 바꿀 수 있다
  - 약점 : 탈취된 토큰은 비밀번호를 바꾸지 않는한 유효기간 동안 만능키가 됨

- **PersistenceTokenBasedRememberMeServices**

  - format : series:token
  - 토큰에 username 이 노출되지 않고, 만료시간도 노출되지 않는다. 만료시간은 서버에서 정하고 노출하지 않고 서버는 로그인 시간만 저장한다.
  - series 값이 키가 된다. 일종의 채널이라고 보면 편리하다.
  - 대신 재로그인이 될 때마다 token 값을 갱신한다. 그래서 토큰이 탈취되어 다른 사용자가 다른 장소에서 로그인을 했다면 정상 사용자가 다시 로그인 할 때, CookieTheftException 이 발생하게 되고, 서버는 해당 사용자로 발급된 모든 remember-me 쿠키값들을 삭제하고 재로그인을 요청하게 된다.
  - InmemoryTokenRepository 는 서버가 재시작하면 등록된 토큰들이 사라진다. 따라서 자동 로그인을 설정했더라도 다시 로그인을 해야 한다. 재시작 후에도 토큰을 남기고 싶다면 JdbcTokenRepository를 사용하거나 이와 유사한 방법으로 토큰을 관리해야 한다.
  - 로그아웃하게 다른 곳에 묻혀놓은 remember-me 쿠키값도 쓸모가 없게 된다. 만약 다른 곳에서 remember-me 로 로그인한 쿠키를 살려놓고 싶다면, series 로 삭제하도록 logout 을 수정해야 한다.
  - TokenBasedRememberMeServices 보다 더 안전함.

- **특징**
  - RememberMe로 로그인한 사용자는 UsernamePasswordAuthenticationToken 이 아닌 RememberMeAuthenticationToken 으로 서비스를 이용하는 것.
  - 같은 사용자이긴 하지만, 토큰의 종류가 다르게 구분되어 있다.

- **설정하기**

```java
@Bean
PersistentTokenBasedRememberMeServices rememberMeServices() {
  PersistentTokenBasedRememberMeServices service = 
    new PersistentTokenBasedRememberMeServices(
        "hello", // key
        spUserService, // user details service
        tokenRepository() // PersistenceTokenRepository tokenRepository
      );
  return service;
}
```

- DB 에 저장할 때, 이전의 값이 유효해야 하기 때문에 반드시 key 값을 줘야 한다.
- tokenRepository 의 값은 Bean 으로 따로 부여하여 설정한다.
- PersistentTokenRepository 에는 dataSource 값이 필요하기 때문에 `private final DataSource dataSource;` 로 값을 받아준다.

```java
@Bean
PersistentTokenRepository tokenRepository() {
  JdbcTokenRepositoryImpl repositoryImpl = new JdbcTokenRepositoryImpl();
  repositoryImpl.setDataSource(dataSource);

  try { // *
    repositoryImpl.removeUserTokens("1");
  } catch (Exception ex) {
    repositoryImpl.setCreateTableOnStartup(true);
  }
  return repositoryImpl;
}
```

- repository 에서 removeUserToken 을 시도해보고, 테이블이 없으면 테이블을 새롭게 만든다.

이렇게 PersistentTokenBasedRememberMeServices 를 구현하고, HttpSecurity configure 에서 rememberMe 서비스를 방금 만든 서비스로 등록한다.

```java
@Override
protected void configure(HttpSecurity http) throws Exception {
  http
      ...
      .rememberMe(r -> 
        r.rememberMeServices(rememberMeServices())) // remember-me enable
      ;
}
```

---

## **AnonymousAuthenticationFilter**

- 로그인 하지 않은 사용자 혹은 로그인이 검증되지 않은 사용자는 기본적으로 AnonymousAuthenticationToken 을 발급해 준다. 
- 즉, anonymous를 허용한 곳만 다닐 수 있게 하겠다는 것.
- 익명 사용자의 권한을 별도로 설정할 수 있고, 익명사용자에게 주는 principal 객체도 설계해서 대체해 줄 수 있다.
