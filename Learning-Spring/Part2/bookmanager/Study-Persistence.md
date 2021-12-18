# 영속성 컨텍스트

- Persistence 영속화 : 사라지지않고 지속적으로 접근할 수 있다.

## MYSQL DB 설정하기

application.yml setting

```yml
spring:
  h2:
    console:
      enabled: true
  jpa:
    show-sql: true
    properties:
      hibernate:
        format_sql: true # 압축된 쿼리를 읽기 좋게 포멧
    generate-ddl: true # 자동으로 entity에서 활용하고있는것을 테이블을 만듦
    hibernate:
      ddl-auto: create-drop # schema.sql이 존재할시 무시됨
    # defer-datasource-initialization: true # for h2 database
  datasource:
    url: jdbc:mysql://localhost:3306/book_manager
    username: root
    password: 1234
server:
  port: 8080
```

이 후에 contextload test를 해보면 MySQL8Dialect 결과값이 나옴
