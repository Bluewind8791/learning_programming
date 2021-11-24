
## Validation

- Validation 이란 프로그래밍에 있어서 가장 필요한 부분.
- 특히 Java에서는 null 값에 대해서 접근하려고 할때,
  null pointer exception이 발생함으로, 
  이러한 부분을 방지하기 위하여 미리 검증하는 과정을 Validation이라고 함.


ex) 단순한 예시 코드

'''
public void run(String account, String pw, int age) {

    if (account == null || pw == null) {
        return;
    }

    if (age == 0) {
        return
    }

    // logics
}
'''java



1. 검증해야할 값이 많은경우 코드의 길이가 길어진다
2. 구현에 따라서 달라질 수 있지만 service logic과의 분리가 필요
3. 흩어져있는 경우 어디에서 검증하는지 알기 어려우며, 재사용의 한계가 있음
4. 구현에 따라 달라질 수 있지만, 검증 logic이 변경되는 경우 
   테스트코드 등 참조하는 클래스에서 logic이 변경되어야 하는 부분이 발생할 수 있음.

#### Annotation

+ @Size                 문자 길이 측정              int type 불가
+ @NotNull              null 불가
+ @NotEmpty             null / "" 불가
+ @NotBlank             null / "" / " " 불가
+ @Past                 과거 날짜
+ @PastOrPresent
+ @Future
+ @FutureOrPresent
+ @Pattern              정규식 적용
+ @Max
+ @Min
+ @AssertTrue / False   별도 Logic 적용
+ @Valid                해당 object validation 실행



## Custom Validation

1. AssertTrue / False 와 같은 method 지정을 통하여 Custom Logic 적용 가능

2. ConstraintValiator를 적용하여 재사용이 가능한 Custom Logic 적용 가능

