package src;

import java.awt.Color;
import java.awt.Font;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

import javax.swing.border.LineBorder;

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

    public class MyColor {
        public static final Color GREY900 = new Color(29, 41, 57);
        public static final Color GREY700 = new Color(74, 85, 104);
        public static final Color PURPLE100 = new Color(250, 245, 255);
        public static final Color PURPLE200 = new Color(233, 216, 253);
        public static final Color PURPLE500 = new Color(159, 122, 234);
        public static final Color GREEN500 = new Color(72, 187, 120);
        public static final Color BLUE500 = new Color(66, 153, 225);
        public static final Color ERROR500 = new Color(255, 57, 50);
        public static final Color WARNING500 = new Color(247, 144, 9);
        public static final Color SUCCESS500 = new Color(96, 181, 39);
    }

    public class MyFont {
        public static final Font TITLE = new Font("Arial", Font.BOLD, 40);
        public static final Font SUBTITLE = new Font("Arial", Font.BOLD, 24);
        public static final Font LABEL = new Font("Arial", Font.BOLD, 18);
        public static final Font TEXTFIELD = new Font("Arial", Font.PLAIN, 14);
        public static final Font BUTTON = new Font("Arial", Font.BOLD, 14);
    }

    public class MyBorder {
        public static final LineBorder BORDER2 = new LineBorder(AppConfig.MyColor.PURPLE200, 2);
        public static final LineBorder ERROR_BORDER2 = new LineBorder(AppConfig.MyColor.ERROR500, 2);
        public static final LineBorder SUCCESS_BORDER2 = new LineBorder(AppConfig.MyColor.SUCCESS500, 2);
    }
}
