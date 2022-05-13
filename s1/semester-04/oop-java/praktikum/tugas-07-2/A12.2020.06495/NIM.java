import java.awt.*;
import java.awt.event.*;
// import java.io.*;
import javax.swing.*;
// import java.sql.*;

public class NIM extends JFrame implements ActionListener {
    @SuppressWarnings("unused")
    private JPanel panelTiket = new JPanel();

    // Label
    private JLabel labelNIK = new JLabel("NIK"),
            labelNamaPenumpang = new JLabel("Nama Penumpang"),
            labelTempatTujuan = new JLabel("Tempat Tujuan"),
            labelUmur = new JLabel("Umur"),
            labelJumlahPotongan = new JLabel("Jumlah Potongan"),
            labelPPH = new JLabel("PPH"),
            labelTotalBayar = new JLabel("Total Bayar"),
            labelPembuat = new JLabel("Kukuh Setya A. | A12.2020.06495");

    // Text Field
    private JTextField fieldNIK = new JTextField(),
            fieldNamaPenumpang = new JTextField(),
            fieldUmur = new JTextField("0"),
            fieldJumlahPotongan = new JTextField(),
            fieldPPH = new JTextField(),
            fieldTotalBayar = new JTextField();

    // Button
    private JButton buttonCheck = new JButton();

    // Combobox
    String[] bandara = { "A", "B", "C", "D" };
    private JComboBox<String> comboBoxTempatTujuan = new JComboBox<String>(bandara);

    public NIM() {
        // set container
        setTitle("Pembayaran Tiket Pesawat");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane paneTiket = new JDesktopPane();

        // variabel set bounds
        int xDefault = 15;
        int yDefault = 15;
        int labelWidth = 120;
        int labelHeight = 15;
        int gapLabel = 5;
        int fieldWidth = 200;
        int fieldHeight = 25;
        int gapField = 15;
        int buttonWidth = 100;
        int buttonHeight = 25;

        // set object posisiton on container
        int x = xDefault;
        int y = yDefault;
        labelNIK.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldNIK.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelNamaPenumpang.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldNamaPenumpang.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelTempatTujuan.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        comboBoxTempatTujuan.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelUmur.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldUmur.setBounds(x, y, 30, fieldHeight);
        y += fieldHeight + gapField;

        // button check
        buttonCheck.setBounds(x, y, buttonWidth, buttonHeight);
        buttonCheck.setText("Check");
        int yFooter = y + buttonHeight + 30;

        x = xDefault;
        y = yDefault;
        x += fieldWidth + gapField * 2;

        labelJumlahPotongan.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldJumlahPotongan.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelPPH.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldPPH.setBounds(x, y, fieldWidth, fieldHeight);
        y += fieldHeight + gapField;

        labelTotalBayar.setBounds(x, y, labelWidth, labelHeight);
        y += labelHeight + gapLabel;
        fieldTotalBayar.setBounds(x, y, fieldWidth, fieldHeight);

        labelPembuat.setBounds(0, yFooter, x + fieldWidth + xDefault * 2, labelHeight);
        labelPembuat.setHorizontalAlignment(SwingConstants.CENTER);
        setPreferredSize(new Dimension(x + fieldWidth + xDefault * 2, yFooter + labelHeight + yDefault * 2 + 30));

        // object set enable/desable
        fieldJumlahPotongan.setEnabled(false);
        fieldPPH.setEnabled(false);
        fieldTotalBayar.setEnabled(false);

        // style field
        fieldJumlahPotongan.setDisabledTextColor(Color.BLACK);
        fieldPPH.setDisabledTextColor(Color.BLACK);
        fieldTotalBayar.setDisabledTextColor(Color.BLACK);

        // set object for interaction
        buttonCheck.addActionListener(this);

        // put all control on object panel
        paneTiket.add(labelNIK);
        paneTiket.add(labelNamaPenumpang);
        paneTiket.add(labelTempatTujuan);
        paneTiket.add(labelUmur);
        paneTiket.add(labelJumlahPotongan);
        paneTiket.add(labelPPH);
        paneTiket.add(labelTotalBayar);
        paneTiket.add(labelPembuat);

        paneTiket.add(fieldNIK);
        paneTiket.add(fieldNamaPenumpang);
        paneTiket.add(comboBoxTempatTujuan);
        paneTiket.add(fieldUmur);
        paneTiket.add(fieldJumlahPotongan);
        paneTiket.add(fieldPPH);
        paneTiket.add(fieldTotalBayar);
        paneTiket.add(buttonCheck);

        // add object panel (panelPegawai) to frame container
        getContentPane().add(paneTiket).setBackground(Color.PINK);

        // display frame on monitor
        pack();

    }

    public static void main(String[] args) {
        new NIM().setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        if (obj == buttonCheck) {
            int hargaTiket = getHargaTiket(comboBoxTempatTujuan.getSelectedItem().toString());
            int umur = fieldUmur.getText() != "" ? Integer.parseInt(fieldUmur.getText()) : 0;

            Double jumlahPotongan = getJumlahPotongan(umur, hargaTiket);
            Double PPH = getPPH(hargaTiket);
            fieldJumlahPotongan.setText(jumlahPotongan.toString());
            fieldPPH.setText(PPH.toString());
            fieldTotalBayar.setText(getTotalBayar(hargaTiket, jumlahPotongan, PPH).toString());
        }
    }

    int getHargaTiket(String choicedBandara) {
        int hargaTiket = 0;
        switch (choicedBandara) {
            case "A":
                hargaTiket = 400000;
                break;
            case "B":
                hargaTiket = 500000;
                break;
            case "C":
                hargaTiket = 600000;
                break;
            case "D":
                hargaTiket = 700000;
                break;
            default:
                break;
        }
        return hargaTiket;
    }

    Double getJumlahPotongan(int usia, int hargaTiket) {
        double jumlahPotongan = 0;
        if (usia < 18) {
            jumlahPotongan = 0.1 * hargaTiket;
        } else if (usia >= 18) {
            jumlahPotongan = 0;
        }
        return jumlahPotongan;
    }

    Double getPPH(int hargaTiket) {
        double PPH = 0;
        if (hargaTiket >= 500000) {
            PPH = 0.02 * hargaTiket;
        } else if (hargaTiket < 500000) {
            PPH = 0.01 * hargaTiket;
        }
        return PPH;
    }

    Double getTotalBayar(int hargaTiket, Double jumlahPotongan, Double PPH) {
        return hargaTiket - (jumlahPotongan + PPH);
    }

}
