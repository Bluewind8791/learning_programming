# BasicAuthenticationFilter

Web 으로 서비스가 잘되고있는 페이지를 spa나 모바일과 같이 ajax로 접근해야하는 Basic Auth Filter를 태워야하는 경우 어떻게 같이 쓸 수 있는지에 대해서 알아보자.

그렇게 하려면 기존의 SecurityConfig와는 다른 FilterChainProxy를 구성해야한다.

이것을 configuration을 다르게 설정한 MobileSecurityConfig 로 만든다.

```java
@Order(1) // filter chain's order
@Configuration
public class MobileSecurityConfig extends WebSecurityConfigurerAdapter {

    private final StudentManager studentManager;
    private final TeacherManager teacherManager;

    public MobileSecurityConfig(StudentManager studentManager, TeacherManager teacherManager) {
        this.studentManager = studentManager;
        this.teacherManager = teacherManager;
    }

    @Override
    protected void configure(AuthenticationManagerBuilder auth) throws Exception {
        auth.authenticationProvider(studentManager);
        auth.authenticationProvider(teacherManager);
    }

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .antMatcher("/api/**")
            .csrf().disable()
            .authorizeRequests(request->
                request.anyRequest().authenticated()
            )
            .httpBasic()
            ;
    }
}
```

이것이 하나의 filterChain을 구성하게 되며, 서버에는 총 두개의 Filter Chain으로 띄워지게 된다.

모바일을 서비스 하기 위한 api 테스트 코드를 작성하기 위하여

```java
@RestController
@RequestMapping("/api/teacher")
public class ApiTeacherController {

    @Autowired
    StudentManager studentManager;

    @PreAuthorize("hasAnyAuthority('ROLE_TEACHER')")
    @GetMapping("/students")
    public List<Student> studentList(@AuthenticationPrincipal Teacher teacher){
        return studentManager.myStudentList(teacher.getId());
    }
}
```

```java
@SpringBootTest(webEnvironment = WebEnvironment.RANDOM_PORT)
public class MultiChainProxyTest {

    @LocalServerPort
    int port;

    RestTemplate restTemplate = new RestTemplate();

    @DisplayName("1. 학생 조사")
    @Test
    void test_1() throws JsonProcessingException {
        String url = format("http://localhost:%d/api/teacher/students", port);
        
        HttpHeaders httpHeaders = new HttpHeaders();
        httpHeaders.add(HttpHeaders.AUTHORIZATION, "Basic "+ Base64.getEncoder().encodeToString(
            "choi:1".getBytes()
        ));

        HttpEntity<String> entity = new HttpEntity<String>("", httpHeaders);
        ResponseEntity<String> response = restTemplate.exchange(url, HttpMethod.GET, entity, String.class);

        List<Student> list = new ObjectMapper().readValue(
            response.getBody(),
            new TypeReference<List<Student>>() {
            });

        System.out.println(list);
        assertEquals(3, list.size());
    }
}
```

사이트를 구성할때 웹으로 잘 구현된 사이트를 spa나 모바일로 서비스를 공지할때는 성격이 다른 request set을 구성해야 한다.
그래서 한쪽은 UsernamePasswordAuthenticationFilter에 csrf 필터를 enable 하고 모바일쪽은 모든것을을 빼버리고 httpBasic만 돌아가도록 설정하도록 개발한다.