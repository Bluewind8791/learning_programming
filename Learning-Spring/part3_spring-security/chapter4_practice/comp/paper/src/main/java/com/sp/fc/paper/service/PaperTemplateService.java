package com.sp.fc.paper.service;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import com.sp.fc.paper.domain.PaperTemplate;
import com.sp.fc.paper.domain.Problem;
import com.sp.fc.paper.repository.PaperTemplateRepository;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import lombok.RequiredArgsConstructor;

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

    public Problem addProblem(long paperTemplateId, Problem problem) {
        problem.setPaperTemplateId(paperTemplateId); // 문제에 시험지 아이디를 추가하고
        return findById(paperTemplateId).map(paperTemplate -> {
            if (paperTemplate.getProblemList() == null) { // 만약 시험지에 문제가 없다면
                paperTemplate.setProblemList(new ArrayList<>()); // 새로운 array list 추가
            }
            problem.setCreated(LocalDateTime.now()); // 생성시간 세팅
            paperTemplate.getProblemList().add(problem); // 시험지에 problem 추가
            IntStream.rangeClosed(1, paperTemplate.getProblemList().size()).forEach(i -> {
                paperTemplate.getProblemList().get(i-1).setIndexNum(i); // 시험지에 int stream으로 1부터 끝까지 가져와서 각 문제를 집어넣는다
            });
            paperTemplate.setTotal(paperTemplate.getProblemList().size()); // set total
            Problem saved = problemService.save(problem);
            save(paperTemplate);
            return saved;
        }).orElseThrow(
            () -> new IllegalArgumentException(paperTemplateId+" 아이디 시험지가 없습니다.")
        );
    }

    public PaperTemplate removeProblem(long paperTemplateId, long problemId) {
        return findById(paperTemplateId).map(paperTemplate -> {
            if (paperTemplate.getProblemList() == null) {
                return paperTemplate; // problem list 가 없으면
            }
            // problem 을 생성하는데, problem Id 와 같은것을 필터링하여 첫번째만 가져온다
            Optional<Problem> problem = paperTemplate.getProblemList().stream().filter(
                p -> p.getProblemId().equals(problemId)).findFirst();
            
            if (problem.isPresent()) { // problem 이 존재한다면
                paperTemplate.setProblemList( // problem id 와 같지않은 problem 만 가져와서 set 한다.
                    paperTemplate.getProblemList().stream().filter(
                        p -> !p.getProblemId().equals(problemId)).collect(Collectors.toList()
                    )
                );
                problemService.delete(problem.get()); // 
                IntStream.rangeClosed(1, paperTemplate.getProblemList().size()).forEach(i -> {
                    paperTemplate.getProblemList().get(i-1).setIndexNum(i);
                });
            }
            paperTemplate.setTotal(paperTemplate.getProblemList().size());
            return save(paperTemplate);
        }).orElseThrow(
            () -> new IllegalArgumentException(paperTemplateId + " 아이디 시험지가 없습니다.")
        );
    }

    public Optional<PaperTemplate> findById(long paperTemplateId) {
        return paperTemplateRepository.findById(paperTemplateId);
    }

    public void update(long problemId, String content, String answer) {
        problemService.updateProblem(problemId, content, answer);
    }

    @Transactional(readOnly = true) // 읽기 전용 트랜잭션
    public Optional<PaperTemplate> findProblemTemplate(Long paperTemplateId) {
        return paperTemplateRepository.findById(paperTemplateId).map(pt -> {
            if (pt.getProblemList().size() != pt.getTotal()) { // lazy 해결을 위하여 체크
                pt.setTotal(pt.getProblemList().size());
            }
            return pt;
        });
    }

    @Transactional(readOnly = true)
    public Map<Integer, String> getPaperAnswerSheet(Long paperTemplateId) {
        Optional<PaperTemplate> template = findById(paperTemplateId);
        if(!template.isPresent()) return new HashMap<>();
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
