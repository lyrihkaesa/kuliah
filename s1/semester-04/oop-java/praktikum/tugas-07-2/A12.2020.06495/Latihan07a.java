import java.awt.*;
import java.awt.event.*;
// import java.io.*;
import javax.swing.*;
// import java.sql.*;

public class Latihan07a extends JFrame implements ActionListener {
    @SuppressWarnings("unused")
    private JPanel pPgw = new JPanel();
    private JLabel lNip = new JLabel("NIP       "), lNama = new JLabel("Nama       "),
            lBagian = new JLabel("Bagian       "), lcreate = new JLabel("nama");
    private JTextField fNip = new JTextField(), fNama = new JTextField(), fBagian = new JTextField();
    private JButton btnAdd = new JButton(), btnCari = new JButton(), btnKoreksi = new JButton(),
            btnHapus = new JButton(), btnSelesai = new JButton();

    public Latihan07a() {
        setPreferredSize(new Dimension(450, 300));
        setTitle("Data Pegawai");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane pPgw = new JDesktopPane();

        // set object label position on container
        lNip.setBounds(15, 20, 100, 25);
        lNama.setBounds(15, 55, 100, 25);
        lBagian.setBounds(15, 90, 100, 25);
        lcreate.setBounds(100, 225, 300, 25);
        lcreate.setText("Created by Kukuh Setya A. A12.2020.06495");

        // set objek text position on container
        fNip.setBounds(115, 20, 100, 25);
        fNama.setBounds(115, 55, 205, 25);
        fBagian.setBounds(115, 90, 92, 25);
        fNip.setToolTipText("Isi Nip dengan Angka !");

        // set object button position on container
        btnAdd.setBounds(20, 150, 85, 25);
        btnAdd.setText("Add");
        btnAdd.setBackground(Color.BLUE);
        btnAdd.setForeground(Color.getHSBColor(250, 0, 255));
        btnCari.setBounds(120, 150, 85, 25);
        btnCari.setText("Cari");
        btnKoreksi.setBounds(220, 150, 85, 25);
        btnKoreksi.setText("Koreksi");
        btnHapus.setBounds(220, 185, 85, 25);
        btnHapus.setText("Hapus");
        btnSelesai.setBounds(320, 150, 85, 60);
        btnSelesai.setText("Selesai");
        btnSelesai.setToolTipText("Mengakhiri Program");

        // object button set on/off
        btnAdd.setEnabled(true);
        btnSelesai.setEnabled(true);

        // set object for interaction
        btnAdd.addActionListener(this);
        btnCari.addActionListener(this);
        btnKoreksi.addActionListener(this);
        btnHapus.addActionListener(this);
        btnSelesai.addActionListener(this);

        // put all control on object panel
        pPgw.add(lNip);
        pPgw.add(fNip);
        pPgw.add(lNama);
        pPgw.add(fNama);
        pPgw.add(lBagian);
        pPgw.add(fBagian);
        pPgw.add(lcreate);
        pPgw.add(btnAdd);
        pPgw.add(btnCari);
        pPgw.add(btnKoreksi);
        pPgw.add(btnHapus);
        pPgw.add(btnSelesai);

        // add object panel (pPgw) to frame container
        getContentPane().add(pPgw).setBackground(Color.getHSBColor(100, 150, 75));

        // display frame on monitor
        pack();
        Kosong();
        setTombol(1, 1, 0, 0, 1);
    }

    public static void main(String[] args) {
        new Latihan07a().setVisible(true);
    }

    // function if user do push button
    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        // when pick Add...
        if (obj == btnAdd) {
            if (btnAdd.getText() == "Simpan") {
                String xnip = fNip.getText();
                if (xnip.length() != 0)
                    Add();
                else
                    JOptionPane.showMessageDialog(this, "Nip Kosong !");

                btnAdd.setText("Add");
                Kosong();
                setTombol(1, 1, 0, 0, 1);
            } else {
                Kosong();
                setTombol(1, 0, 0, 0, 1);
                btnAdd.setText("Simpan");
                btnAdd.setForeground(Color.getHSBColor(100, 10, 0));
                btnAdd.setBackground(Color.getHSBColor(200, 100, 100));
            }
        }

        // when pick cari...
        if (obj == btnCari) {
            String xcari = JOptionPane.showInputDialog(this, "Masukkan Nip !");
            if (xcari != null) {
                fNip.setText(xcari);
                int xx = Cari();
                if (xx == 1)
                    setTombol(1, 1, 1, 1, 1);
            } else
                JOptionPane.showMessageDialog(this, "Nip kosong !");
        }

        // when pick correction...
        if (obj == btnKoreksi) {
            if (btnKoreksi.getText() == "Simpan") {
                if (fNip.getText() != null)
                    Koreksi();
                btnKoreksi.setText("Koreksi");
                Kosong();
                setTombol(1, 1, 0, 0, 1);
            } else {
                btnKoreksi.setText("Simpan");
                setTombol(0, 0, 1, 0, 1);
                fNama.requestFocus();
            }
        }

        // when pick hapus...
        if (obj == btnHapus) {
            int stt = JOptionPane.showConfirmDialog(this, "Yakin dihapus ?");
            System.out.print(stt);

            if (stt == 0) {
                Hapus();
                Kosong();
            }
        }

        // when pick selesai...
        if (obj == btnSelesai) {
            System.exit(0);
        }
    }

    // function for add data to tabel barang
    void Add() {
        try {
            JOptionPane.showMessageDialog(this, "Proses untuk Add!");
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this, "Penambahan Gagal!!!");
        }
    }

    // function for search Kode_Barang to tabel barang
    int Cari() {
        int x = 0;
        return x;
    }

    // function for correction data to tabel barang
    void Koreksi() {

    }

    // function for delete data to tabel barang
    void Hapus() {

    }

    // function for empty input object
    void Kosong() {
        fNip.setText("");
        fNama.setText("");
        fBagian.setText("");
        fNip.requestFocus();
    }

    void setTombol(int a, int b, int c, int d, int e) {
        btnAdd.setEnabled(a >= 1 ? true : false);
        btnCari.setEnabled(b >= 1 ? true : false);
        btnKoreksi.setEnabled(c >= 1 ? true : false);
        btnHapus.setEnabled(d >= 1 ? true : false);
        btnSelesai.setEnabled(e >= 1 ? true : false);
    }

}