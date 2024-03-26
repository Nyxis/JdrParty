package com.example.mjcpp;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import java.io.*;
import javafx.scene.control.Button;

public class HelloController {
    @FXML
    private Label welcomeText;

    @FXML
    private Button button;

    @FXML
    protected void onBowButtonClick() {
        try {
            System.out.println("Succes : 0.45  fumble : 0.05 critique : 0.9");
            Runtime rt = Runtime.getRuntime();
            //Process pr = rt.exec("ls / >fichier.txt");

            //Process pr = rt.exec("/System/Users/admin/Desktop/TP_Cpp/cmake-build-debug/TP_Cpp");
            Process pr = rt.exec("/Users/admin/Desktop/Spring/MJCPP/src/main/resources/com/example/cpp/TP_Cpp");
            int exitVal = pr.waitFor();
            System.out.println("Exited with error code "+exitVal);
            button.getStyleClass().remove("button-normal");
                button.getStyleClass().remove("button-gold");
                button.getStyleClass().remove("button-green");
                button.getStyleClass().remove("button-red");
                button.getStyleClass().remove("button-black");

            switch(exitVal) {
                case 1:
                    button.getStyleClass().add("button-gold");
                    break;
                case 2:
                    button.getStyleClass().add("button-green");
                    break;
                case 3:
                    button.getStyleClass().add("button-red");
                    break;
                case 4:
                    button.getStyleClass().add("button-black");
                    break;
                default:
                    break;
            }
        } catch(Exception e) {
            System.out.println(e.toString());
            e.printStackTrace();
        }

    }
    @FXML
    protected void onSwordButtonClick() {
        try {
            System.out.println("Succes : 0.25  fumble : 0.2 critique : 0.85");
            Runtime rt = Runtime.getRuntime();
            Process pr = rt.exec("ls");
        } catch(Exception e){
            System.out.println(e.toString());
            e.printStackTrace();
        }

    }
    @FXML
    protected void onFistButtonClick() {
        try{
            System.out.println("Succes : 0.60  fumble : 0 critique : 1");
            ProcessBuilder processBuilder = new ProcessBuilder();
            //For Charbo
            //processBuilder.command("/Users/admin/Desktop/Spring/MJCPP/src/main/resources/com/example/cpp/TP_Cpp", "0", "60", "100");
            //For @home
            processBuilder.command("C:/Users/ZhL10/Desktop/JdrParty/cpp/cmake-build-debug/TP_Cpp.exe", "0.0", "0.60", "1.00");
            Process process = processBuilder.start();
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            int exitVal = process.waitFor();
            System.out.println("Exited with error code "+exitVal);
            switch(exitVal) {
                case 0:
                    break;
                case 1:

            }
            }
        } catch(Exception e)
        {
            System.out.println(e.toString());
            e.printStackTrace();
        }

    }

    @FXML
    protected void onFireButtonClick() {
        System.out.println("Succes : -1  fumble : 0.5 critique : 0.5");
    }
}