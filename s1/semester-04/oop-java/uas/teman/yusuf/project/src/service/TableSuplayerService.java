package src.service;

import java.util.List;

import javax.swing.JFrame;
import javax.swing.table.DefaultTableModel;

import src.entity.Suplayer;
import src.repository.SuplayerRepositoryImpl;
import src.util.TableUtil;

public class TableSuplayerService extends TableUtil {
    public JFrame mainFrame;
    public DefaultTableModel tableModel;

    public TableSuplayerService(JFrame mainFrame, DefaultTableModel tableModel) {
        this.mainFrame = mainFrame;
        this.tableModel = tableModel;
    }

    public void updateDataTable() {
        try {
            clearDataTable(tableModel);
            SuplayerRepositoryImpl suplayerRepositoryImpl = new SuplayerRepositoryImpl();
            List<Suplayer> listSuplayer = suplayerRepositoryImpl.selectAll();
            for (int i = 0; i < listSuplayer.size(); i++) {
                Suplayer suplayer = listSuplayer.get(i);
                String[] rowData = {
                        suplayer.getKode(),
                        suplayer.getNama(),
                        suplayer.getKota(),
                        suplayer.getTelepon(),
                        suplayer.getEmail()
                };
                tableModel.addRow(rowData);
            }
        } catch (Exception exception) {
            System.err.println("Gagal update data table: " + exception);
        }
    }
}
