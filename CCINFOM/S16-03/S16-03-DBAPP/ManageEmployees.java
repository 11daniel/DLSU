import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

public class ManageEmployees {
    private static Scanner scanner = new Scanner(System.in);

    public static void manageEmployees() throws Exception {
        while (true) {
            System.out.println("\n--- Manage Employees ---");
            System.out.println("1. Create a new Employee");
            System.out.println("2. Update a record of an Employee");
            System.out.println("3. Delete a record of an Employee");
            System.out.println("4. View a record of a specific Employee");
            System.out.println("5. Back");
            System.out.print("Select an option: ");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    createEmployee();
                    break;
                case 2:
                    updateEmployee();
                    break;
                case 3:
                    deleteEmployee();
                    break;
                case 4:
                    viewEmployee();
                    break;
                case 5:
                    return; 
                default:
                    System.out.println("Invalid option! Please try again.");
            }
        }
    }
    public static void createEmployee() {

        try (Connection connection = ConnectDB.getConnection()) {
            int availableEmployeeNumber = getAvailableEmployeeNumber(connection);
            System.out.println("\n--- Create a new Employee ---");
            scanner.nextLine(); 

            
            java.util.function.Function<String, String> getNonEmptyInput = (String prompt) -> {
                String input;
                do {
                    System.out.print(prompt);
                    input = scanner.nextLine().trim(); 
                    if(input.isEmpty()) {
                        System.out.println("This field cannot be empty. Please enter a valid input.");
                    }
                } while (input.isEmpty());
                return input;
            };

            
            String lastName = getNonEmptyInput.apply("Enter last name: ");
            String firstName = getNonEmptyInput.apply("Enter first name: ");
            String extension = getNonEmptyInput.apply("Enter extension: ");
            String email = getNonEmptyInput.apply("Enter email: ");
            String officeCode = getNonEmptyInput.apply("Enter office code: ");
            System.out.print("Enter reports to (leave blank if none): ");
            String reportsToString = scanner.nextLine().trim();
            Integer reportsTo = reportsToString.isEmpty() ? null : Integer.parseInt(reportsToString);
            String jobTitle = getNonEmptyInput.apply("Enter job title: ");

            String query = "INSERT INTO employees (employeeNumber, lastName, firstName, extension, email, officeCode, reportsTo, jobTitle) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setInt(1, availableEmployeeNumber);
                preparedStatement.setString(2, lastName);
                preparedStatement.setString(3, firstName);
                preparedStatement.setString(4, extension);
                preparedStatement.setString(5, email);
                preparedStatement.setString(6, officeCode);
                if (reportsTo != null) {
                    preparedStatement.setInt(7, reportsTo);
                } else {
                    preparedStatement.setNull(7, java.sql.Types.INTEGER); 
                }
                preparedStatement.setString(8, jobTitle);

                int rowsAffected = preparedStatement.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Employee created successfully.");
                } else {
                    System.out.println("Failed to create employee.");
                }
            }
        } catch (SQLException e) {
            System.err.println("Error creating employee: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    
    private static int getAvailableEmployeeNumber(Connection connection) throws SQLException {
        // Define the range
        final int startRange = 1000;
        final int endRange = 5000;
        
        String query = "SELECT employeeNumber FROM employees WHERE employeeNumber BETWEEN ? AND ? ORDER BY employeeNumber ASC";
        
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setInt(1, startRange);
            preparedStatement.setInt(2, endRange);
            
            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                int expectedNumber = startRange;
                
                while (resultSet.next()) {
                    int currentNumber = resultSet.getInt("employeeNumber");
                    
                    
                    if (currentNumber != expectedNumber) {
                        return expectedNumber; 
                    }
                    
                    
                    expectedNumber++;
                }
                
                
                return expectedNumber <= endRange ? expectedNumber : -1; 
            }
        }
    }

   /**
    * The `updateEmployee` function allows the user to update details of an employee in a database
    * after verifying the employee exists and displaying current details.
 * @throws Exception 
    */
    public static void updateEmployee() throws Exception {
        try (Connection connection = ConnectDB.getConnection()) {
            
            System.out.print("Enter employee number: ");
            int employeeNumber = scanner.nextInt();
            scanner.nextLine(); 
    
            
            String query = "SELECT * FROM employees WHERE employeeNumber = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setInt(1, employeeNumber);
                try (ResultSet resultSet = preparedStatement.executeQuery()) {
                    
                    if (resultSet.next()) {
                        System.out.println("\nCurrent Information:");
                        System.out.println("1. Last Name: " + resultSet.getString("lastName"));
                        System.out.println("2. First Name: " + resultSet.getString("firstName"));
                        System.out.println("3. Extension: " + resultSet.getString("extension"));
                        System.out.println("4. Email: " + resultSet.getString("email"));
                        System.out.println("5. Office Code: " + resultSet.getString("officeCode"));
                        System.out.println("6. Reports To: " + resultSet.getString("reportsTo"));
                        System.out.println("7. Job Title: " + resultSet.getString("jobTitle"));
                    } else {
                        System.out.println("Employee with employee number " + employeeNumber + " not found.");
                        return;
                    }
                }
            } catch (SQLException e) {
                System.err.println("Error executing SQL query: " + e.getMessage());
            }
            
            
            System.out.print("\nEnter the number of the field you want to change: ");
            int option = scanner.nextInt();
            scanner.nextLine(); 
    
            String columnName;
            switch (option) {
                case 1:
                    columnName = "lastName";
                    break;
                case 2:
                    columnName = "firstName";
                    break;
                case 3:
                    columnName = "extension";
                    break;
                case 4:
                    columnName = "email";
                    break;
                case 5:
                    columnName = "officeCode";
                    break;
                case 6:
                    columnName = "reportsTo";
                    break;
                case 7:
                    columnName = "jobTitle";
                    break;
                default:
                    System.out.println("Invalid option.");
                    return;
            }
            
            
            System.out.print("Enter new value: ");
            String newValue = scanner.nextLine();
            
            
            String updateQuery = "UPDATE employees SET " + columnName + " = ? WHERE employeeNumber = ?";
            try (PreparedStatement updateStatement = connection.prepareStatement(updateQuery)) {
                updateStatement.setString(1, newValue);
                updateStatement.setInt(2, employeeNumber);
                int rowsAffected = updateStatement.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Employee information updated successfully.");
                } else {
                    System.out.println("Failed to update employee information.");
                }
            } catch (SQLException e) {
                System.err.println("Error executing SQL update: " + e.getMessage());
            }
        } catch (SQLException e) {
            System.err.println("Error establishing database connection: " + e.getMessage());
        }
    }
    
