import java.util.*;

public class Driver {
    private ArrayList<Exercise> exercises;
    private ArrayList<Workout> workouts;

    public Driver() {
        this.exercises = new ArrayList<Exercise>();
        this.workouts = new ArrayList<Workout>();

        setupExercises();
        setupWorkouts();
    }

    /**
     * initializes a sample list of exercises and its sets
     */
    private void setupExercises() {
        Exercise benchPress = new Exercise("Bench Press", 15, 90);
        benchPress.addSet(6, 30);
        benchPress.addSet(6, 50);
        benchPress.addSet(6, 50);
        exercises.add(benchPress);

        Exercise squats = new Exercise("Squats", 18, 120);
        squats.addSet(6, 50);
        squats.addSet(6, 70);
        squats.addSet(6, 70);
        exercises.add(squats);

        Exercise cableRows = new Exercise("Cable Rows", 5, 60);
        cableRows.addSet(8, 35);
        cableRows.addSet(8, 50);
        cableRows.addSet(8, 50);
        exercises.add(cableRows);

        Exercise deadlift = new Exercise("Deadlift", 20);
        deadlift.addSet(3, 120);
        exercises.add(deadlift);

        Exercise pullups = new Exercise("Pull-ups", 8, 60);
        pullups.addSet(6, 70);
        pullups.addSet(6, 70);
        pullups.addSet(6, 70);
        exercises.add(pullups);
    }

    /**
     * initializes a sample list of workouts from an earlier list of exercises.
     */
    private void setupWorkouts() {
        Workout fullBodyWorkout = new Workout("Full Body Workout");
        fullBodyWorkout.addExercise(exercises.get(0));
        fullBodyWorkout.addExercise(exercises.get(1));
        fullBodyWorkout.addExercise(exercises.get(3));
        fullBodyWorkout.addExercise(exercises.get(4));
        workouts.add(fullBodyWorkout);

        Workout backWorkout = new Workout("Back Workout");
        backWorkout.addExercise(exercises.get(2));
        backWorkout.addExercise(exercises.get(4));
        workouts.add(backWorkout);
    }

    /**
     * resets the sets of the exercises to have 0 current reps and to be marked as unfinished.
     */
    public void resetExercises() {
        for (Exercise exercise : exercises) {
            exercise.resetSets();
        }
    }

    public static void main(String[] args) {
        Driver app = new Driver();

        GymBro broseph = new GymBro("Broseph", 2000);
        broseph.performWorkout(app.workouts.get(0));
        System.out.println();
        System.out.println();
        broseph.displayRecords();

        // reset the rep counts for all exercises
        app.resetExercises();   

        GymBro brochelle = new GymBro("Brochelle", 1800);
        brochelle.performWorkout(app.workouts.get(1));
        System.out.println();
        System.out.println();
        brochelle.displayExerciseRecord("Pull-ups");

        System.out.println();
        // reset the rep counts for all exercises
        app.resetExercises();

        // After eating and resting, Brochelle attempts again
        brochelle.setEnergy(3000);
        brochelle.performWorkout(app.workouts.get(1));
        System.out.println();
        System.out.println();
        brochelle.displayExerciseRecord("Pull-ups");
    }
}
