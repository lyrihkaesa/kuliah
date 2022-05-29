package old;

import java.awt.*;
import java.awt.event.*;
// import java.io.*; // never used
import javax.swing.*;
import java.sql.*;
import javax.swing.table.DefaultTableModel;

public class FPegawai01 extends JFrame implements ActionListener {
    @SuppressWarnings("unused")
    private JPanel pPgw = new JPanel();

    private JLabel lNip = new JLabel("N I P Pegawai       "),
            lNama = new JLabel("Nama        "),
            lBagian = new JLabel("Bagian      "),
            lJenisKel = new JLabel("Jenis Kelamin"),
            lPassword = new JLabel("Passord"),
            lcreate = new JLabel("Setyo");

    private JTextField fNip = new JTextField(),
            fNama = new JTextField(),
            fBagian = new JTextField(),
            fJenisKel = new JTextField(),
            fPassword = new JTextField();

    private JButton btnAdd = new JButton(),
            btnCari = new JButton(),
            btnKoreksi = new JButton(),
            btnHapus = new JButton(),
            btnSelesai = new JButton();

    // private ResultSet rs;
    // rs=record set:yang mengontrol letak kursor terhadap suatu record(baris)
    // yang sedang aktif di suatu table.
    String[] header = { "NIP", "Nama", "Bagian", "Jenis Kelamin", "Password" };

    // DefaultTableModel untuk menampilkan model atau isinya
    // JTable adalah salah satu komponen dari package SWING yang dapat
    // digunakan untuk menampilkan/mengedit data dua dimensi dalam bentuk tabel,
    // seperti spreadsheet
    // JScrollPane untuk memberikan scroll pada tabel disaat datanya melebihi
    // kapasitas tampilan.

    DefaultTableModel tabMode1;
    JTable tabel = new JTable();
    JScrollPane skrTabel = new JScrollPane();

