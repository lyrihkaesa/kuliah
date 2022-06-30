package src.util;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import javax.swing.JButton;

public class ButtonUtil {

    public Map<String, JButton> map;
    public List<JButton> list;

    public ButtonUtil(Map<String, JButton> buttonMap) {
        this.map = buttonMap;
        this.list = new ArrayList<>(buttonMap.values());
    }

    public void setEnabled(boolean b) {
        for (JButton button : list) {
            button.setEnabled(b);
        }
    }

    public void setEnabled(int... number) {
        for (int i = 0; i < list.size(); i++) {
            list.get(i).setEnabled(number[i] >= 1 ? true : false);
        }
    }

}
