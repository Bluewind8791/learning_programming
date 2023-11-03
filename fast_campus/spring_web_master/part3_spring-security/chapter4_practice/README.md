# 온라인 시험 사이트 도메인 설계

## 사이트 시나리오

- 학교의 선생님과 학생이 사이트에 가입한다.
- 선생님은 학교와 학급을 입력하고 가입을 할 수 있다.
- 학생은 학교와 선생님을 입력하고 가입을 할 수 있다.

- 선생님은 시험지를 만들 수 있다.
- 선생님은 시험지를 만들어서 학생들에게 시험지를 낼 수 있다.

- 학생은 자신에게 온 시험지를 조회하고 시험을 볼 수 있다.
- 학생은 시험을 본 후, 제출해서 시험 점수를 확인할 수 있다.
- 선생님은 학생리스트와 시험 점수를 확인할 수 있다.

---
## 사용자 도메인 기능 리스트

### 학교

- 학교를 생성한다.
- 학교 이름을 수정한다.
- 지역 목록을 가져온다.
- 지역으로 학교 목록을 가져온다.

#### domain

user.domain.School
user.repository.SchoolRepository
user.service.SchoolService

## 유저

- 사용자를 생성 한다.
- 이름을 수정할 수 있다.
- 권한을 주면 권한이 주어진다.
- 권한을 취소하면 권한이 취소된다.
- email로 검색할 수 있다.
- role이 중복해서 추가되지 않는다.
- email이 중복되어서 등록되지 않는다.

## 선생님

- 선생님을 등록한다.
- 선생님으로 등록한 학생 리스트를 조회한다.
- 선생님 리스트를 조회 한다.
- 학교로 선생님이 조회된다.

## 학생

- 학습자를 등록 한다.
- 선생님을 등록하면 선생님의 학생으로 조회된다
- 학교로 학생이 조회된다.

---

## 시험지 도메인 기능 리스트

### 템플릿 시험지 / 문제

- 시험지를 한개 만든다.
- 문제를 추가한다.
- 문제를 삭제한다.

### 시험지

- 조건) 선생님, 학생1, 학생2
- 조건) 2문제로 된 시험지 템플릿이 있다.

  - 시험지 템플릿을 학생1 에게 시험지를 낸다.
  - 시험지를 2명 이상의 학생에게 낸다. (학생1, 학생2)
  - 시험지를 삭제한다.

### 문제 풀기

- 조건) 선생님, 학생1, 학생2
- 조건) 2문제로 된 시험지가 있다.

  - 시험지를 모두 풀어서 100점을 맞는다
  - 문제를 한개 틀려서 50점을 맞는다.
  - 문제를 모두 틀려서 0점을 맞는다.
  - 1번 문제 풀고 중간에 제출해 버린다
  - 2문제 풀고 중간에 제출해 버린다.
  - 문제를 풀지 않고 그냥 제출해 버린다
  - 상태에 따라 시험지가 조회된다

---

## 시험 사이트

- 학생, 선생님, 관리자가 각기 다른 테이블에 관리된다.
- 로그인 하는 페이지가 별도로 있다.
- 페이지를 한 서버에 만들 수도 있고, 별도의 서버로 나눌 수도 있다.

### 개발환경 세팅

- IntelliJ 에서 compiler.automake.allow.when.app.running 을 체크하고
- 설정의 Build project automatically 를 체크하고
- Run configuration 에서 On 'Update' action 과 On frame deactivation 의 값을 적절하게 수정해 줍니다.
- application.yml 에서 devtool 의 livereload 기능을 켜줍니다.

### thymeleaf

- 기본 문법
- 템플릿 이용하는 방법
- layout 설정하기


## 사이트 맵

<img src="https://gitlab.com/jongwons.choi/spring-boot-security-lecture/-/raw/master/images/fig-30-sitemap.png" width="600" style="max-width:600px;width:100%;" />


- 메인 화면
- 로그인 화면
- 가입 화면
- 관리자 메인
  - 학교 리스트
    - 학교 등록
  - 선생님 리스트
  - 학생 리스트
