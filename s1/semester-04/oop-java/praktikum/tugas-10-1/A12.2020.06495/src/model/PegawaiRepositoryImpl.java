package src.model;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class PegawaiRepositoryImpl implements PegawaiRepository {

    @Override
    public int insert(PegawaiModel pegawai) {
        int result = 0;
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "INSERT INTO pegawai(nip, nama, bagian, jenis_kelamin, password) VALUES" +
                    " ('" + pegawai.getNip()
                    + "','" + pegawai.getNama()
                    + "','" + pegawai.getBagian()
                    + "','" + pegawai.getJenisKelamin()
                    + "','" + pegawai.getPassword() + "')";
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
    public int update(PegawaiModel pegawai) {
        int result = 0;
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "UPDATE pegawai SET nama = '" + pegawai.getNama() +
                    "', bagian = '" + pegawai.getBagian() +
                    "', jenis_kelamin = '" + pegawai.getJenisKelamin() +
                    "', password = '" + pegawai.getPassword() +
                    "' WHERE nip = '" + pegawai.getNip() + "' ";
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
    public int delete(String nip) {
        int result = 0;
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "DELETE FROM pegawai WHERE nip = '" + nip + "' ";
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
    public PegawaiModel selectByNip(String nip) {
        PegawaiModel pegawai = new PegawaiModel();
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM pegawai WHERE nip ='" + nip + "'";
            ResultSet resultSet = statement.executeQuery(sql);

            if (resultSet.next()) {
                pegawai.setNip(resultSet.getString("nip"));
                pegawai.setNama(resultSet.getString("nama"));
                pegawai.setBagian(resultSet.getString("bagian"));
                pegawai.setJenisKelamin(resultSet.getString("jenis_kelamin"));
                pegawai.setPassword(resultSet.getString("password"));
            }

            resultSet.close();
            statement.close();
            connection.close();
            return pegawai;
        } catch (SQLException exception) {
            System.err.println("Error Select By NIP " + exception.getMessage());
            return pegawai;
        }
    }

    @Override
    public List<PegawaiModel> selectAll() {
        List<PegawaiModel> pegawaiList = new ArrayList<>();
        try {
            Connection connection = new ConnectionUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM pegawai";
            ResultSet resultSet = statement.executeQuery(sql);

            while (resultSet.next()) {
                PegawaiModel pegawai = new PegawaiModel();
                pegawai.setNip(resultSet.getString("nip"));
                pegawai.setNama(resultSet.getString("nama"));
                pegawai.setBagian(resultSet.getString("bagian"));
                pegawai.setJenisKelamin(resultSet.getString("jenis_kelamin"));
                pegawai.setPassword(resultSet.getString("password"));
                pegawaiList.add(pegawai);
            }

            resultSet.close();
            statement.close();
            connection.close();
            return pegawaiList;
        } catch (SQLException exception) {
            System.err.println("Error Select By NIP " + exception.getMessage());
            return pegawaiList;
        }
    }

}
