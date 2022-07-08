package src.view;

import java.awt.Dimension;

import java.util.LinkedHashMap;
import java.util.Map;

import javax.swing.JFrame;

import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;

import javax.swing.JDesktopPane;

import javax.swing.JTable;
import javax.swing.JScrollPane;

import javax.swing.table.DefaultTableModel;

import src.AppConfig;

import src.service.PegawaiServiceImpl;
import src.service.TablePegawaiService;

import src.util.ButtonUtil;
import src.util.ExitUtil;
import src.util.FieldUtil;
import src.util.LabelUtil;

public class FramePegawai extends JFrame {
    // @SuppressWarnings("unused")
    // private JPanel panelPegawai = new JPanel();

    private JLabel nipLabel = new JLabel("NIP Pegawai"),
            nameLabel = new JLabel("Nama"),
            departmentLabel = new JLabel("Bagian"),
            genderLabel = new JLabel("Jenis Kelamin"),
            passwordLabel = new JLabel("Password");

    private JTextField nipField = new JTextField(),
            nameField = new JTextField(),
            departmentField = new JTextField(),
            genderField = new JTextField(),
            passwordField = new JTextField();

    private JButton addButton = new JButton("Tambah"),
            searchButton = new JButton("Cari"),
            updateButton = new JButton("Koreksi"),
            deleteButton = new JButton("Hapus"),
            exitButton = new JButton("Keluar");

