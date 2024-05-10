import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Scanner;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Iterator;

public class ManageOffice {

    private static Scanner scanner = new Scanner(System.in);

    public static void manageOffices() {
        while (true) {
            System.out.println("\n--- Manage Offices ---");
            System.out.println("1. Create a new Office");
            System.out.println("2. Update a record of an Office");
            System.out.println("3. Delete a record of an Office");
            System.out
                    .println("4. View a record of a specific Office and the list of employees assigned to the Office");
            System.out.println("5. Go Back");
            System.out.print("Select an option: ");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    createOffice();
                    break;
                case 2:
                    updateOffice();
                    break;
                case 3:
                    deleteOffice();
                    break;
                case 4:
                    viewOffice();
                    break;
                case 5:
                    return; // Go back to the previous menu
                default:
                    System.out.println("Invalid option! Please try again.");
            }
        }
    }

    public static void createOffice() {
        try (Connection connection = ConnectDB.getConnection()) {
            System.out.println("\n--- Create a new Office ---");
            scanner.nextLine(); // Consume newline character left-over

            java.util.function.Function<String, String> getNonEmptyInput = (String prompt) -> {
                String input;
                do {
                    System.out.print(prompt);
                    input = scanner.nextLine().trim();
                    if (input.isEmpty()) {
                        System.out.println("This field cannot be empty. Please enter a valid input.");
                    }
                } while (input.isEmpty());
                return input;
            };

            String officeCode = getNonEmptyInput.apply("Enter office code: ");
            String city = getNonEmptyInput.apply("Enter city: ");
            String phone = getNonEmptyInput.apply("Enter phone: ");
            String addressLine1 = getNonEmptyInput.apply("Enter address line 1: ");
            String addressLine2 = scanner.nextLine().trim(); // addressLine2 can be empty or null
            String state = getNonEmptyInput.apply("Enter state: ");
            String country = getNonEmptyInput.apply("Enter country: ");
            String postalCode = getNonEmptyInput.apply("Enter postal code: ");
            String territory = getNonEmptyInput.apply("Enter territory: ");

            String query = "INSERT INTO offices (officeCode, city, phone, addressLine1, addressLine2, state, country, postalCode, territory) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setString(1, officeCode);
                preparedStatement.setString(2, city);
                preparedStatement.setString(3, phone);
                preparedStatement.setString(4, addressLine1);
                if (addressLine2.isEmpty()) {
                    preparedStatement.setNull(5, java.sql.Types.VARCHAR); // Handle null for addressLine2
                } else {
                    preparedStatement.setString(5, addressLine2);
                }
                preparedStatement.setString(6, state);
                preparedStatement.setString(7, country);
                preparedStatement.setString(8, postalCode);
                preparedStatement.setString(9, territory);

                int rowsAffected = preparedStatement.executeUpdate();
                if (rowsAffected > 0) {
                    System.out.println("Office created successfully.");
                } else {
                    System.out.println("Failed to create office.");
                }
            }
        } catch (SQLException e) {
            System.err.println("Error creating office: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    
    public static void updateOffice() {
        try (Connection connection = ConnectDB.getConnection()) {
            // Prompt for the office number of the office to update
            System.out.println("\n--- Update Office ---");
            System.out.print("Enter office number of the office to update: ");
            int officeNumber = scanner.nextInt();
            scanner.nextLine(); // Consume newline character

            // Check if the office exists
            if (!officeExists(connection, officeNumber)) {
                System.out.println("Office with office number " + officeNumber + " does not exist.");
                return;
            }

            // Fetch existing details of the office from the database
            String query = "SELECT * FROM office WHERE officeNumber = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setInt(1, officeNumber);
                try (ResultSet resultSet = preparedStatement.executeQuery()) {
                    if (resultSet.next()) {
                        // Display current details of the office
                        System.out.println("Current details:");
                        System.out.println("Office Code: " + resultSet.getString("officeCode"));
                        System.out.println("City: " + resultSet.getString("city"));
                        System.out.println("Phone: " + resultSet.getString("phone"));
                        System.out.println("Address Line 1: " + resultSet.getString("addressLine1"));
                        System.out.println("Address Line 2: " + resultSet.getString("addressLine1"));
                        System.out.println("State: " + resultSet.getString("state"));
                        System.out.println("Country: " + resultSet.getInt("country"));
                        System.out.println("Postal Code: " + resultSet.getString("postalCode"));
                        System.out.println("Territory: " + resultSet.getString("territory"));

                        // Prompt user to update employee details 
                        System.out.println("Enter new details (leave blank to keep existing value):");
                        System.out.print("New Office Code: ");
                        String newOfficeCode = scanner.nextLine();
                        if (newOfficeCode.isEmpty()) {
                            newOfficeCode = resultSet.getString("officeCode"); // Keep existing value
                        }

                        System.out.print("New City: ");
                        String newCity = scanner.nextLine();
                        if (newCity.isEmpty()) {
                            newCity = resultSet.getString("city"); // Keep existing  value
                        }

                        System.out.print("New Phone: ");
                        String newPhone = scanner.nextLine();
                        if (newPhone.isEmpty()) {
                            newPhone = resultSet.getString("phone"); // Keep existing value
                        }

                        System.out.print("New Address Line 1: ");
                        String newAddressLine1 = scanner.nextLine();
                        if (newAddressLine1.isEmpty()) {
                            newAddressLine1 = resultSet.getString("email"); // Keep existing value
                        }

                        System.out.print("New Address Line 1: ");
                        String newAddressLine2 = scanner.nextLine();
                        if (newAddressLine2.isEmpty()) {
                            newAddressLine2 = resultSet.getString("officeCode"); // Keep existing value
                        }

                        System.out.print("New State: ");
                        String newState = scanner.nextLine();
                        if (newState.isEmpty()) {
                            newState = resultSet.getString("state"); // Keep existing value
                        }

                        System.out.print("New Job Title: ");
                        String newCountry = scanner.nextLine();
                        if (newCountry.isEmpty()) {
                            newCountry = resultSet.getString("country"); // Keep existing value
                        }

                        System.out.print("New Job Title: ");
                        String newPostalCode = scanner.nextLine();
                        if (newPostalCode.isEmpty()) {
                            newPostalCode = resultSet.getString("postalCode"); // Keep existing value
                        }

                        System.out.print("New Job Title: ");
                        String newTerritory = scanner.nextLine();
                        if (newTerritory.isEmpty()) {
                            newTerritory = resultSet.getString("territory"); // Keep existing value
                        }

                        // Update employee details in the database
                        updateOfficeDetails(connection, newOfficeCode, newCity, newPhone, newAddressLine1, newAddressLine2, newState, newCountry, newPostalCode, newTerritory); 
                        System.out.println("Office details updated successfully.");
                    } else {
                        System.out.println("Failed to fetch office details.");
                    }
                }
            }
        } catch (SQLException e) {
            System.err.println("Error updating office: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    public static void deleteOffice() {
        try (Connection connection = ConnectDB.getConnection()) {
            // Prompt for the office number of the office to delete
            System.out.println("\n--- Delete Office ---");
            System.out.print("Enter office number of the office to delete: ");
            int officeNumber = scanner.nextInt();
            scanner.nextLine(); // Consume newline character

            // Check if the office exists
            if (!officeExists(connection, officeNumber)) {
                System.out.println("Office with office number " + officeNumber + " does not exist.");
                return;
            }

            // Delete the office record from the database
            deleteOfficeRecord(connection, officeNumber);
            System.out.println("Office with office number " + officeNumber + " deleted successfully.");
        } catch (SQLException e) {
            System.err.println("Error deleting office: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    private static boolean officeExists(Connection connection, int officeNumber) throws SQLException {
        String query = "SELECT COUNT(*) FROM offices WHERE officeNumber = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setInt(1, officeNumber);
            try (ResultSet resultSet = preparedStatement.executeQuery()) {
                resultSet.next();
                int count = resultSet.getInt(1);
                return count > 0;
            }
        }
    }

    private static void updateOfficeDetails(Connection connection, String officeCode, String newCity, String newPhone,
            String newAddressLine1, String newAddressLine2, String newState, String newCountry, String newPostalCode,
            String newTerritory) throws SQLException {
        String query = "UPDATE offices SET city = ?, phone = ?, addressLine1 = ?, addressLine2 = ?, state = ?, country = ?, postalCode = ?, territory = ? WHERE officeCode = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setString(1, newCity);
            preparedStatement.setString(2, newPhone);
            preparedStatement.setString(3, newAddressLine1);
            preparedStatement.setString(4, newAddressLine2);
            preparedStatement.setString(5, newState);
            preparedStatement.setString(6, newCountry);
            preparedStatement.setString(7, newPostalCode);
            preparedStatement.setString(8, newTerritory);
            preparedStatement.setString(9, officeCode);
            preparedStatement.executeUpdate();
        }
    }

    private static void deleteOfficeRecord(Connection connection, int officeNumber) throws SQLException {
        String query = "DELETE FROM offices WHERE officeNumber = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setInt(1, officeNumber);
            preparedStatement.executeUpdate();
        }
    }

    public static void viewOffice() {
        try (Connection connection = ConnectDB.getConnection()) {
            // Prompt for the office number to view
            System.out.println("\n--- View Office ---");
            System.out.print("Enter office number to view: ");
            int officeNumber = scanner.nextInt();
            scanner.nextLine(); // Consume newline character

            // Fetch details of the office from the database
            String query = "SELECT * FROM offices WHERE officeNumber = ?";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setInt(1, officeNumber);
                try (ResultSet resultSet = preparedStatement.executeQuery()) {
                    if (resultSet.next()) {
                        // Display details of the office
                        System.out.println("Office Number: " + resultSet.getInt("officeNumber"));
                        System.out.println("City: " + resultSet.getString("city"));
                        System.out.println("Phone: " + resultSet.getString("phone"));
                        System.out.println("Address Line 1: " + resultSet.getString("addressLine1"));
                        System.out.println("Address Line 2: " + resultSet.getString("addressLine2"));
                        System.out.println("State: " + resultSet.getString("state"));
                        System.out.println("Country: " + resultSet.getString("country"));
                        System.out.println("Postal Code: " + resultSet.getString("postalCode"));
                        System.out.println("Territory: " + resultSet.getString("territory"));
                    } else {
                        System.out.println("Office with office number " + officeNumber + " does not exist.");
                    }
                }
            }
        } catch (SQLException e) {
            System.err.println("Error viewing office: " + e.getMessage());
        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

}
