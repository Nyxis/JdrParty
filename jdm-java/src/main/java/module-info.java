module com.example.jdmjava {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.kordamp.bootstrapfx.core;

    opens com.example.jdmjava to javafx.fxml;
    exports com.example.jdmjava;
}