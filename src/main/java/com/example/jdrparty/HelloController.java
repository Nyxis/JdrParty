package com.example.jdrparty;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
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



    private int callCppApplication(String criticalRate, String failureRate, String fumbleRate) {
        int exitVal = -1;
        try {
            System.out.print(criticalRate);
            System.out.print(failureRate);
            System.out.print(fumbleRate);
            ProcessBuilder processBuilder = new ProcessBuilder();
            processBuilder.command("src/main/resources/CPP/JdrPartyCPP/cmake-build-debug/JdrParty", criticalRate, failureRate, fumbleRate);
            processBuilder.redirectErrorStream(true);
            Process process = processBuilder.start();

            // Reading error output
            BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            String errorLine;
            while ((errorLine = errorReader.readLine()) != null) {
                System.err.println(errorLine); // Print error lines
            }

            // Reading standard output
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line); // Print standard output lines
            }

            // Wait for the process to finish
            exitVal = process.waitFor();
            System.out.println("Exited with error code " + exitVal);
        } catch (Exception e) {
            System.out.println(e.toString());
            e.printStackTrace();
        }
        return exitVal;
    }


    @FXML
    protected void onBowButtonClick() {
        System.out.println("Bow Attack");
        // Add code here to execute when "Bow Attack" button is clicked
        int exitVal = callCppApplication("0.1", "O.5", "0.05");

    }

    @FXML
    protected void onSwordButtonClick() {
        System.out.println("Sword Attack");
        // Add code here to execute when "Sword Attack" button is clicked
        int exitVal = callCppApplication("0.20", "0.25", "0.15");
    }

    @FXML
    protected void onFistButtonClick() {
        System.out.println("Fist Attack");
        // Add code here to execute when "Fist Attack" button is clicked
        int exitVal = callCppApplication("0", "0.6", "0");
    }

    @FXML
    protected void onFireButtonClick() {
        System.out.println("Fire button clicked!");
        int exitVal = callCppApplication("0.5", "0", "0.5");
    }
}



