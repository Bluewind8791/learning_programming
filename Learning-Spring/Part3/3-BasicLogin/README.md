# 페이지에 Security 설정하기

- thymeleaf 에 대한 의존성 추가
- bootstrap 을 이용해 기본 페이지 제작
- 기본 로그인 페이지 제작
- csrf 설정
- 로그인 성공시 설정
- 로그인 실패시 설정
- 로그아웃 설정
- UserDetailsSource 설정

---

SecurityConfig class를 설정한다.

```java
@EnableWebSecurity(debug = true)
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .authorizeRequests(request->{
                request
                    .antMatchers("/").permitAll() // root page permit all
                    .anyRequest().authenticated() // need auth
                    ;
            })
            ;
    }
}
```

모든 request를 승인받는것으로 변경하니 css 가 동작하지 않는 문제가 생김.

```java
    @Override
    public void configure(WebSecurity web) throws Exception {
        web.ignoring()
            .requestMatchers(
                PathRequest.toStaticResources().atCommonLocations()
            );
    }
```

configure 을 overriding 하는데 web resource에 대해서는 security filter가 적용되지 않도록 ignore 시켜준다.

하지만 request를 처리하는 필터가 없기때문에 root 페이지만 문제없이 들어가질뿐 다른 url은 막혀있는 상태.

```java
@EnableWebSecurity(debug = true)
public class SecurityConfig extends WebSecurityConfigurerAdapter {

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .authorizeRequests(request->{
                request
                    .antMatchers("/").permitAll() // root page permit all
                    .anyRequest().authenticated() // need auth
                    ;
            })
            .formLogin() // *
            ;
    }
```

formLogin 을 설정해준다. 이러면 default login 화면이 뜬다. 그 이유는 로그인을 특정하지 않으면 기본적인 default login page가 뜨기 때문.

```java
.formLogin(
    login -> login.loginPage("/login")
    .permitAll() // 무한루프 방지
)
```

무한루프 방지를 위하여 permitAll을 반드시 더해주고 login page를 지정해준다.

---

## **Login**

그 다음은 로그인을 시켜보자.

```java
@Override
protected void configure(AuthenticationManagerBuilder auth) throws Exception {
auth
    .inMemoryAuthentication()
    .withUser(
        User.withDefaultPasswordEncoder()
            .username("user1")
            .password("1111")
            .roles("USER")
    ).withUser(
        User.withDefaultPasswordEncoder()
            .username("admin")
            .password("2222")
            .roles("ADMIN")
    );
}
```

저번과 동일하게 사용자를 생성하는데 저번과는 다르게 패스워드를 withDefaultPasswordEncoder를 사용하여 테스트 용으로만 사용한다.

이렇게해도 로그인이 되지않는 현상이 발생하는데 이것은 csrf 필터를 거치는데 이 필터에서 actual token이 null 값이 찍히기 때문.

이것을 해결하기 위해서 loginForm.html 을 아래와 같이 thymeleaf 이 제공하는 action을 써주면 csrf token이 달린다.

```html
<div class="container center-contents">
    <div class="row">
        <form class="form-signin" method="post" th:action="@{/login}">
            <h1 class="h3 mb-3 font-weight-normal"> 로그인 </h1>
```

다시 새로고침하여 브라우저에서 dev mode로 살펴보면 hidden 으로 csrf value가 달려있음을 알 수 있다.

```html
<input type="hidden" name="_csrf" value="50468860-ccbc-4c0c-89f8-14252f45ff44">
```

이렇게하면 로그인 성공!

---

### **그 밖의 formLogin 설정**

```java
.formLogin(
    login -> login.loginPage("/login")
    .permitAll() // 무한루프 방지
    .defaultSuccessUrl("/", false) // 로그인에 성공했을때
    .failureUrl("/login-error") // 로그인 실패했을때 이 url으로 이동
)
```

- defaultSuccessUrl(defaultSuccessUrl, alwaysUse)

의 메서드를 살펴보면, 로그인에 성공했을때 어디 url로 갈것인지 지정해주고, alwaysUse가 true 값이면 항상 앞에 설정했던 url로 이동하기 때문에 불편을 초래할 수 있다. 그러므로 false값으로 두는것이 일반적.

- failureUrl(url)

로그인에 실패 했을때 이 url으로 이동하게 함.

---

## **Logout setting**

이제 로그아웃을 설정해보자.

### 로그아웃 버튼 만들기

index.html 에 아래와 같이 로그아웃 버튼을 만들고

```html
<div class="link">
    <form th:action="@{/logout}" method="post">
        <button class="btn btn-info" type="submit">로그아웃</button>
    </form>
</div>
```

로그아웃에 성공했을 때, root page로 이동하게 설정한다.

```java
@Override
protected void configure(HttpSecurity http) throws Exception {
    http
        .authorizeRequests(request->{
            request
                ...
        })
        .formLogin(
            ...
        )
        .logout(logout -> logout.logoutSuccessUrl("/")) // *
        ;
}
```

---

## thymeleaf 에서 security를 적용하는 태그

```html
<div sec:authorize="isAuthenticated()">
    로그인 된 유저에게만 보이는 content.
</div>
<div sec:authorize="hasRole('ROLE_ADMIN')">
    administrators에게만 보이는 content.
</div>
<div sec:authorize="hasRole('ROLE_USER')">
  users에게만 보이는 content.
</div>
```

### 관리자 페이지에 모든 유저가 들어갈 수 없게 해결

SecurityConfig class에 EnableGlobalMethodSecurity true를 달면

```java
@EnableWebSecurity(debug = true)
@EnableGlobalMethodSecurity(prePostEnabled = true) // *
public class SecurityConfig extends WebSecurityConfigurerAdapter {
```

기존에 아래와 같이 admin page에 설정되어있던 role대로 security가 적용되게 된다.

```java
@PreAuthorize("hasAnyAuthority('ROLE_ADMIN')")
@GetMapping("/admin-page")
public String adminPage(){
    return "AdminPage";
```

이렇게 설정하면 user가 admin page에 접근할 수 없게된다.

## exceptionHandling

access denied 되었을때 이동할 페이지를 설정할 수 있다.

```java
@Override
protected void configure(HttpSecurity http) throws Exception {
    http
        ...
        .exceptionHandling(exception -> exception.accessDeniedPage("/access-denied"))
        ;
}
```

---

## RoleHierarchy

일반적으로 관리자는 user의 권한도 함께 가지고있는 경우가 많다.

```java
@Bean
RoleHierarchy roleHierarchy() {
    RoleHierarchyImpl roleHierarchy = new RoleHierarchyImpl();
    roleHierarchy.setHierarchy("ROLE_ADMIN > ROLE_USER");
    return roleHierarchy;
}
```

roleHierarchy(역할 계층)를 통하여 역할을 설정해주면 관리자도 유저의 권한을 가질 수 있게된다.

---

## authenticationDetailsSource
