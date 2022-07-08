package src.service;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import src.entity.Suplayer;
import src.repository.SuplayerRepositoryImpl;
import src.util.ButtonUtil;
import src.util.FieldUtil;

public class SuplayerServiceImpl implements ActionListener {

    private JFrame mainFrame;
    private JButton targetButton;
    private FieldUtil fieldUtil;
    private ButtonUtil buttonUtil;
    private TableSuplayerService tableSuplayerService;

    public SuplayerServiceImpl(JFrame mainFrame, JButton targetButton, FieldUtil fieldUtil, ButtonUtil buttonUtil,
            TableSuplayerService tableSuplayerService) {
        this.mainFrame = mainFrame;
        this.targetButton = targetButton;
        this.fieldUtil = fieldUtil;
        this.buttonUtil = buttonUtil;
        this.tableSuplayerService = tableSuplayerService;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        Object object = actionEvent.getSource();

        // JButton ActionListener
        if (object == buttonUtil.map.get("add")) {
            fieldUtil.setEnabled(true);
            buttonUtil.setEnabled(1, 0, 0, 0, 1);

            if (targetButton.getText() == "Simpan") {
                String id = buttonUtil.map.get("add").getText();
                if (id.length() == 0) {
                    JOptionPane.showMessageDialog(mainFrame, "Kode suplayer kosong!");
                } else {
                    insertSuplayer();
                }

                targetButton.setText("Tambah");
                fieldUtil.setBlank();
                fieldUtil.setEnabled(false);
                tableSuplayerService.updateDataTable();
                buttonUtil.setEnabled(1, 1, 0, 0, 1);
            } else {
                fieldUtil.setBlank();
                targetButton.setText("Simpan");
            }
        }

        if (object == buttonUtil.map.get("search")) {
            if (targetButton.getText() == "Cari") {
                String search = JOptionPane.showInputDialog(mainFrame, "Masukan kode suplayer!");
                if (search != null) {
                    fieldUtil.map.get("kode").setText(search);
                    int responseSelectById = searchByKode(fieldUtil.map.get("kode").getText());
                    if (responseSelectById == 1) {
                        fieldUtil.setEnabled(true);
                        buttonUtil.setEnabled(0, 1, 1, 1, 1);
                        targetButton.setText("Kosong");
                    } else {
                        fieldUtil.setEnabled(false);
                        buttonUtil.setEnabled(1, 1, 0, 0, 1);
                    }
                } else {
                    JOptionPane.showMessageDialog(mainFrame, "Kode kosong!");
                    targetButton.setText("Cari");
                    buttonUtil.setEnabled(1, 1, 0, 0, 1);
                }
            } else {
                targetButton.setText("Cari");
                buttonUtil.setEnabled(1, 1, 0, 0, 1);
                fieldUtil.setBlank();
            }
        }

        if (object == buttonUtil.map.get("update")) {
            int status = JOptionPane.showConfirmDialog(mainFrame, "Yakin ingin mengedit?");
            if (status == JOptionPane.YES_OPTION) {
                if (fieldUtil.map.get("kode").getText() != "") {
                    updateSuplayer();
                    buttonUtil.map.get("search").setText("Cari");
                }
                tableSuplayerService.updateDataTable();
                fieldUtil.setBlank();
                buttonUtil.setEnabled(1, 1, 0, 0, 1);
            }
        }

        if (object == buttonUtil.map.get("delete")) {
            int status = JOptionPane.showConfirmDialog(mainFrame, "Yakin dihapus?");
            if (status == JOptionPane.YES_OPTION) {
                deleteSuplayer(fieldUtil.map.get("kode").getText());
                buttonUtil.map.get("search").setText("Cari");
                tableSuplayerService.updateDataTable();
                fieldUtil.setBlank();
                buttonUtil.setEnabled(1, 1, 0, 0, 1);
            }
        }

        // JTextField ActionListener
        if (object == fieldUtil.map.get("kode")) {
            fieldUtil.map.get("nama").requestFocus();
        }

        if (object == fieldUtil.map.get("nama")) {
            fieldUtil.map.get("alamat").requestFocus();
        }

        if (object == fieldUtil.map.get("alamat")) {
            fieldUtil.map.get("kota").requestFocus();
        }

        if (object == fieldUtil.map.get("kota")) {
            fieldUtil.map.get("provinsi").requestFocus();
        }

        if (object == fieldUtil.map.get("provinsi")) {
            fieldUtil.map.get("telepon").requestFocus();
        }

        if (object == fieldUtil.map.get("telepon")) {
            fieldUtil.map.get("email").requestFocus();
        }

        if (object == fieldUtil.map.get("email")) {
            buttonUtil.map.get("add").requestFocus();
        }

    }

