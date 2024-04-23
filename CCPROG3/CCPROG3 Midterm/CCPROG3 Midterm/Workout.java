/**
 * A Workout represents a series of exercises to be performed by a person.
 * It includes the name of the workout and the list of exercises to be performed, in order.
 */
import java.util.*;

public class Workout {
    private String name;
    private ArrayList<Exercise> exercises;

    /**
     * creates a Workout object given the workout's name.
     * @param name the name of the workout
     */
    public Workout(String name) {
        this.name = name;
        this.exercises = new ArrayList<Exercise>();
    }

    /**
     * adds an exercise into the list of exercises to perform.
     * @param exercise the exercise to be performed in the workout
     */
    public void addExercise(Exercise exercise) {
        this.exercises.add(exercise);
    }

    /**
     * removes an exercise from the list of exercises to perform, given the name of the exercise.
     * If the exercise is not found, nothing will be removed.
     * @param name the name of the exrcise to remove
     */
    public void removeExercise(String name) {
        for (int i = 0; i < exercises.size(); i++) {
            Exercise exercise = exercises.get(i);
            if (exercise.getName().equals(name)) {
                exercises.remove(i);
                break;
            }
        }
    }

    /**
     * returns the name of the workout.
     * @return the name of the workout
     */
    public String getName() {
        return this.name;
    }

    /**
     * returns the list of exercises to be performed.
     * @return the list of exercises to be performed
     */
    public ArrayList<Exercise> getExercises() {
        return this.exercises;
    }
}
