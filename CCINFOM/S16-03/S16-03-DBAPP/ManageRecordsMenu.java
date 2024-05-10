

import java.util.Scanner;

public class ManageRecordsMenu {
    
        private static Scanner scanner = new Scanner(System.in);
    
        public static void manageRecords() throws Exception {
            while (true) {
                System.out.println("\n--- Manage Records ---");
                System.out.println("1. Manage Products");
                System.out.println("2. Manage Customers");
                System.out.println("3. Manage Employees");
                System.out.println("4. Manage Offices");
                System.out.println("5. Go Back");
                System.out.print("Select an option: ");
                
                int choice = scanner.nextInt();
                
                switch (choice) {
                    case 1:
                        products.products_menu();
                        break;
                    case 2:
                        //func call here
                        break;
                    case 3:
                        ManageEmployees.manageEmployees();
                        break;
                    case 4:
                        ManageOffice.manageOffices();
                        break;
                    case 5:
                        return; 
                    default:
                        System.out.println("Invalid option! Please try again.");
                }
            }
        }
    
    }

