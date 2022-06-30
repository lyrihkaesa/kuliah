package src;

import src.view.FrameLogin;
// import src.view.FrameMenu;

public class App {

    public static void main(String[] args) {
        String appProp = "application.properties";
        try {
            appProp = args[0];
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("File default " + appProp);
        }

        AppConfig.properties = AppConfig.configProp(appProp);

        AppConfig.NIM = AppConfig.properties.getProperty("author.nim");
        AppConfig.FULLNAME_AUTHOR = AppConfig.properties.getProperty("author.fullname");
        AppConfig.AUTHOR = AppConfig.NIM + "-" + AppConfig.FULLNAME_AUTHOR;

        for (int i = 0; i < AppConfig.PROGRAM_TITLE.length; i++) {
            AppConfig.PROGRAM_TITLE[i] = AppConfig.PROGRAM_TITLE[i] + " | " + AppConfig.AUTHOR;
        }

        // FrameMenu app = new FrameMenu();
        // app.setVisible(true);

        FrameLogin app = new FrameLogin();
        app.setVisible(true);
    }
}
