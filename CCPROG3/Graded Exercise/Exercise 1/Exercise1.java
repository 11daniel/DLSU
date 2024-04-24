import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;
public class Exercise1
{
  public static void main (String[]args)
  {
	Scanner scanner = new Scanner (System.in);
	  System.out.print ("Enter date (mm-dd-yy or mm-dd-yyyy): ");
	String input = scanner.nextLine ();
	DateTimeFormatter inputFormatter;
	if (input.length () == 8)
	  {
		inputFormatter = DateTimeFormatter.ofPattern ("MM-dd-yy");
	  }
	else
	  {
		inputFormatter = DateTimeFormatter.ofPattern ("MM-dd-yyyy");
	  }
	LocalDate date = LocalDate.parse (input, inputFormatter);
	DateTimeFormatter outputFormatter = DateTimeFormatter.ofPattern ("MMM d,
yyyy");
	String formattedDate = date.format (outputFormatter);
	System.out.println (formattedDate);
	scanner.close ();
  }
}
