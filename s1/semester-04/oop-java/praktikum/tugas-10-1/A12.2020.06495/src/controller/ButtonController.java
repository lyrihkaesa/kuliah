package src.controller;

import javax.swing.JButton;

public class ButtonController {

    public JButton[] buttons;

    public ButtonController(JButton... buttons) {
        this.buttons = buttons;
    }

    public void setButtonsEnabled(boolean b) {
        for (int i = 0; i < buttons.length; i++) {
            buttons[i].setEnabled(b);
        }
    }

    public void setButtonsEnabled(int... number) {
        for (int i = 0; i < buttons.length; i++) {
            buttons[i].setEnabled(number[i] >= 1 ? true : false);
        }
    }

}
