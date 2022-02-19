package com.sp.fc.paper.service;


import com.sp.fc.paper.domain.Paper;
import com.sp.fc.paper.domain.PaperAnswer;
import com.sp.fc.paper.repository.PaperAnswerRepository;
import com.sp.fc.paper.repository.PaperRepository;
import com.sp.fc.user.repository.UserRepository;

import org.springframework.data.domain.Page;
import org.springframework.data.domain.PageRequest;
import org.springframework.security.access.prepost.PostAuthorize;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import lombok.RequiredArgsConstructor;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

@Service
@Transactional
@RequiredArgsConstructor
public class PaperService {

    private final UserRepository userRepository;
    private final PaperTemplateService paperTemplateService;
    private final PaperRepository paperRepository;
    private final PaperAnswerRepository paperAnswerRepository;

    protected Paper save(Paper paper) {
        if (paper.getPaperId() == null) {
            paper.setCreated(LocalDateTime.now());
        }
        return paperRepository.save(paper);
    }

    @Transactional
    public List<Paper> publishPaper(long paperTemplateId, List<Long> studyIdList){
        // paperTemplateId로 paper template를 가져온 다음
        List<Paper> papers = paperTemplateService.findById(paperTemplateId).map(paperTemplate ->
                // user repo 에서 student를 모두 찾아서 하나씩 쪼갠다
                StreamSupport.stream(userRepository.findAllById(studyIdList).spliterator(), false)
                        .map(study -> { // 시험지를 build 하여 학생의 아이디를 넣고 save
                            Paper paper = Paper.builder()
                                    .paperTemplateId(paperTemplate.getPaperTemplateId())
                                    .name(paperTemplate.getName())
                                    .state(Paper.PaperState.READY)
                                    .studyUserId(study.getUserId())
                                    .total(paperTemplate.getTotal())
                                    .build();
                            return save(paper);
                        }).collect(Collectors.toList()) // 다시 list로 collect
        ).orElseThrow(()->new IllegalArgumentException(paperTemplateId+" 시험지 템플릿이 존재하지 않습니다."));
        paperTemplateService.updatePublishedCount(paperTemplateId, papers.size());
        return papers;
    }

    public void removePaper(long paperTemplateId, List<Long> studyIdList){
        paperRepository.findAllByPaperTemplateIdAndStudyUserIdIn(paperTemplateId, studyIdList)
                .forEach(paper -> {
                    paperRepository.delete(paper);
                });
    }

    @Transactional
    public void answer(Long paperId, Long problemId, int num, String answer){
        // paper repo에서 시험지를 아이디로 찾고
        paperRepository.findById(paperId).ifPresentOrElse(paper->{
            // 정답리스트를 가져와서 pa에 대입, null 이라면 빈 객체를 삽입
            Optional<PaperAnswer> pa = paper.getPaperAnswerList() == null ? Optional.empty() :
                    // answer list 를 가져와서 정답의 아이디가 num과 같은 첫번째를 꺼낸다.
                    paper.getPaperAnswerList().stream().filter(a -> a.getId().getNum() == num).findFirst();
            if (pa.isPresent()) { // 존재한다면 시험지 정답 setting 후 save
                PaperAnswer pAnswer = pa.get();
                pAnswer.setAnswer(answer);
                pAnswer.setAnswered(LocalDateTime.now());
                pAnswer.setProblemId(problemId);
                paperAnswerRepository.save(pAnswer);
            } else {
                PaperAnswer pAnswer = PaperAnswer.builder() // 존재하지 않는다면 시험지 정답 build 후 save
                        .id(new PaperAnswer.PaperAnswerId(paperId, num))
                        .problemId(problemId)
                        .answer(answer)
                        .answered(LocalDateTime.now())
                        .build();
                // paperAnswerRepository.save(pAnswer);
                pAnswer.setPaper(paper);
                if (paper.getPaperAnswerList() == null) { // 시험지의 정답리스트가 없다면 빈 list를 넣고
                    paper.setPaperAnswerList(new ArrayList<>());
                }
                paper.getPaperAnswerList().add(pAnswer); // 시험지의 정답리스트에 정답 추가
                paper.addAnswered();
                if (paper.getState() != Paper.PaperState.START){
                    paper.setState(Paper.PaperState.START);
                    paper.setStartTime(LocalDateTime.now());
                }
                paperRepository.save(paper);
            }
        }, ()->new IllegalArgumentException(paperId+" 시험지를 찾을 수 없습니다."));
    }

