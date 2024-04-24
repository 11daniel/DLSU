import java.awt.event.*;

public class TemperatureController implements ActionListener {

    private Temperature tempM;
    private TemperatureView tempV;

    public TemperatureController(Temperature tempM, TemperatureView tempV) {
        this.tempM = tempM;
        this.tempV = tempV;

    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String celsiusStr = tempV.getCelsius();
        String fahrenheitStr = tempV.getFahrenheit();

        // Check if both fields are empty
        if (celsiusStr.isEmpty() && fahrenheitStr.isEmpty()) {
            tempV.setInfoText("Please input either temperature.");
            return;
        }

        // Convert Celsius to Fahrenheit
        if (!celsiusStr.isEmpty()) {
            try {
                double celsius = Double.parseDouble(celsiusStr);
                double fahrenheit = (celsius * 9 / 5) + 32;
                String conversionString = String.format("%.2f Celsius to %.2f Fahrenheit", celsius, fahrenheit);
                tempV.setInfoText(conversionString);
            } catch (NumberFormatException ex) {
                tempV.setInfoText("Invalid input for Celsius.");
            }
        }

        // Convert Fahrenheit to Celsius
        if (!fahrenheitStr.isEmpty()) {
            try {
                double fahrenheit = Double.parseDouble(fahrenheitStr);
                double celsius = (fahrenheit - 32) * 5 / 9;
                String conversionString = String.format("%.2f Fahrenheit to %.2f Celsius", fahrenheit, celsius);
                tempV.setInfoText(conversionString);
            } catch (NumberFormatException ex) {
                tempV.setInfoText("Invalid input for Fahrenheit.");
            }
        }

        tempV.clearTextFields();
    }

    public static void main(String[] args) {
        Temperature tempM = new Temperature();
        TemperatureView tempV = new TemperatureView();
        TemperatureController controller = new TemperatureController(tempM, tempV);
    }
}
