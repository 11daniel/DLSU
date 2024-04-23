/**
 * An Exercise represents a specific physical activity. It includes the name of the exercise,
 * the amount of energy used when performing a single repetition of the exercise (energyUse),
 * exercise sets for the exercise, and the amount of rest in seconds (nRestTimer) to be had after every set.
 */
import java.util.*;

public class Exercise {
    private String name;
    private double energyUse;
    private ArrayList<Set> sets;
    private int nRestTimer;

    // TODO: Implement the logic for this constructor of Exercise
    /**
     * creates an Exercise object given the name and the amount of energy used. No rest timer will be set for the created Exericse object.
     * @param name name of the exercise
     * @param energyUse amount of energy used when performing the exercise
     */
    public Exercise (String name, double energyUse) {
        this.name = name;
        this.energyUse = energyUse;
    }

    // TODO: Implement the logic for this constructor of Exercise
    /**
     * creates an Exercise object given the name, the amount of energy used, and amount of rest in seconds to be had after every set.
     * @param name name of the exercise
     * @param energyUse amount of energy used when performing the exercise
     * @param nRestTimer amount of rest in seconds to be had after every set
     */
    public Exercise (String name, double energyUse, int nRestTimer) {
        this.name = name;
        this.energyUse = energyUse;
        this.nRestTimer = nRestTimer;
    }

    /**
     * adds a Set into the exercise, with the given repetition goal and weight
     * @param repGoal repetition goal for the set
     * @param weight amount of weight for the set
     */
    public void addSet(int repGoal, double weight) {
        this.sets.add(new Set(repGoal, weight));
    }

    /**
     * removes the sets registered into the exercise.
     */
    public void removeSets() {
        this.sets.clear();
    }

    /**
     * resets the sets' current repetitions to zero and marks them as unfinished.
     */
    public void resetSets() {
        for (Set set : sets) {
            set.resetReps();
        }
    }

    // TODO: Implement the logic for the getting the total volume for the (performed) exercise
    /**
     * returns the total volume for the given exercise. 
     * The volume of a set is equal to the number of reps performed multiplied by the amount of weight for the set. 
     * The total volume is calculated as the sum of the volumes for all sets of the exercise.
     * @return the total volume for the given exercise
     */
    public double getTotalVolume() {
        double totalVolume;
        double setVolume;
        setVolume = sets.getCurReps() * this.sets.getWeight(); 
        totalVolume += setVolume;
        return totalVolume;
    }

    /**
     * returns the name of the exercise.
     * @return the name of the exercise.
     */
    public String getName() {
        return this.name;
    }

    /**
     * returns the list of sets registered into the exercise.
     * @return list of sets registered into the exercise
     */
    public ArrayList<Set> getSets() {
        return this.sets;
    }

    /**
     * returns the amount of energy used for a single repetition of the exercise.
     * @return the amount of energy used for a single repetition of the exercise
     */
    public double getEnergyUse() {
        return this.energyUse;
    }

    /**
     * returns the amount of rest (in seconds) to be had after every set.
     * @return the amount of rest (in seconds) to be had after every set
     */
    public int getRestTimer() {
        return this.nRestTimer;
    }
}
