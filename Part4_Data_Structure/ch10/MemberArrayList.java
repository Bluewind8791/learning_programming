package ch10;

import java.util.ArrayList;
import java.util.Iterator;

public class MemberArrayList {
  
  private ArrayList<Member> arrayList;

  public MemberArrayList() {
    arrayList = new ArrayList<>();
  }

  public MemberArrayList(int size) {
    arrayList = new ArrayList<>(size);
  }

  public void addMember(Member member) {
    arrayList.add(member);
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
    Iterator<Member> ir = arrayList.iterator();

    while (ir.hasNext()) {
      Member member = ir.next();

      int tempId = member.getMemberId();
      if (tempId == memberId) {
        arrayList.remove(member);
        return true;
      }
    }

    System.out.println(memberId + " is not exist.");
    return false;
  }

  public void showAllMember() {

    for (Member member : arrayList) {
      System.out.println(member);
    }
    System.out.println();
  }

}
