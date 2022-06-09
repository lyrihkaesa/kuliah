package src.service;

import java.util.List;

import javax.swing.JFrame;
import javax.swing.table.DefaultTableModel;

import src.entity.Pegawai;
import src.repository.PegawaiRepositoryImpl;
import src.util.TableUtil;

public class TablePegawaiService extends TableUtil {
    public JFrame mainFrame;
    public DefaultTableModel tableModel;

    public TablePegawaiService(JFrame mainFrame, DefaultTableModel tableModel) {
        this.mainFrame = mainFrame;
        this.tableModel = tableModel;
    }

    public void updateDataTable() {
        try {
            clearDataTable(tableModel);
            PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
            List<Pegawai> listPegawai = pegawaiRepository.selectAll();
            for (int i = 0; i < listPegawai.size(); i++) {
                Pegawai pegawai = listPegawai.get(i);
                String[] rowData = {
                        pegawai.getNip(),
                        pegawai.getNama(),
                        pegawai.getBagian(),
                        pegawai.getJenisKelamin(),
                        pegawai.getPassword()
                };
                tableModel.addRow(rowData);
            }
        } catch (Exception exception) {
            System.err.println("Gagal update data table: " + exception);
        }
    }
}
