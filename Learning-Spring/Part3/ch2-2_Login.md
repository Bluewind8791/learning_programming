# 로그인 하기

스프링 프레임워크에서의 로그인은 authenticated 가 true인 Authentication 객체를 SecurityContext에 갖고있는 상대를 말한다.  
단, Authentication이 AnonymousAuthenticationToken 만 아니면 된다.

```text
로그인 == Authentication(authenticated = true) only if Authentication != AnonymousAuthenticationToken
```

## # Authentication(인증)의 기본 구조

필터들 중 일부는 인증 정보에 관여하는데, 이들 필터가 하는 일은 AuthenticationManager을 통하여 Authentication을 인증하고 그 결과를 SecurityContextHolder에 넣어주는 일이다.

- SecurityContextHolder : 인증보관함 보관소
- SecurityContext : 인증보관함
- Principal(UserDetails) : 인증 대상
- GrantedAuthority : 권한
- AuthenticationManager : 인증 관리자
- ProviderManager : 인증 제공 관리자
- AuthenticationProvider : 인증 제공자

### 인증 토큰(Authentication)을 제공하는 필터들

- UsernamePasswordAuthenticationFilter : 폼 로그인 -> UsernamePasswordAuthenticationToken
- RememberMeAuthenticationFilter : remember-me 쿠키 로그인(자동로그인) -> RememberMeAuthenticationToken
- AnonymousAuthenticationFilter : 로그인하지 않았다는 것을 인증함 -> AnonymousAuthenticationToken (인증되지 않았다는것을 인증하는 토큰)
- SecurityContextPersistenceFilter : 기존 로그인을 유지함 (기본적으로 session을 이용)
- BearerTokenAuthenticationFilter : JWT 로그인
- BasicAuthenticationFilter : ajax 로그인 -> UsernamePasswordAuthenticationToken
- OAuth2LoginAuthenticationFilter : 소셜 로그인 -> OAuth2LoginAuthenticationToken, OAuth2AuthenticationToken
- OpenIDAuthenticationFilter : OpenID 로그인
- Saml2WebSsoAuthenticationFilter : SAML2 로그인
- ... 기타

Authentication 을 제공(Provide) 하는 인증제공자(AuthenticationProvider)는 여러개가 동시에 존재할 수 있고, 인증 방식에 따라 ProviderManager 도 복수로 존재할 수 있다.

Authentication 은 인터페이스로 아래와 같은 정보들을 갖고 있습니다.

- Set\<GrantedAuthority> authorities : 인증된 권한 정보
- principal : 인증 대상에 관한 정보. 주로 UserDetails 객체가 옴
- credentials : 인증 확인을 위한 정보. 주로 비밀번호가 오지만, 인증 후에는 보안을 위해 삭제함.
- details : 그 밖에 필요한 정보. IP, 세션정보, 기타 인증요청에서 사용했던 정보들.
- boolean authenticated : 인증이 되었는지를 체크함.
