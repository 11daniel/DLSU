import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class TemperatureView extends JFrame {

    private JLabel celsiusLabel;
    private JLabel fahrenheitLabel;
    private JTextField celsiusText;
    private JTextField fahrenheitText;
    private JButton convertBtn;
    private JTextField infoText;

    public TemperatureView() {
        setTitle("Converter");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        celsiusLabel = new JLabel("Celsius:");
        fahrenheitLabel = new JLabel("Fahrenheit:");
        celsiusText = new JTextField(10);
        fahrenheitText = new JTextField(10);
        convertBtn = new JButton("Convert");
        infoText = new JTextField(30);

        infoText.setEditable(false);

        // Set JLabel text alignment to LEFT
        celsiusLabel.setHorizontalAlignment(SwingConstants.RIGHT);
        fahrenheitLabel.setHorizontalAlignment(SwingConstants.RIGHT);

        // Panel for input components (labels and text fields)
        JPanel inputPanel = new JPanel();
        inputPanel.setLayout(new GridLayout(2, 2, 10, 10)); // 2 rows, 2 columns, with 10-pixel gaps

        inputPanel.add(celsiusLabel);
        inputPanel.add(celsiusText);
        inputPanel.add(fahrenheitLabel);
        inputPanel.add(fahrenheitText);

        // Panel for "Convert" button and output text field
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new GridLayout(2, 1, 10, 10)); // 2 rows, 1 column, with 10-pixel gaps
        buttonPanel.add(convertBtn);
        buttonPanel.add(infoText);

        // Main panel to hold the two sub-panels
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new GridLayout(2, 1, 10, 10)); // 2 rows, 1 column, with 10-pixel gaps
        mainPanel.add(inputPanel);
        mainPanel.add(buttonPanel);

        add(mainPanel);
        pack();
        setLocationRelativeTo(null);
        setVisible(true);

        convertBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String celsiusStr = celsiusText.getText();
                String fahrenheitStr = fahrenheitText.getText();

                // Check if both fields are empty
                if (celsiusStr.isEmpty() && fahrenheitStr.isEmpty()) {
                    setInfoText("Please input either temperature.");
                    return;
                }

                // Convert Celsius to Fahrenheit
                if (!celsiusStr.isEmpty()) {
                    try {
                        double celsius = Double.parseDouble(celsiusStr);
                        double fahrenheit = (celsius * 9 / 5) + 32;
                        String conversionString = String.format("%.1f Celsius to %.1f Fahrenheit", celsius, fahrenheit);
                        setInfoText(conversionString);
                    } catch (NumberFormatException ex) {
                        setInfoText("Invalid input for Celsius.");
                    }
                }

                // Convert Fahrenheit to Celsius
                if (!fahrenheitStr.isEmpty()) {
                    try {
                        double fahrenheit = Double.parseDouble(fahrenheitStr);
                        double celsius = (fahrenheit - 32) * 5 / 9;
                        String conversionString = String.format("%.1f Fahrenheit to %f Celsius", fahrenheit, celsius);
                        setInfoText(conversionString);
                    } catch (NumberFormatException ex) {
                        setInfoText("Invalid input for Fahrenheit.");
                    }
                }

                clearTextFields();
            }
        });
    }

    public String getCelsius() {
        return celsiusText.getText();
    }

    public String getFahrenheit() {
        return fahrenheitText.getText();
    }

    public void setInfoText(String message) {
        infoText.setText(message);
    }

    public void clearTextFields() {
        celsiusText.setText("");
        fahrenheitText.setText("");
    }
}
