package com.jux.jdrparty;

import javafx.scene.AccessibleRole;
import javafx.scene.Cursor;
import javafx.scene.control.Button;

public class WeaponButton extends Button {

    private final String critRate;
    private final String failRate;
    private final String fumbleRate;


    public String getCritRate() {
        return critRate;
    }

    public String getFailRate() {
        return failRate;
    }

    public String getFumbleRate() {
        return fumbleRate;
    }


    WeaponButton(String buttonName, String critRate, String failRate, String fumbleRate) {
        super(buttonName);
        this.critRate = critRate;
        this.failRate = failRate;
        this.fumbleRate = fumbleRate;
        this.initialize();
    }

    private void initialize() {
        this.getStyleClass().setAll("button");
        this.setAccessibleRole(AccessibleRole.BUTTON);
        this.cursorProperty().set(Cursor.HAND);
        this.setMnemonicParsing(true);
    }

    public void changeColor(String lastOutput) {
        {
            if (lastOutput.equals("Reussite Critique")) {
                this.setStyle("-fx-background-color: green; -fx-text-fill: white");
            } else {
                if (lastOutput.equals("Reussite")) {
                    this.setStyle("-fx-background-color: MediumSeaGreen");
                } else {
                    if (lastOutput.equals("Echec")) {
                        this.setStyle("-fx-background-color: Red");
                    } else {
                        this.setStyle("-fx-background-color: black; -fx-text-fill: white");
                    }
                }
            }
        }
    }

}