    public FPegawai01() {
        // setPreferredSize=mengatur ukuran yang diinginkan
        setPreferredSize(new Dimension(670, 510));
        // titlenya "Data Pegawai"
        setTitle("Data Pegawai");

        // setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // JDesktopPane adalah kelas wadah (container class) untuk membuat
        // MDI (Multiple Document Interface)
        JDesktopPane pPgw = new JDesktopPane();

        /* Mengatur letak objek Label Di container */
        // lnip.setBounds(20, 20, 150, 30);
        // 20 = posisi X; 20 = posisi Y; 100 = Width; 30; Height = 30

        lNip.setBounds(20, 25, 100, 25);
        lNama.setBounds(20, 55, 100, 25);
        lBagian.setBounds(20, 90, 100, 25);
        lJenisKel.setBounds(20, 125, 100, 25);
        lPassword.setBounds(20, 160, 100, 25);

        lcreate.setBounds(230, 225, 200, 25);
        lcreate.setText("create by nama dan nim Anda");

        /* Mengatur letak objek Text Di Container */
        fNip.setBounds(115, 20, 100, 25);
        fNama.setBounds(115, 55, 205, 25);
        fBagian.setBounds(115, 90, 92, 25);
        fJenisKel.setBounds(115, 125, 92, 25);
        fPassword.setBounds(115, 160, 92, 25);

        fNip.setToolTipText("Isi Nip dengan Angka !");

        /* Mengatur letak objek Button di Container */
        btnAdd.setBounds(20, 380, 85, 25);
        btnAdd.setText("Tambah");
        btnAdd.setBackground(Color.green);
        btnAdd.setForeground(Color.getHSBColor(250, 0, 255));
        btnCari.setBounds(120, 380, 85, 25);
        btnCari.setText("Cari");
        btnKoreksi.setBounds(220, 380, 85, 25);
        btnKoreksi.setText("Koreksi");
        btnHapus.setBounds(320, 380, 85, 25);
        btnHapus.setText("Hapus");
        btnSelesai.setBounds(435, 380, 85, 25);
        btnSelesai.setText("Selesai");
        btnSelesai.setToolTipText("Mengakhiri Program");

        // membuat tabel.......................................
        tabMode1 = new DefaultTableModel(null, header);
        // setModel(TableModel dataModel)Menentukan model data untuk tabel.
        tabel.setModel(tabMode1);
        tabel.setBackground(Color.orange);
        // getViewport() menampilkan isi tabel
        skrTabel.getViewport().add(tabel);
        tabel.setEnabled(false);
        skrTabel.setBounds(20, 200, 500, 170);

        /* Objek Button di Non Aktifkan dan di aktifkan */
        btnAdd.setEnabled(true);
        btnSelesai.setEnabled(true);

        // Mengatur objek untuk dapat berinteraksi
        btnAdd.addActionListener(this);
        btnCari.addActionListener(this);
        btnKoreksi.addActionListener(this);
        btnHapus.addActionListener(this);
        btnSelesai.addActionListener(this);

        // Meletakkan seluruh kontrol pada objek panel */
        pPgw.add(skrTabel);
        pPgw.add(lNip);
        pPgw.add(fNip);
        pPgw.add(lNama);
        pPgw.add(fNama);
        pPgw.add(lBagian);
        pPgw.add(fBagian);
        pPgw.add(lJenisKel);
        pPgw.add(fJenisKel);
        pPgw.add(lPassword);
        pPgw.add(fPassword);

        pPgw.add(lcreate);

        pPgw.add(btnAdd);
        pPgw.add(btnCari);
        pPgw.add(btnKoreksi);
        pPgw.add(btnHapus);
        pPgw.add(btnSelesai);

        /* Menambahkan objek panel (pPgr) ke container frame */
        // getContentPane() adalah statement untuk menghasilkan content pane(jendela)
        // dari frame yang merupakan obyek dari kelas Container
        getContentPane().add(pPgw).setBackground(Color.PINK);

        // Menampilkan frame ke layar monitor
        // pack() digunakan untuk mengatur ukuran JFrame. secara otomatis sehingga dapat
        // menampung semua
        pack();
        setLocationRelativeTo(null);
        tampiltabel();

        Kosong();
        // settombol(1, 0, 0, 0, 1);
        setisian(0, 0, 0, 0, 0);

        // setting setelah di tekan enter kursor dari Nip menuju ke masukan Nama
        fNip.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                fNama.requestFocus();
            }
        });

        // setting setelah di tekan enter kursor dari Nama menuju ke masukan Bagian
        fNama.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                fBagian.requestFocus();
            }
        });

        // setting setelah di tekan enter kursor dari Bagian menuju ke masukan Jenis
        // Kelamin
        fBagian.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                fJenisKel.requestFocus();
            }
        });

        // setting setelah di tekan enter kursor dari Jenis Kelamin menuju ke masukan
        // Password
        fJenisKel.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                fPassword.requestFocus();
            }
        });

        // setting setelah di tekan enter kursor dari Jenis Kelamin menuju ke masukan
        // Password
        fPassword.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                btnAdd.requestFocus();
            }
        });

    }

    public static void main(String[] args) {

        new FPegawai01().setVisible(true);
    }

    /* Fungsi jika user melakukan action penekanan tombol Button */
    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        if (obj == btnAdd) {

            setisian(1, 1, 1, 1, 1);
            settombol(1, 1, 1, 1, 1);

            if (btnAdd.getText() == "Simpan") {

                String xnip = fNip.getText();
                if (xnip.length() != 0)
                    Add();
                else
                    JOptionPane.showMessageDialog(this, "Nip kosong !");

                btnAdd.setText("Add");
                Kosong();
                tampiltabel();
                // settombol(1, 1, 0, 0, 1);
            } else {
                Kosong();
                // settombol(1, 0, 0, 0, 1);
                btnAdd.setText("Simpan");
                btnAdd.setForeground(Color.getHSBColor(100, 10, 0));
                btnAdd.setBackground(Color.getHSBColor(200, 100, 100));
            }
        }

        if (obj == btnCari) {
            String xcari = JOptionPane.showInputDialog(this, "Masukkan Nip !");
            if (xcari != null) {
                fNip.setText(xcari);
                int xx = Cari();
                if (xx == 1)
                    settombol(1, 1, 1, 1, 1);
                setisian(1, 1, 1, 1, 1);

            } else
                JOptionPane.showMessageDialog(this, "Nip kosong !");
        }

        if (obj == btnKoreksi) {
            if (btnKoreksi.getText() == "Simpan") {
                if (fNip.getText() != "")
                    Koreksi();
                btnKoreksi.setText("Koreksi");
                tampiltabel();
                Kosong();
                settombol(1, 1, 0, 0, 1);
            } else {
                btnKoreksi.setText("Simpan");
                settombol(0, 0, 1, 0, 1);
                fNama.requestFocus();
            }
        }
        if (obj == btnHapus) {
            int stt = JOptionPane.showConfirmDialog(this, "Yakin dihapus ?");
            System.out.print(stt);

            if (stt == 0) {
                Hapus();
                tampiltabel();
                Kosong();
            }

        }

        if (obj == btnSelesai) {
            // System.exit(0);
            this.dispose();
        }
    }

    // Fungsi untuk menambahkan data ke tabel barang
    void Add() {
        try {
            settombol(1, 0, 0, 0, 1);
            Connection connection = new KoneksiDBMS().getConnection();
            // KoneksiDBMS CnPenjualan = new KoneksiDBMS();
            // Connection connection = CnPenjualan.getConnection();
            Statement stat = connection.createStatement();

            String strsqlcr = "SELECT * FROM pegawai WHERE nip ='" + fNip.getText() + "'";
            ResultSet rs = stat.executeQuery(strsqlcr);

            if (rs.next()) {
                JOptionPane.showMessageDialog(this, "Nip Sudah Ada !");
                return;
            }

            String strsql = "insert into pegawai(nip,nama,bagian,jenis_kelamin,password) values " +
                    " ('" + fNip.getText() + "','" + fNama.getText() + "' " +
                    ",'" + fBagian.getText() + "','" + fJenisKel.getText() + "','" + fPassword.getText() + "')";
            int stsproses = stat.executeUpdate(strsql);

            if (stsproses == 1)
                JOptionPane.showMessageDialog(this, "Sukses Di Tambahkan!!!");
            settombol(1, 1, 1, 1, 1);
            connection.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Penambahan Gagal!!!");
            System.err.println("Kesalahan perintah SQL : " + e.getMessage());
        }
    }

    // Fungsi untuk mencari Kode_Barang ke tabel barang
    int Cari() {
        int x = 0;
        try {
            Connection connection = new KoneksiDBMS().getConnection();
            // KoneksiDBMS CnPenjualan = new KoneksiDBMS();
            // Connection connection = CnPenjualan.getConnection();
            Statement stat = connection.createStatement();

            String strsql = "SELECT * FROM pegawai WHERE nip ='" + fNip.getText() + "'";
            ResultSet rs = stat.executeQuery(strsql);

            if (rs.next()) {
                // Jika Nip Ditemukan Di Tabel

                fNip.setText(rs.getString("nip"));
                fNama.setText(rs.getString("nama"));
                fBagian.setText(rs.getString("bagian"));
                fJenisKel.setText(rs.getString("jenis_kelamin"));
                fPassword.setText(rs.getString("password"));

                x = 1;
            } else {
                // Jika Nip tidak ditemukan
                JOptionPane.showMessageDialog(this, "Data tidak ditemukan !");
                fNip.requestFocus();
            }
            rs.close();
            connection.close();
        } catch (SQLException e) {
        }
        return x;
    }

    // Fungsi untuk menambahkan data ke tabel barang
    void Koreksi() {
        try {
            Connection connection = new KoneksiDBMS().getConnection();
            // KoneksiDBMS CnPenjualan = new KoneksiDBMS();
            // Connection connection = CnPenjualan.getConnection();
            Statement stat = connection.createStatement();

            String strsql = "update pegawai set nama='" + fNama.getText() +
                    "',bagian='" + fBagian.getText() +
                    "',jenis_kelamin='" + fJenisKel.getText() +
                    "',password='" + fPassword.getText() +
                    "' where nip='" + fNip.getText() + "' ";
            int stsproses = stat.executeUpdate(strsql);

            if (stsproses == 1)
                JOptionPane.showMessageDialog(this, "Sukses DiEdit!");
            connection.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Koreksi Gagal !");
            System.err.println("Kesalahan perintah SQL : " + e.getMessage());
        }
    }

    // Fungsi untuk menambahkan data ke tabel barang
    void Hapus() {
        try {
            Connection connection = new KoneksiDBMS().getConnection();
            // KoneksiDBMS CnPenjualan = new KoneksiDBMS();
            // Connection connection = CnPenjualan.getConnection();
            Statement stat = connection.createStatement();

            String strsql = "delete from pegawai where nip='" + fNip.getText() + "' ";
            int stsproses = stat.executeUpdate(strsql);

            if (stsproses == 1)
                JOptionPane.showMessageDialog(this, "Data Terhapus !");
            connection.close();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this, "Penghapusan Gagal!!!");
            System.err.println("Kesalahan perintah SQL : " + e.getMessage());
        }
    }

    // tambah
    void tampiltabel() {
        try {
            bersihtabel();
            Connection connection = new KoneksiDBMS().getConnection();
            // KoneksiDBMS CnPenjualan = new KoneksiDBMS();
            // Connection connection = CnPenjualan.getConnection();
            Statement stat = connection.createStatement();
            String strsql = "select * from pegawai";
            ResultSet rs = stat.executeQuery(strsql);
            @SuppressWarnings("unused")
            ResultSetMetaData meta = rs.getMetaData();

            while (rs.next()) {
                String Nip = rs.getString("nip");
                String Nama = rs.getString("nama");
                String Bagian = rs.getString("bagian");
                String JenisKel = rs.getString("jenis_kelamin");
                String Password = rs.getString("password");
                String[] data = { Nip, Nama, Bagian, JenisKel, Password };
                tabMode1.addRow(data);
            }
            stat.close();
            rs.close();
            connection.close();

        } catch (SQLException se) {
            System.err.println("Kesalahan perintah SQL : " + se.getMessage());
        }
    }

    void bersihtabel() {
        int brs = tabMode1.getRowCount();
        for (int i = 0; i < brs; i++) {
            tabMode1.removeRow(0);
        }
    }

    // Fungsi untuk mengkosongkan Objek masukan
    void Kosong() {
        fNip.setText("");
        fNama.setText("");
        fBagian.setText("");
        fJenisKel.setText("");
        fPassword.setText("");

        fNip.requestFocus();
    }

    void setisian(int a, int b, int c, int d, int e) {
        fNip.setEnabled(a >= 1 ? true : false);
        fNama.setEnabled(b >= 1 ? true : false);
        fBagian.setEnabled(c >= 1 ? true : false);
        fJenisKel.setEnabled(d >= 1 ? true : false);
        fPassword.setEnabled(e >= 1 ? true : false);
    }

    void settombol(int a, int b, int c, int d, int e) {
        btnAdd.setEnabled(a >= 1 ? true : false);
        btnCari.setEnabled(b >= 1 ? true : false);
        btnKoreksi.setEnabled(c >= 1 ? true : false);
        btnHapus.setEnabled(d >= 1 ? true : false);
        btnSelesai.setEnabled(e >= 1 ? true : false);
    }
}