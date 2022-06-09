package src.service;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

import src.entity.Barang;
import src.entity.Transaction;
import src.repository.BarangRepositoryImpl;
import src.repository.TransactionRepositoryImpl;
import src.util.ButtonUtil;
import src.util.FieldUtil;

public class TransactionServiceImpl implements ActionListener, FocusListener {
    private JFrame mainFrame;
    @SuppressWarnings("unused")
    private JButton targetButton;
    private FieldUtil fieldUtil;
    private ButtonUtil buttonUtil;
    private TableTransactionService tableTransactionService;

    public TransactionServiceImpl(JFrame mainFrame, JButton targetButton, FieldUtil fieldUtil, ButtonUtil buttonUtil,
            TableTransactionService tableTransactionService) {
        this.mainFrame = mainFrame;
        this.targetButton = targetButton;
        this.fieldUtil = fieldUtil;
        this.buttonUtil = buttonUtil;
        this.tableTransactionService = tableTransactionService;
    }

    @Override
    public void focusGained(FocusEvent focusEvent) {
        Object object = focusEvent.getSource();
        if (object == fieldUtil.map.get("pay")) {
            if (!fieldUtil.map.get("pay").getText().isBlank()) {
                pay();
                buttonUtil.map.get("selling").requestFocus();
            } else {
                fieldUtil.map.get("pay").requestFocus();
            }
        }
    }

    @Override
    public void focusLost(FocusEvent focusEvent) {
        Object object = focusEvent.getSource();
        var idItemField = fieldUtil.map.get("idItem");
        var amountItemField = fieldUtil.map.get("amountItem");
        var totalField = fieldUtil.map.get("total");
        var payField = fieldUtil.map.get("pay");
        if (object == idItemField) {
            if (!idItemField.getText().isBlank()) {
                searchItemById(idItemField.getText());
                amountItemField.requestFocus();

            }
        }
        if (object == amountItemField) {
            if (!amountItemField.getText().isBlank()) {
                int amount = amountCheck(idItemField.getText());
                if (amount == 1) {
                    amountItemField.requestFocus();
                } else {
                    Transaction transaction = getTransaction(fieldUtil);
                    tableTransactionService.updateDataTable(transaction);
                    totalField.setText(tableTransactionService.getTotal().toString());
                    setFieldBlank();
                    buttonUtil.map.get("selling").setEnabled(true);
                    buttonUtil.map.get("delete").setEnabled(true);
                }
            }
            idItemField.requestFocus();
        }

        if (object == payField) {
            if (!payField.getText().isBlank()) {
                pay();
                buttonUtil.map.get("selling").requestFocus();
            }
        }

    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        Object object = actionEvent.getSource();
        var idItemField = fieldUtil.map.get("idItem");
        if (object == buttonUtil.map.get("selling")) {
            addTransaction();
            tableTransactionService.clear();
            fieldUtil.map.get("total").setText("");
            setFieldBlank();
            buttonUtil.map.get("delete").setEnabled(false);
            setTransactionId();
            idItemField.requestFocus();
        }

        if (object == buttonUtil.map.get("delete")) {
            tableTransactionService.clear();
            fieldUtil.map.get("total").setText("");
            setFieldBlank();
            buttonUtil.map.get("selling").setEnabled(false);
            buttonUtil.map.get("delete").setEnabled(false);
            idItemField.requestFocus();
        }

        if (object == buttonUtil.map.get("search")) {
            if (!idItemField.getText().isBlank()) {
                searchItemById(idItemField.getText());
            } else {
                idItemField.requestFocus();
            }
        }

    }

    // Logic method lainnya
    Transaction getTransaction(FieldUtil fieldUtil) {
        Transaction transaction = new Transaction();
        transaction.setTransactionId(fieldUtil.map.get("transactionId").getText());
        Barang barang = searchItemById(fieldUtil.map.get("idItem").getText());
        transaction.setBarang(barang);
        transaction.setAmount(Integer.parseInt(fieldUtil.map.get("amountItem").getText()));
        return transaction;
    }

    Barang searchItemById(String id) {
        try {
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            Barang barang = barangRepositoryImpl.selectById(id);
            if (barang.getName() == null) {
                JOptionPane.showMessageDialog(mainFrame, "Kode barang dengan " + id + " tidak ditemukan!");
                setFieldBlank();
                fieldUtil.map.get("idItem").requestFocus();
            } else {
                fieldUtil.map.get("nameItem").setText(barang.getName());
                fieldUtil.map.get("priceItem").setText(barang.getSellingPrice().toString());
            }
            return barang;
        } catch (Exception e) {
            System.err.println("Gagal searchItemById(" + id + "): " + e.getMessage());
            return null;
        }

    }

    public void setTransactionId() {
        try {
            TransactionRepositoryImpl transactionRepositoryImpl = new TransactionRepositoryImpl();
            String transactionId = transactionRepositoryImpl.getLastId();
            fieldUtil.map.get("transactionId").setText(transactionId);

            buttonUtil.map.get("selling").setEnabled(false);
            fieldUtil.map.get("idItem").requestFocus();
        } catch (Exception e) {
            System.err.println("Gagal setTransactionId(): " + e.getMessage());
        }
    }

    void addTransaction() {
        try {
            TransactionRepositoryImpl transactionRepositoryImpl = new TransactionRepositoryImpl();
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            int row = tableTransactionService.tableModel.getRowCount();

            for (int i = 0; i < row; i++) {
                Transaction transaction = new Transaction();
                transaction.setTransactionId(fieldUtil.map.get("transactionId").getText());
                Barang barang = barangRepositoryImpl.selectById((String) tableTransactionService.tableModel.getValueAt(i, 0));
                transaction.setAmount(Integer.parseInt((String) tableTransactionService.tableModel.getValueAt(i, 3)));
                transaction.setBarang(barang);
                transactionRepositoryImpl.insert(transaction);
            }

        } catch (Exception e) {
            System.err.println("Gagal menyimpan transaksi : " + e);
        }
    }

    void pay() {
        try {
            fieldUtil.map.get("pay").requestFocus();
            Integer restMoney = Integer.parseInt(fieldUtil.map.get("pay").getText()) - tableTransactionService.getTotal();
            fieldUtil.map.get("rest").setText(restMoney.toString());
        } catch (Exception e) {
            System.err.println("Gagal bayar : " + e);
        }
    }

    int amountCheck(String id) {
        int amount = 0;
        try {
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            Barang barang = barangRepositoryImpl.selectById(id);
            var amountField = fieldUtil.map.get("amountItem");
            if (barang.getAmount() < Integer.parseInt(amountField.getText())) {
                amountField.setText("");
                JOptionPane.showMessageDialog(mainFrame, "Jumlah Barang : " + barang.getAmount());
                amount = 1;
            }
        } catch (Exception e) {
            System.err.println("Error amountCheck(): " + e.getMessage());
        }
        return amount;
    }

    void setFieldBlank() {
        for (JTextField textField : fieldUtil.list) {
            if (textField != fieldUtil.map.get("transactionId") && textField != fieldUtil.map.get("total")) {
                textField.setText("");
            }
        }
    }

}
