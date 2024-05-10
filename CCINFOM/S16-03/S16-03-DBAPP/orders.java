package dbsales;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.Scanner;

public class orders{
    private static final Scanner scan = new Scanner(System.in);
    public static void orders_menu(){
        System.out.println("\n== Orders Menu ==");
        System.out.println("1. Create Orders");
        System.out.println("2. Update an Order");
        System.out.println("3. Update Product in Order");
        System.out.println("4. Delete Product in Order");
        System.out.println("5. Exit");
        System.out.print("Select an option: ");
        int choice = scan.nextInt();
        scan.nextLine();
        switch (choice) {
            case 1 -> createOrder();
            case 2 -> updateOrder();
            case 3 -> updateOrderProduct();
            case 4 -> DeleteOrderProduct();
            case 5 -> {
                System.out.println("Exiting...");
                return;
            }
            default -> System.out.println("Invalid option! Please try again.");
        }
    }
    public static Boolean orderExists(Connection conn, int on) throws SQLException {
        String query = "SELECT COUNT(*) FROM orders WHERE orderNumber = ?";
        try (PreparedStatement pst = conn.prepareStatement(query)) {
            pst.setInt(1, on);
            try (ResultSet rst = pst.executeQuery()) {
                rst.next();
                int count = rst.getInt(1);
                return count > 0;
            }
        }
    }
    public static Boolean productcodeExists(Connection conn, String on) throws SQLException {
        String query = "SELECT COUNT(*) FROM orderdetails WHERE productCode = ?";
        try (PreparedStatement pst = conn.prepareStatement(query)) {
            pst.setString(1, on);
            try (ResultSet rst = pst.executeQuery()) {
                rst.next();
                int count = rst.getInt(1);
                return count > 0;
            }
        }
    }
    public static Boolean customerExists(Connection conn, int on) throws SQLException {
        String query = "SELECT COUNT(*) FROM customers WHERE customerNumber = ?";
        try (PreparedStatement pst = conn.prepareStatement(query)) {
            pst.setInt(1, on);
            try (ResultSet rst = pst.executeQuery()) {
                rst.next();
                int count = rst.getInt(1);
                return count > 0;
            }
        }
    }
    private static int getorderNumber(Connection connection) throws SQLException {
        String query = "SELECT MAX(orderNumber) AS ordernum FROM orders";
        try (PreparedStatement pst = connection.prepareStatement(query)) {
            try (ResultSet rst = pst.executeQuery()) {
                if (rst.next()) {
                    int maxOrder = rst.getInt("ordernum");
                    if (maxOrder == 0) {
                        // No Order numbers exist in the specified range, return the minimum value
                        return 9999;
                    }
                    return maxOrder + 1;
                }
            }
        }
        return 9999; // Return the minimum value if no records found
    }
    private static void createOrder() {
        int orderNumber;
        int quantityOrdered;
        double priceEach;
        short orderLineNumber;
        LocalDate reqDate;
        LocalDate orderDate;
        String status = "In Process";
        String comments;
        String product_code;
        int customerNum;

        try (Connection conn = ConnectDB.getConnection()) {
            orderNumber = getorderNumber(conn);
            System.out.println("\n== Create a new Order ==");
            do {
                System.out.print("Enter Product Code: ");
                product_code = scan.nextLine();
            } while (!productcodeExists(conn, product_code));

            System.out.print("Enter Quantity: ");
            quantityOrdered = scan.nextInt();
            System.out.print("Enter Price Each: ");
            priceEach = scan.nextDouble();
            System.out.print("Enter OrderLineNumber: ");
            orderLineNumber = scan.nextShort();
            orderDate = LocalDate.now();
            reqDate = orderDate.plusDays(15);
            scan.nextLine();
            System.out.print("Enter Comments: ");
            comments = scan.nextLine();
            System.out.print("Enter Customer: ");
            customerNum = scan.nextInt();
            System.out.println("Current Details:   ");
            System.out.println("Order Number:      " + orderNumber);
            System.out.println("Product Code:      " + product_code);
            System.out.println("Quantity:          " + quantityOrdered);
            System.out.println("Price Each:        " + priceEach);
            System.out.println("OrderLineNumber:   " + orderLineNumber);
            System.out.println("Comments:          " + comments);
            System.out.println("Customers:         " + customerNum);
            System.out.print("If details are Correct Type 1: ");
            int question = scan.nextInt();
            if (question == 1) {
                String query = "INSERT INTO orders VALUES(?,?,?,?,?,?,?)";
                try (PreparedStatement pst2 = conn.prepareStatement(query)) {
                    pst2.setInt(1, orderNumber);
                    pst2.setString(2, orderDate.toString());
                    pst2.setString(3, reqDate.toString());
                    pst2.setString(4, null);
                    pst2.setString(5, status);
                    pst2.setString(6, comments);
                    pst2.setInt(7, customerNum);
                    if (pst2.executeUpdate() == 1) {
                    } else {
                        System.out.println("Order Failed to Create!");
                    }
                    query = "INSERT INTO orderdetails VALUES(?,?,?,?,?)";
                    try (PreparedStatement pst = conn.prepareStatement(query)) {
                        pst.setInt(1, orderNumber);
                        pst.setString(2, product_code);
                        pst.setInt(3, quantityOrdered);
                        pst.setDouble(4, priceEach);
                        pst.setShort(5, orderLineNumber);
                        if (pst.executeUpdate() == 1) {
                            System.out.println("O Created Successfully!");
                        } else {
                            System.out.println("O Failed to Create!");
                        }
                    } catch (SQLException e) {
                        System.err.println("Error creating orders: " + e.getMessage());
                    }

                } catch (SQLException e) {
                    System.err.println("Error creating orders: " + e.getMessage());
                }
                }
            }catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    private static void DeleteOrderProduct() {
        int orderNumber;
        String  product_code;
        try (Connection conn = ConnectDB.getConnection()){
            System.out.println("\n=== Delete Orders by Product ===");
            do {
                System.out.print("Enter Order Number: ");
                orderNumber = scan.nextInt();
            } while (!orderExists(conn,orderNumber));
            scan.nextLine();
            do {
                System.out.print("Enter Product Code: ");
                product_code = scan.nextLine();
            } while (!productcodeExists(conn, product_code));
            String query = "DELETE FROM orderdetails WHERE orderNumber = ? AND productCode = ?";
            try(PreparedStatement pst = conn.prepareStatement(query)) {
                pst.setInt(1, orderNumber);
                pst.setString(2, product_code);
                if (pst.executeUpdate() == 1) {
                    System.out.println("Order Deleted by Product Successfully!");
                    conn.close();
                } else {
                    System.out.println("Order Failed to Delete by Product!");
                    conn.close();
                }
            }
        }catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
    }

    private static void updateOrderProduct() {
        int orderNumber;
        String product_code;
        String newproduct_code;
        try (Connection conn = ConnectDB.getConnection()){
            System.out.println("\n=== Update an Order by Product ===");
            do {

                System.out.print("Enter Order Number: ");

                orderNumber = scan.nextInt();
            } while (!orderExists(conn,orderNumber));
            scan.nextLine();
            do {
                System.out.print("Enter Product Code: ");
                product_code = scan.nextLine();
            } while (!productcodeExists(conn, product_code));
            do {
                System.out.print("Enter New Product Code: ");
                 newproduct_code = scan.nextLine();
            } while (!productcodeExists(conn,newproduct_code));

            String query = "UPDATE orderdetails SET productCode = ? WHERE orderNumber = ? AND productCode = ? ";
            try(PreparedStatement pst = conn.prepareStatement(query)) {
                pst.setString(1, newproduct_code);
                pst.setInt(2, orderNumber);
                pst.setString(3, product_code);
                if (pst.executeUpdate() == 1) {
                    System.out.println("Order Updated Successfully!");
                    conn.close();
                } else {
                    System.out.println("Order Failed to update!");
                    conn.close();
                }
            }
        }catch(Exception e){
            System.err.println("Error: " + e.getMessage());
        }
    }
    private static void updateOrder() {
        int orderNumber;
        int index;
        int customer;
        String update;
        String product_code;
        try (Connection conn = ConnectDB.getConnection()){
            System.out.println("\n=== Update an Order ===");
            do {
                System.out.print("Enter Order Number: ");
                orderNumber = scan.nextInt();
            } while (!orderExists(conn,orderNumber));
            String query = "SELECT * FROM orders o LEFT JOIN orderdetails od ON o.orderNumber=od.orderNumber WHERE = ?";
            try (PreparedStatement pst = conn.prepareStatement(query)){
                pst.setInt(1,orderNumber);
                try (ResultSet rst = pst.executeQuery()){
                    if (rst.next()) {
                        System.out.println("Current Details:   ");
                        System.out.println("1. Order Number:      " + rst.getInt("orderNumber"));
                        System.out.println("2. Product Code:      " + rst.getString("productCode"));
                        System.out.println("3. Quantity:          " + rst.getInt("quantityOrdered"));
                        System.out.println("4. Price Each:        " + rst.getDouble("priceEach"));
                        System.out.println("5. OrderLineNumber:   " + rst.getInt("orderLineNumber"));
                        System.out.println("6. Comments:          " + rst.getString("comments"));
                        System.out.println("7. Customers:         " + rst.getInt("customerNum"));
                        do {
                            System.out.print("Select a index to update: ");
                            index = scan.nextInt();
                            index--;
                        } while (!((index) >= 0 && (index) < 7));
                        switch (index){
                            case 0:
                                System.out.println("Cannot Update Order Number due to being used by other tables");
                                break;
                            case 1:
                                do {
                                    System.out.print("Enter Product Code: ");
                                    product_code = scan.nextLine();
                                } while (!productcodeExists(conn, product_code));
                                update = String.valueOf(product_code);
                                update_od(conn,"productCode",update,orderNumber,1);
                                break;
                            case 2:
                                System.out.print("Enter Quantity: ");
                                int quantity = scan.nextInt();
                                update = String.valueOf(quantity);
                                update_od(conn,"quantityOrdered",update,orderNumber,4);
                                break;
                            case 3:
                                System.out.print("Enter Price each: ");
                                Double priceEach  = scan.nextDouble();
                                update = String.valueOf(priceEach);
                                update_od(conn,"priceEach",update,orderNumber,3);
                                break;
                            case 4:
                                System.out.print("Enter OrderLine Number: ");
                                int orderLine  = scan.nextInt();
                                update = String.valueOf(orderLine);
                                update_od(conn,"orderLineNumber",update,orderNumber,4);
                                break;
                            case 5:
                                System.out.print("Enter Comment: ");
                                String comment = scan.nextLine();
                                update = String.valueOf(comment);
                                update_o(conn,"comments",update,orderNumber,1);
                                break;
                            case 6:
                                do {
                                    System.out.print("Enter Customer: ");
                                    customer = scan.nextInt();
                                } while (!customerExists(conn,customer));
                                update = String.valueOf(customer);
                                update_o(conn, "customerNum",update,orderNumber,1);
                                break;
                        }
                        conn.close();
                    }
            }catch (SQLException e) {System.err.println("Error updating Orders: " + e.getMessage());
        }}
        }catch(Exception e){
                System.err.println("Error: " + e.getMessage());}
    }
    public static void update_o(Connection conn, String column, String update,int ordernum, int datatype){
        String query = "UPDATE orders SET " + column + " = ? WHERE orderNum = ?";
        try (PreparedStatement pst = conn.prepareStatement(query)) {
            switch (datatype) {
                case 1 -> pst.setString(1, update);
                case 2 -> pst.setShort(1, Short.parseShort(update));
                case 3 -> pst.setDouble(1, Double.parseDouble(update));
                case 4 -> pst.setInt(1, Integer.parseInt(update));
            }
            pst.setInt(2,ordernum);
            if(pst.executeUpdate()==1){System.out.println("Order Updated Successfully");}
            else{System.out.println("- Order Failed to Update");}
        }catch (SQLException e) {System.err.println("Error updating Order: " + e.getMessage());}
    }
    public static void update_od(Connection conn, String column, String update,int ordernum, int datatype){
        String query = "UPDATE orderdetails SET " + column + " = ? WHERE orderNum = ?";
        try (PreparedStatement pst = conn.prepareStatement(query)) {
            switch (datatype) {
                case 1 -> pst.setString(1, update);
                case 2 -> pst.setShort(1, Short.parseShort(update));
                case 3 -> pst.setDouble(1, Double.parseDouble(update));
                case 4 -> pst.setInt(1, Integer.parseInt(update));
            }
            pst.setInt(2,ordernum);
            if(pst.executeUpdate()==1){System.out.println("Order Updated Successfully");}
            else{System.out.println("- Order Failed to Update");}
        }catch (SQLException e) {System.err.println("Error updating Order: " + e.getMessage());}
    }
}
