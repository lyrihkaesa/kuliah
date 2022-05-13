import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class A12_2020_06489 extends JFrame implements ActionListener {
    @SuppressWarnings("unused")
    private JPanel panelPembayaranAir = new JPanel();

    // Label
    private JLabel labelNoPelanggan = new JLabel("No Pelanggan"), labelNama = new JLabel("Nama"),
        labelNIK = new JLabel("NIK"), labelGol = new JLabel("Gol. : (1,2,3)"), labelAlamat = new JLabel("Alamat"),
        labelJumlahPakai = new JLabel("Jml Pakai"), labelBiPakai = new JLabel("Bi.Pakai"),
        labelBiAdministrasi = new JLabel("Bi.Administrasi"), labelPajak = new JLabel("Pajak"),
        labelTotalBayar = new JLabel("Total Bayar"), labelPembuat = new JLabel("Yusuf Nasrulloh_A12.2020.06489");

    // Text Field
    private JTextField fieldNoPelanggan = new JTextField(), fieldNama = new JTextField(), fieldNIK = new JTextField(),
        fieldGol = new JTextField(), fieldAlamat = new JTextField(), fieldJumlahPakai = new JTextField(),
        fieldBiPakai = new JTextField(), fieldBiAdministrasi = new JTextField(), fieldPajak = new JTextField(),
        fieldTotalBayar = new JTextField();

    // Button
    private JButton buttonHitung = new JButton("Hitung"), buttonHapus = new JButton("Hapus"),
        buttonSelesai = new JButton("Selesai");

    public A12_2020_06489() {
        // set container
        setTitle("PERHITUNGAN PEMBAYARAN AIR");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane panePembayaranAir = new JDesktopPane();

        // Frontend
        // set object posisiton on container
        // variabel set bounds
        int labelWidth = 150;
        int labelHeight = 15;
        int gapHorizontal = 20;
        int gapVertical = 10;
        int fieldWidth = 150;
        int fieldHeight = 25;
        int buttonWidth = 100;
        int buttonHeight = 25;

        // set object posisiton on container
        int x = 20;
        int y = 20;
        int xField = x + labelWidth + gapVertical;

        labelNoPelanggan.setBounds(x, y, labelWidth, labelHeight);
        fieldNoPelanggan.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelNama.setBounds(x, y, labelWidth, labelHeight);
        fieldNama.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelNIK.setBounds(x, y, labelWidth, labelHeight);
        fieldNIK.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelGol.setBounds(x, y, labelWidth, labelHeight);
        fieldGol.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelAlamat.setBounds(x, y, labelWidth, labelHeight);
        fieldAlamat.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelJumlahPakai.setBounds(x, y, labelWidth, labelHeight);
        fieldJumlahPakai.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelBiPakai.setBounds(x, y, labelWidth, labelHeight);
        fieldBiPakai.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelBiAdministrasi.setBounds(x, y, labelWidth, labelHeight);
        fieldBiAdministrasi.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelPajak.setBounds(x, y, labelWidth, labelHeight);
        fieldPajak.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        labelTotalBayar.setBounds(x, y, labelWidth, labelHeight);
        fieldTotalBayar.setBounds(xField, y, fieldWidth, fieldHeight);
        y += labelHeight + gapHorizontal;

        buttonHitung.setBounds(xField, y, buttonWidth, buttonHeight);
        int xButton = xField + buttonWidth + gapVertical;
        buttonHapus.setBounds(xButton, y, buttonWidth, buttonHeight);
        xButton += buttonWidth + gapVertical;
        buttonSelesai.setBounds(xButton, y, buttonWidth, buttonHeight);
        y += buttonHeight + gapHorizontal;

        labelPembuat.setBounds(0, y, 600, 25);
        labelPembuat.setHorizontalAlignment(JTextField.CENTER);
        setPreferredSize(new Dimension(600, 600));

        // object set enable/desable
        fieldBiPakai.setEnabled(false);
        fieldBiAdministrasi.setEnabled(false);
        fieldPajak.setEnabled(false);
        fieldTotalBayar.setEnabled(false);

        // style field
        fieldBiPakai.setDisabledTextColor(Color.BLACK);
        fieldBiAdministrasi.setDisabledTextColor(Color.BLACK);
        fieldPajak.setDisabledTextColor(Color.BLACK);
        fieldTotalBayar.setDisabledTextColor(Color.BLACK);

        // set object for interaction
        buttonHitung.addActionListener(this);
        buttonHapus.addActionListener(this);
        buttonSelesai.addActionListener(this);

        // put all control on object panel
        panePembayaranAir.add(labelNoPelanggan);
        panePembayaranAir.add(labelNama);
        panePembayaranAir.add(labelNIK);
        panePembayaranAir.add(labelGol);
        panePembayaranAir.add(labelAlamat);
        panePembayaranAir.add(labelJumlahPakai);
        panePembayaranAir.add(labelBiPakai);
        panePembayaranAir.add(labelBiAdministrasi);
        panePembayaranAir.add(labelPajak);
        panePembayaranAir.add(labelTotalBayar);
        panePembayaranAir.add(labelPembuat);

        panePembayaranAir.add(fieldNoPelanggan);
        panePembayaranAir.add(fieldNama);
        panePembayaranAir.add(fieldNIK);
        panePembayaranAir.add(fieldGol);
        panePembayaranAir.add(fieldAlamat);
        panePembayaranAir.add(fieldJumlahPakai);
        panePembayaranAir.add(fieldBiPakai);
        panePembayaranAir.add(fieldBiAdministrasi);
        panePembayaranAir.add(fieldPajak);
        panePembayaranAir.add(fieldTotalBayar);

        panePembayaranAir.add(buttonHitung);
        panePembayaranAir.add(buttonHapus);
        panePembayaranAir.add(buttonSelesai);

        // add object panel (panelPegawai) to frame container
        getContentPane().add(panePembayaranAir).setBackground(Color.PINK);

        // display frame on monitor
        pack();
    }

    public static void main(String[] args) {
        new A12_2020_06489().setVisible(true);
    }

    // Backend
    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        if (obj == buttonHitung) {
            int gol = Integer.parseInt(fieldGol.getText());
            int jumlahPakai = Integer.parseInt(fieldJumlahPakai.getText());
            Integer biPakai = getBiPakai(jumlahPakai);
            Integer biAdministrasi = getBiAdministrasi(gol);
            Double pajak = getPajak(biPakai, biAdministrasi);
            Integer totalBayar = getTotalBayar(biPakai, biAdministrasi, pajak);

            fieldBiPakai.setText(biPakai.toString());
            fieldBiAdministrasi.setText(biAdministrasi.toString());
            fieldPajak.setText(pajak.toString());
            fieldTotalBayar.setText(totalBayar.toString());
        }

        if (obj == buttonHapus) {
            fieldNoPelanggan.setText("");
            fieldNama.setText("");
            fieldNIK.setText("");
            fieldGol.setText("");
            fieldAlamat.setText("");
            fieldJumlahPakai.setText("");
            fieldBiPakai.setText("");
            fieldBiAdministrasi.setText("");
            fieldPajak.setText("");
            fieldTotalBayar.setText("");
        }

        if (obj == buttonSelesai) {
            System.exit(0);
        }
    }

    int getBiPakai(int jumlahPakai) {
        int biPakai = 0;
        biPakai = jumlahPakai * 500;
        return biPakai;
    }

    int getBiAdministrasi(int gol) {
        int biAdministrasi = 0;
        switch (gol) {
            case 1:
                biAdministrasi = 15000;
                break;
            case 2:
                biAdministrasi = 10000;
                break;
            default:
                biAdministrasi = 5000;
                break;
        }
        return biAdministrasi;
    }

    Double getPajak(int biPakai, int biAdministrasi) {
        Double pajak = 0.0;
        pajak = 0.5 * (biPakai + biAdministrasi);
        return pajak;
    }

    int getTotalBayar(int biPakai, int biAdministrasi, Double pajak) {
        int totalBayar = 0;
        totalBayar = (int)(biPakai + biAdministrasi + pajak);
        return totalBayar;
    }
}
