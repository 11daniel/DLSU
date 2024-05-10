import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

/**
 * The `ManageTransactionsMenu` class provides a menu for managing payments including creating,
 * updating, and deleting payments.
 */
public class ManageTransactionsMenu {
    private static Scanner scanner = new Scanner(System.in);

    public static void manageTransactions() {
        try {
            while (true) {
                System.out.println("\n--- Manage Transactions ---");
                System.out.println("1. Create a new Payment");
                System.out.println("2. Update a Payment");
                System.out.println("3. Delete a Payment");
                System.out.println("4. Back");
                System.out.print("Select an option: ");
    
                int choice = scanner.nextInt();
    
                switch (choice) {
                    case 1:
                        createPayment();
                        break;
                    case 2:
                        updatePayment();
                        break;
                    case 3:
                        deletePayment();
                        break;
                    case 4:
                        return; 
                    default:
                        System.out.println("Invalid option! Please try again.");
                }
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    


/**
 * The `createPayment` method in Java allows users to input payment details and store them in a
 * database table.
 */
    private static void createPayment() {
        try {
            try (Connection connection = ConnectDB.getConnection()) {
                System.out.println("\n--- Create a new Payment ---");
                System.out.print("Enter Customer Number: ");
                int customerNumber = scanner.nextInt();
                scanner.nextLine(); // Consume newline character
                System.out.print("Enter Check Number: ");
                String checkNumber = scanner.nextLine();
                System.out.print("Enter Payment Date (YYYY-MM-DD): ");
                String paymentDate = scanner.nextLine();
                System.out.print("Enter Amount: ");
                double amount = scanner.nextDouble();
    
                String query = "INSERT INTO payments (customerNumber, checkNumber, paymentDate, amount) VALUES (?, ?, ?, ?)";
                try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                    preparedStatement.setInt(1, customerNumber);
                    preparedStatement.setString(2, checkNumber);
                    preparedStatement.setString(3, paymentDate);
                    preparedStatement.setDouble(4, amount);
                    int rowsAffected = preparedStatement.executeUpdate();
                    if (rowsAffected > 0) {
                        System.out.println("Payment created successfully.");
                    } else {
                        System.out.println("Failed to create payment.");
                    }
                }
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    


 /**
  * The `updatePayment` function in Java allows the user to update payment details in a database table
  * based on customer number and check number.
  */
    private static void updatePayment() {
        try {
            try (Connection connection = ConnectDB.getConnection()) {
                System.out.println("\n--- Update a Payment ---");
                System.out.print("Enter Customer Number: ");
                int customerNumber = scanner.nextInt();
                scanner.nextLine(); 
                System.out.print("Enter Check Number: ");
                String checkNumber = scanner.nextLine();
                System.out.print("Enter New Payment Date (YYYY-MM-DD): ");
                String paymentDate = scanner.nextLine();
                System.out.print("Enter New Payment Amount: ");
                double amount = scanner.nextDouble();
    
                String query = "UPDATE payments SET paymentDate = ?, amount = ? WHERE customerNumber = ? AND checkNumber = ?";
                try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                    preparedStatement.setString(1, paymentDate);
                    preparedStatement.setDouble(2, amount);
                    preparedStatement.setInt(3, customerNumber);
                    preparedStatement.setString(4, checkNumber);
                    int rowsAffected = preparedStatement.executeUpdate();
                    if (rowsAffected > 0) {
                        System.out.println("Payment updated successfully.");
                    } else {
                        System.out.println("Failed to update payment. Payment not found.");
                    }
                }
            }
        } catch (SQLException e) {
            System.err.println("Error updating payment: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    
    private static void deletePayment() {
        try {
            try (Connection connection = ConnectDB.getConnection()) {
                System.out.println("\n--- Delete a Payment ---");
                System.out.print("Enter Customer Number: ");
                int customerNumber = scanner.nextInt();
                scanner.nextLine(); 
                System.out.print("Enter Check Number: ");
                String checkNumber = scanner.nextLine();
    
                String query = "DELETE FROM payments WHERE customerNumber = ? AND checkNumber = ?";
                try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                    preparedStatement.setInt(1, customerNumber);
                    preparedStatement.setString(2, checkNumber);
                    int rowsAffected = preparedStatement.executeUpdate();
                    if (rowsAffected > 0) {
                        System.out.println("Payment deleted successfully.");
                    } else {
                        System.out.println("Failed to delete payment. Payment not found.");
                    }
                }
            }
        } catch (SQLException e) {
            System.err.println("Error deleting payment: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}    