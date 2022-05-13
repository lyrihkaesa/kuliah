import java.awt.*;
import java.awt.event.*;
import java.text.NumberFormat;
import java.util.*;

import javax.swing.*;

public class A12_2020_06495 extends JFrame implements ActionListener {
    @SuppressWarnings("unused")
    private JPanel panelGaji = new JPanel();

    // Label
    private JLabel labelNIP = new JLabel("NIP"), labelNamaPegawai = new JLabel("Nama Pegawai"),
            labelMasaKerja = new JLabel("Masa Kerja"), labelGajiPokok = new JLabel("Gaji Pokok"),
            labelTunjanganJabatan = new JLabel("Tunjangan Jabatan"), labelGajiKotor = new JLabel("Gaji Kotor"),
            labelPotongan = new JLabel("Potongan"), labelGajiBersih = new JLabel("Gaji Bersih"),
            labelPembuat = new JLabel("Kukuh Setya Arumansyah | A12.2020.06495");

    // Text Field
    private JTextField fieldNIP = new JTextField(), fieldNamaPegawai = new JTextField(),
            fieldMasaKerja = new JTextField(), fieldGajiPokok = new JTextField(),
            fieldTunjanganJabatan = new JTextField(), fieldGajiKotor = new JTextField(),
            fieldPotongan = new JTextField(), fieldGajiBersih = new JTextField();

    // Button
    private JButton buttonHitung = new JButton("Hitung"), buttonKosong = new JButton("Kosong");

    public A12_2020_06495() {
        // set container
        setTitle("Program Gaji Pegawai");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane paneGaji = new JDesktopPane();

        // Frontend
        // set object posisiton on container
        // variabel set bounds
        int xDefault = 20;
        int yDefault = 20;
        int labelWidth = 150;
        int labelHeight = 15;
        int gapLabel = 5;
        int fieldWidth = 150;
        int fieldHeight = 25;
        int gapField = 10;
        int buttonWidth = 150;
        int buttonHeight = 30;
        int verticalGap = 20;

        // set object posisiton on container
        int x = xDefault;
        int y = yDefault;
        labelNIP.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldNIP.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelNamaPegawai.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldNamaPegawai.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelMasaKerja.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldMasaKerja.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelTunjanganJabatan.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldTunjanganJabatan.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelPotongan.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldPotongan.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        int yFooter = y;
        x = xDefault + fieldWidth + verticalGap;
        y = yDefault;

        labelGajiPokok.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldGajiPokok.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelGajiKotor.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldGajiKotor.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelGajiBersih.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldGajiBersih.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField + labelHeight;

        buttonHitung.setBounds(x, y, buttonWidth, buttonHeight);
        y += buttonHeight + gapLabel;
        buttonKosong.setBounds(x, y, buttonWidth, buttonHeight);

        labelPembuat.setBounds(0, yFooter, x + fieldWidth + xDefault * 2, labelHeight);
        labelPembuat.setHorizontalAlignment(SwingConstants.CENTER);

        int dimensionWidth = x + fieldWidth + xDefault * 2;
        int dimensionHight = yFooter + gapField * 2 + labelHeight + yDefault * 2;
        setPreferredSize(new Dimension(dimensionWidth, dimensionHight));

        // object set enable/desable
        fieldGajiPokok.setEnabled(false);
        fieldGajiKotor.setEnabled(false);
        fieldGajiBersih.setEnabled(false);

        // style field
        fieldGajiPokok.setDisabledTextColor(Color.BLACK);
        fieldGajiKotor.setDisabledTextColor(Color.BLACK);
        fieldGajiBersih.setDisabledTextColor(Color.BLACK);
        buttonHitung.setBackground(Color.GREEN);
        buttonKosong.setBackground(Color.RED);

        // set object for interaction
        buttonHitung.addActionListener(this);
        buttonKosong.addActionListener(this);

        // put all control on object panel
        paneGaji.add(labelNIP);
        paneGaji.add(labelNamaPegawai);
        paneGaji.add(labelMasaKerja);
        paneGaji.add(labelGajiPokok);
        paneGaji.add(labelTunjanganJabatan);
        paneGaji.add(labelGajiKotor);
        paneGaji.add(labelPotongan);
        paneGaji.add(labelGajiBersih);
        paneGaji.add(labelPembuat);

        paneGaji.add(fieldNIP);
        paneGaji.add(fieldNamaPegawai);
        paneGaji.add(fieldMasaKerja);
        paneGaji.add(fieldGajiPokok);
        paneGaji.add(fieldTunjanganJabatan);
        paneGaji.add(fieldGajiKotor);
        paneGaji.add(fieldPotongan);
        paneGaji.add(fieldGajiBersih);

        paneGaji.add(buttonHitung);
        paneGaji.add(buttonKosong);

        // add object panel (panelPegawai) to frame container
        getContentPane().add(paneGaji).setBackground(Color.ORANGE);

        // display frame on monitor
        pack();
    }

    public static void main(String[] args) {
        new A12_2020_06495().setVisible(true);
    }

    // Backend
    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        if (obj == buttonHitung) {
            int masaKerja = 0;
            if (!fieldMasaKerja.getText().isEmpty()) {
                masaKerja = Integer.parseInt(fieldMasaKerja.getText());
            } else {
                fieldMasaKerja.setText("0");
            }
            Integer gajiPokok = getGajiPokok(masaKerja);
            fieldGajiPokok.setText(formatNumber(gajiPokok));

            int tunjanganJabatan = 0;
            if (!fieldTunjanganJabatan.getText().isEmpty()) {
                tunjanganJabatan = Integer.parseInt(fieldTunjanganJabatan.getText());
            } else {
                fieldTunjanganJabatan.setText("0");
            }
            Integer gajiKotor = getGajiKotor(gajiPokok, tunjanganJabatan);
            fieldGajiKotor.setText(formatNumber(gajiKotor));

            int potongan = 0;
            if (!fieldPotongan.getText().isEmpty()) {
                potongan = Integer.parseInt(fieldPotongan.getText());
            } else {
                fieldPotongan.setText("0");
            }
            Integer gajiBersih = getGajiBersih(gajiKotor, potongan);
            fieldGajiBersih.setText(formatNumber(gajiBersih));
        }

        if (obj == buttonKosong) {
            fieldNIP.setText("");
            fieldNamaPegawai.setText("");
            fieldMasaKerja.setText("");
            fieldTunjanganJabatan.setText("");
            fieldPotongan.setText("");
            fieldGajiPokok.setText("");
            fieldGajiKotor.setText("");
            fieldGajiBersih.setText("");
        }
    }

    int getGajiPokok(int masaKerja) {
        int gajiPokok = 0;
        if (masaKerja >= 4) {
            gajiPokok = 4000000;
        } else if (masaKerja >= 2 && masaKerja < 4) {
            gajiPokok = 3000000;
        } else if (masaKerja < 2) {
            gajiPokok = 1000000;
        }
        return gajiPokok;
    }

    int getGajiKotor(int gajiPokok, int tunjanganJabatan) {
        return gajiPokok + tunjanganJabatan;
    }

    int getGajiBersih(int gajiKotor, int potongan) {
        return gajiKotor - potongan;
    }

    String formatNumber(int number) {
        // Create a new Locale
        Locale idn = new Locale("id", "ID");
        // Create a Currency instance for the Locale
        // Currency rupiah = Currency.getInstance(idn);
        // Create a formatter given the Locale
        NumberFormat rupiahFormat = NumberFormat.getCurrencyInstance(idn);
        return rupiahFormat.format(number);
    }
}
