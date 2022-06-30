package src;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

import src.entity.Pegawai;
import src.entity.Transaction;

public class AppConfig {

    public static Properties properties;

    public static Properties configProp(String appProp) {
        Properties properties = new Properties();
        try {
            InputStream inputStream = new FileInputStream(appProp);
            // load a properties file from class path, inside static method
            properties.load(inputStream);
            return properties;
        } catch (FileNotFoundException fileNotFoundException) {
            System.err.println("File " + appProp + " tidak ditemukan.");
            return properties;
        } catch (IOException ioException) {
            System.err.println("File " + appProp + " tidak bisa di load.");
            return properties;
        }
    }

    public static String NIM;
    public static String FULLNAME_AUTHOR;
    public static String AUTHOR;

    public static String[] PROGRAM_TITLE = {
            "Program Pegawai",
            "Program Barang",
            "Menu Penjualan",
            "Transaksi Penjualan",
            "Cetak Laporan" };

    public static Pegawai pegawai;
    public static List<Transaction> listTransaction = new ArrayList<>();

}