/**
 * The `deleteEmployee` function deletes an employee record from the database based on the employee
 * number provided by the user.
 */

    public static void deleteEmployee() {
        try (Connection connection = ConnectDB.getConnection()) {
            System.out.println("\n--- Delete Employee ---");
            System.out.print("Enter employee number of the employee to delete: ");
            int employeeNumber = scanner.nextInt();
            scanner.nextLine(); 

            if (!employeeExists(connection, employeeNumber)) {
                System.out.println("Employee with employee number " + employeeNumber + " does not exist.");
                return;
            }

            deleteEmployeeRecord(connection, employeeNumber);
            System.out.println("Employee with employee number " + employeeNumber + " deleted successfully.");
        } catch (SQLException e) {
            System.err.println("Error deleting employee: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

  /**
   * The function checks if an employee with a specific employee number exists in the database.
   * 
   * @param connection The `connection` parameter is an object of type `Connection` which represents a
   * connection to a database. It is used to communicate with the database to execute SQL queries and
   * retrieve results.
   * @param employeeNumber The `employeeNumber` parameter is an integer value representing the unique
   * identifier of an employee. This method `employeeExists` checks if an employee with the specified
   * `employeeNumber` exists in the database table `employees`. It executes a SQL query to count the
   * number of rows where the `employeeNumber`
   * @return The method `employeeExists` returns a boolean value indicating whether an employee with
   * the specified employee number exists in the database. It returns `true` if the count of employees
   * with the given employee number is greater than 0, and `false` otherwise.
   */
    private static boolean employeeExists(Connection connection, int employeeNumber) throws SQLException {
        String query = "SELECT COUNT(*) FROM employees WHERE employeeNumber = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setInt(1, employeeNumber);
            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                resultSet.next();
                int count = resultSet.getInt(1);
                return count > 0;
            }
        }
    }

  

  /**
   * The function `deleteEmployeeRecord` deletes an employee record from a database table, updating
   * referencing records first.
   * 
   * @param connection The `connection` parameter in the `deleteEmployeeRecord` method is of type
   * `Connection` and represents the connection to the database. This connection is used to execute SQL
   * queries and statements within the method to delete an employee record from the database.
   * @param employeeNumber The `deleteEmployeeRecord` method takes two parameters:
   */
    private static void deleteEmployeeRecord(Connection connection, int employeeNumber) throws SQLException {
        // Update referencing records first
        String updateQuery = "UPDATE employees SET reportsTo = NULL WHERE reportsTo = ?";
        try (PreparedStatement updateStatement = connection.prepareStatement(updateQuery)) {
            updateStatement.setInt(1, employeeNumber);
            updateStatement.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Error updating referencing records: " + e.getMessage());
            throw e; 
        }
    
        String deleteQuery = "DELETE FROM employees WHERE employeeNumber = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(deleteQuery)) {
            preparedStatement.setInt(1, employeeNumber);
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            System.err.println("Error deleting employee: " + e.getMessage());
            throw e; 
        }
    }
    


   public static void viewEmployee() {
    try (Connection connection = ConnectDB.getConnection()) {
        System.out.println("\n--- View Employee and List of Customers Handled ---");
        System.out.print("Enter employee number: ");
        int employeeNumber = scanner.nextInt();

        String employeeQuery = "SELECT * FROM employees WHERE employeeNumber = ?";
        try (PreparedStatement employeeStatement = connection.prepareStatement(employeeQuery)) {
            employeeStatement.setInt(1, employeeNumber);
            try (ResultSet employeeResultSet = employeeStatement.executeQuery()) {
                if (employeeResultSet.next()) {
                    System.out.println("Employee Details:");
                    System.out.println("Employee Number: " + employeeResultSet.getInt("employeeNumber"));
                    System.out.println("Last Name: " + employeeResultSet.getString("lastName"));
                    System.out.println("First Name: " + employeeResultSet.getString("firstName"));
                    System.out.println("Extension: " + employeeResultSet.getString("extension"));
                    System.out.println("Email: " + employeeResultSet.getString("email"));
                    System.out.println("Office Code: " + employeeResultSet.getString("officeCode"));
                    System.out.println("Reports To: " + employeeResultSet.getInt("reportsTo"));
                    System.out.println("Job Title: " + employeeResultSet.getString("jobTitle"));

                    System.out.println("\nCustomers Handled:");
                    String customersQuery = "SELECT customerName FROM customers WHERE salesRepEmployeeNumber = ?";
                    try (PreparedStatement customersStatement = connection.prepareStatement(customersQuery)) {
                        customersStatement.setInt(1, employeeNumber);
                        try (ResultSet customersResultSet = customersStatement.executeQuery()) {
                            int count = 0;
                            while (customersResultSet.next()) {
                                count++;
                                System.out.println(count + ". " + customersResultSet.getString("customerName"));
                            }
                            if (count == 0) {
                                System.out.println("No customers assigned to this Employee.");
                            }
                        }
                    }
                } else {
                    System.out.println("Employee with employee number " + employeeNumber + " does not exist.");
                }
            }
        }
    } catch (SQLException e) {
        System.err.println("Error viewing employee and customers: " + e.getMessage());
    } catch (Exception e) {
        System.err.println("Error: " + e.getMessage());
    }
}



}