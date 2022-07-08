package src.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

import src.AppConfig;

public class DatabaseUtil {
    Properties properties = AppConfig.properties;
    String HOST = properties.getProperty("database.host");
    String PORT = properties.getProperty("database.port");
    String DATABASE = properties.getProperty("database.database");
    String USERNAME = properties.getProperty("database.username");
    String PASSWORD = properties.getProperty("database.password");

    // usang (deprecated) driver: "mysql-connector-java-5.1.4.jar" [not recomend]
    // String driverdbms = "com.mysql.jdbc.Driver";

    // new driver: "mysql-connector-java-8.0.29.jar"
    String driverDBMS = "com.mysql.cj.jdbc.Driver";

    // jdbc:jenis-database://host:port/database
    String database = "jdbc:mysql://" + HOST + ":" + PORT + "/" + DATABASE;

    public Connection getConnection() {
        try {
            Connection connection = DriverManager.getConnection(database, USERNAME, PASSWORD);
            // System.out.println("Connection success!");
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