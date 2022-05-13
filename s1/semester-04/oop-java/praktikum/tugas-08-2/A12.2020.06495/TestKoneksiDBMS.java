import java.sql.*;

public class TestKoneksiDBMS {
    public static void main(String[] args) {
        try {
            KoneksiDBMS CnPenjualan = new KoneksiDBMS();
            Connection con = CnPenjualan.BukaCn();

            if (con != null) {
                System.out.println("Connection Succesfully!");

            } else {
                System.out.println("Connection Failed!");
            }
            con.close();
        } catch (SQLException e) {
            System.out.println("SQL Syntax Error!" + e.getMessage());
        }
    }
}
