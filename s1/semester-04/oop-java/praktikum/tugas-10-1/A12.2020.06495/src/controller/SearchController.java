package src.controller;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import src.ProgramConfig;
import src.model.BarangModel;
import src.model.BarangRepositoryImpl;
import src.model.PegawaiModel;
import src.model.PegawaiRepositoryImpl;

public class SearchController implements ActionListener {
    private JFrame mainFrame;
    @SuppressWarnings("unused")
    private JButton targetButton;
    private FieldController fieldController;
    private ButtonController buttonController;
    @SuppressWarnings("unused")
    private TableController tableController;

    public SearchController(JFrame mainFrame, JButton targetButton, FieldController fieldController, ButtonController buttonController,
            TableController tableController) {
        this.mainFrame = mainFrame;
        this.targetButton = targetButton;
        this.fieldController = fieldController;
        this.buttonController = buttonController;
        this.tableController = tableController;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[0]) {
            String search = JOptionPane.showInputDialog(mainFrame, "Masukan NIP pegawai!");
            if (search != null) {
                fieldController.fields[0].setText(search);
                int responseSelectByNip = searchByNip(fieldController.fields[0].getText());
                if (responseSelectByNip == 1) {
                    buttonController.setButtonsEnabled(true);
                }
                fieldController.setFieldsEnabled(true);
            } else {
                JOptionPane.showMessageDialog(mainFrame, "NIP kosong!");
            }
        } else if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[1]) {
            String search = JOptionPane.showInputDialog(mainFrame, "Masukan kode barang!");
            if (search != null) {
                fieldController.fields[0].setText(search);
                int responseSelectById = searchById(fieldController.fields[0].getText());
                if (responseSelectById == 1) {
                    buttonController.setButtonsEnabled(true);
                }
                fieldController.setFieldsEnabled(true);
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Kode kosong!");
            }
        }

    }

    public int searchByNip(String nip) {
        try {
            PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
            PegawaiModel responseSelectByNip = pegawaiRepository.selectByNip(nip);
            if (responseSelectByNip.getNip() != null) {
                fieldController.fields[0].setText(responseSelectByNip.getNip());
                fieldController.fields[1].setText(responseSelectByNip.getNama());
                fieldController.fields[2].setText(responseSelectByNip.getBagian());
                fieldController.fields[3].setText(responseSelectByNip.getJenisKelamin());
                fieldController.fields[4].setText(responseSelectByNip.getPassword());
                return 1;
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Data tidak ditemukan !");
                fieldController.fields[0].requestFocus();
                return 0;
            }
        } catch (Exception e) {
            System.err.println("Search By NIP Error: " + e);
            return 0;
        }
    }

    public int searchById(String id) {
        try {
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            BarangModel responseSelectById = barangRepositoryImpl.selectById(id);
            if (responseSelectById.getId() != null) {
                fieldController.fields[0].setText(responseSelectById.getId());
                fieldController.fields[1].setText(responseSelectById.getName());
                fieldController.fields[2].setText(responseSelectById.getSellingPrice().toString());
                fieldController.fields[3].setText(responseSelectById.getPurchasePrice().toString());
                fieldController.fields[4].setText(responseSelectById.getAmount().toString());
                return 1;
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Data tidak ditemukan !");
                fieldController.fields[0].requestFocus();
                return 0;
            }
        } catch (Exception e) {
            System.err.println("Search By Id Error: " + e);
            return 0;
        }
    }

}
