
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Transaction {
    private static final Scanner scan = new Scanner(System.in);

    public static void transaction_menu() {
        while (true) {
            System.out.println("\n== Transaction Menu ==");
            System.out.println("1. Orders");
            System.out.println("2. Payment");
            System.out.println("3. Exit");
            System.out.print("Select an option: ");
            int choice = scan.nextInt();
            switch (choice) {
                case 1 -> orders.orders_menu();
                case 2 -> manageTransactions();
                case 3 -> {
                    System.out.println("Exiting...");
                    return;
                }
                default -> System.out.println("Invalid option! Please try again.");
            }
        }
    }

    /*
    public static void payment() {
        while (true) {
            System.out.println("\n--- Orders Menu ---");
            System.out.println("1. Create Orders");
            System.out.println("2. Update an Order");
            System.out.println("3. Update Product in Order");
            System.out.println("4. Delete Product in Order");
            System.out.println("5. Exit");
            System.out.print("Select an option: ");
            int choice = scan.nextInt();
            scan.nextLine(); // Consume newline character

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
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid option! Please try again.");
            }
        }
    }

    public static int createPayment() {
        int paymentId;
        int orderId;
        double amount;
        LocalDate paymentDate;
        String paymentMethod;
        String status = "Pending";
        String comments;
        int customerId;

        try (Connection conn = ConnectDB.getConnection()) {
            paymentId = getPaymentId(conn);
            System.out.println("\n--- Create a new Payment ---");
            scan.nextLine(); // Consume newline character

            System.out.print("Enter Order ID: ");
            orderId = scan.nextInt();

            System.out.print("Enter Amount: ");
            amount = scan.nextDouble();

            System.out.print("Enter Payment Method: ");
            paymentMethod = scan.nextLine();

            paymentDate = LocalDate.now();

            System.out.print("Enter Comments: ");
            comments = scan.nextLine();

            System.out.print("Enter Customer ID: ");
            customerId = scan.nextInt();

            System.out.println("Current Details:   ");
            System.out.println("Payment ID:        " + paymentId);
            System.out.println("Order ID:          " + orderId);
            System.out.println("Amount:            " + amount);
            System.out.println("Payment Method:    " + paymentMethod);
            System.out.println("Payment Date:      " + paymentDate.toString());
            System.out.println("Comments:          " + comments);
            System.out.println("Customer ID:       " + customerId);
            System.out.print("If details are Correct Type 1: ");
            int question = scan.nextInt();
            if (question == 1) {
                String query = "INSERT INTO payments VALUES(?,?,?,?,?,?,?,?)";
                try (PreparedStatement pst = conn.prepareStatement(query)) {
                    pst.setInt(1, paymentId);
                    pst.setInt(2, orderId);
                    pst.setDouble(3, amount);
                    pst.setString(4, paymentMethod);
                    pst.setString(5, paymentDate.toString());
                    pst.setString(6, status);
                    pst.setString(7, comments);
                    pst.setInt(8, customerId);
                    if (pst.executeUpdate() == 1) {
                        System.out.println("Payment Created Successfully!");
                    } else {
                        System.out.println("Failed to Create Payment!");
                    }
                }
                conn.close();
                return 1;
            } else {
                conn.close();
                throw new InputMismatchException();
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
            return 0;
        }
    }

    public static int updatePayment() {
        int paymentID;
        int index;
        String update;
        String[] details = { "orderNumber", "productCode", "quantityOrdered", "priceEach", "orderLineNumber",
                "comments", "customerNum" };
        Scanner scan = new Scanner(System.in);

        System.out.println("\n--- Update Payment Information ---");

        System.out.print("Enter Payment ID: ");
        paymentID = scan.nextInt();

        if (!paymentExists(paymentID)) {
            System.out.println("Payment with ID " + paymentID + " does not exist.");
            return 0;
        }

        try (Connection conn = ConnectDB.getConnection()) {
            String query = "SELECT * FROM Payment p JOIN Order o ON p.order_id = o.id WHERE p.id = ?";
            PreparedStatement pst = conn.prepareStatement(query);
            pst.setInt(1, paymentID);

            ResultSet rst = pst.executeQuery();
            if (rst.next()) {
                System.out.println("Current Payment Information:");
                System.out.println("1. Payment ID: " + rst.getInt("id"));
                System.out.println("2. Order ID: " + rst.getInt("o.id"));
                System.out.println("3. Payment Amount: " + rst.getDouble("amount"));
                System.out.println("4. Payment Date: " + rst.getDate("payment_date"));
                System.out.println("5. Payment Status: " + rst.getString("status"));

                do {
                    System.out.print("Select an index to update: ");
                    index = scan.nextInt();
                } while (index < 1 || index > 5);
                index--;

                scan.nextLine();
                System.out.print("Enter the new value: ");
                update = scan.nextLine();

                String newQuery;
                if (index == 0) {
                    newQuery = "UPDATE Payment SET id = ? WHERE id = ?";
                } else if (index == 1) {
                    newQuery = "UPDATE Order SET id = ? WHERE id = ?";
                } else {
                    newQuery = "UPDATE Payment SET ";
                    switch (index) {
                        case 2:
                            newQuery += "amount = ? ";
                            break;
                        case 3:
                            newQuery += "payment_date = ? ";
                            break;
                        case 4:
                            newQuery += "status = ? ";
                            break;
                        default:
                            newQuery += "UNKNOWN COLUMN " + index;
                            break;
                    }
                    newQuery += "WHERE id = ?";
                }

                PreparedStatement pst2 = conn.prepareStatement(newQuery);
                if (index == 0) {
                    pst2.setInt(1, paymentID);
                    pst2.setInt(2, paymentID);
                } else if (index == 1) {
                    pst2.setInt(1, paymentID);
                    pst2.setInt(2, paymentID);
                } else {
                    pst2.setString(1, update);
                    pst2.setInt(2, paymentID);
                }

                int rowsAffected = pst2.executeUpdate();
                if (rowsAffected == 1) {
                    System.out.println("Payment Information updated.");
                } else {
                    System.out.println("Failed to update Payment Information.");
                }
            } else {
                System.out.println("No payment with ID " + paymentID);
            }
        } catch (SQLException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    
    public static int deletePayment() {

        int paymentId;
    
        try(Connection conn = ConnectDB.getConnection()){
    
          System.out.println("\n--- Delete a Payment ---");
    
          System.out.print("Enter Payment ID: ");  
          paymentId = scan.nextInt();
    
          if(!paymentExists(conn, paymentId)) {
            System.out.println("Payment with ID " + paymentId + " does not exist.");
            return 0;
          }
    
          String query = "DELETE FROM payments WHERE id = ?";
    
          try(PreparedStatement pst = conn.prepareStatement(query)){
            pst.setInt(1, paymentId);
    
            if(pst.executeUpdate() == 1){
              System.out.println("Payment deleted successfully!");
              return 1;
            } else {
              System.out.println("Payment deletion failed!");  
              return 0;
            }
    
          }
    
        } catch(Exception e) {
          System.err.println("Error: " + e.getMessage());
          return 0;
        }
    
      }

    public static Boolean paymentExists(Connection conn, int paymentNumber) throws SQLException {
        String query = "SELECT COUNT(*) FROM payments WHERE paymentNumber = ?";
        try (PreparedStatement pst = conn.prepareStatement(query)) {
            pst.setInt(1, paymentNumber);
            try (ResultSet rst = pst.executeQuery()) {
                rst.next();
                int count = rst.getInt(1);
                return count > 0;
            }
        }
    }

    private static int getPaymentId(Connection connection) throws SQLException {
        String query = "SELECT MAX(paymentId) AS payment FROM payments";
        try (PreparedStatement pst = connection.prepareStatement(query)) {
            try (ResultSet rst = pst.executeQuery()) {
                if (rst.next()) {
                    int maxPayment = rst.getInt("payment");
                    if (maxPayment == 0) {
                        // No payment IDs exist in the specified range, return the minimum value
                        return 9999;
                    }
                    return maxPayment + 1;
                }
            }
        }
        return 9999; // Return the minimum value if no records found
    }*/
    public static void manageTransactions() {
        try {
            while (true) {
                System.out.println("\n--- Manage Transactions ---");
                System.out.println("1. Create a new Payment");
                System.out.println("2. Update a Payment");
                System.out.println("3. Delete a Payment");
                System.out.println("4. Back");
                System.out.print("Select an option: ");
    
                int choice = scan.nextInt();
    
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
                int customerNumber = scan.nextInt();
                scan.nextLine(); // Consume newline character
                System.out.print("Enter Check Number: ");
                String checkNumber = scan.nextLine();
                System.out.print("Enter Payment Date (YYYY-MM-DD): ");
                String paymentDate = scan.nextLine();
                System.out.print("Enter Amount: ");
                double amount = scan.nextDouble();
    
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
                int customerNumber = scan.nextInt();
                scan.nextLine(); 
                System.out.print("Enter Check Number: ");
                String checkNumber = scan.nextLine();
                System.out.print("Enter New Payment Date (YYYY-MM-DD): ");
                String paymentDate = scan.nextLine();
                System.out.print("Enter New Payment Amount: ");
                double amount = scan.nextDouble();
    
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
                int customerNumber = scan.nextInt();
                scan.nextLine(); 
                System.out.print("Enter Check Number: ");
                String checkNumber = scan.nextLine();
    
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