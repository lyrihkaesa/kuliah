package src.view;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.Color;
import java.awt.BorderLayout;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JTextArea;
import javax.swing.KeyStroke;

import src.AppConfig;

public class FrameMenu extends JFrame {

    private JTextArea mEditArea = new JTextArea(20, 50);
    @SuppressWarnings("unused")
    private JPanel menuPanel = new JPanel();

    private JPopupMenu mPopupMenu = new JPopupMenu();
    private JLabel nameLabel = new JLabel(AppConfig.FULLNAME_AUTHOR),
            addressLabel = new JLabel(AppConfig.NIM);

    // constructor
    public FrameMenu() {
        setPreferredSize(new Dimension(800, 600));
        setTitle(AppConfig.PROGRAM_TITLE[2]);

        JDesktopPane desktopPane = new JDesktopPane();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        nameLabel.setBounds(15, 20, 400, 50);
        addressLabel.setBounds(15, 55, 200, 25);

        nameLabel.setFont(new Font("Arial", Font.BOLD, 32));
        nameLabel.setForeground(new Color(220, 10, 10));

        addressLabel.setFont(new Font("Verdana", Font.PLAIN, 15));
        addressLabel.setForeground(new Color(10, 10, 220));

        // sub menu (M0) Pegawai.....................................
        JMenuItem M01Pegawai = new JMenuItem("Pegawai");
        M01Pegawai.setMnemonic('P');
        M01Pegawai.setAccelerator(KeyStroke.getKeyStroke("control P"));

        JMenuItem M02Password = new JMenuItem("PaSsword");
        M02Password.setMnemonic('S');
        M02Password.setEnabled(false);
        M02Password.setAccelerator(KeyStroke.getKeyStroke("control S"));

        JMenuItem M03Quit = new JMenuItem("Quit");
        M03Quit.setMnemonic('Q');
        M03Quit.setAccelerator(KeyStroke.getKeyStroke("control Q"));

        // sub menu (M1) Barang.....................................
        JMenuItem M11Barang = new JMenuItem("Barang");
        M11Barang.setMnemonic('B');
        M11Barang.setAccelerator(KeyStroke.getKeyStroke("control B"));

        JMenuItem M12Stok = new JMenuItem("Stock Minim");
        M12Stok.setMnemonic('M');
        M12Stok.setEnabled(false);
        M12Stok.setAccelerator(KeyStroke.getKeyStroke("control M"));

        // sub menu (M2) Transaksi.....................................
        JMenuItem M21Pengadaan = new JMenuItem("PengaDaan");
        M21Pengadaan.setMnemonic('D');
        M21Pengadaan.setEnabled(false);
        M21Pengadaan.setAccelerator(KeyStroke.getKeyStroke("control D"));

        JMenuItem M22Penjualan = new JMenuItem("PenJualan");
        M22Penjualan.setMnemonic('J');
        M22Penjualan.setEnabled(true);
        M22Penjualan.setAccelerator(KeyStroke.getKeyStroke("control J"));

        JMenuItem M23Laporan = new JMenuItem("Laporan");
        M23Laporan.setMnemonic('L');
        M23Laporan.setEnabled(true);
        M23Laporan.setAccelerator(KeyStroke.getKeyStroke("control L"));

        // (2) Build menubar, menus, and add menuitems....................
        JMenuBar menubar = new JMenuBar(); // Create new menu bar.........
        JMenu MenuPegawai = new JMenu("Pegawai"); // Create new menu...
        MenuPegawai.setMnemonic('P');
        menubar.add(MenuPegawai);
        MenuPegawai.add(M01Pegawai);
        MenuPegawai.add(M02Password);
        MenuPegawai.addSeparator();
        MenuPegawai.add(M03Quit);
        JMenu MenuBarang = new JMenu("Barang");
        MenuBarang.setMnemonic('B');
        menubar.add(MenuBarang);
        MenuBarang.add(M11Barang);
        MenuBarang.add(M12Stok);
        JMenu MenuTransaksi = new JMenu("Transaksi");
        MenuTransaksi.setMnemonic('T');
        menubar.add(MenuTransaksi);
        MenuTransaksi.add(M21Pengadaan);
        MenuTransaksi.add(M22Penjualan);
        MenuTransaksi.add(M23Laporan);

        // Siap untuk menjalankan pilihan.....................
        M01Pegawai.addActionListener(new BukaPegawai());
        M03Quit.addActionListener(new QuitAction());
        M11Barang.addActionListener(new BukaBarang());
        M22Penjualan.addActionListener(new BukaJual());
        M23Laporan.addActionListener(new Laporan());

        // Add the (unused) text area to the content pane............
        JPanel content = new JPanel();
        content.setLayout(new BorderLayout());
        content.add(mEditArea, BorderLayout.CENTER);

        // ... Add menu items to popup menu, add popup menu to text area.
        mPopupMenu.add(new JMenuItem("Testing"));
        mEditArea.setComponentPopupMenu(mPopupMenu);

        // ... Set the JFrame's content pane and menu bar.
        setContentPane(content);
        setJMenuBar(menubar);

        desktopPane.add(nameLabel);
        desktopPane.add(addressLabel);
        getContentPane().add(desktopPane).setBackground(Color.getHSBColor(180, 100, 200));

        pack();
        setLocationRelativeTo(null);
    }

    class OpenAction implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            JOptionPane.showMessageDialog(FrameMenu.this, "Can't Open.");
        }
    }

    class BukaPegawai implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            FramePegawai framePegawai = new FramePegawai();
            framePegawai.setVisible(true);

            // ..........................................
            // panggil Form pegawai untuk menjalankan program pegawai !
            // Perintah System.exit(0); pada FPegawai ganti dengan perintah
            // this.dispose();
            // System.exit(0); menjadi this.dispose();
        }
    }

    class BukaBarang implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            FrameBarang frameBarang = new FrameBarang();
            frameBarang.setVisible(true);
        }
    }

    class BukaJual implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            FrameJual frameJual = new FrameJual();
            frameJual.setVisible(true);
        }
    }

    class Laporan implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            FrameCetakBarangMin frameCetakBarangMin = new FrameCetakBarangMin();
            frameCetakBarangMin.setVisible(true);
        }
    }

    class QuitAction implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            System.exit(0); // Terminate the program..........
        }
    }

    // main method................................................
    public static void main(String[] args) {
        JFrame win = new FrameMenu();
        win.setVisible(true);
    }

}
