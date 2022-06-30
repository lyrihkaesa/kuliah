package src.service;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.awt.Graphics;
import java.awt.print.PageFormat;
import java.awt.print.Printable;
import java.awt.print.PrinterException;
import java.awt.print.PrinterJob;
import java.util.List;

import javax.swing.JButton;
import javax.swing.JFrame;

import src.AppConfig;
import src.entity.Barang;
import src.repository.BarangRepositoryImpl;
import src.util.FieldUtil;

public class CetakBarangServiceImpl implements ActionListener {

    @SuppressWarnings("unused")
    private JFrame mainFrame;
    private JButton targetButton;
    private FieldUtil fieldUtil;

    public CetakBarangServiceImpl(JFrame mainFrame, JButton targetButton, FieldUtil fieldUtil) {
        this.mainFrame = mainFrame;
        this.targetButton = targetButton;
        this.fieldUtil = fieldUtil;
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        Object object = actionEvent.getSource();
        if (object == targetButton) {
            cetakBarangMinimal();
        }

    }

    void cetakBarangMinimal() {
        try {
            PrinterJob printerJob = PrinterJob.getPrinterJob();
            printerJob.setJobName("Graphics Demo Printout");
            printerJob.setCopies(1);
            Painter painter = new Painter(fieldUtil);
            printerJob.setPrintable(painter);

            if (printerJob.printDialog() == false) {
                return;
            }
            printerJob.print();
        } catch (PrinterException printerException) {
            printerException.printStackTrace();
        }
    }
}

class Painter implements Printable {
    private FieldUtil fieldUtil;

    public Painter(FieldUtil fieldUtil) {
        this.fieldUtil = fieldUtil;
    }

    @Override
    public int print(Graphics graphics, PageFormat pageFormat, int pageIndex) throws PrinterException {
        if (pageIndex > 0) {
            return Printable.NO_SUCH_PAGE;
        }

        graphics.drawString("Create by " + AppConfig.AUTHOR, 10, 10);
        // cetak data....................................
        try {
            // Koneksi ke table barang..................
            BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
            List<Barang> listBarang = barangRepositoryImpl.selectAllByAmount(Integer.parseInt(fieldUtil.map.get("amount").getText()));

            int i1, x1, y1;

            // Header
            graphics.drawString("Laporan Barang", 50, 100);
            graphics.drawString("CV. Mekar Indah", 50, 130);
            graphics.drawLine(50, 140, 450, 140);
            graphics.drawString("No.", 50, 155);
            graphics.drawString("Kode", 80, 155);
            graphics.drawString("Nama", 150, 155);
            graphics.drawString("Harga", 295, 155);
            graphics.drawString("Jumlah", 450, 155);
            graphics.drawLine(50, 160, 450, 160);
            x1 = 50;
            y1 = 190;
            i1 = 1;

            // Cetak Record Barang.................

            for (Barang barang : listBarang) {
                graphics.drawString(" " + i1 + ".", 50, y1);
                graphics.drawString(barang.getId(), 80, y1);
                graphics.drawString(barang.getName(), 150, y1);
                graphics.drawString(barang.getSellingPrice().toString(), 300, y1);
                graphics.drawString(barang.getAmount().toString(), 450, y1);
                y1 += 14;
                i1++;
            }

            graphics.drawLine(x1, y1, 450, y1);

        } catch (Exception e) {
            System.out.println("Ada Kesalahan !");
        }

        return Printable.PAGE_EXISTS;
    }

}
