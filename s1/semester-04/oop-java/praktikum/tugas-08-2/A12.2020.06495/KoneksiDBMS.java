import java.sql.*;

public class KoneksiDBMS {
    String driverdbms = "com.mysql.cj.jdbc.Driver";
    String database = "jdbc:mysql://localhost:3306/pbo_kukuh06495"; // port mysql
    String user = "kukuh";
    String password = "";

    public KoneksiDBMS() {
    }

    public Connection BukaCn() throws SQLException {
        Connection condbms = null;
        try {
            Class.forName(driverdbms);
            condbms = DriverManager.getConnection(database, user, password);
            return condbms;
        } catch (SQLException se) {
            System.out.println("SQL Error!");
            return null;
        } catch (Exception ex) {
            System.out.println("Database Connection failed!");
            return null;
        }
    }
}
