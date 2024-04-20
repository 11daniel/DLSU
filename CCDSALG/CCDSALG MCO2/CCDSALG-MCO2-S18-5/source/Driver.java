import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;

public class Driver
{
    public static void main(String args[])
    {
        Scanner inputScanner = new Scanner(System.in);
        String fileName;
        boolean flag;
        int counter1 = 0, counter2 = 0;
        int numAccounts = 0, numFriendships = 0;
        ArrayList<Integer> list = new ArrayList<Integer>(); // https://stackoverflow.com/questions/14421943/java-arraylist-for-integers

        // this checks if the inputted file exists, if it doesn't, program terminates immediately.
        try
        {
            System.out.print("Input the name of the file: ");
            fileName = inputScanner.nextLine();

            Scanner fileScanner = new Scanner(new FileReader(fileName));
            
            // scans every single integer in the file
            while(fileScanner.hasNext())
            {
                int intLine = fileScanner.nextInt();
                list.add(intLine);
                counter1++;
            }
            
            // assigns the number of nodes and connections to the variables and deletes them from the array.
            numAccounts = list.get(0);
            list.remove(0);
            numFriendships = list.get(0);
            list.remove(0);

            flag = true;
        }

        catch (FileNotFoundException e)
        {
            System.out.println("File not found!");
            flag = false;
        }

        // if flag is true, the data will start being graphed
        if(flag)
        {
            System.out.println("Graph Loaded!");
            Graph graph = new Graph(numAccounts, numFriendships, list);
            graph.graphData();

            // loop until user decides to quit
            do
            {
                flag = graph.menu();
            } while(flag == true);
            
        }
    }
}