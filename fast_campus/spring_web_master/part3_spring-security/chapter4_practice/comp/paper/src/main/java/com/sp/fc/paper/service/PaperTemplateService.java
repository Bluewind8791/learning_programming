package com.sp.fc.paper.service;

import com.sp.fc.paper.domain.PaperTemplate;
import com.sp.fc.paper.domain.Problem;
import com.sp.fc.paper.repository.PaperTemplateRepository;
import com.sp.fc.user.domain.Authority;
import com.sp.fc.user.domain.User;

import lombok.RequiredArgsConstructor;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.security.access.AccessDeniedException;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

@Service
@Transactional
@RequiredArgsConstructor
public class PaperTemplateService {

    private final PaperTemplateRepository paperTemplateRepository;
    private final ProblemService problemService;

    public PaperTemplate save(PaperTemplate paperTemplate) {
        if (paperTemplate.getPaperTemplateId() == null) {
            paperTemplate.setCreated(LocalDateTime.now());
        }
        paperTemplate.setUpdated(LocalDateTime.now());
        return paperTemplateRepository.save(paperTemplate);
    }

    public Optional<PaperTemplate> findById(long paperTemplateId) {
        return paperTemplateRepository.findById(paperTemplateId);
    }


    public Problem addProblem(long paperTemplateId, Problem problem) {
        // problem 에 paper template id setting
        problem.setPaperTemplateId(paperTemplateId);
        return findById(paperTemplateId).map(paperTemplate -> {
            // paper template 에서 problem list 를 가져오는데
            if (paperTemplate.getProblemList() == null) { // 없다면 새로운 리스트를 만든다.
                paperTemplate.setProblemList(new ArrayList<>());
            }
            problem.setCreated(LocalDateTime.now()); // problem 생성일자 setting
            paperTemplate.getProblemList().add(problem); // paper template 의 problem list 에 problem 추가
            IntStream.rangeClosed(1, paperTemplate.getProblemList().size()).forEach(i -> {
                paperTemplate.getProblemList().get(i-1).setIndexNum(i); // paper template 의 problemlist 에서 하나씩 꺼내와서 index를 매긴다.
            });
            paperTemplate.setTotal(paperTemplate.getProblemList().size()); // 총 문제 개수 세팅
            Problem saved = problemService.save(problem);
            save(paperTemplate);
            return saved;
        }).orElseThrow(()-> new IllegalArgumentException(paperTemplateId+" 아이디 시험지가 없습니다."));
    }

    public PaperTemplate removeProblem(long paperTemplateId, long problemId) {
        return findById(paperTemplateId).map(paperTemplate -> {
            if (paperTemplate.getProblemList() == null) {
                return paperTemplate; // problem list 가 없다면 return
            }
            // paper template 에서 problem list 를 가져와서 가져온 problem id가 같은 문제의 첫번째 삽입
            Optional<Problem> problem = paperTemplate.getProblemList().stream().filter(p -> p.getProblemId().equals(problemId)).findFirst();
            if (problem.isPresent()) { // 문제가 있다면
                paperTemplate.setProblemList(
                    // problem list 중에 받아온 problem id 가 다른것들만 모아서 paper template에 집어넣는다
                    paperTemplate.getProblemList().stream().filter(p -> !p.getProblemId().equals(problemId))
                                .collect(Collectors.toList())
                );
                // 그리고 problem 을 삭제
                problemService.delete(problem.get());
                IntStream.rangeClosed(1, paperTemplate.getProblemList().size()).forEach( i -> {
                    paperTemplate.getProblemList().get(i-1).setIndexNum(i); // problem template의 problem list 에 인덱스를 매긴다.
                });
            }
            paperTemplate.setTotal(paperTemplate.getProblemList().size());
            return save(paperTemplate);
        }).orElseThrow(()-> new IllegalArgumentException(paperTemplateId+" 아이디 시험지가 없습니다."));
    }


    // problem update 이기 때문에 paper template 에는 영향 x
    public void update(long problemId, String content, String answer) {
        problemService.updateProblem(problemId, content, answer);
    }

    // @PostAuthorize("returnObject.isEmpty() || returnObject.get().userId == principal.userId")
    @Transactional(readOnly = true)
    public Optional<PaperTemplate> findProblemTemplate(Long paperTemplateId) {
        return paperTemplateRepository.findById(paperTemplateId).map(pt->{
            if (pt.getProblemList().size() != pt.getTotal()) { // lazy 해결위해 체크
                pt.setTotal(pt.getProblemList().size()); // total size 가 다르다면 total을 맞춤
            }
            // 만약 user id 가 security context holder 의 user id 와 같지 않고
            if (pt.getUserId() != ((User)SecurityContextHolder.getContext().getAuthentication().getPrincipal()).getUserId()) {
                // admin 권한이 없다면
                if (!((User)SecurityContextHolder.getContext().getAuthentication().getPrincipal()).getAuthorities().contains(Authority.ADMIN_AUTHORITY) ) {
                    throw new AccessDeniedException("권한이 없습니다.");
                }
            }
            return pt;
        });
    }

    @Transactional(readOnly = true)
    public Map<Integer, String> getPaperAnswerSheet(Long paperTemplateId) {
        Optional<PaperTemplate> template = findById(paperTemplateId);
        if (!template.isPresent()) return new HashMap<>();
        return template.get().getProblemList().stream().collect(Collectors.toMap(Problem::getIndexNum, Problem::getAnswer));
    }

    @Transactional(readOnly = true)
    public List<PaperTemplate> findByTeacherId(Long userId) {
        return paperTemplateRepository.findAllByUserIdOrderByCreatedDesc(userId);
    }

    @Transactional(readOnly = true)
    public Page<PaperTemplate> findByTeacherId(Long userId, int pageNum, int size) {
        return paperTemplateRepository.findAllByUserIdOrderByCreatedDesc(userId, PageRequest.of(pageNum-1, size));
    }

    @Transactional(readOnly = true)
    public Object countByUserId(Long userId) {
        return paperTemplateRepository.countByuserId(userId);
    }

    public void updatePublishedCount(long paperTemplateId, long publishedCount) {
        paperTemplateRepository.findById(paperTemplateId).ifPresent(paperTemplate -> {
            paperTemplate.setPublishedCount(publishedCount);
            paperTemplateRepository.save(paperTemplate);
        });
    }

    public void updateCompleteCount(Long paperTemplateId) {
        paperTemplateRepository.findById(paperTemplateId).ifPresent(paperTemplate -> {
            paperTemplate.setCompleteCount(paperTemplate.getCompleteCount()+1);
            paperTemplateRepository.save(paperTemplate);
        });
    }
}
