import java.util.*;
import java.util.Formatter;

public class Practice1 {
    public static void main(String[] args){
        // initialize variables
		int n, i;
        // has to be double since will be working with Math.sqrt()
		double total = 0, sum = 0, diff = 0, average, std;
		
        // creating scanner object for input
		Scanner sc = new Scanner(System.in);
        // accept number of values to input and compute
		n = sc.nextInt();
		
        // display divider
		System.out.println("---------------");
		
        // create an array to store float values
		double[] nums = new double[n];
		
        // accepts n number of input
		for(i=0; i<n; i++){
			nums[i] = sc.nextDouble();
		}

        // close the input stream after use
        sc.close();
		
        // compute for the total of all values
		for(i=0; i<n; i++){
			total = total + nums[i];
		}
		
        // compute for the average using total
		average = total / n;
        // loop through each values to compute the numerator
		for(i=0; i<n; i++){
            // get the absolute difference of current input and average
			diff = Math.abs(nums[i]-average);
            // get the square of the difference and total them
			sum = sum + (diff*diff); 
		}
		//std = Math.sqrt(sum/n-1);
        std = Math.sqrt(sum/n);
		
		System.out.println("---------------");
		System.out.println("Avg: " + String.format("%.2f", average));
		Formatter formatter = new Formatter();
		formatter.format("%.2f", std);
		System.out.println("Std: " + formatter.toString());
        formatter.close();
	}
}
