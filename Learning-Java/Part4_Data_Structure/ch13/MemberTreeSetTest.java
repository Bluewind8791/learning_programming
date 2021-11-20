package ch13;

import java.util.Comparator;
import java.util.TreeSet;


public class MemberTreeSetTest {
  
  public static void main(String[] args) {
    
    /*
    TreeSet<String> set = new TreeSet<String>();

    set.add("Hong");
    set.add("Kang");
    set.add("Lee");

    System.out.println(set);*/

    /*
    MemberTreeSet memberTreeSet = new MemberTreeSet();
    
    Member memberHong = new Member(1003, "Hong");
    Member memberLee = new Member(1001, "Lee");
    Member memberKim = new Member(1002, "Kim");
    Member memberKang = new Member(1004, "Kang");

    memberTreeSet.addMember(memberHong);
    memberTreeSet.addMember(memberLee);
    memberTreeSet.addMember(memberKim);
    memberTreeSet.addMember(memberKang);

    memberTreeSet.showAllMember();
    // Comparable 에서 compareTo 로 override해줘야 정렬의 기준을 세울 수 있음.
    */

    //                                       무엇으로 비교할지 지정
    TreeSet<String> set = new TreeSet<String>(new MyCompare());
    set.add("Park");
    set.add("Kim");
    set.add("Lee");

    System.out.println(set); // Kim Lee Park

  }
}


class MyCompare implements Comparator<String> {
  @Override
  public int compare(String o1, String o2) {
    // return o2.compareTo(o1); // Park Lee Kim
    return o1.compareTo(o2); // Kim Lee Park
  }
}