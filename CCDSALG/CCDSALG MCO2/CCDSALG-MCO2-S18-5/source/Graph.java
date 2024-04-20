import java.util.*;
import java.io.*;

/* 
 * Resources I used to create this:
 * https://www.programiz.com/dsa/graph-adjacency-list
 * https://www.youtube.com/watch?v=OffNesBSRA4
 * https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
 * https://www.geeksforgeeks.org/find-if-there-is-a-path-between-two-vertices-in-a-given-graph/
 * https://www.geeksforgeeks.org/print-paths-given-source-destination-using-bfs/
*/

public class Graph
{
    private int numAccounts; // vertices
    private int numFriendships; // edges
    private ArrayList<Integer> data; // connections
    private LinkedList<Integer> list[]; // array of adjacency lists with index n being the nth account/vertex

    // constructor method for Graph class
    public Graph(int numAccounts, int numFriendships, ArrayList<Integer> data)
    {
        this.numAccounts = numAccounts;
        this.numFriendships = numFriendships;
        this.data = data;

        list = new LinkedList[numAccounts];

        for(int i = 0; i < this.numAccounts; i++)
            list[i] = new LinkedList(); // create a linked list for every node
    }

    // testing if the raw data matches the numbers in the text file
    public void testPrintRawData()
    {
        int i = 0;

        System.out.println("numAccounts: "+numAccounts);
        System.out.println("numFriendships: " +numFriendships);

        while (data.size() > i)
        {
	        System.out.println(data.get(i));
	        i++;
        }
    }

    // graphing algorithm that utilizes adjacency lists
    public void graphData()
    {
        // integer to represent the current node
        int j = 0;

        // loops until end of the array
        for(int i = 0; i < data.size(); i++)
        {
            // see the report for the explanation of this code
            if (i%2 == 0)
            {
                if (j == data.get(i+1))
                {
                    // System.out.println(data.get(i)+" "+data.get(i+1)); // for testing
                    addEdge(data.get(i), data.get(i+1));
                }

                else if (j+1 == data.get(i+1))
                {
                    // System.out.println(data.get(i)+" "+data.get(i+1)); // for testing
                    addEdge(data.get(i), data.get(i+1));
                    j++;
                }
            }
        }
    }

    // adds the node to index node of the array of linked lists
    public void addEdge(int v1, int v2)
    {
        list[v1].add(v2);
    }

    // asks the user for the index (node) and prints its direct connections if it exists
    public void viewFriendlist(int index)
    {
        int i = 0;

        if(index > this.numAccounts || index < 0)
        {
            System.out.println("INVALID INDEX!");
        }

        else
        {
            System.out.println("Person "+index+" has "+list[index].size()+" friends.");
            System.out.println("List of Friends: ");
            while (list[index].size() > i)
            {
                System.out.print(list[index].get(i)+" ");
                i++;
            }

            System.out.println(" ");
        }
    }

    // asks user for two indices if they choose the connections and checks for the validity of the indices.
    public void displayConnections(int index1, int index2)
    {
        boolean flag;

        if((index1 < 0 || index1 > this.numAccounts) || (index2 < 0 || index2 > this.numAccounts))
        {
            System.out.println("INVALID INPUTTED INDEX/INDICES!");
        }

        else if(index1 == index2)
        {
            System.out.println("Node "+index1+" has no connection with itself!");
        }

        else
        {
            flag = checkConnection(index1, index2);

            if (flag)
            {
                System.out.println("There is a connection from "+index1+" to "+index2+".");
                getConnection(index1, index2);
            }
            
            else
            {
                System.out.println("There is no connection between "+index1+" to "+index2+".");
            }
        }
    }

    // prints the path from destination A to B
    public void printPath(List<Integer> path)
    {
        System.out.println("Here are the paths: ");
        
        for(Integer v : path)
        {
            System.out.print(v+" ");
        }

        System.out.println();
    }

    // checks if the given node x is inside the linked list by searching it. Returns false if it is found and true if not
    public boolean isNotVisited(int x, List<Integer> path)
    {
        int size = path.size();

        for(int i = 0; i < size; i++)
        {
            if (path.get(i) == x)
                return false;
        }

        return true;
    }

    // this Breadth-First Search Algorithm sourced online (please see the links above) 
    public void getConnection(int index1, int index2)
    {
        Queue<List<Integer>> queue = new LinkedList();
        List<Integer> path = new ArrayList<>();
        path.add(index1);
        queue.offer(path);

        while(!queue.isEmpty())
        {
            path = queue.poll();

            int last = path.get(path.size()-1);

            if (last == index2)
            {
                printPath(path);
            }

            List<Integer> lastNode = list[last];

            for(int i = 0; i < lastNode.size(); i++)
            {
                if (isNotVisited(lastNode.get(i), path))
                {
                    List<Integer> newPath = new ArrayList<>(path);
                    newPath.add(lastNode.get(i));
                    queue.offer(newPath);
                }
            }
        }
    }

    // this Breadth-First Search Algorithm checks if a path exists fron start to destination. Returns true if yes and false if not.
    public boolean checkConnection(int start, int destination)
    {
        LinkedList<Integer> temp;
        boolean visited[] = new boolean[numAccounts];
        LinkedList<Integer> queue = new LinkedList<Integer>();

        visited[start] = true;
        queue.add(start);

        Iterator<Integer> i;

        while(queue.size() != 0)
        {
            start = queue.poll();

            int n;
            i = list[start].listIterator();

            while(i.hasNext())
            {
                n = i.next();

                if(n == destination)
                    return true;
                
                if(!visited[n])
                {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }

        return false;
    }

    // main menu of the program
    public boolean menu()
    {
        int dChoice, dChoice2, index1, index2;
        boolean flag = false;
        Scanner s = new Scanner(System.in);

        System.out.println("MAIN MENU");
        System.out.println("[1] Get Friend List");
        System.out.println("[2] Get Connection");
        System.out.println("[3] Exit");

        do
        {
            dChoice = s.nextInt();
        } while(dChoice != 1 && dChoice != 2 && dChoice != 3);

        switch(dChoice)
        {
            case 1:
                System.out.print("Enter ID of Person: ");
                dChoice2 = s.nextInt();
                viewFriendlist(dChoice2);
                flag = true;
                break;

            case 2:
                System.out.print("Enter Index 1: ");
                index1 = s.nextInt();
                System.out.print("Enter Index 2: ");
                index2 = s.nextInt();

                displayConnections(index1, index2);

                flag = true;
                break;

            case 3:
                flag = false;
        }

        return flag;
    }

    // getters and setters: 

    public int getNumAccounts()
    {
        return this.numAccounts;
    }

    public int getNumFriendships()
    {
        return this.numFriendships;
    }
}