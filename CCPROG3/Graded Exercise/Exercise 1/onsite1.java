import java.util.*;
class onsite1
{
  public static void main (String[]args)
  {
	Scanner scanner = new Scanner (System.in);
	  System.out.println ("Enter date : ");
	String InputDate = scanner.nextLine ();
	String mm = InputDate.substring (0, 2);
	String dd = InputDate.substring (3, 5);
	String yy = InputDate.substring (6);
	switch (mm)
	  {
	  case "01":
		System.out.print ("Jan");
		break;
		case "02":System.out.print ("Feb");
		break;
		case "03":System.out.print ("Mar");
		break;
		case "04":System.out.print ("Apr");
		break;
		case "05":System.out.print ("May");
		break;
		case "06":System.out.print ("Jun");
		break;
		case "07":System.out.print ("Jul");
		break;
		case "08":System.out.print ("Aug");
		break;
		case "09":System.out.print ("Sep");
		break;
		case "10":System.out.print ("Oct");
		break;
		case "11":System.out.print ("Nov");
		break;
		case "12":System.out.print ("Dec");
		break;
	  }
	switch (dd)
	  {
	  case "01":
		System.out.print (" 01,");
		break;
	  case "02":
		System.out.print (" 02,");
		break;
	  case "03":
		System.out.print (" 03,");
		;
		break;
	  case "04":
		System.out.print (" 04,");
		break;
	  case "05":
		System.out.print (" 05,");
		break;
	  case "06":
		System.out.print (" 06,");
		break;
	  case "07":
		System.out.print (" 07,");
		break;
	  case "08":
		System.out.print (" 08,");
		break;
	  case "09":
		System.out.print (" 09,");
		break;
	  default:
		System.out.print (" " + dd + ",");
	  }
	if (yy.length () == 1)
	  {
		System.out.println (" 200" + yy);
	  }
	else if (yy.length () == 2)
	  {
		System.out.println (" 20" + yy);
	  }
	else
	  {
		System.out.println (" " + yy);
	  }
	scanner.close ();
  }
}