    Suplayer getSuplayer(FieldUtil fieldUtil) {
        Suplayer suplayer = new Suplayer();
        suplayer.setKode(fieldUtil.map.get("kode").getText());
        suplayer.setNama(fieldUtil.map.get("nama").getText());
        suplayer.setAlamat(fieldUtil.map.get("alamat").getText());
        suplayer.setKota(fieldUtil.map.get("kota").getText());
        suplayer.setProvinsi(fieldUtil.map.get("provinsi").getText());
        suplayer.setTelepon(fieldUtil.map.get("telepon").getText());
        suplayer.setEmail(fieldUtil.map.get("email").getText());
        return suplayer;
    }

    void insertSuplayer() {
        try {
            Suplayer suplayer = getSuplayer(fieldUtil);

            buttonUtil.setEnabled(1, 0, 0, 0, 1);

            SuplayerRepositoryImpl suplayerRepositoryImpl = new SuplayerRepositoryImpl();
            Suplayer responseSelectByKode = suplayerRepositoryImpl.selectByKode(suplayer.getKode());
            if (responseSelectByKode.getKode() != null) {
                JOptionPane.showMessageDialog(mainFrame, "Kode suplayer sudah ada!");
                return;
            }

            int responseInsert = suplayerRepositoryImpl.insert(suplayer);

            if (responseInsert == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses Di Tambahkan!!!");
            }

            buttonUtil.setEnabled(true);
        } catch (Exception exception) {
            JOptionPane.showMessageDialog(mainFrame, "Penambahan Gagal!!!");
            System.err.println("Penambahan gagal : " + exception);
        }
    }

    int searchByKode(String kode) {
        try {
            SuplayerRepositoryImpl suplayerRepositoryImpl = new SuplayerRepositoryImpl();
            Suplayer responseSelectByKode = suplayerRepositoryImpl.selectByKode(kode);
            if (responseSelectByKode.getKode() != null) {
                fieldUtil.map.get("kode").setText(responseSelectByKode.getKode());
                fieldUtil.map.get("nama").setText(responseSelectByKode.getNama());
                fieldUtil.map.get("alamat").setText(responseSelectByKode.getAlamat());
                fieldUtil.map.get("kota").setText(responseSelectByKode.getKota());
                fieldUtil.map.get("provinsi").setText(responseSelectByKode.getProvinsi());
                fieldUtil.map.get("telepon").setText(responseSelectByKode.getTelepon());
                fieldUtil.map.get("email").setText(responseSelectByKode.getEmail());
                return 1;
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Data tidak ditemukan !");
                fieldUtil.map.get("kode").requestFocus();
                return 0;
            }
        } catch (Exception exception) {
            System.err.println("Search By Id Error: " + exception);
            return 0;
        }
    }

    void updateSuplayer() {
        try {
            Suplayer suplayer = getSuplayer(fieldUtil);

            SuplayerRepositoryImpl suplayerRepositoryImpl = new SuplayerRepositoryImpl();
            int resultUpdateSuplayer = suplayerRepositoryImpl.update(suplayer);
            if (resultUpdateSuplayer == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses diperbarui!");
            }
        } catch (Exception exception) {
            System.err.println("Update suplayer gagal : " + exception);
        }
    }

    void deleteSuplayer(String kode) {
        try {
            SuplayerRepositoryImpl suplayerRepositoryImpl = new SuplayerRepositoryImpl();
            int responseDelete = suplayerRepositoryImpl.delete(kode);

            if (responseDelete == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Data Terhapus!");
            }
        } catch (Exception exception) {
            JOptionPane.showMessageDialog(mainFrame, "Penghapusan Gagal!!!");
            System.err.println("Delete : " + exception.getMessage());
        }
    }

}
