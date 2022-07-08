package src.util;

import javax.swing.table.DefaultTableModel;

public class TableUtil {

    public void clearDataTable(DefaultTableModel tableModel) {
        int row = tableModel.getRowCount();
        for (int i = 0; i < row; i++) {
            tableModel.removeRow(0);
        }
    }

}
