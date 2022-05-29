package src.controller;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JFrame;

public class ExitController implements ActionListener {

    private JFrame jFrame;

    public ExitController(JFrame jFrame) {
        this.jFrame = jFrame;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // System.exit(0);
        jFrame.dispose();
    }

}
