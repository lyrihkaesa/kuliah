package src.util;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import javax.swing.JTextField;

public class FieldUtil {

    public Map<String, JTextField> map;
    public List<JTextField> list;

    public FieldUtil(Map<String, JTextField> fieldMap) {
        this.map = fieldMap;
        this.list = new ArrayList<>(fieldMap.values());
    }

    public void setEnabled(boolean b) {
        for (JTextField textField : list) {
            textField.setEnabled(b);
        }
    }

    public void setEnabled(int... number) {
        for (int i = 0; i < list.size(); i++) {
            list.get(i).setEnabled(number[i] >= 1 ? true : false);
        }
    }

    public void setBlank() {
        for (JTextField textField : list) {
            textField.setText("");
        }
    }
}
