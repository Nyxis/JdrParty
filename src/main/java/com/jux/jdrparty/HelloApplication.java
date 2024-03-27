package com.jux.jdrparty;

import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
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

        WeaponButton buttonArc = new WeaponButton("Tir à l'arc", "1.1", "1.45", "0.95");
        WeaponButton buttonEpee = new WeaponButton("Coup d'épée","1.2", "1.25", "0.85");
        WeaponButton buttonPoing = new WeaponButton("Coup de poing", "1.5", "1", "0.5");
        WeaponButton buttonFeu = new WeaponButton("Boule de feu", "1.5", "1", "0.5");

        mainFrame.getChildren().addAll(buttonArc, buttonEpee, buttonPoing, buttonFeu);

        Scene scene = new Scene(mainFrame, 500, 500);

        stage.setTitle("Jeu De Role de gros Nerd");
        stage.setScene(scene);
        stage.show();

        buttonArc.setOnAction(e -> ButtonActionHandler.doThat(buttonArc));

        buttonEpee.setOnAction(e -> ButtonActionHandler.doThat(buttonEpee));

        buttonPoing.setOnAction(e -> ButtonActionHandler.doThat(buttonPoing));

        buttonFeu.setOnAction(e -> ButtonActionHandler.doThat(buttonFeu));
    }
}