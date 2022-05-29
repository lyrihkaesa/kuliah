package old;

import java.sql.*;

public class KoneksiDBMS {

    // usang (deprecated) driver: "mysql-connector-java-5.1.4.jar" [not recomend]
    // String driverdbms = "com.mysql.jdbc.Driver";

    // new driver: "mysql-connector-java-8.0.29.jar"
    String driverdbms = "com.mysql.cj.jdbc.Driver";

    // jdbc:jenis-database://host:port/database
    String database = "jdbc:mysql://localhost:3306/pbo_kukuh06495";
    String username = "root";
    String password = "";

    public Connection getConnection() {
        try {
            Connection connection = DriverManager.getConnection(database, username, password);
            System.out.println("Connection success!");
            return connection;
        } catch (SQLException exception) {
            System.out.println("SQL Error! " + exception.getMessage());
            return null;
        } catch (Exception exception) {
            System.out.println("Database Connection failed! " + exception.getMessage());
            return null;
        }
    }
}
