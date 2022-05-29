package src.model;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class BarangRepositoryImpl implements BarangRepository {

    @Override
    public int insert(BarangModel barang) {
        int result = 0;
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "INSERT INTO barang(id, name, selling_price, purchase_price, amount) VALUES ('"
                    + barang.getId() + "','"
                    + barang.getName() + "','"
                    + barang.getSellingPrice() + "','"
                    + barang.getPurchasePrice() + "','"
                    + barang.getAmount() + "')";
            result = statement.executeUpdate(sql);
            statement.close();
            connection.close();
            return result;
        } catch (SQLException exception) {
            System.err.println("Error Insert " + exception.getMessage());
            return result;
        }
    }

    @Override
    public int update(BarangModel barang) {
        int result = 0;
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "UPDATE barang SET name = '"
                    + barang.getName()
                    + "', selling_price = '" + barang.getSellingPrice()
                    + "', purchase_price = '" + barang.getPurchasePrice()
                    + "', amount = '" + barang.getAmount()
                    + "' WHERE id = '" + barang.getId() + "' ";
            result = statement.executeUpdate(sql);
            statement.close();
            connection.close();
            return result;
        } catch (SQLException exception) {
            System.err.println("Error Update " + exception.getMessage());
            return result;
        }
    }

    @Override
    public int delete(String id) {
        int result = 0;
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "DELETE FROM barang WHERE id = '" + id + "' ";
            result = statement.executeUpdate(sql);
            statement.close();
            connection.close();
            return result;
        } catch (SQLException exception) {
            System.err.println("Error Delete " + exception.getMessage());
            return result;
        }
    }

    @Override
    public BarangModel selectById(String id) {
        BarangModel barang = new BarangModel();
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM barang WHERE id ='" + id + "'";
            ResultSet resultSet = statement.executeQuery(sql);

            if (resultSet.next()) {
                barang.setId(resultSet.getString("id"));
                barang.setName(resultSet.getString("name"));
                barang.setSellingPrice(resultSet.getInt("selling_price"));
                barang.setPurchasePrice(resultSet.getInt("purchase_price"));
                barang.setAmount(resultSet.getInt("amount"));
            }

            resultSet.close();
            statement.close();
            connection.close();
            return barang;
        } catch (SQLException exception) {
            System.err.println("Error Select By NIP " + exception.getMessage());
            return barang;
        }
    }

    @Override
    public List<BarangModel> selectAll() {
        List<BarangModel> barangList = new ArrayList<>();
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM barang";
            ResultSet resultSet = statement.executeQuery(sql);

            while (resultSet.next()) {
                BarangModel barang = new BarangModel();
                barang.setId(resultSet.getString("id"));
                barang.setName(resultSet.getString("name"));
                barang.setSellingPrice(resultSet.getInt("selling_price"));
                barang.setPurchasePrice(resultSet.getInt("purchase_price"));
                barang.setAmount(resultSet.getInt("amount"));
                barangList.add(barang);
            }

            resultSet.close();
            statement.close();
            connection.close();
            return barangList;
        } catch (SQLException exception) {
            System.err.println("Error Select By NIP " + exception.getMessage());
            return barangList;
        }
    }

}
