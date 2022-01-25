package spring.hellospring.sevice;

import java.util.List;
import java.util.Optional;

import org.springframework.transaction.annotation.Transactional;

import spring.hellospring.domain.Member;
import spring.hellospring.repository.MemberRepository;

@Transactional // 데이터를 저장하거나 변경할때 트랜잭션이 필요
public class MemberService {
    
    private final MemberRepository memberRepository;

    public MemberService(MemberRepository memberRepository) {
        this.memberRepository = memberRepository;
    }

    // 회원가입
    public Long join(Member member) {
        // 같은 이름의 중복 회원은 안된다
        validateDuplicateMember(member);
        memberRepository.save(member);
        return member.getId();
    }

    private void validateDuplicateMember(Member member) {
        memberRepository.findByName(member.getName())
            .ifPresent(m -> {
                throw new IllegalStateException("이미 존재하는 회원입니다.");
            });
    }

    // 전체 회원 조회
    public List<Member> findMembers() {
        return memberRepository.findAll();
    }

    public Optional<Member> findOne(Long memberId) {
        return memberRepository.findById(memberId);
    }


}
