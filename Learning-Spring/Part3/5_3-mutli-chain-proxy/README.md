# BasicAuthenticationFilter

## **POST 방식**

```java
@PostMapping("/greeting")
public String greeting(@RequestBody String name) {
    return "post "+name;
}
```

```java
@DisplayName("4. POST 인증")
@Test
void test_4() {
    TestRestTemplate testClient = new TestRestTemplate("user1", "1111");
    ResponseEntity<String> resp = testClient.postForEntity(greetingUrl(), "ben", String.class);
    assertEquals("post ben", resp.getBody());
}
```

POST 에 대해서는 결과값이 오지를 않아 테스트에 실패한다. 그 이유는 

```java
@EnableWebSecurity
public class SecurityConfig extends WebSecurityConfigurerAdapter {
	...
    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .csrf().disable()
            .authorizeRequests().anyRequest().authenticated()
            .and()
            .httpBasic()
            ;
    }
}
```

CSRF filter 가 작동하고 있기 때문이다. 그래서 disable 시켜야 테스트가 정상적으로 완료된다.

하지만 이렇게하면 실제 서비스할때와 다르게 테스트를 진행하기 때문에 상이한 환경에서 테스트를 진행하게 된다.

그래서 이때는 
