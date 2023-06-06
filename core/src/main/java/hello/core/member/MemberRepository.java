package hello.core.member;

public interface MemberRepository {

    /**
     * 회원 저장
     * @param member
     */
    void save(Member member);

    /**
     * 회원 찾기
     * @param memberId
     * @return
     */
    Member findById(Long memberId);
}
