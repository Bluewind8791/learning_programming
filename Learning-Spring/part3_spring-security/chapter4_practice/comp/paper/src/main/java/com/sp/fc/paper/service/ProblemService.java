package com.sp.fc.paper.service;

import java.time.LocalDateTime;

import com.sp.fc.paper.domain.Problem;
import com.sp.fc.paper.repository.ProblemRepository;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import lombok.RequiredArgsConstructor;

@Service
@Transactional
@RequiredArgsConstructor
public class ProblemService {

    private final ProblemRepository problemRepository;

    protected Problem save(Problem problem) {
        if (problem.getProblemId() == null) {
            problem.setCreated(LocalDateTime.now());
        }
        return problemRepository.save(problem);
    }

    public void delete(Problem problem) {
        problemRepository.delete(problem);
    }

    public void updateProblem(long problemId, String content, String answer) {
        problemRepository.updateProblem(problemId, content, answer, LocalDateTime.now());
    }

    // @Transactional
    // public List<Paper> publishPaper(long paperTemplateId, List<Long> studentIdList) {
    //     List<Paper> papers = paperTemplateService.findById(paperTemplateId)
    // }


}
