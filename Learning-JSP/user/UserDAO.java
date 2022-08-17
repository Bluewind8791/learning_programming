package user;

public class UserDAO {
    
    private Connection conn;
    private PreparedStatement pasmt;
    private ResultSet rs;

    public UserDAO() {
        try {
            String dbURL = "jdbc:oracle:thin:@localhost:1521:BBS";
            String dbID = "sys";
            String dbPassword = "1234";
            Class.forName("oracle.jdbc.driver.OracleDriver");
            conn = DriverManager.getConnection(dbURL, dbID, dbPassword);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
