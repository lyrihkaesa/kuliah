package src.view;

import java.awt.Dimension;
import java.util.LinkedHashMap;
import java.util.Map;
import java.awt.BorderLayout;

import javax.swing.JButton;
import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

import src.AppConfig;
import src.service.CetakBarangServiceImpl;
import src.util.ExitUtil;
import src.util.FieldUtil;

public class FrameCetakBarangMin extends JFrame {

    private JLabel minimLabel = new JLabel("Stok Minim");

    private JTextField amountField = new JTextField();

    private JButton printButton = new JButton("Cetak"),
            exitButton = new JButton("Keluar");

    public FrameCetakBarangMin() {
        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("amount", amountField);
        FieldUtil fieldUtil = new FieldUtil(fieldMap);

        setPreferredSize(new Dimension(300, 250));
        setTitle(AppConfig.PROGRAM_TITLE[4]);
        // setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        new BorderLayout();
        JDesktopPane desktopPane = new JDesktopPane();
        add(desktopPane, BorderLayout.CENTER);

        /* Mengatur letak objek Label Di container */
        minimLabel.setBounds(15, 20, 100, 25);
        minimLabel.setForeground(AppConfig.MyColor.PURPLE200);

        /* Mengatur letak objek Text Di Container */
        amountField.setBounds(115, 20, 130, 25);
        amountField.setForeground(AppConfig.MyColor.PURPLE200);
        amountField.setBackground(AppConfig.MyColor.GREY900);
        amountField.setBorder(AppConfig.MyBorder.BORDER2);
        amountField.setCaretColor(AppConfig.MyColor.PURPLE200);
        amountField.setText("100");
        amountField.requestFocus();

        /* Mengatur letak objek Button di Container */
        printButton.setBounds(50, 90, 85, 60);
        printButton.setBackground(AppConfig.MyColor.SUCCESS500);
        printButton.setForeground(AppConfig.MyColor.PURPLE100);
        printButton.setFont(AppConfig.MyFont.BUTTON);
        exitButton.setBounds(140, 90, 85, 60);
        exitButton.setToolTipText("Mengakhiri Program");
        exitButton.setBackground(AppConfig.MyColor.GREY900);
        exitButton.setForeground(AppConfig.MyColor.ERROR500);
        exitButton.setBorder(AppConfig.MyBorder.ERROR_BORDER2);
        exitButton.setFont(AppConfig.MyFont.BUTTON);

        /* Objek Button di Non Aktifkan dan di aktifkan */
        printButton.setEnabled(true);
        exitButton.setEnabled(true);

        // Mengatur objek untuk dapat berinteraksi
        printButton.addActionListener(new CetakBarangServiceImpl(this, printButton, fieldUtil));
        exitButton.addActionListener(new ExitUtil(this));

        // Meletakkan seluruh kontrol pada objek panel */
        desktopPane.add(minimLabel);
        desktopPane.add(amountField);
        desktopPane.add(printButton);
        desktopPane.add(exitButton);

        desktopPane.setBackground(AppConfig.MyColor.GREY900);

        /* Menambahkan objek panel (pBrg) ke container frame */
        // getContentPane().add(pBrg);

        /* Menampilkan frame ke layar monitor */
        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    public static void main(String[] args) {
        new FrameCetakBarangMin().setVisible(true);
    }
}
