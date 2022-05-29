package src.controller;

import java.awt.Color;

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

public class AddController implements ActionListener {

    private JFrame mainFrame;
    private JButton targetButton;
    private FieldController fieldController;
    private ButtonController buttonController;
    private TableController tableController;

    public AddController(JFrame mainFrame, JButton targetButton, FieldController fieldController, ButtonController buttonController,
            TableController tableController) {
        this.mainFrame = mainFrame;
        this.targetButton = targetButton;
        this.fieldController = fieldController;
        this.buttonController = buttonController;
        this.tableController = tableController;
    }

    @Override
    public void actionPerformed(ActionEvent e) {

        fieldController.setFieldsEnabled(true);
        buttonController.setButtonsEnabled(true);

        if (targetButton.getText() == "Simpan") {

            if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[0]) {
                String nip = fieldController.fields[0].getText();
                if (nip.length() == 0) {
                    JOptionPane.showMessageDialog(mainFrame, "NIP pegawai kosong!");
                } else {
                    insertPegawai();
                }
            } else if (mainFrame.getTitle() == ProgramConfig.PROGRAM_TITLE[1]) {
                String id = fieldController.fields[0].getText();
                if (id.length() == 0) {
                    JOptionPane.showMessageDialog(mainFrame, "Kode barang kosong!");
                } else {
                    insertBarang();
                }
            }

            targetButton.setText("Tambah");
            targetButton.setBackground(Color.GREEN);
            targetButton.setForeground(Color.getHSBColor(250, 0, 255));
            fieldController.setFieldsEmpty();
            fieldController.setFieldsEnabled(false);
            tableController.updateDataTable();
        } else {
            fieldController.setFieldsEmpty();
            targetButton.setText("Simpan");
            targetButton.setForeground(Color.getHSBColor(100, 10, 0));
            targetButton.setBackground(Color.getHSBColor(200, 100, 100));
        }

    }

    void insertPegawai() {
        try {
            PegawaiModel pegawai = new PegawaiModel();
            pegawai.setNip(fieldController.fields[0].getText());
            pegawai.setNama(fieldController.fields[1].getText());
            pegawai.setBagian(fieldController.fields[2].getText());
            pegawai.setJenisKelamin(fieldController.fields[3].getText());
            pegawai.setPassword(fieldController.fields[4].getText());

            buttonController.setButtonsEnabled(1, 0, 0, 0, 1);

            PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
            PegawaiModel responseSelectByNip = pegawaiRepository.selectByNip(pegawai.getNip());
            if (responseSelectByNip.getNip() != null) {
                JOptionPane.showMessageDialog(mainFrame, "Nip Sudah Ada !");
                return;
            }

            int responseInsert = pegawaiRepository.insert(pegawai);

            if (responseInsert == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses Di Tambahkan!!!");
            }

            buttonController.setButtonsEnabled(true);
        } catch (Exception exception) {
            JOptionPane.showMessageDialog(mainFrame, "Penambahan Gagal!!!");
            System.err.println("Penambahan gagal : " + exception);
        }
    }

    void insertBarang() {
        try {
            BarangModel barang = new BarangModel();
            barang.setId(fieldController.fields[0].getText());
            barang.setName(fieldController.fields[1].getText());
            barang.setSellingPrice(Integer.parseInt(fieldController.fields[2].getText()));
            barang.setPurchasePrice(Integer.parseInt(fieldController.fields[3].getText()));
            barang.setAmount(Integer.parseInt(fieldController.fields[4].getText()));

            buttonController.setButtonsEnabled(1, 0, 0, 0, 1);

            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            BarangModel responseSelectById = barangRepositoryImpl.selectById(barang.getId());
            if (responseSelectById.getId() != null) {
                JOptionPane.showMessageDialog(mainFrame, "Kode barang sudah ada!");
                return;
            }

            int responseInsert = barangRepositoryImpl.insert(barang);

            if (responseInsert == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses Di Tambahkan!!!");
            }

            buttonController.setButtonsEnabled(true);
        } catch (Exception exception) {
            JOptionPane.showMessageDialog(mainFrame, "Penambahan Gagal!!!");
            System.err.println("Penambahan gagal : " + exception);
        }
    }

}
