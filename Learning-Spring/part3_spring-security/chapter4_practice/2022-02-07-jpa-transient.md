
# @Transient

@Transient는 JPA의 표준이라 할 수 있는 javax.persistence 패키지에 포함되어있는 컬럼 매핑 레퍼런스 애노테이션입니다.
@Transient는 영속 대상에서 제외 하기위해 사용합니다.

## 두가지 방식

ElementType.METHOD
ElementType.FIELD

### Field 방식

필드 방식은 영속 대상에서 제외하고 싶은 필드에 @Transient 애노테이션을 선언

### Method 방식

이 외에도 @Transient는 메서드에도 선언시킬 수 있습니다.



## 참조

- https://gmoon92.github.io/jpa/2019/09/29/what-is-the-transient-annotation-used-for-in-jpa.html