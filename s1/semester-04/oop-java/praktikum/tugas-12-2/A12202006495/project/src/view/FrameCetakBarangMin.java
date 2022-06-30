package src.view;

import java.awt.Dimension;
import java.util.LinkedHashMap;
import java.util.Map;
import java.awt.BorderLayout;
import java.awt.Color;

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

        /* Mengatur letak objek Text Di Container */
        amountField.setBounds(115, 20, 130, 25);

        /* Mengatur letak objek Button di Container */
        printButton.setBounds(50, 90, 85, 60);
        printButton.setBackground(Color.BLUE);
        printButton.setForeground(Color.getHSBColor(250, 0, 255));
        exitButton.setBounds(140, 90, 85, 60);
        exitButton.setToolTipText("Mengakhiri Program");

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
