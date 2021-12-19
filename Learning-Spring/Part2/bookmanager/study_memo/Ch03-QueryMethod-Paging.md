# QueryMethod로 Paging 처리하기

import org.springframework.data.domain.Page;  
import org.springframework.data.domain.Pageable;

pageable은 paging에 대한 요청값, page는 응답값.

## Find with Paging

```java
public interface UserRepository extends JpaRepository<User, Long> {
    Page<User> findByName(String name, Pageable pageable);
}

@Test
void pagingTest() {
    log.info("findByName with paging : {}",
            userRepository.findByName("ben", PageRequest.of(0, 1, Sort.by(Order.desc("id")))));
}
```

첫번째 페이지를 id를 기준으로 역순으로 정렬하여 값을 가져온다.
