module com.jux.jdrparty {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;

    opens com.jux.jdrparty to javafx.fxml;
    exports com.jux.jdrparty;
}