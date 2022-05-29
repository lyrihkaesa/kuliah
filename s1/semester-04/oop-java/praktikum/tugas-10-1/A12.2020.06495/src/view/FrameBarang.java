package src.view;

import java.awt.Color;
import java.awt.Dimension;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import java.util.ArrayList;
import java.util.List;

import javax.swing.JFrame;

import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;

import javax.swing.JDesktopPane;

import javax.swing.JTable;
import javax.swing.JScrollPane;

import javax.swing.table.DefaultTableModel;

import src.ProgramConfig;
import src.controller.ButtonController;
import src.controller.FieldController;

import src.controller.AddController;
import src.controller.SearchController;
import src.controller.UpdateController;
import src.controller.DeleteController;
import src.controller.ExitController;

import src.controller.TableController;

public class FrameBarang extends JFrame {
    // @SuppressWarnings("unused")
    // private JPanel pPgw = new JPanel();

    private JLabel idLabel = new JLabel("Kode Barang"),
            nameLabel = new JLabel("Nama Barang"),
            sellingPriceLabel = new JLabel("Harga Jual"),
            purchasePriceLabel = new JLabel("Harga Beli"),
            amountLabel = new JLabel("Jumlah");

    String[] header = { "Kode", "Nama", "Harga Jual", "Harga Beli", "Jumlah" };

    private JTextField idField = new JTextField(),
            nameField = new JTextField(),
            sellingPriceField = new JTextField(),
            purchasePriceField = new JTextField(),
            amountField = new JTextField();
    FieldController fieldController = new FieldController(
            idField,
            nameField,
            sellingPriceField,
            purchasePriceField,
            amountField);

    private JButton addButton = new JButton("Tambah"),
            searchButton = new JButton("Cari"),
            updateButton = new JButton("Koreksi"),
            deleteButton = new JButton("Hapus"),
            exitButton = new JButton("Keluar");
    ButtonController buttonController = new ButtonController(
            addButton,
            searchButton,
            updateButton,
            deleteButton,
            exitButton);

    public FrameBarang() {
        setPreferredSize(new Dimension(670, 510));
        setTitle(ProgramConfig.PROGRAM_TITLE[1]);

        // setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JDesktopPane desktopPane = new JDesktopPane();

        List<JLabel> listLabel = new ArrayList<>();
        listLabel.add(idLabel);
        listLabel.add(nameLabel);
        listLabel.add(sellingPriceLabel);
        listLabel.add(purchasePriceLabel);
        listLabel.add(amountLabel);

        // X, Y, Width, Height
        int defaultX = 20;
        int defaultY = 20;

        int labelWidth = 100;
        int labelHeight = 25;

        int gap = 10 + labelHeight;
        int xField = defaultX + labelWidth + gap;

        int buttonWidth = 85;
        int buttonHeight = 25;
        int gapButton = 10;
        int yButton = 0;

        for (int i = 0; i < listLabel.size(); i++) {
            if (i == 0) {
                listLabel.get(i).setBounds(defaultX, defaultY, labelWidth, labelHeight);
                fieldController.fields[i].setBounds(xField, defaultY, labelWidth, labelHeight);
            } else {
                int y = listLabel.get(i - 1).getY() + gap;
                listLabel.get(i).setBounds(defaultX, y, labelWidth, labelHeight);
                fieldController.fields[i].setBounds(xField, y, i == 1 ? labelWidth + 100 : labelWidth, labelHeight);
            }
        }

        idField.setToolTipText("Isi Kode dengan Angka!");

        // membuat tabel.......................................
        DefaultTableModel tableModel = new DefaultTableModel(null, header);
        JTable tabel = new JTable();
        tabel.setModel(tableModel);
        tabel.setBackground(Color.ORANGE);
        tabel.setEnabled(false);

        JScrollPane scrollPaneTable = new JScrollPane();
        scrollPaneTable.getViewport().add(tabel);
        scrollPaneTable.setBounds(defaultX, amountLabel.getY() + gap, 500, 170);

        yButton = scrollPaneTable.getY() + gapButton + scrollPaneTable.getHeight();

        for (int i = 0; i < buttonController.buttons.length; i++) {
            if (i == 0) {
                buttonController.buttons[i].setBounds(defaultX, yButton, buttonWidth, buttonHeight);
            } else {
                int xButton = defaultX + buttonController.buttons[i - 1].getX() + buttonWidth + gapButton;
                buttonController.buttons[i].setBounds(xButton, yButton, buttonWidth, buttonHeight);
            }
        }

        exitButton.setToolTipText("Mengakhiri Program");

        addButton.setBackground(Color.green);
        addButton.setForeground(Color.getHSBColor(250, 0, 255));

        /* Objek Button di Non Aktifkan dan di aktifkan */
        addButton.setEnabled(true);
        exitButton.setEnabled(true);

        // Mengatur objek untuk dapat berinteraksi
        TableController tableController = new TableController(this, tableModel);
        addButton.addActionListener(new AddController(this, addButton, fieldController, buttonController, tableController));
        searchButton.addActionListener(new SearchController(this, searchButton, fieldController, buttonController, tableController));
        updateButton.addActionListener(new UpdateController(this, updateButton, fieldController, buttonController, tableController));
        deleteButton.addActionListener(new DeleteController(this, deleteButton, fieldController, buttonController, tableController));
        exitButton.addActionListener(new ExitController(this));

        // Meletakkan seluruh kontrol pada objek panel */

        for (int i = 0; i < listLabel.size(); i++) {
            desktopPane.add(listLabel.get(i));
        }

        for (int i = 0; i < fieldController.fields.length; i++) {
            desktopPane.add(fieldController.fields[i]);
        }

        for (int i = 0; i < buttonController.buttons.length; i++) {
            desktopPane.add(buttonController.buttons[i]);
        }

        desktopPane.add(scrollPaneTable);

        getContentPane().add(desktopPane).setBackground(Color.PINK);

        pack();
        setLocationRelativeTo(null);
        tableController.updateDataTable();
        fieldController.setFieldsEmpty();
        fieldController.setFieldsEnabled(false);

        // setting setelah di tekan enter kursor dari Nip menuju ke masukan Nama
        idField.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                nameField.requestFocus();
            }
        });

        // setting setelah di tekan enter kursor dari Nama menuju ke masukan Bagian
        nameField.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                sellingPriceField.requestFocus();
            }
        });

        // setting setelah di tekan enter kursor dari Bagian menuju ke masukan Jenis
        // Kelamin
        sellingPriceField.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                purchasePriceField.requestFocus();
            }
        });

        // setting setelah di tekan enter kursor dari Jenis Kelamin menuju ke masukan
        // Password
        purchasePriceField.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                amountField.requestFocus();
            }
        });

        // setting setelah di tekan enter kursor dari Jenis Kelamin menuju ke masukan
        // Password
        amountField.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                addButton.requestFocus();
            }
        });

    }

    public static void main(String[] args) {
        new FrameBarang().setVisible(true);
    }
}