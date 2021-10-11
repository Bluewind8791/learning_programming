package ch13.domain.userinfo.dao.mysql;

import ch13.domain.userinfo.UserInfo;
import ch13.domain.userinfo.dao.UserInfoDao;

public class UserInfoMySQLDao implements UserInfoDao {

  @Override
  public void insertUserInfo(UserInfo userInfo) {
    System.out.println("Inserted into MySQL Database. USER ID : " + userInfo.getUserID());
  }

  @Override
  public void updateUserInfo(UserInfo userInfo) {
    System.out.println("Updated MySQL Database. USER ID : " + userInfo.getUserID());
  }

  @Override
  public void deleteUserInfo(UserInfo userInfo) {
    System.out.println("Deleted User Info at MySQL Database. USER ID : " + userInfo.getUserID());
  }
  
}
