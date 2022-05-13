import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class A12_2020_06476 extends JFrame implements ActionListener {
    @SuppressWarnings("unused")
    private JPanel panelGaji = new JPanel();

    // Label
    private JLabel labelNIP = new JLabel("NIP"),
            labelNamaPegawai = new JLabel("Nama Pegawai"),
            labelMasaKerja = new JLabel("Masa Kerja"),
            labelGajiPokok = new JLabel("Gaji Pokok"),
            labelTunjanganJabatan = new JLabel("Tunjangan Jabatan"),
            labelGajiKotor = new JLabel("Gaji Kotor"),
            labelPotongan = new JLabel("Potongan"),
            labelGajiBersih = new JLabel("Gaji Bersih"),
            labelPembuat = new JLabel("Farhan Taqi | A12.2020.06476");

    // Text Field
    private JTextField fieldNIP = new JTextField(),
            fieldNamaPegawai = new JTextField(),
            fieldMasaKerja = new JTextField(),
            fieldGajiPokok = new JTextField(),
            fieldTunjanganJabatan = new JTextField(),
            fieldGajiKotor = new JTextField(),
            fieldPotongan = new JTextField(),
            fieldGajiBersih = new JTextField();

    // Button
    private JButton buttonHitung = new JButton("Hitung");

    public A12_2020_06476() {
        // set container
        setTitle("Program Gaji Pegawai");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane paneGaji = new JDesktopPane();

        // set object posisiton on container
        labelNIP.setBounds(15, 15, 120, 15);
        fieldNIP.setBounds(15, 35, 150, 25);

        labelNamaPegawai.setBounds(15, 75, 120, 15);
        fieldNamaPegawai.setBounds(15, 95, 150, 25);

        labelMasaKerja.setBounds(15, 135, 120, 15);
        fieldMasaKerja.setBounds(15, 155, 150, 25);

        labelTunjanganJabatan.setBounds(15, 195, 120, 15);
        fieldTunjanganJabatan.setBounds(15, 215, 150, 25);

        labelPotongan.setBounds(15, 255, 120, 15);
        fieldPotongan.setBounds(15, 275, 150, 25);

        buttonHitung.setBounds(15, 315, 100, 25);

        labelGajiPokok.setBounds(195, 15, 120, 15);
        fieldGajiPokok.setBounds(195, 35, 150, 25);

        labelGajiKotor.setBounds(195, 75, 120, 15);
        fieldGajiKotor.setBounds(195, 95, 150, 25);

        labelGajiBersih.setBounds(195, 135, 120, 15);
        fieldGajiBersih.setBounds(195, 155, 150, 25);

        labelPembuat.setBounds(0, 355, 375, 15);
        labelPembuat.setHorizontalAlignment(SwingConstants.CENTER);
        setPreferredSize(new Dimension(375, 425));

        // object set enable/desable
        fieldGajiPokok.setEnabled(false);
        fieldGajiKotor.setEnabled(false);
        fieldGajiBersih.setEnabled(false);

        // style field
        fieldGajiPokok.setDisabledTextColor(Color.BLACK);
        fieldGajiKotor.setDisabledTextColor(Color.BLACK);
        fieldGajiBersih.setDisabledTextColor(Color.BLACK);

        // set object for interaction
        buttonHitung.addActionListener(this);

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

        // add object panel (panelPegawai) to frame container
        getContentPane().add(paneGaji).setBackground(Color.PINK);

        // display frame on monitor
        pack();
    }

    public static void main(String[] args) {
        new A12_2020_06476().setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        if (obj == buttonHitung) {
            int masaKerja = fieldMasaKerja.getText() == "" ? 0 : Integer.parseInt(fieldMasaKerja.getText());
            int tunjanganJabatan = fieldTunjanganJabatan.getText() == "" ? 0 : Integer.parseInt(fieldTunjanganJabatan.getText());
            int potongan = fieldPotongan.getText() == "" ? 0 : Integer.parseInt(fieldPotongan.getText());
            Integer gajiPokok = getGajiPokok(masaKerja);
            Integer gajiKotor = getGajiKotor(gajiPokok, tunjanganJabatan);
            Integer gajiBersih = getGajiBersih(gajiKotor, potongan);

            fieldGajiPokok.setText(gajiPokok.toString());
            fieldGajiKotor.setText(gajiKotor.toString());
            fieldGajiBersih.setText(gajiBersih.toString());
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
        int gajiKotor = gajiPokok + tunjanganJabatan;
        return gajiKotor;
    }

    int getGajiBersih(int gajiKotor, int potongan) {
        int gajiBersih = gajiKotor - potongan;
        return gajiBersih;
    }

}