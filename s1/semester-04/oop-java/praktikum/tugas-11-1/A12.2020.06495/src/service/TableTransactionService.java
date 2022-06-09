package src.service;

import javax.swing.JFrame;
import javax.swing.table.DefaultTableModel;

import src.entity.Transaction;
import src.util.TableUtil;

public class TableTransactionService extends TableUtil {
    @SuppressWarnings("unused")
    private JFrame mainFrame;
    public DefaultTableModel tableModel;
    private Integer total;

    public TableTransactionService(JFrame mainFrame, DefaultTableModel tableModel) {
        this.mainFrame = mainFrame;
        this.tableModel = tableModel;
        this.total = 0;
    }

    public void updateDataTable(Transaction transaction) {
        try {
            String totalString = String.valueOf(transaction.getBarang().getPurchasePrice() * transaction.getAmount());
            String[] data = {
                    transaction.getBarang().getId(),
                    transaction.getBarang().getName(),
                    transaction.getBarang().getSellingPrice().toString(),
                    transaction.getAmount().toString(),
                    totalString
            };
            tableModel.addRow(data);
            total = total + Integer.parseInt(totalString);
        } catch (Exception exception) {
            System.err.println("Gagal update data table: " + exception.getMessage());
        }

    }

    public Integer getTotal() {
        return this.total;
    }

    public void setTotal(Integer total) {
        this.total = total;
    }

    public void clear() {
        clearDataTable(tableModel);
        total = 0;
    }

}
