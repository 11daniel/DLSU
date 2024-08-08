//Soulmate Heuristics

import java.util.*;

public class hard1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] ages = new int[n];
        for (int i = 0; i < n; i++) {
            ages[i] = scanner.nextInt();
        }
        
        int[][] queries = new int[k][4];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 4; j++) {
                queries[i][j] = scanner.nextInt();
            }
        }

        List<Integer> results = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            int s1 = queries[i][0];
            int e1 = queries[i][1];
            int s2 = queries[i][2];
            int e2 = queries[i][3];
            int result = solve(n, ages, s1, e1, s2, e2);
            results.add(result);
        }

        for (int result : results) {
            System.out.println(result);
        }

        scanner.close();
    }

    private static int solve(int n, int[] ages, int s1, int e1, int s2, int e2) {
        int[] family1 = Arrays.copyOfRange(ages, s1 - 1, e1);
        int[] family2 = Arrays.copyOfRange(ages, s2 - 1, e2);

        int dannyAge = family1[0];

        Arrays.sort(family1);
        Arrays.sort(family2);

        int dannyOrder = family1.length - 1 - indexOf(family1, dannyAge);
        
        int soulmateAge = family2[family2.length - 1 - dannyOrder];
        
        return soulmateAge;
    }

    private static int indexOf(int[] array, int value) {
        for (int i = 0; i < array.length; i++) {
            if (array[i] == value) {
                return i;
            }
        }
        return -1;
    }
}
