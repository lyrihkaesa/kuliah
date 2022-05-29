package src.controller;

import javax.swing.JTextField;

public class FieldController {

    public JTextField[] fields;

    public FieldController(JTextField... fields) {
        this.fields = fields;
    }

    public void setFieldsEnabled(boolean b) {
        for (int i = 0; i < fields.length; i++) {
            fields[i].setEnabled(b);
        }
    }

    public void setFieldsEnabled(int... number) {
        for (int i = 0; i < fields.length; i++) {
            fields[i].setEnabled(number[i] >= 1 ? true : false);
        }
    }

    public void setFieldsEmpty() {
        for (int i = 0; i < fields.length; i++) {
            fields[i].setText("");
        }
        fields[0].requestFocus();
    }
}
