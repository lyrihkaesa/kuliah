package src.repository;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import src.entity.Pegawai;
import src.util.DatabaseUtil;

public class PegawaiRepositoryImpl implements PegawaiRepository {

    @Override
    public int insert(Pegawai pegawai) {
        int result = 0;
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "INSERT INTO pegawai(nip, name, department, gender, password) VALUES" +
                    " ('" + pegawai.getNip()
                    + "','" + pegawai.getName()
                    + "','" + pegawai.getDepartment()
                    + "','" + pegawai.getGender()
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
    public int update(Pegawai pegawai) {
        int result = 0;
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "UPDATE pegawai SET name = '" + pegawai.getName() +
                    "', department = '" + pegawai.getDepartment() +
                    "', gender = '" + pegawai.getGender() +
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
            Connection connection = new DatabaseUtil().getConnection();
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
    public Pegawai selectByNip(String nip) {
        Pegawai pegawai = new Pegawai();
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM pegawai WHERE nip ='" + nip + "'";
            ResultSet resultSet = statement.executeQuery(sql);

            if (resultSet.next()) {
                pegawai.setNip(resultSet.getString("nip"));
                pegawai.setName(resultSet.getString("name"));
                pegawai.setDepartment(resultSet.getString("department"));
                pegawai.setGender(resultSet.getString("gender"));
                pegawai.setPassword(resultSet.getString("password"));
            }

            resultSet.close();
            statement.close();
            connection.close();
            return pegawai;
        } catch (SQLException exception) {
            System.err.println("Error selectByNip() " + exception.getMessage());
            return pegawai;
        }
    }

    @Override
    public List<Pegawai> selectAll() {
        List<Pegawai> pegawaiList = new ArrayList<>();
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM pegawai";
            ResultSet resultSet = statement.executeQuery(sql);

            while (resultSet.next()) {
                Pegawai pegawai = new Pegawai();
                pegawai.setNip(resultSet.getString("nip"));
                pegawai.setName(resultSet.getString("name"));
                pegawai.setDepartment(resultSet.getString("department"));
                pegawai.setGender(resultSet.getString("gender"));
                pegawai.setPassword(resultSet.getString("password"));
                pegawaiList.add(pegawai);
            }

            resultSet.close();
            statement.close();
            connection.close();
            return pegawaiList;
        } catch (SQLException exception) {
            System.err.println("Error selectAll() " + exception.getMessage());
            return pegawaiList;
        }
    }

    @Override
    public Pegawai selectByNipAndPassword(String nip, String password) {
        Pegawai pegawai = new Pegawai();
        try {
            Connection connection = new DatabaseUtil().getConnection();
            Statement statement = connection.createStatement();

            String sql = "SELECT * FROM pegawai WHERE nip ='" + nip + "' AND password = '" + password + "'";
            ResultSet resultSet = statement.executeQuery(sql);

            if (resultSet.next()) {
                pegawai.setNip(resultSet.getString("nip"));
                pegawai.setName(resultSet.getString("name"));
                pegawai.setDepartment(resultSet.getString("department"));
                pegawai.setGender(resultSet.getString("gender"));
                pegawai.setPassword(resultSet.getString("password"));
            }

            resultSet.close();
            statement.close();
            connection.close();
            return pegawai;
        } catch (SQLException exception) {
            System.err.println("Error selectByNipAndPassword() " + exception.getMessage());
            return pegawai;
        }
    }

}
