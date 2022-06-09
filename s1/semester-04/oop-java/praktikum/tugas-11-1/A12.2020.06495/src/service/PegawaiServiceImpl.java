package src.service;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import src.entity.Pegawai;
import src.repository.PegawaiRepositoryImpl;
import src.util.ButtonUtil;
import src.util.FieldUtil;

public class PegawaiServiceImpl implements ActionListener {

    private JFrame mainFrame;
    private JButton targetButton;
    private FieldUtil fieldUtil;
    private ButtonUtil buttonUtil;
    private TablePegawaiService tablePegawaiService;

    public PegawaiServiceImpl(JFrame mainFrame, JButton targetButton, FieldUtil fieldUtil, ButtonUtil buttonUtil,
            TablePegawaiService tablePegawaiService) {
        this.mainFrame = mainFrame;
        this.targetButton = targetButton;
        this.fieldUtil = fieldUtil;
        this.buttonUtil = buttonUtil;
        this.tablePegawaiService = tablePegawaiService;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        Object object = actionEvent.getSource();

        // JButton ActionListener
        if (object == buttonUtil.map.get("add")) {
            fieldUtil.setEnabled(true);
            buttonUtil.setEnabled(true);

            if (targetButton.getText() == "Simpan") {
                String id = buttonUtil.map.get("add").getText();
                if (id.length() == 0) {
                    JOptionPane.showMessageDialog(mainFrame, "NIP pegawai kosong!");
                } else {
                    insertPegawai();
                }

                targetButton.setText("Tambah");
                targetButton.setBackground(Color.GREEN);
                targetButton.setForeground(Color.getHSBColor(250, 0, 255));
                fieldUtil.setBlank();
                fieldUtil.setEnabled(false);
                tablePegawaiService.updateDataTable();
            } else {
                fieldUtil.setBlank();
                targetButton.setText("Simpan");
                targetButton.setForeground(Color.getHSBColor(100, 10, 0));
                targetButton.setBackground(Color.getHSBColor(200, 100, 100));
            }
        }

        if (object == buttonUtil.map.get("search")) {
            String search = JOptionPane.showInputDialog(mainFrame, "Masukan NIP pegawai!");
            if (search != null) {
                fieldUtil.map.get("nip").setText(search);
                int responseSelectByNip = searchByNip(fieldUtil.map.get("nip").getText());
                if (responseSelectByNip == 1) {
                    buttonUtil.setEnabled(true);
                }
                fieldUtil.setEnabled(true);
            } else {
                JOptionPane.showMessageDialog(mainFrame, "NIP kosong!");
            }
        }

        if (object == buttonUtil.map.get("update")) {
            if (targetButton.getText() == "Simpan") {
                if (fieldUtil.map.get("nip").getText() != "") {
                    updatePegawai();
                }
                targetButton.setText("Koreksi");
                tablePegawaiService.updateDataTable();
                fieldUtil.setBlank();
                buttonUtil.setEnabled(1, 1, 0, 0, 1);
            } else {
                targetButton.setText("Simpan");
                buttonUtil.setEnabled(0, 0, 1, 0, 1);
                fieldUtil.map.get("nip").requestFocus();
            }
        }

        if (object == buttonUtil.map.get("delete")) {
            int status = JOptionPane.showConfirmDialog(mainFrame, "Yakin dihapus?");
            if (status == JOptionPane.YES_OPTION) {
                deletePegawai(fieldUtil.map.get("nip").getText());
                tablePegawaiService.updateDataTable();
                fieldUtil.setBlank();
            }
        }

        // JTextField ActionListener
        if (object == fieldUtil.map.get("nip")) {
            fieldUtil.map.get("name").requestFocus();
        }

        if (object == fieldUtil.map.get("name")) {
            fieldUtil.map.get("department").requestFocus();
        }

        if (object == fieldUtil.map.get("department")) {
            fieldUtil.map.get("gender").requestFocus();
        }

        if (object == fieldUtil.map.get("gender")) {
            fieldUtil.map.get("password").requestFocus();
        }

        if (object == fieldUtil.map.get("password")) {
            buttonUtil.map.get("add").requestFocus();
        }

    }

    Pegawai getPegawai(FieldUtil fieldUtil) {
        Pegawai pegawai = new Pegawai();
        pegawai.setNip(fieldUtil.map.get("nip").getText());
        pegawai.setNama(fieldUtil.map.get("name").getText());
        pegawai.setBagian(fieldUtil.map.get("department").getText());
        pegawai.setJenisKelamin(fieldUtil.map.get("gender").getText());
        pegawai.setPassword(fieldUtil.map.get("password").getText());
        return pegawai;
    }

    void insertPegawai() {
        try {
            Pegawai pegawai = getPegawai(fieldUtil);
            buttonUtil.setEnabled(1, 0, 0, 0, 1);

            PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
            Pegawai responseSelectByNip = pegawaiRepository.selectByNip(pegawai.getNip());
            if (responseSelectByNip.getNip() != null) {
                JOptionPane.showMessageDialog(mainFrame, "Nip Sudah Ada !");
                return;
            }

            int responseInsert = pegawaiRepository.insert(pegawai);

            if (responseInsert == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses Di Tambahkan!!!");
            }

            buttonUtil.setEnabled(true);
        } catch (Exception exception) {
            JOptionPane.showMessageDialog(mainFrame, "Penambahan Gagal!!!");
            System.err.println("Penambahan gagal : " + exception);
        }
    }

    public int searchByNip(String nip) {
        try {
            PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
            Pegawai responseSelectByNip = pegawaiRepository.selectByNip(nip);
            if (responseSelectByNip.getNip() != null) {
                fieldUtil.map.get("nip").setText(responseSelectByNip.getNip());
                fieldUtil.map.get("name").setText(responseSelectByNip.getNama());
                fieldUtil.map.get("department").setText(responseSelectByNip.getBagian());
                fieldUtil.map.get("gender").setText(responseSelectByNip.getJenisKelamin());
                fieldUtil.map.get("password").setText(responseSelectByNip.getPassword());
                return 1;
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Data tidak ditemukan !");
                fieldUtil.map.get("nip").requestFocus();
                return 0;
            }
        } catch (Exception e) {
            System.err.println("Search By NIP Error: " + e);
            return 0;
        }
    }

    public void updatePegawai() {
        try {
            Pegawai pegawai = getPegawai(fieldUtil);

            PegawaiRepositoryImpl pegawaiRepository = new PegawaiRepositoryImpl();
            int resultUpdatePegawai = pegawaiRepository.update(pegawai);
            if (resultUpdatePegawai == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses diperbarui!");
            }
        } catch (Exception exception) {
            System.err.println("Update pegawai gagal : " + exception);
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
}
