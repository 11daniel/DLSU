package solver;
import java.util.Comparator; 

// Acknowledgement: This idea was inspired by the ManhDist class
// from GitHub: https://github.com/zzhongab/AI_Sokoban/blob/master/src/ManhDist.java
// Given the usage of priority queue, the comparator is used to know the priority of elements

public class Compare implements Comparator<State>{
    public int compare(State n1, State n2) {
        return n1.getHeuristic() - n2.getHeuristic();
    }
}
