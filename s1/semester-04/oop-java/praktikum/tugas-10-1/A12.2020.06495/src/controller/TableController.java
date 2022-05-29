package src.controller;

import java.util.List;

import javax.swing.JFrame;
import javax.swing.table.DefaultTableModel;

import src.ProgramConfig;
import src.model.BarangModel;
import src.model.BarangRepositoryImpl;
import src.model.PegawaiModel;
import src.model.PegawaiRepositoryImpl;

public class TableController {
    public DefaultTableModel tableModel;
    public JFrame mainFrame;

    public TableController(JFrame mainFrame, DefaultTableModel tableModel) {
        this.mainFrame = mainFrame;
        this.tableModel = tableModel;
    }

    public void updateDataTable() {
        try {
            clearDataTable();
            if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[0]) {
                PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
                List<PegawaiModel> listPegawai = pegawaiRepository.selectAll();
                for (int i = 0; i < listPegawai.size(); i++) {
                    PegawaiModel pegawai = listPegawai.get(i);
                    String[] rowData = {
                            pegawai.getNip(),
                            pegawai.getNama(),
                            pegawai.getBagian(),
                            pegawai.getJenisKelamin(),
                            pegawai.getPassword()
                    };
                    tableModel.addRow(rowData);
                }
            } else if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[1]) {
                BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
                List<BarangModel> listBarang = barangRepositoryImpl.selectAll();
                for (int i = 0; i < listBarang.size(); i++) {
                    BarangModel barang = listBarang.get(i);
                    String[] rowData = {
                            barang.getId(),
                            barang.getName(),
                            barang.getSellingPrice().toString(),
                            barang.getPurchasePrice().toString(),
                            barang.getAmount().toString()
                    };
                    tableModel.addRow(rowData);
                }
            }
        } catch (Exception exception) {
            System.err.println("Gagal update data table: " + exception);
        }
    }

    public void clearDataTable() {
        int row = tableModel.getRowCount();
        for (int i = 0; i < row; i++) {
            tableModel.removeRow(0);
        }
    }
}
