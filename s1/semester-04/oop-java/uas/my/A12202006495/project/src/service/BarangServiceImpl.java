package src.service;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import src.AppConfig;
import src.entity.Barang;
import src.repository.BarangRepositoryImpl;
import src.util.ButtonUtil;
import src.util.FieldUtil;

public class BarangServiceImpl implements ActionListener {

    private JFrame mainFrame;
    private JButton targetButton;
    private FieldUtil fieldUtil;
    private ButtonUtil buttonUtil;
    private TableBarangService tableBarangService;

    public BarangServiceImpl(JFrame mainFrame, JButton targeButton, FieldUtil fieldUtil, ButtonUtil buttonUtil,
            TableBarangService tableBarangService) {
        this.mainFrame = mainFrame;
        this.targetButton = targeButton;
        this.fieldUtil = fieldUtil;
        this.buttonUtil = buttonUtil;
        this.tableBarangService = tableBarangService;
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
                    JOptionPane.showMessageDialog(mainFrame, "Kode barang kosong!");
                } else {
                    insertBarang();
                }

                targetButton.setText("Tambah");
                targetButton.setBackground(AppConfig.MyColor.SUCCESS500);
                targetButton.setForeground(AppConfig.MyColor.PURPLE100);
                fieldUtil.setBlank();
                fieldUtil.setEnabled(false);
                tableBarangService.updateDataTable();
                buttonUtil.setEnabled(1, 1, 0, 0, 1);
            } else {
                fieldUtil.setBlank();
                targetButton.setText("Simpan");
                targetButton.setForeground(AppConfig.MyColor.SUCCESS500);
                targetButton.setBackground(AppConfig.MyColor.GREY900);
                targetButton.setBorder(AppConfig.MyBorder.SUCCESS_BORDER2);
            }
        }

        if (object == buttonUtil.map.get("search")) {
            if (targetButton.getText() == "Cari") {
                String search = JOptionPane.showInputDialog(mainFrame, "Masukan kode barang!");
                if (search != null) {
                    fieldUtil.map.get("id").setText(search);
                    int responseSelectById = searchById(fieldUtil.map.get("id").getText());
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
                if (fieldUtil.map.get("id").getText() != "") {
                    updateBarang();
                    buttonUtil.map.get("search").setText("Cari");
                }
                tableBarangService.updateDataTable();
                fieldUtil.setBlank();
                buttonUtil.setEnabled(1, 1, 0, 0, 1);
            }
        }

        if (object == buttonUtil.map.get("delete")) {
            int status = JOptionPane.showConfirmDialog(mainFrame, "Yakin dihapus?");
            if (status == JOptionPane.YES_OPTION) {
                deleteBarang(fieldUtil.map.get("id").getText());
                buttonUtil.map.get("search").setText("Cari");
                tableBarangService.updateDataTable();
                fieldUtil.setBlank();
                buttonUtil.setEnabled(1, 1, 0, 0, 1);
            }
        }

        // JTextField ActionListener
        if (object == fieldUtil.map.get("id")) {
            fieldUtil.map.get("name").requestFocus();
        }

        if (object == fieldUtil.map.get("name")) {
            fieldUtil.map.get("sellingPrice").requestFocus();
        }

        if (object == fieldUtil.map.get("sellingPrice")) {
            fieldUtil.map.get("purchasePrice").requestFocus();
        }

        if (object == fieldUtil.map.get("purchasePrice")) {
            fieldUtil.map.get("amount").requestFocus();
        }

        if (object == fieldUtil.map.get("amount")) {
            buttonUtil.map.get("add").requestFocus();
        }

    }

    // Logic

    Barang getBarang(FieldUtil fieldUtil) {
        Barang barang = new Barang();
        barang.setId(fieldUtil.map.get("id").getText());
        barang.setName(fieldUtil.map.get("name").getText());
        barang.setSellingPrice(Integer.parseInt(fieldUtil.map.get("sellingPrice").getText()));
        barang.setPurchasePrice(Integer.parseInt(fieldUtil.map.get("purchasePrice").getText()));
        barang.setAmount(Integer.parseInt(fieldUtil.map.get("amount").getText()));
        return barang;
    }

    void insertBarang() {
        try {
            Barang barang = getBarang(fieldUtil);

            buttonUtil.setEnabled(1, 0, 0, 0, 1);

            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            Barang responseSelectById = barangRepositoryImpl.selectById(barang.getId());
            if (responseSelectById.getId() != null) {
                JOptionPane.showMessageDialog(mainFrame, "Kode barang sudah ada!");
                return;
            }

            int responseInsert = barangRepositoryImpl.insert(barang);

            if (responseInsert == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses Di Tambahkan!!!");
            }

            buttonUtil.setEnabled(true);
        } catch (Exception exception) {
            JOptionPane.showMessageDialog(mainFrame, "Penambahan Gagal!!!");
            System.err.println("Penambahan gagal : " + exception);
        }
    }

    int searchById(String id) {
        try {
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            Barang responseSelectById = barangRepositoryImpl.selectById(id);
            if (responseSelectById.getId() != null) {
                fieldUtil.map.get("id").setText(responseSelectById.getId());
                fieldUtil.map.get("name").setText(responseSelectById.getName());
                fieldUtil.map.get("sellingPrice").setText(responseSelectById.getSellingPrice().toString());
                fieldUtil.map.get("purchasePrice").setText(responseSelectById.getPurchasePrice().toString());
                fieldUtil.map.get("amount").setText(responseSelectById.getAmount().toString());
                return 1;
            } else {
                JOptionPane.showMessageDialog(mainFrame, "Data tidak ditemukan !");
                fieldUtil.map.get("id").requestFocus();
                return 0;
            }
        } catch (Exception exception) {
            System.err.println("Search By Id Error: " + exception);
            return 0;
        }
    }

    void updateBarang() {
        try {
            Barang barang = getBarang(fieldUtil);

            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            int resultUpdateBarang = barangRepositoryImpl.update(barang);
            if (resultUpdateBarang == 1) {
                JOptionPane.showMessageDialog(mainFrame, "Sukses diperbarui!");
            }
        } catch (Exception exception) {
            System.err.println("Update barang gagal : " + exception);
        }
    }

    void deleteBarang(String id) {
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
