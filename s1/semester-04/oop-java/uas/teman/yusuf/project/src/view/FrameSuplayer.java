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

import javax.swing.table.DefaultTableModel;
import javax.swing.JTable;
import javax.swing.JScrollPane;

import src.AppConfig;

import src.service.SuplayerServiceImpl;
import src.service.TableSuplayerService;

import src.util.ButtonUtil;
import src.util.ExitUtil;
import src.util.FieldUtil;
import src.util.LabelUtil;

public class FrameSuplayer extends JFrame {
    // @SuppressWarnings("unused")
    // private JPanel panelBarang = new JPanel();

    private JLabel kodeLabel = new JLabel("Kode Suplayer"),
            namaLabel = new JLabel("Nama Suplayer"),
            alamatLabel = new JLabel("Alamat"),
            kotaLabel = new JLabel("Kota"),
            provinsiLabel = new JLabel("Provinsi"),
            teleponLabel = new JLabel("Telepon"),
            emailLabel = new JLabel("Email"),
            createdLabel = new JLabel(AppConfig.CREATEDBY);

    private JTextField kodeField = new JTextField(),
            namaField = new JTextField(),
            alamatField = new JTextField(),
            kotaField = new JTextField(),
            provinsiField = new JTextField(),
            teleponField = new JTextField(),
            emailField = new JTextField();

    private JButton addButton = new JButton("Tambah"),
            searchButton = new JButton("Cari"),
            updateButton = new JButton("Koreksi"),
            deleteButton = new JButton("Hapus"),
            exitButton = new JButton("Keluar");

    public FrameSuplayer() {
        Map<String, JLabel> labelMap = new LinkedHashMap<>();
        labelMap.put("kode", kodeLabel);
        labelMap.put("nama", namaLabel);
        labelMap.put("alamat", alamatLabel);
        labelMap.put("kota", kotaLabel);
        labelMap.put("provinsi", provinsiLabel);
        labelMap.put("telepon", teleponLabel);
        labelMap.put("email", emailLabel);
        LabelUtil labelUtil = new LabelUtil(labelMap);

        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("kode", kodeField);
        fieldMap.put("nama", namaField);
        fieldMap.put("alamat", alamatField);
        fieldMap.put("kota", kotaField);
        fieldMap.put("provinsi", provinsiField);
        fieldMap.put("telepon", teleponField);
        fieldMap.put("email", emailField);
        FieldUtil fieldUtil = new FieldUtil(fieldMap);

        Map<String, JButton> buttonMap = new LinkedHashMap<>();
        buttonMap.put("add", addButton);
        buttonMap.put("search", searchButton);
        buttonMap.put("update", updateButton);
        buttonMap.put("delete", deleteButton);
        buttonMap.put("exit", exitButton);
        ButtonUtil buttonUtil = new ButtonUtil(buttonMap);

        setPreferredSize(new Dimension(800, 550));
        setTitle("Data Suplayer");

        // setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane desktopPane = new JDesktopPane();

        // X, Y, Width, Height
        int defaultX = 20;
        int defaultY = 20;

        int labelWidth = 100;
        int labelHeight = 25;
        int fieldWidth = 300;
        int fieldHeight = 25;

        int gap = 10 + labelHeight;
        int xField = defaultX + labelWidth + gap;

        int buttonWidth = 85;
        int buttonHeight = 25;
        int gapButton = 10;
        int yButton = 0;

        for (int i = 0; i < labelUtil.list.size(); i++) {
            if (i == 0) {
                labelUtil.list.get(i).setBounds(defaultX, defaultY, labelWidth, labelHeight);
                fieldUtil.list.get(i).setBounds(xField, defaultY, fieldWidth, fieldHeight);
            } else {
                int y = labelUtil.list.get(i - 1).getY() + gap;
                labelUtil.list.get(i).setBounds(defaultX, y, labelWidth, labelHeight);
                fieldUtil.list.get(i).setBounds(xField, y, fieldWidth, fieldHeight);
            }
        }

        kodeField.setToolTipText("Isi Kode dengan Angka!");

        int xCreated = kodeField.getX() + kodeField.getWidth() + 20;
        createdLabel.setBounds(xCreated, defaultY, 300, 25);

        // membuat tabel.......................................
        String[] header = { "Kode", "Nama", "Kota", "Telepon", "Email" };
        DefaultTableModel tableModel = new DefaultTableModel(null, header);
        JTable tabel = new JTable();
        tabel.setModel(tableModel);
        tabel.setBackground(Color.ORANGE);
        tabel.setEnabled(false);

        JScrollPane scrollPaneTable = new JScrollPane();
        scrollPaneTable.getViewport().add(tabel);
        scrollPaneTable.setBounds(defaultX, emailLabel.getY() + gap, 740, 170);

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
        TableSuplayerService tableSuplayerService = new TableSuplayerService(this, tableModel);
        addButton.addActionListener(new SuplayerServiceImpl(this, addButton, fieldUtil, buttonUtil, tableSuplayerService));
        searchButton.addActionListener(new SuplayerServiceImpl(this, searchButton, fieldUtil, buttonUtil, tableSuplayerService));
        updateButton.addActionListener(new SuplayerServiceImpl(this, updateButton, fieldUtil, buttonUtil, tableSuplayerService));
        deleteButton.addActionListener(new SuplayerServiceImpl(this, deleteButton, fieldUtil, buttonUtil, tableSuplayerService));
        exitButton.addActionListener(new ExitUtil(this));

        kodeField.addActionListener(new SuplayerServiceImpl(this, null, fieldUtil, buttonUtil, tableSuplayerService));
        namaField.addActionListener(new SuplayerServiceImpl(this, null, fieldUtil, buttonUtil, tableSuplayerService));
        alamatField.addActionListener(new SuplayerServiceImpl(this, null, fieldUtil, buttonUtil, tableSuplayerService));
        kotaField.addActionListener(new SuplayerServiceImpl(this, null, fieldUtil, buttonUtil, tableSuplayerService));
        provinsiField.addActionListener(new SuplayerServiceImpl(this, null, fieldUtil, buttonUtil, tableSuplayerService));
        teleponField.addActionListener(new SuplayerServiceImpl(this, null, fieldUtil, buttonUtil, tableSuplayerService));
        emailField.addActionListener(new SuplayerServiceImpl(this, null, fieldUtil, buttonUtil, tableSuplayerService));

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
        desktopPane.add(createdLabel);

        getContentPane().add(desktopPane).setBackground(Color.PINK);

        pack();
        setLocationRelativeTo(null);
        tableSuplayerService.updateDataTable();
        fieldUtil.setBlank();
        fieldUtil.setEnabled(false);
    }

    public static void main(String[] args) {
        new FrameSuplayer().setVisible(true);
    }
}
