package src.service;

import java.util.List;

import javax.swing.JFrame;
import javax.swing.table.DefaultTableModel;

import src.entity.Barang;
import src.repository.BarangRepositoryImpl;
import src.util.TableUtil;

public class TableBarangService extends TableUtil {
    public JFrame mainFrame;
    public DefaultTableModel tableModel;

    public TableBarangService(JFrame mainFrame, DefaultTableModel tableModel) {
        this.mainFrame = mainFrame;
        this.tableModel = tableModel;
    }

    public void updateDataTable() {
        try {
            clearDataTable(tableModel);
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            List<Barang> listBarang = barangRepositoryImpl.selectAll();
            for (int i = 0; i < listBarang.size(); i++) {
                Barang barang = listBarang.get(i);
                String[] rowData = {
                        barang.getId(),
                        barang.getName(),
                        barang.getSellingPrice().toString(),
                        barang.getPurchasePrice().toString(),
                        barang.getAmount().toString()
                };
                tableModel.addRow(rowData);
            }
        } catch (Exception exception) {
            System.err.println("Gagal update data table: " + exception);
        }
    }

}
