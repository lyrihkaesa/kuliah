package src.view;

import java.awt.Color;
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

        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("nip", nipField);
        fieldMap.put("name", nameField);
        fieldMap.put("department", departmentField);
        fieldMap.put("gender", genderField);
        fieldMap.put("password", passwordField);
        FieldUtil fieldUtil = new FieldUtil(fieldMap);

        Map<String, JButton> buttonMap = new LinkedHashMap<>();
        buttonMap.put("add", addButton);
        buttonMap.put("search", searchButton);
        buttonMap.put("update", updateButton);
        buttonMap.put("delete", deleteButton);
        buttonMap.put("exit", exitButton);
        ButtonUtil buttonUtil = new ButtonUtil(buttonMap);

        setPreferredSize(new Dimension(670, 510));
        setTitle(AppConfig.PROGRAM_TITLE[0]);

        // setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane desktopPane = new JDesktopPane();

        // X, Y, Width, Height
        int defaultX = 20;
        int defaultY = 20;

        int labelWidth = 100;
        int labelHeight = 25;

        int gap = 10 + labelHeight;
        int xField = defaultX + labelWidth + gap;

        int buttonWidth = 85;
        int buttonHeight = 25;
        int gapButton = 10;
        int yButton = 0;

        for (int i = 0; i < labelUtil.list.size(); i++) {
            if (i == 0) {
                labelUtil.list.get(i).setBounds(defaultX, defaultY, labelWidth, labelHeight);
                fieldUtil.list.get(i).setBounds(xField, defaultY, labelWidth, labelHeight);
            } else {
                int y = labelUtil.list.get(i - 1).getY() + gap;
                labelUtil.list.get(i).setBounds(defaultX, y, labelWidth, labelHeight);
                fieldUtil.list.get(i).setBounds(xField, y, i == 1 ? labelWidth + 100 : labelWidth, labelHeight);
            }
        }

        nipField.setToolTipText("Isi Nip dengan Angka!");

        // membuat tabel.......................................
        String[] header = { "NIP", "Nama", "Bagian", "Jenis Kelamin", "Password" };
        DefaultTableModel tableModel = new DefaultTableModel(null, header);
        JTable tabel = new JTable();
        tabel.setModel(tableModel);
        tabel.setBackground(Color.ORANGE);
        tabel.setEnabled(false);

        JScrollPane scrollPaneTable = new JScrollPane();
        scrollPaneTable.getViewport().add(tabel);
        scrollPaneTable.setBounds(defaultX, passwordLabel.getY() + gap, 500, 170);

        yButton = scrollPaneTable.getY() + gapButton + scrollPaneTable.getHeight();

        for (int i = 0; i < buttonUtil.list.size(); i++) {
            if (i == 0) {
                buttonUtil.list.get(i).setBounds(defaultX, yButton, buttonWidth, buttonHeight);
            } else {
                int xButton = defaultX + buttonUtil.list.get(i - 1).getX() + buttonWidth + gapButton;
                buttonUtil.list.get(i).setBounds(xButton, yButton, buttonWidth, buttonHeight);
            }
        }

        exitButton.setToolTipText("Mengakhiri Program");

        addButton.setBackground(Color.green);
        addButton.setForeground(Color.getHSBColor(250, 0, 255));

        /* Objek Button di Non Aktifkan dan di aktifkan */
        addButton.setEnabled(true);
        exitButton.setEnabled(true);

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

        getContentPane().add(desktopPane).setBackground(Color.PINK);

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