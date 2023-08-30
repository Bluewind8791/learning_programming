
# 스프링 입문 - 코드로 배우는 스프링 부트 웹 MVC, DB 접근 기술

## API

### @ResponseBody 문자 반환

- `@ResponseBody` 를 사용하면 ViewResolver 를 사용하지 않는다.
- 대신에 http 의 body 에 문자 내용을 직접 반환한다.

### @ResponseBody 객체 반환

```java
@GetMapping("hello-api")
@ResponseBody
public Hello helloApi(@RequestParam("name") String name) {
    Hello hello = new Hello();
    hello.setName(name);
    return hello;
}
```

- `@ResponseBody` 를 사용하여 이렇게 객체를 반환하게 되면 객체가 json 형태로 변환된다.

- `@ResponseBody` 를 사용
  - http body 에 문자 내용을 직접 반환
  - `viewResolver` 대신에 `HttpMessageConverter` 가 동작
  - 기본 문자처리 : `StringHttpMessageConverter`
  - 기본 객체처리 : `MappingJackson2HttpMessageConverter`
  - byte 처리 등 기타 여러 HttpMessageConverter 가 기본적으로 등록되어 있음.

- 문자 변환보다는 객체 변환을 자주 사용한다.

---

## 회원 관리 에제

- 비즈니스 요구사항 정리
- 회원 domain 과 repository 만들기
- 회원 repository test case 작성
- 회원 service 개발
- 회원 service test

### 일반적인 web application 계층 구조

- controller : web MVC controller
- sevice : 핵심 비즈니스 logic 구현
- repository : db 에 접근, domain 객체를 db 에 저장하고 관리
- domain : 비즈니스 domain 객체
  - 예) 회원, 주문, 쿠폰, 등등 주로 데이터베이스에 저장하고 관리됨


## DI

DI에는 3가지 방법이 있다.
  - 필드 주입 : `@Autowired private MemberService memberService;`
  - setter 주입 :
    ```java
    @Autowired
    public void setMemberService(MemberService memberService) {
        this.memberService = memberService;
    }
    ```
  - 생성자 주입 :
    ```java
    @Autowired
    public MemberController(MemberService memberService) {
        this.memberService = memberService;
    }
    ```

의존관계가 실행중에 동적으로 변하는 경우는 거의 없으므로 생성자 주입을 권장한다.

- 참고: 실무에서는 주로 정형화된 컨트롤러, 서비스, 리포지토리 같은 코드는 컴포넌트 스캔을 사용한다.
- 그리고 정형화 되지 않거나, 상황에 따라 구현 클래스를 변경해야 하면 설정을 통해 spring bean 으로 등록한다.

- 주의: `@Autowired` 를 통한 DI는 helloConroller , memberService 등과 같이 스프링이 관리하는 객체에서만 동작한다.
- 스프링 빈으로 등록하지 않고 내가 직접 생성한 객체에서는 동작하지 않는다.


## AOP

- 모든 메소드의 호출 시간을 측정하고 싶다면?
- 회원 가입 시간, 회원 조회 시간을 측정하고 싶다면?

- 공통 관심 사항(cross-cutting concern) vs 핵심 관심 사항 (core concern)
- 위의 과제는 공통 관심 사항에 해당한다.

- AOP: Aspect Oriented Programming
- 공통관심사항 과 핵심관심사항 분리
