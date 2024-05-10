

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Scanner;
public class products {
    private static final Scanner scan = new Scanner(System.in);
    private static final ArrayList<String> products_Listing = new ArrayList<>();
    private static final ArrayList<String> products_Code = new ArrayList<>();
    public static void products_menu(){
        while(true){
            list(); //always updates arraylist as a new transaction will be progressed
            System.out.println("\n-== CRUD Products ==-");
            System.out.println("1. Create a new Product");
            System.out.println("2. Update a record of an Product");
            System.out.println("3. Delete a record of an Product");
            System.out.println("4. View a record of a specific Product");
            System.out.println("5. View list of orders with a Product");
            System.out.println("6. Back to Menu");
            System.out.print("Select option: ");
            int choice = scan.nextInt();
            switch (choice) {
                case 1 -> createProduct();
                case 2 -> updateProduct();
                case 3 ->  deleteProduct();
                case 4 -> viewProduct();
                case 5 -> viewOrder();
                case 6 -> {
                    return; // Go back to the previous menu
                }
                default -> System.out.println("Invalid option! Please try again.");
            }
        }

    }
    public static void createProduct(){
        String code;//All variables for product
        String name;
        String scale;
        String vendor;
        String description;
        short stock;
        double price;
        double MSRP;
        int index;
        try (Connection conn = ConnectDB.getConnection()){
            System.out.println("== C - Create Product ==");
            scan.nextLine();
            do{
                System.out.print("Enter Product Code: ");
                code = scan.nextLine();
                if (products_Code.contains(code)){System.out.println("- Product Code is already being used");}
            }while(products_Code.contains(code));
            System.out.print("Enter Product Name: ");
            name = scan.nextLine();

            showlist(products_Listing); // display list of possible products
            System.out.println("Size: "+ products_Listing.size());
            do{
                System.out.print("Enter Product Line: ");
                index = scan.nextInt();
                index--;
                if (index < 0 || index >= products_Listing.size()){System.out.println("- Product Listing not found");}
            } while (index < 0 || index >= products_Listing.size());

            System.out.print("Enter Product Scale (1:?): ");
            int number = scan.nextInt();
            scale = "1:" + number;

            System.out.print("Enter Product Vendor: ");
            scan.nextLine();
            vendor = scan.nextLine();

            System.out.print("Enter Product Description: ");
            description = scan.nextLine();

            System.out.print("Enter Product Stock: ");
            stock = scan.nextShort();

            System.out.print("Enter Product Price: ");
            price = scan.nextDouble();

            System.out.print("Enter Product MSRP: ");
            MSRP = scan.nextDouble();

            String query = "INSERT INTO products VALUES (?,?,?,?,?,?,?,?,?)";
            try(PreparedStatement pst = conn.prepareStatement(query)){
                pst.setString(1, code);
                pst.setString(2, name);
                pst.setString(3, products_Listing.get(index));
                pst.setString(4, scale);
                pst.setString(5, vendor);
                pst.setString(6, description);
                pst.setShort(7, stock);
                pst.setDouble(8, price);
                pst.setDouble(9, MSRP);
                if(pst.executeUpdate()==1){
                    System.out.println("- Product Created Successfully!");
                }
                else{
                    System.out.println("- Product Failed to Create!");
                }
                conn.close();
            }
            catch (SQLException e) {
                System.err.println("Error creating Product: " + e.getMessage());
            }
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    public static void viewProduct(){
        String code;
        try (Connection conn = ConnectDB.getConnection()){

            System.out.println("== V - View Product ==");

            scan.nextLine();
            do{
                System.out.print("Enter Product Code: ");
                code = scan.nextLine();
                if (!(products_Code.contains(code))){System.out.println("- Product Code is not found");}
            }while(!(products_Code.contains(code)));
            String query = "SELECT * FROM products WHERE productCode = ?";
            try (PreparedStatement pst = conn.prepareStatement(query)){
                pst.setString(1,code);
                try (ResultSet rst = pst.executeQuery()) {
                    if((rst.next())){
                        System.out.println("Current details:");
                        display_productdetails(rst);
                    }
                    else{
                        System.out.println("Error in Finding Product");
                    }
                }
            }catch (SQLException e) {
                System.err.println("Error viewing Product: " + e.getMessage());
            }
        }catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    private static void display_productdetails(ResultSet rst) throws SQLException {
        System.out.println("1. Code: " + rst.getString("productCode"));
        System.out.println("2. Name: " + rst.getString("productName"));
        System.out.println("3. Line: " + rst.getString("productLine"));
        System.out.println("4. Scale: " + rst.getString("productScale"));
        System.out.println("5. Vendor: " + rst.getString("productVendor"));
        System.out.println("6. Description: " + rst.getString("productDescription"));
        System.out.println("7. Stock: " + rst.getShort("quantityInStock"));
        System.out.println("8. Price: $" + rst.getDouble("buyPrice"));
        System.out.println("9. MSRP: $" + rst.getDouble("MSRP"));
    }

    public static void deleteProduct(){
        
        String code;
        try (Connection conn = ConnectDB.getConnection()){

            System.out.println("== D -Delete Product ==");
            System.out.println("- Warning Product May be not be deleted due to being used by Orders/Customers");
            scan.nextLine();
            do{
                System.out.print("Enter Product Code: ");
                code = scan.nextLine();
                if (!(products_Code.contains(code))){System.out.println("- Product Code is not found");}
            }while(!(products_Code.contains(code)));
            try (PreparedStatement pst = conn.prepareStatement("DELETE FROM products WHERE productCode = ?")){
                pst.setString(1,code);
                if(pst.executeUpdate()==1){
                    System.out.println("Deleted Product");
                }
                else{
                    System.out.println("Failed to Delete Product");
                }
            }
        }
        catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    public static void updateProduct(){
        int productl_index;
        int detail_index;
        String code;
        String update;
        double decimal_num;
        try (Connection conn = ConnectDB.getConnection()) {
            System.out.println("== U -Update  Product ==");
            scan.nextLine();

            do{
                System.out.print("Enter Product Code: ");
                code = scan.nextLine();
                if (!(products_Code.contains(code))){System.out.println("- Product Code is not found");}
            }while(!(products_Code.contains(code)));

            String query = "SELECT * FROM products WHERE productCode = ?";
            try (PreparedStatement pst = conn.prepareStatement(query)){
                pst.setString(1,code);
                try (ResultSet rst = pst.executeQuery()) {
                    if((rst.next())){
                        System.out.println("Current Product Details:");
                        display_productdetails(rst);
                        do{
                            System.out.print("Which should be Updated: ");
                            detail_index = scan.nextInt();
                            detail_index--;
                        } while (!((detail_index) >= 0 && (detail_index) < 9));
                        scan.nextLine();
                        switch (detail_index) {
                            case 0 -> System.out.println("- Error in updating product due to being connected to orders");
                            case 1 -> {
                                System.out.print("Enter New Name:");
                                update = scan.nextLine();
                                update_statment(conn, "productName", update, code, 1);
                            }
                            case 2 -> {
                                showlist(products_Listing);
                                do {
                                    System.out.print("Enter Product Line: ");
                                    productl_index = scan.nextInt();
                                    productl_index--;
                                    if ( productl_index < 0 ||  productl_index >= products_Listing.size()){System.out.println("- Product Listing not found");}
                                } while (productl_index < 0 || productl_index >= products_Listing.size());
                                update = products_Listing.get(productl_index);
                                update_statment(conn, "productLine", update, code, 1);
                            }
                            case 3 -> {
                                System.out.print("Enter New Scale (1:?): ");
                                int number = scan.nextInt();
                                update = "1:" + number;
                                update_statment(conn, "productScale", update, code, 1);
                            }
                            case 4 -> {
                                System.out.print("Enter New Vendor: ");
                                update = scan.nextLine();
                                update_statment(conn, "productVendor", update, code, 1);
                            }
                            case 5 -> {
                                System.out.print("Enter New Description: ");
                                update = scan.nextLine();
                                update_statment(conn, "productDescription", update, code, 1);
                            }
                            case 6 -> {
                                System.out.print("Enter New Value for Stock: ");
                                short short_num = scan.nextShort();
                                update = String.valueOf(short_num);
                                update_statment(conn, "quantityInStock", update, code, 2);
                            }
                            case 7 -> {
                                System.out.print("Enter New Price: ");
                                decimal_num = scan.nextDouble();
                                update = String.valueOf(decimal_num);
                                update_statment(conn, "buyPrice", update, code, 3);
                            }
                            case 8 -> {
                                System.out.print("Enter New MSRP: ");
                                decimal_num = scan.nextDouble();
                                update = String.valueOf(decimal_num);
                                update_statment(conn, "MSRP", update, code, 3);
                            }
                            default -> System.out.print("- Error in updating Product ");
                        }
                    }
                    else { System.out.println("- Product Not Found");}
                }
            }
        }
        catch (Exception e) {System.err.println("Error: " + e.getMessage());}
    }
    public static void update_statment(Connection conn, String column, String update,String code, int datatype){
        String query = "UPDATE products SET " + column + " = ? WHERE productCode = ?";
        try (PreparedStatement pst = conn.prepareStatement(query)) {
            switch (datatype) {
                case 1 -> pst.setString(1, update);
                case 2 -> pst.setShort(1, Short.parseShort(update));
                case 3 -> pst.setDouble(1, Double.parseDouble(update));
            }
            pst.setString(2,code);
            if(pst.executeUpdate()==1){System.out.println("Product Updated Successfully");}
            else{System.out.println("- Product Failed to Update");}
        }catch (SQLException e) {System.err.println("Error updating Product: " + e.getMessage());}
    }
    public static void viewOrder(){
        String code;
        try (Connection conn = ConnectDB.getConnection()){
            System.out.println("== V -View  Orders ==");
            scan.nextLine();
            do{
                System.out.print("Enter Product Code: ");
                code = scan.nextLine();
                if (products_Code.contains(code)){System.out.println("- Product Code is already being used");}
            }while(!(products_Code.contains(code)));
            System.out.print("Enter Year to view (ex. 2003): ");
            int year = scan.nextInt();
            String query = "SELECT o.orderNumber, YEAR(o.orderDate) AS orderDate, od.productCode AS productCode FROM orders o LEFT JOIN orderdetails od ON o.orderNumber=od.orderNumber WHERE YEAR(o.orderDate) = ? &&  productCode = ?";
            try (PreparedStatement pst = conn.prepareStatement(query)){
                pst.setInt(1,year);
                pst.setString(2,code);
                try(ResultSet rst = pst.executeQuery()){
                    System.out.println("Current Details:");
                    while((rst.next())){
                        //Display all Available Orders in that Year
                        System.out.print("1. OrderNumber:"+ rst.getInt("orderNumber"));
                        System.out.print("2. OrderDate:"+ rst.getInt("orderDate"));
                        System.out.println("3. ProductCode:"+ rst.getString("productCode"));
                    }
                }catch (SQLException e) {
                    System.err.println("Error viewing Orders: " + e.getMessage());
                }
            }
        }catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    private static void productLine() {
        try (Connection conn = ConnectDB.getConnection()){
            products_Listing.clear(); // empty arraylist
            String query = "SELECT productLine FROM productlines";
            try (PreparedStatement pst = conn.prepareStatement(query)) {
                try (ResultSet rst = pst.executeQuery()) {
                    while (rst.next()) {
                        products_Listing.add(rst.getString("productLine")); // read all product lines
                    }
                }
            }
        } catch (Exception e) {
            System.out.println("Error connecting to the database: " + e.getMessage());
        }
    }
    public static void productCode () {
        try (Connection conn = ConnectDB.getConnection()){
            products_Code.clear(); // empty arraylist
            String query = "SELECT productCode FROM products";
            try (PreparedStatement pst = conn.prepareStatement(query)) {
                try (ResultSet rst = pst.executeQuery()) {
                    while (rst.next()) {
                        products_Code.add(rst.getString("productCode")); // read all product codes
                    }
                }
            }
        } catch (Exception e) {
            System.out.println("Error connecting to the database: " + e.getMessage());
        }
    }
    public static void showlist(ArrayList<String> arr){
        int i = 0;
        for (String s : arr) {
            System.out.println((i + 1) + ": " + s);
            i++;
        }
    }

    private static void list(){
        try {
            productLine();
            productCode();
        } catch (Exception e) {
            System.out.println("Error connecting to the database: " + e.getMessage());
        }
    }

}
