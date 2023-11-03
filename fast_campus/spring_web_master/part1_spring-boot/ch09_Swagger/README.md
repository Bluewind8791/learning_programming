# Swagger

- Swagger란 개발한 REST API를 편리하게 문서화 해주고, 이를 통해서 관리 및 제3의 사용자가 편리하게 API를 호출해보고 테스트할 수 있는 프로젝트이다.

- Spring Boot에서는 간단하게 springfox-boot-starter를 gradle dependencies에 추가하여 사용 가능하다.

- 하지만 운영환경과 같은 외부에 노출되면 안되는 곳에는 사용할 때 주의해야 한다.

## Swagger Annotation

| Annotation | Description |
| --- | --- |
| @Api | 클래스를 Swagger의 리소스로 표시|
| @ApiOperation | 특정 경로의 오퍼레이션 HTTP method 설명|
| @ApiParam | 오퍼레이션 파라미터에 메타 데이터 설명|
| @ApiResponse | 오퍼레이션의 응답 지정|
| @ApiModelProperty | 모델의 속성 데이터를 설명|
| @ApiImplicitParam | 메소드 단위의 오퍼레이션 파라미터를 설명|
| @ApiImplicitParams | 메소드 단위의 오퍼레이션 파라미터들을 설명|

---

## 적용하기

<https://mvnrepository.com/> 에서 'Springfox Boot Starter' 를 검색하여 dependencies 를 추가해준다.

```
implementation group: 'io.springfox', name: 'springfox-boot-starter', version: '3.0.0'
```

- 이 dependency 만 달아주면 기본적으로 모든것이 공개된다.

- Controller 에 기본적인 GetMethod 하나를 만들어주고 아래의 url 로 들어가면 swagger ui 를 사용할 수 있다. (끝에 슬래쉬(/) 필요)

```html
http://localhost:8080/swagger-ui/
```

- 이 UI 로 들어가게되면 구현된 모든 api 가 보여지게 된다.

# Swagger Annotation 활용하기

## - @Api

Rest Controller 에 @Api 태그를 달아주게되면

```java
@Api(tags = {"API 정보를 제공하는 Controller"})
@RestController
@RequestMapping("/api")
public class ApiController {
```

아래처럼 컨트롤러에 대하여 설명되어 있는 것을 볼 수 있다.

![swagger-api](https://bluewind8791.github.io/assets/image/swagger-api.png)

---

## - @ApiParam

아래와 같은 x 와 y 를 받아서 연산하는 api가 있다고 가정하자.

```java
@GetMapping("/plus/{x}")
public int plus(@RequestParam int x, @RequestParam int y) {
    return x + y;
}
```

여기에서 인자로 받는 request parameter 를 swagger-ui 에서 사용할때, `@ApiParam` 를 통하여 좀 더 자세하게 설명할 수 있다.

```java
@GetMapping("/plus/{x}")
public int plus(
        @ApiParam(value = "X value")
        @RequestParam int x,
        @ApiParam(value = "Y value")
        @RequestParam int y) {
    return x + y;
}
```

![api-param](https://bluewind8791.github.io/assets/image/swagger-apiParam.png)

---

## - @ApiImplicitParam / @ApiImplicitParams

위의 @ApiParam 대신 아래의 annotation 을 통하여 좀 더 간편하고 디테일하게 설정할 수 있다.

```java
@ApiImplicitParams({
    @ApiImplicitParam(name = "x", value = "X value", required = true, dataType = "int", paramType = "path"),
    @ApiImplicitParam(name = "y", value = "Y value", required = true, dataType = "int", paramType = "query")
})
@GetMapping("/plus/{x}")
public int plus(@RequestParam int x, @RequestParam int y) {
    return x + y;
}
```

---

## - @ApiModelProperty

이름과 나이를 받는 GET 방식의 API 가 있다고 가정하자. 이것을 어떻게 설명할 수 있을까?

```java
@GetMapping("/user")
public UserRes user(UserReq userReq) {
    return new UserRes(userReq.getName(), userReq.getAge());
}
```

- UserReq 와 UserRes 에서 `@ApiModelProperty` 를 통하여 꾸며줄 수 있다.
  - UserReq 와 UserRes 의 코드차이가 거의 없기 때문에 UserRes 의 코드는 생략한다.

```java
@Data
@NoArgsConstructor
@AllArgsConstructor
public class UserReq {

    @ApiModelProperty(value = "사용자의 이름", example = "Ben", required = true)
    private String name;

    @ApiModelProperty(value = "사용자의 나이", example = "31", required = true)
    private int age;
}
```

아래와 같이 설명이 추가 되었다.

![api-model-param](https://bluewind8791.github.io/assets/image/swagger-apiModel-param.png)

example 또한 확인할 수 있다.

![api-model-ex](https://bluewind8791.github.io/assets/image/swagger-apiModel-example.png)

이제 테스트를 진행해보자, 우측 상단의 'Try it out' 을 클릭하고 나이와 이름을 적고 Execute 를 누르면

![api-try](https://bluewind8791.github.io/assets/image/swagger-try.png)

아래와 같이 결과값들이 나타나게된다.

![api-try-res](https://bluewind8791.github.io/assets/image/swagger-try-res.png)

---

## - @ApiResponse / @ApiOperation

- `@ApiResponse` 를 통하여 Http method 뒤에 설명을 붙여줄 수 있다.
- `@ApiOperation` 를 통하여 502 에러 코드에 대한 설명을 붙여줄 수 있다.

```java
@ApiResponse(code = 502, message = "사용자의 나이가 10살 이하일 때")
@ApiOperation(value = "사용자의 이름과 나이를 return하는 Method")
@GetMapping("/user")
public UserRes user(UserReq userReq) {
    return new UserRes(userReq.getName(), userReq.getAge());
}
```

GET method 뿐만 아니라 POST 메소드도 동일하게 사용할 수 있다.
