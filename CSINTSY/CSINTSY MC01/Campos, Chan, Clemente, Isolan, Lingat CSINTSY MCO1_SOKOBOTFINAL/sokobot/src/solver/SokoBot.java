package solver;

import java.util.HashSet;
import java.util.PriorityQueue;

public class SokoBot {

    private PriorityQueue<State> openSet;
    private HashSet<State> visited;

    public SokoBot() {
        openSet = new PriorityQueue<>(new Compare());
        visited = new HashSet<>();
    }

    public String solveSokobanPuzzle(int width, int height, char[][] mapData, char[][] itemsData) {
        char[] moves = {'l', 'd', 'u', 'r'};
        State initial = new State(height, width, mapData, itemsData);

        return search(initial, moves);
    }

    // Acknowledgement: Used these references in implementing the code
    // https://www.tutorialspoint.com/greedy-best-first-search-algorithm-in-cplusplus
    // https://codegym.cc/groups/posts/a-search-algorithm-in-java?fbclid=IwAR3WiAoFAJHRbQRyoCsEgmlKzlZ-RexNOlluM2Q56sq-8PhZs90otzVYe9Y
    // (initially used A* search but used this as reference for GBFS given the similarities of both search)
    private String search(State initial, char[] moves) {
        openSet.clear();
        visited.clear();
        openSet.add(initial);

        while (!openSet.isEmpty()) {
            State node = openSet.poll();

            if (node.isGoalState()) {
                System.out.println(node.getPath());
                return node.getPath();
            }

            visited.add(node);
            expandState(node, moves);
        }
        return initial.getPath();
    }

    private void expandState(State node, char[] moves) {
        for (char move : moves) {
            if (node.isValid(move)) {
                State next = new State(node, move);
                if (!next.isDeadlock() && !openSet.contains(next) && !visited.contains(next)) {
                    openSet.add(next);
                }
            }
        }
    }
}

