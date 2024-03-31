package com.example.jdrparty;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

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
    private void handleButtonAction(ActionEvent event) {
        Button button = (Button) event.getSource();
        String action = button.getText();
        switch (action) {
            case "Bow Attack":
                // Action for "Bow Attack" button
                callCppApplication("10%", "45%", "5%");
                break;
            case "Sword Attack":
                // Action for "Sword Attack" button
                callCppApplication("20%", "25%", "15%");
                break;
            case "Fist Attack":
                // Action for "Fist Attack" button
                callCppApplication("0%", "60%", "0%");
                break;
            case "Fireball":
                // Action for "Fireball" button
                callCppApplication("50%", "0%", "50%");
                break;
            default:
                break;
        }
    }

    private void callCppApplication(String criticalRate, String failureRate, String fumbleRate) {
        try {
            // Chemin d'accès vers l'exécutable C++
            String cppExecutablePath = "src/main/resources/CPP/JdrExo/cmake-build-debug/JdrExo";

            // Création de la commande à exécuter avec les arguments
            List<String> command = new ArrayList<>();
            command.add(cppExecutablePath);
            command.add(criticalRate);
            command.add(failureRate);
            command.add(fumbleRate);

            // Création du processus
            ProcessBuilder pb = new ProcessBuilder(command);
            pb.inheritIO(); // Redirection de l'entrée et de la sortie standard du processus
            Process process = pb.start();

            // Attendre la fin de l'exécution du processus
            process.waitFor();
        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
    }


    @FXML
    protected void onBowButtonClick(ActionEvent event) {
        System.out.println("Bow Attack");
        // Add code here to execute when "Bow Attack" button is clicked
    }

    @FXML
    protected void onSwordButtonClick(ActionEvent event) {
        System.out.println("Sword Attack");
        // Add code here to execute when "Sword Attack" button is clicked
    }

    @FXML
    protected void onFistButtonClick(ActionEvent event) {
        System.out.println("Fist Attack");
        // Add code here to execute when "Fist Attack" button is clicked
    }

    @FXML
    protected void onFireButtonClick() {
        System.out.println("Fire button clicked!");
    }
}



