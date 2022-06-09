package src.repository;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import src.entity.Barang;
import src.entity.Transaction;
import src.util.DatabaseUtil;

public class TransactionRepositoryImpl implements TransactionRepository {

    @Override
    public int insert(Transaction transaction) {
        int result = 0;
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "INSERT INTO jual(transaction_id, id_item, price_item, amount_item) VALUES ('"
                    + transaction.getTransactionId() + "','"
                    + transaction.getBarang().getId() + "',"
                    + transaction.getBarang().getSellingPrice() + ","
                    + transaction.getAmount() + ")";
            result = statement.executeUpdate(sql);

            Barang barang = transaction.getBarang();
            barang.setAmount(barang.getAmount() - transaction.getAmount());
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            barangRepositoryImpl.update(barang);

            statement.close();
            connection.close();
            return result;
        } catch (SQLException sqlException) {
            System.err.println("Error Insert " + sqlException.getMessage());
            return result;
        }
    }

    @Override
    public String getLastId() {
        String result = "";
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT transaction_id FROM jual ORDER BY transaction_id DESC";
            ResultSet resultSet = statement.executeQuery(sql);

            if (resultSet.next()) {
                int tempTransactionId = Integer.parseInt(resultSet.getString("transaction_id"));
                result = String.valueOf(tempTransactionId + 1);
            } else {
                result = "21001";
            }

            resultSet.close();
            statement.close();
            connection.close();
            return result;
        } catch (SQLException sqlException) {
            System.err.println("Error Insert " + sqlException.getMessage());
            return result;
        }
    }

}
