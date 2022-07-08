package src.view;

import java.awt.Dimension;
import java.util.LinkedHashMap;
import java.util.Map;

import javax.swing.JButton;
import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

import src.AppConfig;
import src.service.LoginServiceImpl;
import src.util.ButtonUtil;
import src.util.ExitUtil;
import src.util.FieldUtil;
import src.util.LabelUtil;

public class FrameLogin extends JFrame {
    private JLabel titleLabel = new JLabel("Masuk"),
            nipLabel = new JLabel("NIP"),
            passwordLabel = new JLabel("Password");

    private JTextField nipField = new JTextField(),
            passwordField = new JPasswordField();

    private JButton loginButton = new JButton("Masuk"),
            exitButton = new JButton("Batal");

    public FrameLogin() {
        Map<String, JLabel> labelMap = new LinkedHashMap<>();
        labelMap.put("title", titleLabel);
        labelMap.put("nip", nipLabel);
        labelMap.put("password", passwordLabel);
        LabelUtil labelUtil = new LabelUtil(labelMap);

        for (JLabel label : labelUtil.list) {
            label.setForeground(AppConfig.MyColor.PURPLE200);
        }

        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("nip", nipField);
        fieldMap.put("password", passwordField);
        FieldUtil fieldUtil = new FieldUtil(fieldMap);

        for (JTextField textField : fieldUtil.list) {
            textField.setBorder(AppConfig.MyBorder.BORDER2);
            textField.setBackground(AppConfig.MyColor.GREY900);
            textField.setForeground(AppConfig.MyColor.PURPLE200);
            textField.setFont(AppConfig.MyFont.TEXTFIELD);
            textField.setCaretColor(AppConfig.MyColor.PURPLE200);
        }

        Map<String, JButton> buttonMap = new LinkedHashMap<>();
        buttonMap.put("login", loginButton);
        buttonMap.put("exit", exitButton);
        ButtonUtil buttonUtil = new ButtonUtil(buttonMap);

        setPreferredSize(new Dimension(800, 450));
        setTitle("Login");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane desktopPane = new JDesktopPane();

        titleLabel.setBounds(327, 20, 145, 66);
        titleLabel.setFont(AppConfig.MyFont.TITLE);

        int labelHeight = 25;
        int labelWidth = 300;
        int fieldHeight = 25;
        int fieldWidth = 300;
        int xDefault = 250;
        int gap10 = 10;
        int gap20 = 20;

        nipLabel.setBounds(xDefault, titleLabel.getHeight() + titleLabel.getY() + gap20, labelWidth, labelHeight);
        nipLabel.setFont(AppConfig.MyFont.LABEL);
        nipField.setBounds(xDefault, nipLabel.getHeight() + nipLabel.getY() + gap10, fieldWidth, fieldHeight);
        nipField.requestFocus();

        passwordLabel.setBounds(xDefault, nipField.getHeight() + nipField.getY() + gap20, labelWidth, labelHeight);
        passwordLabel.setFont(AppConfig.MyFont.LABEL);
        passwordField.setBounds(xDefault, passwordLabel.getHeight() + passwordLabel.getY() + gap10, fieldWidth, fieldHeight);

        nipField.setToolTipText("Isi Nip dengan Angka !");

        int buttonHeight = 36;
        int buttonWidth = 140;
        int buttonY = passwordField.getHeight() + passwordField.getY() + gap20;
        /* Mengatur letak objek Button di Container */
        exitButton.setBounds(xDefault, buttonY, buttonWidth, buttonHeight);
        exitButton.setBackground(AppConfig.MyColor.PURPLE200);
        exitButton.setFont(AppConfig.MyFont.BUTTON);
        exitButton.setToolTipText("Keluar dari Program");

        loginButton.setBounds(exitButton.getX() + exitButton.getWidth() + gap20, buttonY, buttonWidth, buttonHeight);
        loginButton.setBackground(AppConfig.MyColor.GREEN500);
        loginButton.setForeground(AppConfig.MyColor.PURPLE100);
        exitButton.setFont(AppConfig.MyFont.BUTTON);

        // Mengatur objek untuk dapat berinteraksi
        nipField.addFocusListener(new LoginServiceImpl(this, fieldUtil, buttonUtil));
        loginButton.addActionListener(new LoginServiceImpl(this, fieldUtil, buttonUtil));
        exitButton.addActionListener(new ExitUtil(this));

        // Meletakkan seluruh kontrol pada objek panel */
        desktopPane.add(titleLabel);
        desktopPane.add(nipLabel);
        desktopPane.add(nipField);
        desktopPane.add(passwordLabel);
        desktopPane.add(passwordField);
        desktopPane.add(loginButton);
        desktopPane.add(exitButton);

        /* Menambahkan objek panel (pPgr) ke container frame */
        getContentPane().add(desktopPane).setBackground(AppConfig.MyColor.GREY900);

        /* Menampilkan frame ke layar monitor */
        pack();
        setLocationRelativeTo(null);

    }

    public static void main(String[] args) {
        new FrameLogin().setVisible(true);
    }

}
