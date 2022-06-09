package src.util;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;

public class ExitUtil implements ActionListener {

    public JFrame mainFrame;

    public ExitUtil(JFrame mainFrame) {
        this.mainFrame = mainFrame;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // System.exit(0);
        mainFrame.dispose();

    }

}
