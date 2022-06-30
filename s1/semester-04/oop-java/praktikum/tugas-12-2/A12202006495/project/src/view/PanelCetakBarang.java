package src.view;

import java.awt.Graphics;
import java.awt.print.PageFormat;
import java.awt.print.Printable;
import java.awt.print.PrinterException;
import java.awt.print.PrinterJob;
import java.util.List;

import javax.swing.JPanel;

import src.AppConfig;
import src.entity.Barang;
import src.repository.BarangRepositoryImpl;

public class PanelCetakBarang extends JPanel {

    public static void main(String[] args) {
        try {
            PrinterJob printerJob = PrinterJob.getPrinterJob();
            printerJob.setJobName("Graphics Demo Printout");
            printerJob.setCopies(1);
            Painter painter = new Painter();
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

    @Override
    public int print(Graphics graphics, PageFormat pageFormat, int pageIndex) throws PrinterException {
        if (pageIndex > 0) {
            return Printable.NO_SUCH_PAGE;
        }

        graphics.drawString("Create by " + AppConfig.AUTHOR, 10, 10);

        BarangRepositoryImpl barangRepositoryImpl = new BarangRepositoryImpl();
        List<Barang> listBarang = barangRepositoryImpl.selectAll();

        graphics.drawString("Laporan Barang", 50, 100);
        graphics.drawString("CV. Mekar Indah", 50, 130);
        graphics.drawLine(50, 140, 500, 140);
        graphics.drawString("No.", 50, 155);
        graphics.drawString("Kode", 80, 155);
        graphics.drawString("Nama", 150, 155);
        graphics.drawString("Harga", 300, 155);
        graphics.drawString("Harga", 320, 155);
        graphics.drawLine(50, 165, 500, 165);
        int i1 = 50, x1 = 190, y1 = 1;

        for (Barang barang : listBarang) {
            graphics.drawString(" " + i1 + ".", 50, y1);
            graphics.drawString(barang.getId(), 80, y1);
            graphics.drawString(barang.getName(), 150, y1);
            graphics.drawString(barang.getPurchasePrice().toString(), 300, y1);
            graphics.drawString(barang.getSellingPrice().toString(), 450, y1);
            y1 += 14;
            i1++;
        }

        graphics.drawLine(x1, y1, 500, y1);

        return Printable.PAGE_EXISTS;
    }

}