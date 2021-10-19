package ch12;

import java.util.HashSet;
import java.util.Iterator;

public class MemberHashSet {
  
  private HashSet<Member> hashSet;

  public MemberHashSet() {
    hashSet = new HashSet<>();
  }

  public MemberHashSet(int size) {
    hashSet = new HashSet<>(size);
  }

  public void addMember(Member member) {
    hashSet.add(member);
  }

  public boolean removeMember(int memberId) {

    /*
    for (int i=0; i<arrayList.size(); i++) {
      Member member = arrayList.get(i);
      int tempId = member.getMemberId();
      if (tempId == memberId) {
        arrayList.remove(i);
        return true;
      }
    }
    */

    // Using Iterator method
    Iterator<Member> ir = hashSet.iterator();

    while (ir.hasNext()) {
      Member member = ir.next();

      int tempId = member.getMemberId();
      if (tempId == memberId) {
        hashSet.remove(member);
        return true;
      }
    }

    System.out.println(memberId + " is not exist.");
    return false;
  }

  public void showAllMember() {

    for (Member member : hashSet) {
      System.out.println(member);
    }
    System.out.println();
  }

}
