module com.example.jdrparty {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.jdrparty to javafx.fxml;
    exports com.example.jdrparty;
}