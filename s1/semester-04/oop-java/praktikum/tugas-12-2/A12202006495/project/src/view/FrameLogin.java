package src.view;

import java.awt.Dimension;
import java.util.LinkedHashMap;
import java.util.Map;
import java.awt.Color;

import javax.swing.JButton;
import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import src.service.LoginServiceImpl;
import src.util.ButtonUtil;
import src.util.ExitUtil;
import src.util.FieldUtil;

public class FrameLogin extends JFrame {
    private JLabel nipLabel = new JLabel("NIP"),
            nameLabel = new JLabel("Nama"),
            passwordLabel = new JLabel("Password");

    private JTextField nipField = new JTextField(),
            nameField = new JTextField(),
            passwordField = new JPasswordField();

    private JButton loginButton = new JButton("Login"),
            exitButton = new JButton("Keluar");

    public FrameLogin() {

        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("nip", nipField);
        fieldMap.put("name", nameField);
        fieldMap.put("password", passwordField);
        FieldUtil fieldUtil = new FieldUtil(fieldMap);

        Map<String, JButton> buttonMap = new LinkedHashMap<>();
        buttonMap.put("login", loginButton);
        buttonMap.put("exit", exitButton);
        ButtonUtil buttonUtil = new ButtonUtil(buttonMap);

        setPreferredSize(new Dimension(350, 230));
        setTitle("LOGIN");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane desktopPane = new JDesktopPane();

        /* Mengatur letak objek Label Di container */
        nipLabel.setBounds(15, 20, 100, 25);
        nameLabel.setBounds(15, 55, 100, 25);
        passwordLabel.setBounds(15, 90, 100, 25);

        /* Mengatur letak objek Text Di Container */
        nipField.setBounds(110, 20, 100, 25);
        nameField.setBounds(110, 55, 205, 25);
        passwordField.setBounds(110, 90, 92, 25);

        nipField.setToolTipText("Isi Nip dengan Angka !");

        /* Mengatur letak objek Button di Container */
        loginButton.setBounds(130, 140, 85, 25);
        exitButton.setBounds(230, 140, 85, 25);
        exitButton.setToolTipText("Mengakhiri Program");

        // enable/disable
        nameField.setEnabled(false);

        // Mengatur objek untuk dapat berinteraksi
        nipField.addFocusListener(new LoginServiceImpl(this, fieldUtil, buttonUtil));
        loginButton.addActionListener(new LoginServiceImpl(this, fieldUtil, buttonUtil));
        exitButton.addActionListener(new ExitUtil(this));

        // Meletakkan seluruh kontrol pada objek panel */
        desktopPane.add(nipLabel);
        desktopPane.add(nipField);
        desktopPane.add(nameLabel);
        desktopPane.add(nameField);
        desktopPane.add(passwordLabel);
        desktopPane.add(passwordField);
        desktopPane.add(loginButton);
        desktopPane.add(exitButton);

        /* Menambahkan objek panel (pPgr) ke container frame */
        getContentPane().add(desktopPane).setBackground(Color.getHSBColor(180, 100, 200));

        /* Menampilkan frame ke layar monitor */
        pack();
        setLocationRelativeTo(null);

    }

    public static void main(String[] args) {
        new FrameLogin().setVisible(true);
    }

}
