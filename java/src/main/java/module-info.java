module com.example.mjcpp {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.example.mjcpp to javafx.fxml;
    exports com.example.mjcpp;
}