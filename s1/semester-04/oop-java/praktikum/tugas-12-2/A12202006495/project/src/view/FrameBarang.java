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

import src.service.BarangServiceImpl;
import src.service.TableBarangService;

import src.util.ButtonUtil;
import src.util.ExitUtil;
import src.util.FieldUtil;
import src.util.LabelUtil;

public class FrameBarang extends JFrame {
    // @SuppressWarnings("unused")
    // private JPanel panelBarang = new JPanel();

    private JLabel idLabel = new JLabel("Kode Barang"),
            nameLabel = new JLabel("Nama Barang"),
            sellingPriceLabel = new JLabel("Harga Jual"),
            purchasePriceLabel = new JLabel("Harga Beli"),
            amountLabel = new JLabel("Jumlah");

    private JTextField idField = new JTextField(),
            nameField = new JTextField(),
            sellingPriceField = new JTextField(),
            purchasePriceField = new JTextField(),
            amountField = new JTextField();

    private JButton addButton = new JButton("Tambah"),
            searchButton = new JButton("Cari"),
            updateButton = new JButton("Koreksi"),
            deleteButton = new JButton("Hapus"),
            exitButton = new JButton("Keluar");

    public FrameBarang() {
        Map<String, JLabel> labelMap = new LinkedHashMap<>();
        labelMap.put("id", idLabel);
        labelMap.put("name", nameLabel);
        labelMap.put("sellingPrice", sellingPriceLabel);
        labelMap.put("purchasePrice", purchasePriceLabel);
        labelMap.put("amount", amountLabel);
        LabelUtil labelUtil = new LabelUtil(labelMap);

        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("id", idField);
        fieldMap.put("name", nameField);
        fieldMap.put("sellingPrice", sellingPriceField);
        fieldMap.put("purchasePrice", purchasePriceField);
        fieldMap.put("amount", amountField);
        FieldUtil fieldUtil = new FieldUtil(fieldMap);

        Map<String, JButton> buttonMap = new LinkedHashMap<>();
        buttonMap.put("add", addButton);
        buttonMap.put("search", searchButton);
        buttonMap.put("update", updateButton);
        buttonMap.put("delete", deleteButton);
        buttonMap.put("exit", exitButton);
        ButtonUtil buttonUtil = new ButtonUtil(buttonMap);

        setPreferredSize(new Dimension(670, 510));
        setTitle(AppConfig.PROGRAM_TITLE[1]);

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

        idField.setToolTipText("Isi Kode dengan Angka!");

        // membuat tabel.......................................
        String[] header = { "Kode", "Nama", "Harga Jual", "Harga Beli", "Jumlah" };
        DefaultTableModel tableModel = new DefaultTableModel(null, header);
        JTable tabel = new JTable();
        tabel.setModel(tableModel);
        tabel.setBackground(Color.ORANGE);
        tabel.setEnabled(false);

        JScrollPane scrollPaneTable = new JScrollPane();
        scrollPaneTable.getViewport().add(tabel);
        scrollPaneTable.setBounds(defaultX, amountLabel.getY() + gap, 500, 170);

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
        TableBarangService tableBarangService = new TableBarangService(this, tableModel);
        addButton.addActionListener(new BarangServiceImpl(this, addButton, fieldUtil, buttonUtil, tableBarangService));
        searchButton.addActionListener(new BarangServiceImpl(this, searchButton, fieldUtil, buttonUtil, tableBarangService));
        updateButton.addActionListener(new BarangServiceImpl(this, updateButton, fieldUtil, buttonUtil, tableBarangService));
        deleteButton.addActionListener(new BarangServiceImpl(this, deleteButton, fieldUtil, buttonUtil, tableBarangService));
        exitButton.addActionListener(new ExitUtil(this));

        idField.addActionListener(new BarangServiceImpl(this, null, fieldUtil, buttonUtil, tableBarangService));
        nameField.addActionListener(new BarangServiceImpl(this, null, fieldUtil, buttonUtil, tableBarangService));
        sellingPriceField.addActionListener(new BarangServiceImpl(this, null, fieldUtil, buttonUtil, tableBarangService));
        purchasePriceField.addActionListener(new BarangServiceImpl(this, null, fieldUtil, buttonUtil, tableBarangService));
        amountField.addActionListener(new BarangServiceImpl(this, null, fieldUtil, buttonUtil, tableBarangService));

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
        tableBarangService.updateDataTable();
        fieldUtil.setBlank();
        fieldUtil.setEnabled(false);
    }

    public static void main(String[] args) {
        new FrameBarang().setVisible(true);
    }
}