package ch13;

import java.util.Iterator;
import java.util.TreeSet;

public class MemberTreeSet {
  
  private TreeSet<Member> treeSet;

  public MemberTreeSet() {
    // comparator 구현 시, 어떤것으로 구현했는지 comparator 대상을 써줘야함
    treeSet = new TreeSet<Member>(new Member());
    // treeSet = new TreeSet<>();
    
  }

  public void addMember(Member member) {
    treeSet.add(member);
  }

  public boolean removeMember(int memberId) {


    // Using Iterator method
    Iterator<Member> ir = treeSet.iterator();

    while (ir.hasNext()) {
      Member member = ir.next();

      int tempId = member.getMemberId();
      if (tempId == memberId) {
        treeSet.remove(member);
        return true;
      }
    }

    System.out.println(memberId + " is not exist.");
    return false;
  }

  public void showAllMember() {

    for (Member member : treeSet) {
      System.out.println(member);
    }
    System.out.println();
  }

}