- 선생님 메인
  - 학생 리스트
  - 시험지 리스트
    - 시험지 생성
    - 시험지 수정
    - 시험 결과 보기
- 학생 메인
  - 응시할 시험지 리스트
    - 시험 보기
  - 결과 시험지 리스트
    - 시험 결과

---

## 보안 취약점 보완

1. 관리자는 학생들의 시험지 결과를 조회할 수 있어야 한다.

2. 학생은 다른 학생의 시험지를 응시할 수도, 조회할 수도 없어야 한다.

```java
@PostAuthorize("returnObject.isEmpty() || returnObject.get().studyUserId == principal.userId")
@Transactional(readOnly = true)
public Optional<Paper> findPaper(Long paperId) {
    return paperRepository.findById(paperId).map(paper -> {
        paper.setUser(userRepository.getOne(paper.getStudyUserId()));
        return paper; // user 정보까지 같이 return
    });
}
```

3. 선생님은 다른 선생님이 만든 시험지의 결과를 조회할 수 없어야 한다.

```java
@GetMapping("/study/results")
public String studyResults(
        @RequestParam Long paperTemplateId,
        @AuthenticationPrincipal User user,
        Model model) {
    model.addAttribute("menu", "paper");

    List<Paper> papers = paperService.getPapers(paperTemplateId);
    Map<Long, User> userMap = userService.getUsers(papers.stream().map(p -> p.getStudyUserId()).collect(Collectors.toList()));
    papers.stream().forEach(paper -> paper.setUser(userMap.get(paper.getStudyUserId())));
    model.addAttribute("template", paperTemplateService.findById(paperTemplateId).get());
    model.addAttribute("papers", papers);
    return "/teacher/study/results.html";
}
```

시험지의 결과를 아래와 같이 변경한다.

```java
@GetMapping("/study/results")
public String studyResults(
        @RequestParam Long paperTemplateId,
        @AuthenticationPrincipal User user,
        Model model) {
    model.addAttribute("menu", "paper");

    return paperTemplateService.findProblemTemplate(paperTemplateId).map(paperTemplate -> {
        List<Paper> papers = paperService.getPapers(paperTemplateId);
        Map<Long, User> userMap = userService.getUsers(papers.stream().map(p -> p.getStudyUserId()).collect(Collectors.toList()));
        papers.stream().forEach(paper -> paper.setUser(userMap.get(paper.getStudyUserId())));
        model.addAttribute("template", paperTemplateService.findById(paperTemplateId).get());
        model.addAttribute("papers", papers);
        return "/teacher/study/results.html";
    }).orElseThrow(() -> new AccessDeniedException("시험지가 존재하지 않습니다."));
}
```

PaperTemplateService의 findProblemTemplate 메소드에는 PostAuthorize를 추가하여 권한을 확인한다.

```java
@Transactional(readOnly = true)
@PostAuthorize("returnObject.isEmpty() || returnObject.get().userId == principal.userId")
public Optional<PaperTemplate> findProblemTemplate(Long paperTemplateId) {
    return paperTemplateRepository.findById(paperTemplateId).map(pt->{
        if (pt.getProblemList().size() != pt.getTotal()) { // lazy 해결위해 체크
            pt.setTotal(pt.getProblemList().size()); // total size 가 다르다면 total을 맞춤
        }
        return pt;
    });
}
```

4. remember-me 취약성 해결 : TokenBasedRememberMe 토큰 대신 PersistentTokenBasedRememberMeServices 로 바꿔보자.


---

## 참고 사이트

- 옥탑방개발자님의 강의자료 : [GitLab](https://gitlab.com/jongwons.choi/spring-boot-security-lecture/-/blob/master/part3/Lec-2%20%EC%9B%B9%20%ED%8E%98%EC%9D%B4%EC%A7%80%20%EC%A0%9C%EC%9E%91%EA%B3%BC%20%EA%B8%B0%EB%8A%A5%ED%85%8C%EC%8A%A4%ED%8A%B8.md)
- https://velog.io/@bread_dd/Spring-Boot-Devtools
- http://progtrend.blogspot.com/2019/05/thymeleaf.html