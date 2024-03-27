package com.jux.jdrparty;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CppLauncher {
    private static String lastOutput;

    public static String getLastOutput() {
        return lastOutput;
    }

    public static void launchCPP(String arg1, String arg2, String arg3, Callback callback) throws IOException {

        try {
            String command = "src/main/resources/CPP/JdrExo/cmake-build-debug/JdrExo";

            ProcessBuilder cpp = new ProcessBuilder(command, arg1, arg2, arg3);

            Process process = cpp.start();
            new Thread(() -> {
                try (BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        lastOutput = line;
                        System.out.println(lastOutput);
                    }

                    javafx.application.Platform.runLater(callback::onProcessComplete);

                } catch (IOException e) {
                    e.getCause();
                }

            }).start();

        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }
}