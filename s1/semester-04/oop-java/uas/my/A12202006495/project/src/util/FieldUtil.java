package src.util;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import javax.swing.JTextField;

import src.AppConfig;

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
            textField.setBackground(b ? AppConfig.MyColor.GREY900 : AppConfig.MyColor.GREY700);
        }
    }

    public void setEnabled(int... number) {
        for (int i = 0; i < list.size(); i++) {
            list.get(i).setEnabled(number[i] >= 1 ? true : false);
            list.get(i).setBackground(number[i] >= 1 ? AppConfig.MyColor.GREY900 : AppConfig.MyColor.GREY700);
        }
    }

    public void setBlank() {
        for (JTextField textField : list) {
            textField.setText("");
        }
    }
}