    public FramePegawai() {
        Map<String, JLabel> labelMap = new LinkedHashMap<>();
        labelMap.put("nip", nipLabel);
        labelMap.put("name", nameLabel);
        labelMap.put("department", departmentLabel);
        labelMap.put("gender", genderLabel);
        labelMap.put("password", passwordLabel);
        LabelUtil labelUtil = new LabelUtil(labelMap);

        for (JLabel label : labelUtil.list) {
            label.setForeground(AppConfig.MyColor.PURPLE200);
            label.setFont(AppConfig.MyFont.LABEL);
        }

        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("nip", nipField);
        fieldMap.put("name", nameField);
        fieldMap.put("department", departmentField);
        fieldMap.put("gender", genderField);
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
        buttonMap.put("add", addButton);
        buttonMap.put("search", searchButton);
        buttonMap.put("update", updateButton);
        buttonMap.put("delete", deleteButton);
        buttonMap.put("exit", exitButton);
        ButtonUtil buttonUtil = new ButtonUtil(buttonMap);

        for (JButton button : buttonUtil.list) {
            button.setForeground(AppConfig.MyColor.PURPLE100);
            button.setFont(AppConfig.MyFont.BUTTON);
        }

        setPreferredSize(new Dimension(1070, 540));
        setTitle(AppConfig.PROGRAM_TITLE[0]);

        // setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane desktopPane = new JDesktopPane();

        // X, Y, Width, Height
        int defaultX = 20;
        int defaultY = 20;

        int labelWidth = 135;
        int labelHeight = 36;
        int fieldWidth = 350;
        int fieldHeight = 36;

        int gap20 = 20;
        int gap10 = 10;

        int xFieldLeft = defaultX + labelWidth + gap10;

        nipLabel.setBounds(defaultX, defaultY, labelWidth, labelHeight);
        nipField.setBounds(xFieldLeft, defaultY, fieldWidth, fieldHeight);
        for (int i = 1; i < labelUtil.list.size() - 2; i++) {
            int yLabelBefore = labelUtil.list.get(i - 1).getY() + labelUtil.list.get(i - 1).getHeight();
            labelUtil.list.get(i).setBounds(defaultX, gap10 + yLabelBefore, labelWidth, labelHeight);
            fieldUtil.list.get(i).setBounds(xFieldLeft, gap10 + yLabelBefore, fieldWidth, fieldHeight);
        }

        int xLabelRight = nipField.getX() + nipField.getWidth() + gap20;
        genderLabel.setBounds(xLabelRight, defaultY, labelWidth, labelHeight);

        int xFieldRight = genderLabel.getX() + genderLabel.getWidth() + gap10;
        genderField.setBounds(xFieldRight, defaultY, fieldWidth, fieldHeight);

        int yLabelRight = genderLabel.getY() + genderLabel.getHeight() + gap10;
        passwordLabel.setBounds(xLabelRight, yLabelRight, labelWidth, labelHeight);
        passwordField.setBounds(xFieldRight, yLabelRight, fieldWidth, fieldHeight);

        nipField.setToolTipText("Isi Nip dengan Angka!");

        // membuat tabel.......................................
        String[] header = { "NIP", "Nama", "Bagian", "Jenis Kelamin", "Password" };
        DefaultTableModel tableModel = new DefaultTableModel(null, header);
        JTable tabel = new JTable();
        tabel.setModel(tableModel);
        tabel.setBackground(AppConfig.MyColor.GREY900);
        tabel.setForeground(AppConfig.MyColor.PURPLE200);
        tabel.setEnabled(false);

        JScrollPane scrollPaneTable = new JScrollPane();
        scrollPaneTable.getViewport().add(tabel);
        scrollPaneTable.setBounds(defaultX, departmentLabel.getY() + departmentLabel.getHeight() + gap20, 1010, 320);

        int buttonWidth = 92;
        int buttonHeight = 36;
        int yButton = passwordField.getY() + passwordField.getHeight() + gap10;

        addButton.setBounds(xLabelRight, yButton, buttonWidth, buttonHeight);
        for (int i = 1; i < buttonUtil.list.size(); i++) {
            int xButton = buttonUtil.list.get(i - 1).getX() + buttonWidth + gap10;
            buttonUtil.list.get(i).setBounds(xButton, yButton, buttonWidth, buttonHeight);

        }

        exitButton.setToolTipText("Mengakhiri Program");

        addButton.setBackground(AppConfig.MyColor.SUCCESS500);
        searchButton.setBackground(AppConfig.MyColor.BLUE500);
        updateButton.setBackground(AppConfig.MyColor.WARNING500);
        deleteButton.setBackground(AppConfig.MyColor.ERROR500);
        exitButton.setBorder(AppConfig.MyBorder.ERROR_BORDER2);
        exitButton.setForeground(AppConfig.MyColor.ERROR500);
        exitButton.setBackground(AppConfig.MyColor.GREY900);

        /* Objek Button di Non Aktifkan dan di aktifkan */
        updateButton.setEnabled(false);
        deleteButton.setEnabled(false);

        // Mengatur objek untuk dapat berinteraksi
        TablePegawaiService tablePegawaiService = new TablePegawaiService(this, tableModel);
        addButton.addActionListener(new PegawaiServiceImpl(this, addButton, fieldUtil, buttonUtil, tablePegawaiService));
        searchButton.addActionListener(new PegawaiServiceImpl(this, searchButton, fieldUtil, buttonUtil, tablePegawaiService));
        updateButton.addActionListener(new PegawaiServiceImpl(this, updateButton, fieldUtil, buttonUtil, tablePegawaiService));
        deleteButton.addActionListener(new PegawaiServiceImpl(this, deleteButton, fieldUtil, buttonUtil, tablePegawaiService));
        exitButton.addActionListener(new ExitUtil(this));

        nipField.addActionListener(new PegawaiServiceImpl(this, null, fieldUtil, buttonUtil, tablePegawaiService));
        nameField.addActionListener(new PegawaiServiceImpl(this, null, fieldUtil, buttonUtil, tablePegawaiService));
        departmentField.addActionListener(new PegawaiServiceImpl(this, null, fieldUtil, buttonUtil, tablePegawaiService));
        genderField.addActionListener(new PegawaiServiceImpl(this, null, fieldUtil, buttonUtil, tablePegawaiService));
        passwordField.addActionListener(new PegawaiServiceImpl(this, null, fieldUtil, buttonUtil, tablePegawaiService));

        // Meletakkan seluruh kontrol pada objek panel */
        for (JLabel label : labelMap.values()) {
            desktopPane.add(label);
        }

        for (JTextField textField : fieldMap.values()) {
            desktopPane.add(textField);
        }

        for (JButton button : buttonMap.values()) {
            desktopPane.add(button);
        }

        desktopPane.add(scrollPaneTable);

        getContentPane().add(desktopPane).setBackground(AppConfig.MyColor.GREY900);

        pack();
        setLocationRelativeTo(null);
        tablePegawaiService.updateDataTable();
        fieldUtil.setBlank();
        fieldUtil.setEnabled(false);
    }

    public static void main(String[] args) {
        new FramePegawai().setVisible(true);
    }
}