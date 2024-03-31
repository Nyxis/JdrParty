package com.example.jdrparty;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class HelloController {

    @FXML
    private Button bowButton;

    @FXML
    private Button swordButton;

    @FXML
    private Button fistButton;

    @FXML
    private Button fireballButton;

    @FXML
    private Label welcomeText;

    // Method to call the C++ application with given parameters and update button style
    private void callCppApplication(String criticalRate, String failureRate, String fumbleRate, Button button) {
        try {
            // Create a process builder for executing the C++ application
            ProcessBuilder processBuilder = new ProcessBuilder();
            processBuilder.command("src/main/resources/CPP/JdrPartyCPP/cmake-build-debug/JdrParty", criticalRate, failureRate, fumbleRate);
            processBuilder.redirectErrorStream(true);
            Process process = processBuilder.start();

            // Read error output from the process
            BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
            String errorLine;
            while ((errorLine = errorReader.readLine()) != null) {
                System.err.println(errorLine);
            }

            // Read standard output from the process
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
            }

            // Wait for the process to finish and get the exit value
            int exitVal = process.waitFor();

            // Update button style and text based on the exit value
            updateButtonStyleAndText(exitVal, button);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    // Method to update button style and text based on the exit value
    private void updateButtonStyleAndText(int exitVal, Button button) {
        String resultText;
        String style;
        switch (exitVal) {
            case 0:
                resultText = "Success";
                style = "-fx-background-color: green;";
                break;
            case 1:
                resultText = "Failure";
                style = "-fx-background-color: red;";
                break;
            case 2:
                resultText = "Fumble";
                style = "-fx-background-color: black;";
                break;
            default:
                resultText = "Unknown";
                style = "-fx-background-color: gray;";
                break;
        }

        // Set the result text and style for the welcome label
        welcomeText.setText(resultText);
        welcomeText.setStyle(style + "-fx-font-size: 20px; -fx-text-fill: white;");

        // Set the button style and text fill
        button.setStyle(style);
        button.setTextFill(javafx.scene.paint.Color.WHITE);
    }

    // Event handler for Bow button click
    @FXML
    protected void onBowButtonClick(ActionEvent event) {
        callCppApplication("0.1", "0.5", "0.05", bowButton);
    }

    // Event handler for Sword button click
    @FXML
    protected void onSwordButtonClick(ActionEvent event) {
        callCppApplication("0.20", "0.25", "0.15", swordButton);
    }

    // Event handler for Fist button click
    @FXML
    protected void onFistButtonClick(ActionEvent event) {
        callCppApplication("0", "0.6", "0", fistButton);
    }

    // Event handler for Fire button click
    @FXML
    protected void onFireButtonClick(ActionEvent event) {
        callCppApplication("0.5", "0", "0.5", fireballButton);
    }
}







