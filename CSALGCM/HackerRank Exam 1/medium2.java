//Combination Card Game

import java.io.*;
import java.util.*;

public class medium2 {
    public static int r;
    public static long tp;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        String[] parts = br.readLine().trim().split(" ");
        int n = Integer.parseInt(parts[0]);
        int k = Integer.parseInt(parts[1]);
        Card[] cards = new Card[n];

        for(int i = 0; i < n; i++) {
            parts = br.readLine().trim().split(" ");
            int power = Integer.parseInt(parts[1]);
            cards[i] = new Card(parts[0], power);
        }

        solve(n, k, cards);
        System.out.printf("%d %d\n", r, tp);
    }

    /*
    Solves a test case.

    Parameters:
    n : int - number of cards available
    k : int - number of cards to include in Jason's deck
    cards : array-like - array of Card objects

    Save the answers to the static variables r and tp where:
    r  : int - number of red cards added
    tp : long - total power of cards in your deck
    */
    public static void solve(int n, int k, Card[] cards) {
        // Convert Card array to a list of AbstractMap.SimpleEntry (Boolean, Integer)
        List<Map.Entry<Boolean, Integer>> cardList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            boolean isRed = cards[i].color.equals("red");
            int power = cards[i].power;
            cardList.add(new AbstractMap.SimpleEntry<>(isRed, power));
        }

        // Sort the list based on the criteria specified
        Collections.sort(cardList, new Comparator<Map.Entry<Boolean, Integer>>() {
            @Override
            public int compare(Map.Entry<Boolean, Integer> o1, Map.Entry<Boolean, Integer> o2) {
                // Sort by isRed (true first), and by power (descending order)
                if (o1.getKey().equals(o2.getKey())) {
                    return Integer.compare(o2.getValue(), o1.getValue());
                } else {
                    return Boolean.compare(o2.getKey(), o1.getKey());
                }
            }
        });

        // Initialize r and tp
        r = 0;
        tp = 0;

        // Iterate through the sorted list and calculate r and tp
        for (int i = 0; i < k; i++) {
            boolean isRed = cardList.get(i).getKey();
            int power = cardList.get(i).getValue();
            if (isRed) {
                r++;
            }
            tp += power;
        }
    }
}

class Card {
    public String color;
    public int power;

    public Card(String color, int power) {
        this.color = color;
        this.power = power;
    }
}
