package ch13.domain.userinfo;


public class UserInfo {

  private String userID;
  private String password;
  private String userName;

  public String getUserID() {
    return userID;
  }
  public String getPassword() {
    return password;
  }
  public String getUserName() {
    return userName;
  }
  public void setUserID(String userID) {
    this.userID = userID;
  }
  public void setPassword(String password) {
    this.password = password;
  }
  public void setUserName(String userName) {
    this.userName = userName;
  }
}