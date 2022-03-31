import javax.swing.JOptionPane;

public class BelajarSwing {
    public static void main(String[] args) {
        String name = JOptionPane.showInputDialog("Masukan nama: ");
        JOptionPane.showMessageDialog(null, "Nama Anda " + name);
    }
}
