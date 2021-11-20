package ch14;

import java.util.Comparator;

public class Member implements Comparator<Member> {
	
	private int memberId;        // 회원 아이디
	private String memberName;   // 회원 이름

	public Member(int memberId, String memberName){ // 생성자
		this.memberId = memberId;
		this.memberName = memberName;
	}
	
	public int getMemberId() {  //
		return memberId;
	}
	public void setMemberId(int memberId) {
		this.memberId = memberId;
	}
	public String getMemberName() {
		return memberName;
	}
	public void setMemberName(String memberName) {
		this.memberName = memberName;
	}
	
	// 무엇이 같은지 equals와 hashCode를 구현해야함
	// equals와 hashCode를 구현하고나면 memberId가 같으면 hash에 들어가지 않음.
	@Override
	public boolean equals(Object obj) {
		
		if (obj instanceof Member) {
			Member member = (Member) obj;
			if(this.memberId == member.memberId) {
				return true;
			}
			else return false;
		}
		return false;
	}

	@Override
	public int hashCode() {
		return memberId;
	}


	@Override
	public String toString(){   // toString 메소드 오버로딩
		return memberName + " 회원님의 아이디는 " + memberId + "입니다";
	}

/*
	// Comparable에 추가해야할 메서드
	// 콜백함수로 내가 부르지않았지만 시스템이 부름
	@Override
	public int compareTo(Member member) {
		
		// member id를 기준으로 정렬, id 가 더 크면 true
		if (this.memberId > member.memberId) {
			return 1;
		}
		else if (this.memberId < member.memberId) {
			return -1;
		}
		else return 0;
		

		// 간략하게
		return (this.memberId - member.memberId); // 오름차순
		// return (this.memberId - member.memberId) * (-1); // 내림차순
	}
*/

	// comparator에 추가해야할 method
	@Override
	public int compare(Member o1, Member o2) {
		return (o1.memberId - o2.memberId);
	}

	// MemberTreeSet class에 어떤것으로 구현했는지 comparator 대상을 써줬기 때문에
	public Member() {}

}