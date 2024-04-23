/**
 * An ExerciseRecord represents a person's record regarding a specific exercise. It contains the exercise's name,
 * the maximum total volume that the person have performed in a single workout, and the total (lifetime) number of sets completed
 * for the given exercise. 
 */
public class ExerciseRecord {
    private String exerciseName;
    private double maxVolume;
    private int numSetCompleted;

    /**
     * creates an ExerciseRecord object given the name of the exercise.
     * The maximum total volume and number of sets completed are initialized as zero.
     * @param exerciseName the name of the exercise which the record is for
     */
    public ExerciseRecord(String exerciseName) {
        this.exerciseName = exerciseName;
        this.maxVolume = 0;
        this.numSetCompleted = 0;
    }

    /**
     * sets the new maximum total volume for the exercise record.
     * @param newMax the new maximum total volume for the exercise record
     */
    public void setMaxVolume(double newMax) {
        this.maxVolume = newMax;
    }

    /**
     * increments the number of sets completed by 1.
     */
    public void addNumSetCompleted() {
        this.numSetCompleted += 1;
    }

    /**
     * returns the number of sets completed for the given exercise.
     * @return the number of sets completed for the given exercise
     */
    public int getNumSetCompleted() {
        return this.numSetCompleted;
    }

    /**
     * returns the name of the exercise which the record is for.
     * @return the name of the exercise which the record is for
     */
    public String getName() {
        return this.exerciseName;
    }

    /**
     * returns the maximum total volume that the person have performed in a single workout for this exercise.
     * @return the maximum total volume that the person have performed in a single workout
     */
    public double getMaxVolume() {
        return this.maxVolume;
    }
}
