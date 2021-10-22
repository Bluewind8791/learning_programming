package ch14;

import java.util.HashMap;

public class MemberHashMapTest {
  public static void main(String[] args) {
    
    MemberHashMap memberHashMap = new MemberHashMap();

    Member memberHong = new Member(1003, "Hong");
    Member memberLee = new Member(1001, "Lee");
    Member memberKim = new Member(1002, "Kim");
    Member memberKang = new Member(1004, "Kang");

    memberHashMap.addMember(memberHong);
    memberHashMap.addMember(memberLee);
    memberHashMap.addMember(memberKim);
    memberHashMap.addMember(memberKang);

    memberHashMap.showAllMember();

    HashMap<Integer, String> hashMap = new HashMap<Integer, String>();
    hashMap.put(1001, "Kim");
    hashMap.put(1003, "Lee");
    hashMap.put(1002, "Kang");
    hashMap.put(1005, "Kong");

    System.out.println(hashMap); // {1001=Kim, 1002=Kang, 1003=Lee, 1005=Kong} key=value pair로 출력
  }
}
