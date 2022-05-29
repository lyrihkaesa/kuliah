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

public class UpdateController implements ActionListener {

    private JFrame mainFrame;
    private JButton targetButton;
    private FieldController fieldController;
    private ButtonController buttonController;
    private TableController tableController;

    public UpdateController(JFrame mainFrame, JButton targetButton, FieldController fieldController, ButtonController buttonController,
            TableController tableController) {
        this.mainFrame = mainFrame;
        this.targetButton = targetButton;
        this.fieldController = fieldController;
        this.buttonController = buttonController;
        this.tableController = tableController;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (targetButton.getText() == "Simpan") {
            if (fieldController.fields[0].getText() != "") {
                if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[0]) {
                    updatePegawai();
                } else if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[1]) {
                    updateBarang();
                }
            }
            targetButton.setText("Koreksi");
            tableController.updateDataTable();
            fieldController.setFieldsEmpty();
            buttonController.setButtonsEnabled(1, 1, 0, 0, 1);
        } else {
            targetButton.setText("Simpan");
            buttonController.setButtonsEnabled(0, 0, 1, 0, 1);
            fieldController.fields[1].requestFocus();
        }
    }

    public void updatePegawai() {
        try {
            PegawaiModel pegawai = new PegawaiModel();
            pegawai.setNip(fieldController.fields[0].getText());
            pegawai.setNama(fieldController.fields[1].getText());
            pegawai.setBagian(fieldController.fields[2].getText());
            pegawai.setJenisKelamin(fieldController.fields[3].getText());
            pegawai.setPassword(fieldController.fields[4].getText());

            PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
            int resultUpdatePegawai = pegawaiRepository.update(pegawai);
            if (resultUpdatePegawai == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses diperbarui!");
            }
        } catch (Exception exception) {
            System.err.println("Update pegawai gagal : " + exception);
        }
    }

    public void updateBarang() {
        try {
            BarangModel barang = new BarangModel();
            barang.setId(fieldController.fields[0].getText());
            barang.setName(fieldController.fields[1].getText());
            barang.setSellingPrice(Integer.parseInt(fieldController.fields[2].getText()));
            barang.setPurchasePrice(Integer.parseInt(fieldController.fields[2].getText()));
            barang.setAmount(Integer.parseInt(fieldController.fields[2].getText()));

            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            int resultUpdateBarang = barangRepositoryImpl.update(barang);
            if (resultUpdateBarang == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses diperbarui!");
            }
        } catch (Exception exception) {
            System.err.println("Update barang gagal : " + exception);
        }
    }
}
