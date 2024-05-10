import java.util.Scanner;

public class Driver {

    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        
        while (true) {
            System.out.println("\n--- Main Menu ---");
            System.out.println("1. Manage Records");
            System.out.println("2. Manage Transactions");
            System.out.println("3. Generate Records");
            System.out.println("4. Exit");
            System.out.print("Select an option: ");
            
            int choice = scanner.nextInt();
            
            switch (choice) {
                case 1:
                    ManageRecordsMenu.manageRecords();
                    break;
                case 2:
                    Transaction.transaction_menu();
                    break;
                case 3:
                    GenerateRecords.generateRecordsMenu();;
                    break;
                case 4:
                    System.out.println("Exiting program");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
            
        }
        
    }
    
    
}
