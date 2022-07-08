package src.view;

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

        for (JLabel label : labelUtil.list) {
            label.setForeground(AppConfig.MyColor.PURPLE200);
            label.setFont(AppConfig.MyFont.LABEL);
        }

        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("id", idField);
        fieldMap.put("name", nameField);
        fieldMap.put("sellingPrice", sellingPriceField);
        fieldMap.put("purchasePrice", purchasePriceField);
        fieldMap.put("amount", amountField);
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
        setTitle(AppConfig.PROGRAM_TITLE[1]);

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

        idLabel.setBounds(defaultX, defaultY, labelWidth, labelHeight);
        idField.setBounds(xFieldLeft, defaultY, fieldWidth, fieldHeight);
        for (int i = 1; i < labelUtil.list.size() - 2; i++) {
            int yLabelBefore = labelUtil.list.get(i - 1).getY() + labelUtil.list.get(i - 1).getHeight();
            labelUtil.list.get(i).setBounds(defaultX, gap10 + yLabelBefore, labelWidth, labelHeight);
            fieldUtil.list.get(i).setBounds(xFieldLeft, gap10 + yLabelBefore, fieldWidth, fieldHeight);
        }

        int xLabelRight = idField.getX() + idField.getWidth() + gap20;
        purchasePriceLabel.setBounds(xLabelRight, defaultY, labelWidth, labelHeight);

        int xFieldRight = purchasePriceLabel.getX() + purchasePriceLabel.getWidth() + gap10;
        purchasePriceField.setBounds(xFieldRight, defaultY, fieldWidth, fieldHeight);

        int yLabelRight = purchasePriceLabel.getY() + purchasePriceLabel.getHeight() + gap10;
        amountLabel.setBounds(xLabelRight, yLabelRight, labelWidth, labelHeight);
        amountField.setBounds(xFieldRight, yLabelRight, fieldWidth, fieldHeight);

        idField.setToolTipText("Isi Kode dengan Angka!");

        // membuat tabel.......................................
        String[] header = { "Kode", "Nama", "Harga Jual", "Harga Beli", "Jumlah" };
        DefaultTableModel tableModel = new DefaultTableModel(null, header);
        JTable tabel = new JTable();
        tabel.setModel(tableModel);
        tabel.setBackground(AppConfig.MyColor.GREY900);
        tabel.setForeground(AppConfig.MyColor.PURPLE200);
        tabel.setEnabled(false);

        JScrollPane scrollPaneTable = new JScrollPane();
        scrollPaneTable.getViewport().add(tabel);
        scrollPaneTable.setBounds(defaultX, sellingPriceLabel.getY() + sellingPriceLabel.getHeight() + gap20, 1010, 320);

        int buttonWidth = 92;
        int buttonHeight = 36;
        int yButton = amountField.getY() + amountField.getHeight() + gap10;

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

        getContentPane().add(desktopPane).setBackground(AppConfig.MyColor.GREY900);

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