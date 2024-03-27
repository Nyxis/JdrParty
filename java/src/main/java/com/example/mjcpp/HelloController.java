package com.example.mjcpp;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import java.io.*;
import javafx.scene.control.Button;

public class HelloController {

    @FXML
    private Button bowButton;

    @FXML
    private Button swordButton;

    @FXML
    private Button fistButton;

    @FXML
    private Button fireballButton;

    private void changeButtonColor(int exVal, Button button){
        try{
            button.getStyleClass().remove("button-normal");
            button.getStyleClass().remove("button-gold");
            button.getStyleClass().remove("button-green");
            button.getStyleClass().remove("button-red");
            button.getStyleClass().remove("button-black");
        } catch (Exception e){
            System.out.println(e.toString());
            e.printStackTrace();
        }

    switch(exVal)
    {
        case 4:
            System.out.println("Gold");
            button.getStyleClass().add("button-gold");
            break;
        case 3:
            System.out.println("Green");
            button.getStyleClass().add("button-green");
            break;
        case 2:
            System.out.println("Red");
            button.getStyleClass().add("button-red");
            break;
        case 1:
            System.out.println("Black");
            button.getStyleClass().add("button-black");
            break;
        default:
            break;
    }

}

private int launchCpp(String ech, String suc, String crit){
        int exitVal = -1;
        try {
            ProcessBuilder processBuilder = new ProcessBuilder();
            //For Charbo
            processBuilder.command("/Users/admin/Desktop/jdrParty/cpp/cmake-build-debug/TP_Cpp", ech, suc, crit);
            //For @home
            //processBuilder.command("C:/Users/ZhL10/Desktop/JdrParty/cpp/cmake-build-debug/TP_Cpp.exe", "0.0", "0.60", "1.00");
            Process process = processBuilder.start();
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }
            exitVal = process.waitFor();
            System.out.println("Exited with error code "+exitVal);

        } catch(Exception e){
            System.out.println(e.toString());
            e.printStackTrace();
        }
    return exitVal;
}
    @FXML
    protected void onBowButtonClick() {
        int exitVal = launchCpp("0.05", "0.45", "0.55");
        changeButtonColor(exitVal, bowButton);
    }
    @FXML
    protected void onSwordButtonClick() {
        int exitVal = launchCpp("0.15", "0.25", "0.45");
        changeButtonColor(exitVal, swordButton);
    }
    @FXML
    protected void onFistButtonClick() {
        int exitVal = launchCpp("0", "0.6", "1");
        changeButtonColor(exitVal, fistButton);
    }

    @FXML
    protected void onFireButtonClick() {
        int exitVal = launchCpp( "0.5", "-1", "0.5");
        changeButtonColor(exitVal, fireballButton);
    }


}