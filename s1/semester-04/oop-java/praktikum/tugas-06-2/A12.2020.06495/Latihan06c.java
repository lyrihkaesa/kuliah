import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Latihan06c extends JFrame implements ActionListener {
    @SuppressWarnings("unused")
    private JPanel jpCalculator = new JPanel();

    private JTextField fLayar = new JTextField();
    private JLabel labelmhs = new JLabel("NIM: A12.2020.06495 | Nama: Kukuh Setya A.");

    private JButton btnTambah = new JButton("+");
    private JButton btnKurang = new JButton("-");
    private JButton btnKali = new JButton("*");
    private JButton btnBagi = new JButton("/");
    private JButton btnTitik = new JButton(".");
    private JButton btnC = new JButton("C");
    private JButton btn1 = new JButton("1");
    private JButton btn2 = new JButton("2");
    private JButton btn3 = new JButton("3");
    private JButton btn4 = new JButton("4");
    private JButton btn5 = new JButton("5");
    private JButton btn6 = new JButton("6");
    private JButton btn7 = new JButton("7");
    private JButton btn8 = new JButton("8");
    private JButton btn9 = new JButton("9");
    private JButton btn0 = new JButton("0");
    private JButton btnSama = new JButton("=");

    private String isiLayar = "";
    private String snilai1, snilai2, tombol;
    private int hasil;
    Font font1 = new Font("SansSerif", Font.BOLD, 24);

    // Atur x, y, lebar, tinggi (x, y, width, height) pada button
    private int yDefault = 120;
    private int xBtn = 50;
    private int yBtn = 50;
    private int widthBtn = 50;
    private int heightBtn = 30;
    private int gab = 20;
    private int widthDimension = (xBtn * 2) + ((gab + widthBtn) * 4);
    private int heightDimension = (yBtn * 2) + ((gab + heightBtn) * 5) + (50 * 2) + gab;

    public Latihan06c() {
        setPreferredSize(new Dimension(widthDimension, heightDimension));
        setTitle("Kalkulator");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        new BorderLayout();
        JDesktopPane jpCalculator = new JDesktopPane();
        add(jpCalculator, BorderLayout.CENTER);

        // Mengatur letak objek Button di container
        yBtn = yDefault;
        yBtn += gab + heightBtn;
        btn7.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btn4.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btn1.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btn0.setBounds(xBtn, yBtn, widthBtn, heightBtn);

        xBtn += gab + widthBtn;
        yBtn = yDefault;
        yBtn += gab + heightBtn;
        btn8.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btn5.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btn2.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btnTitik.setBounds(xBtn, yBtn, widthBtn, heightBtn);

        xBtn += gab + widthBtn;
        yBtn = yDefault;
        yBtn += gab + heightBtn;
        btn9.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btn6.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btn3.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btnSama.setBounds(xBtn, yBtn, widthBtn, heightBtn);

        xBtn += gab + widthBtn;
        yBtn = yDefault;
        btnC.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btnKali.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btnBagi.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btnTambah.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;
        btnKurang.setBounds(xBtn, yBtn, widthBtn, heightBtn);
        yBtn += gab + heightBtn;

        fLayar.setBounds(50, 50, (xBtn + widthBtn - 50), 50);
        fLayar.setFont(font1);
        fLayar.setHorizontalAlignment(JTextField.RIGHT);
        labelmhs.setBounds(50, yBtn, (xBtn + widthBtn - 50), 50);
        labelmhs.setHorizontalAlignment(JTextField.CENTER);

        // Object Button di Nonaktifkan dan diaktifkan
        btnSama.setEnabled(false);
        btnTitik.setEnabled(false);

        // Mengatur objek untuk dapat berinteraksi
        btn1.addActionListener(this);
        btn2.addActionListener(this);
        btn3.addActionListener(this);
        btn4.addActionListener(this);
        btn5.addActionListener(this);
        btn6.addActionListener(this);
        btn7.addActionListener(this);
        btn8.addActionListener(this);
        btn9.addActionListener(this);
        btn0.addActionListener(this);

        btnTambah.addActionListener(this);
        btnKurang.addActionListener(this);
        btnKali.addActionListener(this);
        btnBagi.addActionListener(this);
        btnTitik.addActionListener(this);
        btnC.addActionListener(this);
        btnSama.addActionListener(this);

        // Meletakkan seluruh kontrol pada objek panel
        jpCalculator.add(fLayar);
        jpCalculator.add(labelmhs);
        jpCalculator.add(btn1);
        jpCalculator.add(btn2);
        jpCalculator.add(btn3);
        jpCalculator.add(btn4);
        jpCalculator.add(btn5);
        jpCalculator.add(btn6);
        jpCalculator.add(btn7);
        jpCalculator.add(btn8);
        jpCalculator.add(btn9);
        jpCalculator.add(btn0);

        jpCalculator.add(btnTambah);
        jpCalculator.add(btnKurang);
        jpCalculator.add(btnKali);
        jpCalculator.add(btnBagi);
        jpCalculator.add(btnTitik);
        jpCalculator.add(btnC);
        jpCalculator.add(btnSama);

        // menambahkan objek panel (jpCalculator) ke kontainer frame
        getContentPane().add(jpCalculator).setBackground(Color.getHSBColor(249, 68, 78));

        // menampilkan frame ke layar monitor
        pack();
        setVisible(true);
    }

    public static void main(String[] args) {
        new Latihan06c().setVisible(true);
    }

    public void falseButton() {
        btnTambah.setEnabled(false);
        btnKurang.setEnabled(false);
        btnKali.setEnabled(false);
        btnBagi.setEnabled(false);
    }

    public void trueButton() {
        btnTambah.setEnabled(true);
        btnKurang.setEnabled(true);
        btnKali.setEnabled(true);
        btnBagi.setEnabled(true);
    }

    // Fungsi jika user melakukan action penekanan tombol Button
    public void actionPerformed(ActionEvent ae) {
        Object obj = ae.getSource();

        if (obj == btnC) {
            snilai1 = "";
            snilai2 = "";
            isiLayar = "";
            fLayar.setText(isiLayar);
        }

        if (obj == btn1) {
            isiLayar = isiLayar + "1";
            fLayar.setText(isiLayar);
        }
        if (obj == btn2) {
            isiLayar = isiLayar + "2";
            fLayar.setText(isiLayar);
        }
        if (obj == btn3) {
            isiLayar = isiLayar + "3";
            fLayar.setText(isiLayar);
        }
        if (obj == btn4) {
            isiLayar = isiLayar + "4";
            fLayar.setText(isiLayar);
        }
        if (obj == btn5) {
            isiLayar = isiLayar + "5";
            fLayar.setText(isiLayar);
        }
        if (obj == btn6) {
            isiLayar = isiLayar + "6";
            fLayar.setText(isiLayar);
        }
        if (obj == btn7) {
            isiLayar = isiLayar + "7";
            fLayar.setText(isiLayar);
        }
        if (obj == btn8) {
            isiLayar = isiLayar + "8";
            fLayar.setText(isiLayar);
        }
        if (obj == btn9) {
            isiLayar = isiLayar + "9";
            fLayar.setText(isiLayar);
        }
        if (obj == btn0) {
            isiLayar = isiLayar + "0";
            fLayar.setText(isiLayar);
        }

        if (obj == btnTambah) {
            tombol = "+";
            snilai1 = fLayar.getText();
            isiLayar = "";
            fLayar.setText(isiLayar);
            btnSama.setEnabled(true);
            falseButton();
        }
        if (obj == btnKurang) {
            tombol = "-";
            snilai1 = fLayar.getText();
            isiLayar = "";
            fLayar.setText(isiLayar);
            btnSama.setEnabled(true);
            falseButton();
        }
        if (obj == btnKali) {
            tombol = "*";
            snilai1 = fLayar.getText();
            isiLayar = "";
            fLayar.setText(isiLayar);
            btnSama.setEnabled(true);
            falseButton();
        }
        if (obj == btnBagi) {
            tombol = "/";
            snilai1 = fLayar.getText();
            isiLayar = "";
            fLayar.setText(isiLayar);
            btnSama.setEnabled(true);
            falseButton();
        }
        if (obj == btnTitik) {
            isiLayar = isiLayar + ".";
            fLayar.setText(isiLayar);
        }

        if (obj == btnSama) {
            snilai2 = fLayar.getText();
            // saat ditekan tombol samadengan
            // sebelumnya operator yang digunakan tambah
            switch (tombol) {
            case "+":
                hasil = Integer.parseInt(snilai1) + Integer.parseInt(snilai2);
                break;
            case "-":
                hasil = Integer.parseInt(snilai1) - Integer.parseInt(snilai2);
                break;
            case "*":
                hasil = Integer.parseInt(snilai1) * Integer.parseInt(snilai2);
                break;
            case "/":
                hasil = Integer.parseInt(snilai1) / Integer.parseInt(snilai2);
                break;
            default:
                break;
            }

            String shasil = "" + hasil;
            fLayar.setText(shasil);
            btnSama.setEnabled(false);
            trueButton();
        }
    } // tutup method public void actionPerfomed

    void Kosong() {
        fLayar.setText("");
        fLayar.requestFocus();
    }
}
