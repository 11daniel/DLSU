import java.util.Scanner;
public class VendingMachineFactoryDriver
{
  public static void main (String[]args)
  {
	RegularVendingMachine vendingMachine = new RegularVendingMachine ();
	Scanner scanner = new Scanner (System.in);
	int choice;
	do
	  {
		System.out.println ("------ Vending Machine Factory ------");
		System.out.println ("1. Create a Regular Vending Machine");
		System.out.println ("2. Create a Special Vending Machine");
		System.out.println ("3. Test a Vending Machine");
		System.out.println ("4. Maintenance");
		System.out.println ("5. Exit");
		System.out.print ("Enter your choice: ");
		choice = scanner.nextInt ();
		switch (choice)
		  {
		  case 1:
			vendingMachine.createRegularVendingMachine (scanner);
			break;
			case 2:System.out.
			  println ("Special Vending Machines are not available
in Phase 1.");
			break;
			case 3:vendingMachine.testVendingMachine (scanner);
			break;
			case 4:MaintenanceMenu maintenanceMenu = new
			  MaintenanceMenu (vendingMachine, scanner);
			maintenanceMenu.startMaintenanceMenu ();
			break;
			case 5:System.out.println ("Exiting Vending Machine Factory.
Goodbye!");
			break;
			default:System.out.println ("Invalid choice. Please try again.");
		  }
	  }
	while (choice != 5);
	scanner.close ();
  }
}