    @Transactional
    public void paperDone(Long paperId){
        // 시험을 끝냈으면 해당 시험지의 답안을 비교해서 채점 한다.
        final Paper paper = paperRepository.findById(paperId).orElseThrow(()->new IllegalArgumentException(paperId+" 시험지를 찾을 수 없습니다."));
        final Map<Integer, String> answerSheet = paperTemplateService.getPaperAnswerSheet(paper.getPaperTemplateId());
        paper.setCorrect(0);
        if (paper.getPaperAnswerList() != null) {
            paper.getPaperAnswerList().forEach(answer -> {
                if (answer.getAnswer() != null && answer.getAnswer().equals(answerSheet.get(answer.getId().getNum()))) {
                    answer.setCorrect(true);
                    paper.addCorrect();
                    paperAnswerRepository.save(answer);
                }
            });
        }
        paper.setState(Paper.PaperState.END);
        paper.setEndTime(LocalDateTime.now());
        Paper saved = paperRepository.save(paper);
//        paperTemplateService.findById(saved.getPaperTemplateId()).map(paperTemplate -> paperTemplate.setCompleteCount(saved.))
        paperTemplateService.updateCompleteCount(saved.getPaperTemplateId());
    }

    @Transactional(readOnly = true)
    public List<Paper> getPapers(Long paperTemplateId) {
        return paperRepository.findAllByPaperTemplateId(paperTemplateId);
    }

    @Transactional(readOnly = true)
    public List<Paper> getPapersByUser(Long studyUserId) {
        return paperRepository.findAllByStudyUserIdOrderByCreatedDesc(studyUserId);
    }

    @Transactional(readOnly = true)
    public List<Paper> getPapersByUserState(Long studyUserId, Paper.PaperState state) {
        return paperRepository.findAllByStudyUserIdAndStateOrderByCreatedDesc(studyUserId, state);
    }

    @Transactional(readOnly = true)
    public List<Paper> getPapersByUserIng(Long studyUserId) {
        return paperRepository.findAllByStudyUserIdAndStateInOrderByCreatedDesc(studyUserId, List.of(Paper.PaperState.READY, Paper.PaperState.START));
    }

    @Transactional(readOnly = true)
    public long countPapersByUserIng(Long studyUserId) {
        return paperRepository.countByStudyUserIdAndStateIn(studyUserId, List.of(Paper.PaperState.READY, Paper.PaperState.START));
    }

    @Transactional(readOnly = true)
    public Page<Paper> getPapersByUserResult(Long studyUserId, int pageNum, int size) {
        return paperRepository.findAllByStudyUserIdAndStateOrderByCreatedDesc(studyUserId, Paper.PaperState.END, PageRequest.of(pageNum-1, size));
    }

    @Transactional(readOnly = true)
    public long countPapersByUserResult(Long studyUserId) {
        return paperRepository.countByStudyUserIdAndState(studyUserId, Paper.PaperState.END);
    }

    @Transactional(readOnly = true)
    public List<Paper> getPapersByUserState(Long studyUserId, List<Paper.PaperState> states) {
        return paperRepository.findAllByStudyUserIdAndStateInOrderByCreatedDesc(studyUserId, states);
    }

    @PostAuthorize("returnObject.isEmpty() || returnObject.get().studyUserId == principal.userId") // 본인만 조회하도록 권한을 건다
    @Transactional(readOnly = true)
    public Optional<Paper> findPaper(Long paperId) {
        return paperRepository.findById(paperId).map(paper -> {
            paper.setUser(userRepository.getOne(paper.getStudyUserId()));
            return paper; // user 정보까지 같이 return
        });
    }

}

