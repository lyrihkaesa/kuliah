package src.repository;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import src.entity.Suplayer;
import src.util.DatabaseUtil;

public class SuplayerRepositoryImpl implements SuplayerRepository {

    @Override
    public int insert(Suplayer suplayer) {
        int result = 0;
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "INSERT INTO suplayer6498(kode, nama, alamat, kota, provinsi, telepon, email) VALUES ('"
                    + suplayer.getKode() + "','"
                    + suplayer.getNama() + "','"
                    + suplayer.getAlamat() + "','"
                    + suplayer.getKota() + "','"
                    + suplayer.getProvinsi() + "','"
                    + suplayer.getTelepon() + "','"
                    + suplayer.getEmail() + "')";
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
    public int update(Suplayer suplayer) {
        int result = 0;
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "UPDATE suplayer6498 SET nama = '"
                    + suplayer.getNama()
                    + "', alamat = '" + suplayer.getAlamat()
                    + "', kota = '" + suplayer.getKota()
                    + "', provinsi = '" + suplayer.getProvinsi()
                    + "', telepon = '" + suplayer.getTelepon()
                    + "', email = '" + suplayer.getEmail()
                    + "' WHERE kode = '" + suplayer.getKode() + "' ";
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
    public int delete(String kode) {
        int result = 0;
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "DELETE FROM suplayer WHERE kode = '" + kode + "' ";
            result = statement.executeUpdate(sql);
            statement.close();
            connection.close();
            return result;
        } catch (SQLException exception) {
            System.err.println("Error delete() " + exception.getMessage());
            return result;
        }
    }

    @Override
    public Suplayer selectByKode(String kode) {
        Suplayer suplayer = new Suplayer();
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM suplayer6498 WHERE kode ='" + kode + "'";
            ResultSet resultSet = statement.executeQuery(sql);

            if (resultSet.next()) {
                suplayer.setKode(resultSet.getString("kode"));
                suplayer.setNama(resultSet.getString("nama"));
                suplayer.setAlamat(resultSet.getString("alamat"));
                suplayer.setKota(resultSet.getString("kota"));
                suplayer.setProvinsi(resultSet.getString("provinsi"));
                suplayer.setTelepon(resultSet.getString("telepon"));
                suplayer.setEmail(resultSet.getString("email"));
            }

            resultSet.close();
            statement.close();
            connection.close();
            return suplayer;
        } catch (SQLException exception) {
            System.err.println("Error selectByKode " + exception.getMessage());
            return suplayer;
        }
    }

    @Override
    public List<Suplayer> selectAll() {
        List<Suplayer> suplayerList = new ArrayList<>();
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM suplayer6498";
            ResultSet resultSet = statement.executeQuery(sql);

            while (resultSet.next()) {
                Suplayer suplayer = new Suplayer();
                suplayer.setKode(resultSet.getString("kode"));
                suplayer.setNama(resultSet.getString("nama"));
                suplayer.setAlamat(resultSet.getString("alamat"));
                suplayer.setKota(resultSet.getString("kota"));
                suplayer.setProvinsi(resultSet.getString("provinsi"));
                suplayer.setTelepon(resultSet.getString("telepon"));
                suplayer.setEmail(resultSet.getString("email"));
                suplayerList.add(suplayer);
            }

            resultSet.close();
            statement.close();
            connection.close();
            return suplayerList;
        } catch (SQLException exception) {
            System.err.println("Error selectAll " + exception.getMessage());
            return suplayerList;
        }
    }

}
