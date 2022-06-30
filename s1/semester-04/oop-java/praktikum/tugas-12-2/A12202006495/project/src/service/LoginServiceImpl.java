package src.service;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;

import src.AppConfig;
import src.entity.Pegawai;
import src.repository.PegawaiRepositoryImpl;
import src.util.ButtonUtil;
import src.util.FieldUtil;
import src.view.FrameMenu;

public class LoginServiceImpl implements ActionListener, FocusListener {

    private JFrame mainFrame;
    private FieldUtil fieldUtil;
    private ButtonUtil buttonUtil;

    public LoginServiceImpl(JFrame mainFrame, FieldUtil fieldUtil, ButtonUtil buttonUtil) {
        this.mainFrame = mainFrame;
        this.fieldUtil = fieldUtil;
        this.buttonUtil = buttonUtil;
    }

    @Override
    public void focusGained(FocusEvent e) {
    }

    @Override
    public void focusLost(FocusEvent focusEvent) {
        Object object = focusEvent.getSource();
        var nipField = fieldUtil.map.get("nip");
        var passwordField = fieldUtil.map.get("password");
        if (object == nipField) {
            if (!nipField.getText().isBlank()) {
                if (findPegawaiByNip(nipField.getText())) {
                    passwordField.requestFocus();
                } else {
                    nipField.requestFocus();
                }
            } else {
                nipField.requestFocus();
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
        Object object = actionEvent.getSource();
        if (object == buttonUtil.map.get("login")) {

            if (checkPassword(AppConfig.pegawai)) {
                mainFrame.dispose();
                FrameMenu frameMenu = new FrameMenu();
                frameMenu.setVisible(true);
            } else {
                fieldUtil.map.get("password").requestFocus();
            }
        }
    }

    boolean findPegawaiByNip(String nip) {
        PegawaiRepositoryImpl pegawaiRepositoryImpl = new PegawaiRepositoryImpl();
        Pegawai pegawai = pegawaiRepositoryImpl.selectByNip(nip);

        if (pegawai.getName() != null) {
            fieldUtil.map.get("name").setText(pegawai.getName());
            AppConfig.pegawai = pegawai;
            return true;
        } else {
            fieldUtil.setBlank();
            JOptionPane.showMessageDialog(mainFrame, "NIP " + nip + " tidak ditemukan!");
            fieldUtil.map.get("nip").requestFocus();
            return false;
        }
    }

    boolean checkPassword(Pegawai pegawai) {
        JPasswordField passwordField = (JPasswordField) fieldUtil.map.get("password");
        String password = String.valueOf(passwordField.getPassword());
        if (pegawai.getPassword().equals(password)) {
            return true;
        } else {
            JOptionPane.showMessageDialog(mainFrame, "Password salah!");
            return false;
        }
    }

}
