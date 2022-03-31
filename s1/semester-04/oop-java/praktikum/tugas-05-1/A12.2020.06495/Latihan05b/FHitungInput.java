package Latihan05b;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("unused")
public class FHitungInput extends JFrame implements ActionListener {
    private JPanel pPgw = new JPanel();
    private JLabel lNilai1 = new JLabel("Nilai 1        "), lNilai2 = new JLabel("Nilai 2        "),
            lHasil = new JLabel("Hasil        "), lcreate = new JLabel("nama");

    private JTextField fNilai1 = new JTextField(), fNilai2 = new JTextField(), fHasil = new JTextField();

    private JButton btnTambah = new JButton(), btnKurang = new JButton(), btnKali = new JButton(),
            btnBagi = new JButton(), btnBersih = new JButton(), btnSelesai = new JButton();

    public FHitungInput() {
        setPreferredSize(new Dimension(450, 280));
        setTitle("Form Hittung");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane pPgw = new JDesktopPane();

        // set object label place on the container
        lNilai1.setBounds(15, 20, 100, 25);
        lNilai2.setBounds(15, 55, 100, 25);
        lHasil.setBounds(15, 90, 100, 25);
        lcreate.setBounds(170, 210, 260, 25);
        lcreate.setText("Created by Kukuh Setya A & A12.2020.06495");

        // set object text place on the container
        fNilai1.setBounds(115, 20, 100, 25);
        fNilai2.setBounds(115, 55, 205, 25);
        fHasil.setBounds(115, 90, 92, 25);
        fNilai1.setToolTipText("Isi nilai dengan Angka !");

        // set object button place on the container
        // replace setLabel to setText because it's deprecated
        btnTambah.setBounds(50, 150, 85, 25);
        btnTambah.setText("Tambah");
        btnTambah.setBackground(Color.red);
        btnTambah.setForeground(Color.getHSBColor(50, 0, 55));
        btnKurang.setBounds(150, 150, 85, 25);
        btnKurang.setText("Kurang");
        btnKali.setBounds(50, 185, 85, 25);
        btnKali.setText("Kali");
        btnBagi.setBounds(150, 185, 85, 25);
        btnBagi.setText("Bagi");
        btnBersih.setBounds(250, 150, 75, 25);
        btnBersih.setText("Bersih");
        btnSelesai.setBounds(335, 150, 80, 25);
        btnSelesai.setText("Selesai");
        btnSelesai.setToolTipText("Mengakhiri Program!");

        // Object button switch on off
        btnTambah.setEnabled(true);
        btnSelesai.setEnabled(true);

        // Setting object interaction
        btnTambah.addActionListener(this);
        btnKurang.addActionListener(this);
        btnKali.addActionListener(this);
        btnBagi.addActionListener(this);
        btnBersih.addActionListener(this);
        btnSelesai.addActionListener(this);

        // put all control on object panel
        pPgw.add(lNilai1);
        pPgw.add(fNilai1);
        pPgw.add(lNilai2);
        pPgw.add(fNilai2);
        pPgw.add(lHasil);
        pPgw.add(fHasil);
        pPgw.add(lcreate);
        pPgw.add(btnKurang);
        pPgw.add(btnTambah);
        pPgw.add(btnKali);
        pPgw.add(btnBagi);
        pPgw.add(btnBersih);
        pPgw.add(btnSelesai);

        // add object panel (pPgr) to container frame
        getContentPane().add(pPgw).setBackground(Color.getHSBColor(250, 0, 255));

        // display frame on screen
        pack();
    }

    // main program
    public static void main(String[] args) {
        new FHitungInput().setVisible(true);
    }

    // function if user press button
    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        if (obj == btnTambah) {
            methodTambah();
        }
        if (obj == btnKurang) {
            methodKurang();
        }
        if (obj == btnKali) {
            methodKali();
        }
        if (obj == btnBagi) {
            methodBagi();
        }
        if (obj == btnBersih) {
            kosong();
        }
        if (obj == btnSelesai) {
            System.exit(0);
        }
    }

    void methodTambah() {
        int xhasil = Integer.parseInt(fNilai1.getText()) + Integer.parseInt(fNilai2.getText());
        fHasil.setText(Integer.toString(xhasil));
    }

    void methodKurang() {
        int xhasil = Integer.parseInt(fNilai1.getText()) - Integer.parseInt(fNilai2.getText());
        fHasil.setText(Integer.toString(xhasil));
    }

    void methodKali() {
        int xhasil = Integer.parseInt(fNilai1.getText()) * Integer.parseInt(fNilai2.getText());
        fHasil.setText(Integer.toString(xhasil));
    }

    void methodBagi() {
        int xhasil = Integer.parseInt(fNilai1.getText()) / Integer.parseInt(fNilai2.getText());
        fHasil.setText(Integer.toString(xhasil));
    }

    // function for clear object input
    void kosong() {
        fNilai1.setText("");
        fNilai2.setText("");
        fHasil.setText("");
        fNilai1.requestFocus();
    }
}
