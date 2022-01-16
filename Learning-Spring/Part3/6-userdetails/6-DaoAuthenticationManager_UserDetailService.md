# DaoAuthenticationManager와 UserDetailsService

## 실습 하기

- login-userdetails 폴더를 만든다.
- user-admin comp 모듈을 만들고, SpUser, SpAuthority Entity와 Repository 를 만든다.
- h2 DB 를 세팅한다.

web 폴더에는 user-admin 이라는 웹 모듈을 만든다.
comp 폴더에는 user-admin 이라는 component를 만든다.
그리고 gradle update를 하면 기본세팅이 완료된다.

login-basic 의 resource-static, templates 를 web-user-admin의 폴더로 옮겨서 코드를 재활용한다.