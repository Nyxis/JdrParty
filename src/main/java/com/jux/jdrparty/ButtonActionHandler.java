package com.jux.jdrparty;

import java.io.IOException;

public class ButtonActionHandler {

    public static void doThat(WeaponButton button){
        try {
            CppLauncher.launchCPP(button.getCritRate(),button.getFailRate(), button.getFumbleRate(), () ->
                    button.changeColor(CppLauncher.getLastOutput()));
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }

    }
}
