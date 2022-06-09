package src.view;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Color;
import java.util.LinkedHashMap;
import java.util.Map;

import javax.swing.JButton;
import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

import src.ProgramConfig;
import src.service.TableTransactionService;
import src.service.TransactionServiceImpl;
import src.util.ButtonUtil;
import src.util.ExitUtil;
import src.util.FieldUtil;
// import src.util.LabelUtil;

public class FrameJual extends JFrame {
    private JLabel transactionIdLabel = new JLabel("ID Transaksi"),
            idItemLabel = new JLabel("ID Barang"),
            nameItemLabel = new JLabel("Nama Barang"),
            priceItemLabel = new JLabel("Harga Barang"),
            amountItemLabel = new JLabel("Jumlah Barang"),
            totalLabel = new JLabel("Total"),
            payLabel = new JLabel("Bayar"),
            restLabel = new JLabel("Kembalian"),
            brandLabel = new JLabel(ProgramConfig.FULLNAME_AUTHOR),
            addressLabel = new JLabel(ProgramConfig.NIM);

    private JTextField transactionIdField = new JTextField(),
            idItemField = new JTextField(),
            nameItemField = new JTextField(),
            priceItemField = new JTextField(),
            amountItemField = new JTextField(),
            totalField = new JTextField(),
            payField = new JTextField(),
            restField = new JTextField();

    private JButton sellingButton = new JButton("Jual"),
            deleteButton = new JButton("Hapus"),
            searchButton = new JButton("Cari"),
            exitButton = new JButton("Keluar");

    public FrameJual() {
        Map<String, JLabel> labelMap = new LinkedHashMap<>();
        labelMap.put("transactionId", transactionIdLabel);
        labelMap.put("idItem", idItemLabel);
        labelMap.put("nameItem", nameItemLabel);
        labelMap.put("priceItem", priceItemLabel);
        labelMap.put("amountItem", amountItemLabel);
        labelMap.put("total", totalLabel);
        labelMap.put("pay", payLabel);
        labelMap.put("rest", restLabel);
        labelMap.put("brand", brandLabel);
        labelMap.put("address", addressLabel);
        // LabelUtil labelUtil = new LabelUtil(labelMap);

        Map<String, JTextField> fieldMap = new LinkedHashMap<>();
        fieldMap.put("transactionId", transactionIdField);
        fieldMap.put("idItem", idItemField);
        fieldMap.put("nameItem", nameItemField);
        fieldMap.put("priceItem", priceItemField);
        fieldMap.put("amountItem", amountItemField);
        fieldMap.put("total", totalField);
        fieldMap.put("pay", payField);
        fieldMap.put("rest", restField);
        FieldUtil fieldUtil = new FieldUtil(fieldMap);

        Map<String, JButton> buttonMap = new LinkedHashMap<>();
        buttonMap.put("selling", sellingButton);
        buttonMap.put("delete", deleteButton);
        buttonMap.put("search", searchButton);
        buttonMap.put("exit", exitButton);
        ButtonUtil buttonUtil = new ButtonUtil(buttonMap);

        setPreferredSize(new Dimension(580, 600));
        setTitle(ProgramConfig.PROGRAM_TITLE[3]);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        new BorderLayout();
        JDesktopPane desktopPane = new JDesktopPane();
        add(desktopPane, BorderLayout.CENTER);

        // mengatur letak objek label pada container
        brandLabel.setBounds(15, 28, 450, 40);
        brandLabel.setFont(new Font("Dialog", Font.BOLD, 36));
        brandLabel.setForeground(Color.BLUE);

        addressLabel.setBounds(15, 58, 450, 40);
        addressLabel.setFont(new Font("Dialog", Font.BOLD, 18));

        transactionIdLabel.setBounds(15, 100, 120, 20);
        idItemLabel.setBounds(15, 400, 60, 20);
        priceItemLabel.setBounds(15, 425, 60, 20);
        amountItemLabel.setBounds(15, 450, 60, 20);
        payLabel.setBounds(350, 425, 60, 20);
        restLabel.setBounds(350, 450, 60, 20);

        // mengatur letak objek textField pada container
        transactionIdField.setBounds(15, 125, 100, 20);
        idItemField.setBounds(75, 400, 100, 20);
        nameItemField.setBounds(180, 400, 205, 20);
        priceItemField.setBounds(75, 425, 92, 20);
        amountItemField.setBounds(75, 450, 100, 20);
        payField.setBounds(400, 425, 150, 20);
        restField.setBounds(400, 450, 150, 20);
        totalField.setBounds(400, 400, 150, 20);

        // mengatur aligment text
        priceItemField.setHorizontalAlignment(JTextField.RIGHT);
        amountItemField.setHorizontalAlignment(JTextField.RIGHT);
        payField.setHorizontalAlignment(JTextField.RIGHT);
        restField.setHorizontalAlignment(JTextField.RIGHT);
        totalField.setHorizontalAlignment(JTextField.RIGHT);

        // mengatur letak objek button pada container
        sellingButton.setBounds(165, 500, 85, 25);
        deleteButton.setBounds(265, 500, 85, 25);
        searchButton.setBounds(365, 500, 85, 25);
        exitButton.setBounds(465, 500, 85, 25);

        // mengatur button enable
        fieldUtil.setEnabled(0, 1, 0, 0, 1, 0, 1, 0);
        deleteButton.setEnabled(false);

        // mengatur letak objek table pada container
        String[] header = { "Id Barang", "Nama", "Harga", "Jumlah", "Total" };

        DefaultTableModel tableModel = new DefaultTableModel(null, header);
        JTable table = new JTable();
        table.setModel(tableModel);
        table.setEnabled(true);

        JScrollPane scrollPaneTable = new JScrollPane();
        scrollPaneTable.getViewport().add(table);
        scrollPaneTable.setBounds(15, 160, 540, 220);

        TableTransactionService tableTransactionService = new TableTransactionService(this, tableModel);

        // mengatur listerner
        idItemField.addFocusListener(new TransactionServiceImpl(this, null, fieldUtil, buttonUtil, tableTransactionService));
        amountItemField.addFocusListener(new TransactionServiceImpl(this, null, fieldUtil, buttonUtil, tableTransactionService));
        payField.addFocusListener(new TransactionServiceImpl(this, null, fieldUtil, buttonUtil, tableTransactionService));

        sellingButton.addActionListener(new TransactionServiceImpl(this, sellingButton, fieldUtil, buttonUtil, tableTransactionService));
        deleteButton.addActionListener(new TransactionServiceImpl(this, deleteButton, fieldUtil, buttonUtil, tableTransactionService));
        searchButton.addActionListener(new TransactionServiceImpl(this, searchButton, fieldUtil, buttonUtil, tableTransactionService));
        exitButton.addActionListener(new ExitUtil(this));

        // menambahkan seluruh objek kedalam desktopPane
        desktopPane.add(scrollPaneTable);

        for (JLabel label : labelMap.values()) {
            desktopPane.add(label);
        }
        for (JTextField textField : fieldMap.values()) {
            desktopPane.add(textField);
        }
        for (JButton button : buttonMap.values()) {
            desktopPane.add(button);
        }

        // menambahkan objek desktopPane ke container frame
        getContentPane().add(desktopPane);

        // menampilkan frame ke layar monitor
        pack();
        setLocationRelativeTo(null);

        TransactionServiceImpl transactionServiceImpl = new TransactionServiceImpl(this, null, fieldUtil, buttonUtil, tableTransactionService);
        transactionServiceImpl.setTransactionId();
    }

    public static void main(String[] args) {
        new FrameJual().setVisible(true);
    }

}
