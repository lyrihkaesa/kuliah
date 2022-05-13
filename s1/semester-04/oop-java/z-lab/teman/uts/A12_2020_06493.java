import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class A12_2020_06493 extends JFrame implements ActionListener {
    @SuppressWarnings("unused")
    private JPanel panelBarang = new JPanel();

    // Label
    private JLabel labelKodeBarang = new JLabel("Kode Barang"),
            labelNamaBarang = new JLabel("Nama Barang"),
            labelJumlahBarang = new JLabel("Jumlah Barang"),
            labelHargaBarang = new JLabel("Harga Harga"),
            labelTotalHarga = new JLabel("Total Barang"),
            labelBayarKotor = new JLabel("Total Bayar Kotor"),
            labelPotongan = new JLabel("Potongan"),
            labelBayarBersih = new JLabel("Total Bayar Bersih"),
            labelPembuat = new JLabel("Angelia Merici Muku | A12.2020.06493");

    // Text Field
    private JTextField fieldKodeBarang = new JTextField(),
            fieldNamaBarang = new JTextField(),
            fieldJumlahBarang = new JTextField(),
            fieldHargaBarang = new JTextField(),
            fieldTotalHarga = new JTextField(),
            fieldBayarKotor = new JTextField(),
            fieldPotongan = new JTextField(),
            fieldBayarBersih = new JTextField();

    // Button
    private JButton buttonHitung = new JButton("Hitung");

    public A12_2020_06493() {
        // set container
        setTitle("Program Penjualan Barang");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane paneBarang = new JDesktopPane();

        // set object posisiton on container
        labelKodeBarang.setBounds(15, 15, 120, 15);
        fieldKodeBarang.setBounds(15, 35, 150, 25);

        labelNamaBarang.setBounds(15, 75, 120, 15);
        fieldNamaBarang.setBounds(15, 95, 150, 25);

        labelJumlahBarang.setBounds(15, 135, 120, 15);
        fieldJumlahBarang.setBounds(15, 155, 150, 25);

        labelHargaBarang.setBounds(15, 195, 120, 15);
        fieldHargaBarang.setBounds(15, 215, 150, 25);

        labelPotongan.setBounds(15, 255, 120, 15);
        fieldPotongan.setBounds(15, 275, 150, 25);

        buttonHitung.setBounds(15, 315, 100, 25);

        labelTotalHarga.setBounds(195, 15, 120, 15);
        fieldTotalHarga.setBounds(195, 35, 150, 25);

        labelBayarKotor.setBounds(195, 75, 120, 15);
        fieldBayarKotor.setBounds(195, 95, 150, 25);

        labelBayarBersih.setBounds(195, 135, 120, 15);
        fieldBayarBersih.setBounds(195, 155, 150, 25);

        labelPembuat.setBounds(0, 355, 375, 15);
        labelPembuat.setHorizontalAlignment(SwingConstants.CENTER);
        setPreferredSize(new Dimension(375, 425));

        // object set enable/desable
        fieldTotalHarga.setEnabled(false);
        fieldBayarKotor.setEnabled(false);
        fieldBayarBersih.setEnabled(false);

        // style field
        fieldTotalHarga.setDisabledTextColor(Color.BLACK);
        fieldBayarKotor.setDisabledTextColor(Color.BLACK);
        fieldBayarBersih.setDisabledTextColor(Color.BLACK);

        // set object for interaction
        buttonHitung.addActionListener(this);

        // put all control on object panel
        paneBarang.add(labelKodeBarang);
        paneBarang.add(labelNamaBarang);
        paneBarang.add(labelJumlahBarang);
        paneBarang.add(labelTotalHarga);
        paneBarang.add(labelHargaBarang);
        paneBarang.add(labelBayarKotor);
        paneBarang.add(labelPotongan);
        paneBarang.add(labelBayarBersih);
        paneBarang.add(labelPembuat);

        paneBarang.add(fieldKodeBarang);
        paneBarang.add(fieldNamaBarang);
        paneBarang.add(fieldJumlahBarang);
        paneBarang.add(fieldTotalHarga);
        paneBarang.add(fieldHargaBarang);
        paneBarang.add(fieldBayarKotor);
        paneBarang.add(fieldPotongan);
        paneBarang.add(fieldBayarBersih);
        paneBarang.add(buttonHitung);

        // add object panel (panelPegawai) to frame container
        getContentPane().add(paneBarang).setBackground(Color.PINK);

        // display frame on monitor
        pack();
    }

    public static void main(String[] args) {
        new A12_2020_06493().setVisible(true);
    }

    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        if (obj == buttonHitung) {
            int jumlahBarang = Integer.parseInt(fieldJumlahBarang.getText());
            int hargaBarang = Integer.parseInt(fieldHargaBarang.getText());
            int potongan = Integer.parseInt(fieldPotongan.getText());

            Integer totalHarga = getTotalHarga(jumlahBarang, hargaBarang);
            Double totalBayarKotor = getTotalBayarKotor(totalHarga);
            Integer totalBayarBersih = getTotalBayarBersih(totalBayarKotor, potongan);

            fieldTotalHarga.setText(totalHarga.toString());
            fieldBayarKotor.setText(totalBayarKotor.toString());
            fieldBayarBersih.setText(totalBayarBersih.toString());

        }
    }

    int getTotalHarga(int jumlahBarang, int hargaBarang) {
        int totalHarga = 0;
        totalHarga = jumlahBarang * hargaBarang;
        return totalHarga;
    }

    Double getTotalBayarKotor(int totalHarga) {
        Double totalBayarKotor = 0.0;
        if (totalHarga >= 1000000) {
            totalBayarKotor = 0.3 * totalHarga;
        } else if (totalHarga < 1000000 && totalHarga >= 700000) {
            totalBayarKotor = 0.2 * totalHarga;
        } else if (totalHarga < 700000) {
            totalBayarKotor = (double) totalHarga;
        }
        return totalBayarKotor;
    }

    int getTotalBayarBersih(Double totalBayarKotor, int potongan) {
        int totalBayarBersih = 0;
        totalBayarBersih = (int) (totalBayarKotor - potongan);
        return totalBayarBersih;
    }

}