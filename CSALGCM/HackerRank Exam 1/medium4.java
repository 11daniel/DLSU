//Dance-off-Protected Sovereignty

import java.io.*;
import java.util.*;

public class medium4 {
    public static int win_a, win_b;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] parts = br.readLine().trim().split(" ");
        int a = Integer.parseInt(parts[0]);
        int b = Integer.parseInt(parts[1]);
        int[] r_i = new int[a];
        int[] s_j = new int[b];

        for(int i = 0; i < a; i++) {
            r_i[i] = Integer.parseInt(br.readLine().trim());
        }
        
        for(int i = 0; i < b; i++) {
            s_j[i] = Integer.parseInt(br.readLine().trim());
        }

        solve(a,b,r_i,s_j);

        System.out.printf("%d %d\n",win_a,win_b);
    }    

    /*
    Solves a test case

    Parameters:
    a   : int   - number of leaders in Hamiltonia
    b   : int   - number of leaders in Burrgadia
    r_i : int[] - dance proficiencies of Hamiltonia's leaders
    s_j : int[] - dance proficiencies of Burrgadia's leaders

    Saves the following values in the given static variables:
    win_a : int - number of wins from Hamiltonia
    win_b : int - number of wins from Burrgadia
    */
    public static void solve(int a, int b, int[] r_i, int[] s_j) {
        // TODO
        Arrays.sort(r_i);
        Arrays.sort(s_j);

        win_a = 0;
        win_b = 0;

        int matches = Math.min(a, b);

        if (a < b) {
            // Hamiltonia chooses matchups optimally
            int j = 0;
            for (int i = 0; i < a; i++) {
                if (j < b && r_i[i] > s_j[j]) {
                    win_a++;
                    j++;
                }
            }
            win_b = matches - win_a;
        } else {
            // Burrgadia chooses matchups optimally
            int i = 0;
            for (int j = 0; j < b; j++) {
                if (i < a && s_j[j] > r_i[i]) {
                    win_b++;
                    i++;
                }
            }
            win_a = matches - win_b;
        }
    }
}