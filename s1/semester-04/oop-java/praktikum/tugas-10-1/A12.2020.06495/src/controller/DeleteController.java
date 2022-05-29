package src.controller;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import src.ProgramConfig;
import src.model.BarangRepositoryImpl;
import src.model.PegawaiRepositoryImpl;

public class DeleteController implements ActionListener {

    private JFrame mainFrame;
    @SuppressWarnings("unused")
    private JButton targetButton;
    private FieldController fieldController;
    @SuppressWarnings("unused")
    private ButtonController buttonController;
    private TableController tableController;

    public DeleteController(JFrame mainFrame, JButton targetButton, FieldController fieldController, ButtonController buttonController,
            TableController tableController) {
        this.mainFrame = mainFrame;
        this.targetButton = targetButton;
        this.fieldController = fieldController;
        this.buttonController = buttonController;
        this.tableController = tableController;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        int status = JOptionPane.showConfirmDialog(mainFrame, "Yakin dihapus?");
        if (status == JOptionPane.YES_OPTION) {
            if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[0]) {
                deletePegawai(fieldController.fields[0].getText());
            } else if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[1]) {
                deleteBarang(fieldController.fields[0].getText());
            }
            tableController.updateDataTable();
            fieldController.setFieldsEmpty();
        }
    }

    public void deletePegawai(String nip) {
        try {
            PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
            int responseDelete = pegawaiRepository.delete(nip);

            if (responseDelete == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Data Terhapus!");
            }
        } catch (Exception exception) {
            JOptionPane.showMessageDialog(mainFrame, "Penghapusan Gagal!!!");
            System.err.println("Delete : " + exception.getMessage());
        }
    }

    public void deleteBarang(String id) {
        try {
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            int responseDelete = barangRepositoryImpl.delete(id);

            if (responseDelete == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Data Terhapus!");
            }
        } catch (Exception exception) {
            JOptionPane.showMessageDialog(mainFrame, "Penghapusan Gagal!!!");
            System.err.println("Delete : " + exception.getMessage());
        }
    }

}
