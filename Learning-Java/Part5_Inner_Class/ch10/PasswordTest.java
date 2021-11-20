package ch10;

public class PasswordTest {
  
  private String password;

  public String getPassword() {
    return password;
  }
  public void setPassword(String password) throws PasswordException {
    
    if (password == null) {
      throw new PasswordException("비밀번호를 입력해 주세요.");
    }
    else if (password.length() < 5) {
      throw new PasswordException("비밀번호는 5자 이상이여야 합니다.");
    }// regular expression
    else if(password.matches("[a-zA-Z]+")) {
      throw new PasswordException("비밀번호는 숫자나 특수문자를 포함해야 합니다.");
    }

    this.password = password;
  }





  public static void main(String[] args) {
    
    PasswordTest test = new PasswordTest();

    String password = null;

    try {
      test.setPassword(password);
      System.out.println("No Error1");
    } catch (PasswordException e) {
      System.out.println(e.getMessage());
    }


    password = "abc";

    try {
      test.setPassword(password);
      System.out.println("No Error2");
    } catch (PasswordException e) {
      System.out.println(e.getMessage());
    }

    password = "abcde";

    try {
      test.setPassword(password);
      System.out.println("No Error3");
    } catch (PasswordException e) {
      System.out.println(e.getMessage());
    }

    password = "abcde1#";

    try {
      test.setPassword(password);
      System.out.println("No Error4");
    } catch (PasswordException e) {
      System.out.println(e.getMessage());
    }

  }
}
