package com.jux.jdrparty;

import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import java.io.IOException;

public class HelloApplication extends Application {

    public static void main(String[] args) {
        launch();
    }

    @FXML
    @Override
    public void start(Stage stage) {

        VBox mainFrame = new VBox();

        mainFrame.setSpacing(50);
        mainFrame.setAlignment(Pos.CENTER);

        WeaponButton buttonArc = new WeaponButton("Tir à l'arc");
        WeaponButton buttonEpee = new WeaponButton("Coup d'épée");
        WeaponButton buttonPoing = new WeaponButton("Coup de poing");
        WeaponButton buttonFeu = new WeaponButton("Boule de feu");

        mainFrame.getChildren().addAll(buttonArc, buttonEpee, buttonPoing, buttonFeu);

        Scene scene = new Scene(mainFrame, 500, 500);

        stage.setTitle("Jeu De Role de gros Nerd");
        stage.setScene(scene);
        stage.show();
        stage.onHiddenProperty();

        buttonArc.setOnAction(e -> {
            try {
                CppLauncher.launchCPP("1.1", "1.45", "0.95", () ->
                    buttonArc.changeColor(CppLauncher.getLastOutput()));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        buttonEpee.setOnAction(e -> {
            try {
                CppLauncher.launchCPP("1.1", "1.45", "0.95", () ->
                    buttonEpee.changeColor(CppLauncher.getLastOutput()));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        buttonPoing.setOnAction(e -> {
            try {
                CppLauncher.launchCPP("1.1", "1.45", "0.95", () ->
                    buttonPoing.changeColor(CppLauncher.getLastOutput()));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        buttonFeu.setOnAction(e -> {
            try {
                CppLauncher.launchCPP("1.1", "1.45", "0.95", () ->
                    buttonFeu.changeColor(CppLauncher.getLastOutput()));
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });
    }
}