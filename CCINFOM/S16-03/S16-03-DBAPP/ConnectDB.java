import java.sql.Connection;
import java.sql.DriverManager;

public class ConnectDB {

    public static Connection getConnection() throws Exception {
        String url = "jdbc:mysql://localhost:3306/dbsales?serverTimezone=Asia/Kuala_Lumpur";
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            return DriverManager.getConnection(url, "root", "12345");
        } catch (Exception e) {
            System.out.println("Error connecting to the database: " + e.getMessage());
            throw e;
        }
    }
}

