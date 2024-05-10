import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class GenerateRecords {
    private static Scanner scanner = new Scanner(System.in);

    public static void generateRecordsMenu() {
        while (true) {
            System.out.println("\n--- Generate Records Menu ---");
            System.out.println("1. Generate Records per Status");
            System.out.println("2. Generate Records per Product");
            System.out.println("3. Exit");
            System.out.print("Select an option: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); 

            switch (choice) {
                case 1:
                    generateRecordsPerStatus();
                    break;
                case 2:
                    generateRecordsPerProduct();
                    break;
                case 3:
                    System.out.println("Exiting...");
                    return;
                default:
                    System.out.println("Invalid option! Please try again.");
            }
        }
    }   

    public static void generateRecordsPerStatus() {
        try (Connection connection = ConnectDB.getConnection()) {
            
            System.out.println("\n--- Generate Sales Report ---");
            System.out.print("Enter the month (1-12): ");
            int month = scanner.nextInt();
            System.out.print("Enter the year: ");
            int year = scanner.nextInt();
            scanner.nextLine(); 

            // retrieve data from given month + year
            String query = "SELECT o.orderDate, o.status, SUM(od.quantityOrdered * od.priceEach) AS total_sales " +
                           "FROM orders o " +
                           "JOIN orderdetails od ON o.orderNumber = od.orderNumber " +
                           "WHERE MONTH(o.orderDate) = ? AND YEAR(o.orderDate) = ? " +
                           "GROUP BY o.orderDate, o.status";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setInt(1, month);
                preparedStatement.setInt(2, year);
                try (ResultSet resultSet = preparedStatement.executeQuery()) {
                    Map<LocalDate, Map<String, Double>> salesData = new HashMap<>();

                    //process query
                    while (resultSet.next()) {
                        LocalDate orderDate = resultSet.getDate("orderDate").toLocalDate();
                        String status = resultSet.getString("status");
                        double totalSales = resultSet.getDouble("total_sales");

                        //add sales data to the map
                        if (!salesData.containsKey(orderDate)) {
                            salesData.put(orderDate, new HashMap<>());
                        }
                        salesData.get(orderDate).put(status, totalSales);
                    }

                    
                    System.out.println("\nSales Report for " + month + "/" + year);
                    double totalSales = 0;
                    for (LocalDate date : salesData.keySet()) {
                        System.out.println("\nDate: " + date);
                        Map<String, Double> dailySales = salesData.get(date);
                        for (String status : dailySales.keySet()) {
                            double salesAmount = dailySales.get(status);
                            
                            String formattedSalesAmount = String.format("%.2f", salesAmount);
                            System.out.println("Status: " + status + ", Total Sales: $" + formattedSalesAmount);
                            totalSales += salesAmount;
                        }
                    }
                    
                    String formattedTotalSales = String.format("%.2f", totalSales);
                    System.out.println("\nTotal Sales for " + month + "/" + year + ": $" + formattedTotalSales);
                }
            }
        } catch (SQLException e) {
            System.err.println("Error generating sales report: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

// The `generateRecordsPerProduct()` method in the provided Java code is responsible for generating a
// sales report per product based on the user input for month and year. Here is a breakdown of what the
// method does:
   

private static void generateRecordsPerProduct() {
    try (Connection connection = ConnectDB.getConnection()) {
        System.out.println("\n--- Generate Sales Report per Product ---");
        System.out.print("Enter the month (1-12): ");
        int month = scanner.nextInt();
        System.out.print("Enter the year: ");
        int year = scanner.nextInt();
        scanner.nextLine();

        String query = "SELECT o.orderDate, p.productName, od.quantityOrdered, od.priceEach, od.quantityOrdered * od.priceEach AS total_price " +
                       "FROM orders o " +
                       "JOIN orderdetails od ON o.orderNumber = od.orderNumber " +
                       "JOIN products p ON od.productCode = p.productCode " +
                       "WHERE MONTH(o.orderDate) = ? AND YEAR(o.orderDate) = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setInt(1, month);
            preparedStatement.setInt(2, year);
            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                Map<String, Map<LocalDate, Double>> productSales = new HashMap<>();

                while (resultSet.next()) {
                    LocalDate orderDate = resultSet.getDate("orderDate").toLocalDate();
                    String productName = resultSet.getString("productName");
                    double totalPrice = resultSet.getDouble("total_price");

                    if (!productSales.containsKey(productName)) {
                        productSales.put(productName, new HashMap<>());
                    }
                    productSales.get(productName).put(orderDate, productSales.get(productName).getOrDefault(orderDate, 0.0) + totalPrice);
                }

                System.out.println("\nSales Report for " + month + "/" + year + " per Product:");
                double totalSales = 0;
                for (String productName : productSales.keySet()) {
                    System.out.println("\nProduct: " + productName);
                    Map<LocalDate, Double> dailySales = productSales.get(productName);
                    for (LocalDate date : dailySales.keySet()) {
                        double salesAmount = dailySales.get(date);
                        String formattedSalesAmount = String.format("%.2f", salesAmount);
                        System.out.println("Date: " + date + ", Total Sales: $" + formattedSalesAmount);
                        totalSales += salesAmount;
                    }
                }

                String formattedTotalSales = String.format("%.2f", totalSales);
                System.out.println("\nTotal Sales for " + month + "/" + year + ": $" + formattedTotalSales);
            }
        }
    } catch (SQLException e) {
        System.err.println("Error generating sales report per product: " + e.getMessage());
    } catch (Exception e) {
        System.err.println("Error: " + e.getMessage());
    }
}
}