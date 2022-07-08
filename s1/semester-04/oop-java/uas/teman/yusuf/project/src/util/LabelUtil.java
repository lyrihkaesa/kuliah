package src.util;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import javax.swing.JLabel;

public class LabelUtil {
    public Map<String, JLabel> map;
    public List<JLabel> list;

    public LabelUtil(Map<String, JLabel> labelMap) {
        this.map = labelMap;
        this.list = new ArrayList<>(labelMap.values());
    }

}
