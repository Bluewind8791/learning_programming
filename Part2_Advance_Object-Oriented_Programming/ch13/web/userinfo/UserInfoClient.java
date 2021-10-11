package ch13.web.userinfo;

import java.io.FileInputStream;
// import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import ch13.domain.userinfo.UserInfo;
import ch13.domain.userinfo.dao.UserInfoDao;
import ch13.domain.userinfo.dao.mysql.UserInfoMySQLDao;
import ch13.domain.userinfo.dao.oracle.UserInfoOracleDao;

public class UserInfoClient {
  public static void main(String[] args) throws IOException {

    // file 읽어오기
    FileInputStream fis = new FileInputStream("./ch13/db.properties");

    // 00 = 00 이렇게 쌍으로 되어있는 형식을 읽어옴
    Properties prop = new Properties();
    prop.load(fis);

    UserInfo userInfo = new UserInfo();
    UserInfoDao userInfoDao = null; // userInfoDao는 나중에 if문에서 구현

    userInfo.setUserID("Bluewind");
    userInfo.setPassword("12345");
    userInfo.setUserName("Kim");

    // 앞 = 뒤 의 형식에서 뒤의 값을 반환해 줌
    String dbType = prop.getProperty("DBTYPE");

    if (dbType.equals("ORACLE")) { // 뒤의 값이 오라클이면 오라클 dao를 사용
      userInfoDao = new UserInfoOracleDao();
    }
    else if (dbType.equals("MYSQL")) { // 뒤의 값이 MySQL이면 MYSQL 사용
      userInfoDao = new UserInfoMySQLDao();
    }
    else { // 아무것도 없다면 에러문구 표시 후 return
      System.out.println("DB ERROR!");
      return;
    }

    userInfoDao.insertUserInfo(userInfo);
    userInfoDao.updateUserInfo(userInfo);
    userInfoDao.deleteUserInfo(userInfo);
  }

}
