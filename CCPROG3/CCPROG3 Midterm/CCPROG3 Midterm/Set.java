/**
 * A Set represents consecutive repetitions with the same weight of an exercise. Each set
 * has a repetition goal (repGoal), amount of weight used, amount of repetitions performed (curReps), 
 * and whether it has been completed or not (bDone).
 */
public class Set {
    private int repGoal;
    private double weight;
    private int curReps;
    private boolean bDone;

    /**
     * creates a Set object with a given repetition goal and amount of weight
     * @param repGoal repetition goal to 'complete' the set
     * @param weight amount of weight used for the exercise during the set
     */
    public Set (int repGoal, double weight) {
        this.repGoal = repGoal;
        this.weight = weight;
        this.curReps = 0;
        this.bDone = false;
    }

    // TODO: Implement the logic for the addRep method
    /**
     * updates the current repetition count by 1. If the new repetition count reaches the repetition goal,
     * then the set is deemed as completed / done.
     */
    public void addRep() {
        curReps +=1;
        if (curReps == repGoal) {
            bDone = true;
        }
    }

    // TODO: Implement the logic for the resetReps method
    /**
     * resets the number of current repetition counts to zero and marks the set as incomplete / unfinished.
     */
    public void resetReps() {
        curReps = 0;
        bDone = false;
    }

    /**
     * returns the status of the set.
     * @return status of the set in regards to its completion
     */
    public boolean isDone() {
        return bDone;
    }

    /**
     * returns the repetition goal for the set
     * @return repetition goal for the set
     */
    public int getRepGoal() {
        return repGoal;
    }

    /**
     * returns the current amount repetitions performed in the set
     * @return current amount repetitions performed in the set
     */
    public int getCurReps() {
        return curReps;
    }

    /**
     * returns the amount of weight used in the set
     * @return the amount of weight used in the set
     */
    public double getWeight() {
        return weight;
    }
}