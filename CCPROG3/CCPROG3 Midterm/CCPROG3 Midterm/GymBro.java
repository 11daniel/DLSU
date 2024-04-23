/**
 * A GymBro represents a person that performs the workouts. It includes the name of the person (name),
 * the amount of energy the person has (energy), and a list of exercise records (records).
 */
import java.util.ArrayList;

public class GymBro {
    // TODO: Declare the appropriate variables for the GymBro class
    private String name;
    private double energy;
    private ArrayList<ExerciseRecord> records = new ArrayList<ExerciseRecord>();
    // TODO: Implement the logic for the constructor of GymBro
    /**
     * creates a GymBro object given their name and the amount of energy they have.
     * @param name name of the person
     * @param energy amount of energy they have
     */
    public GymBro (String name, double energy) {
        this.name = name;
        this.energy = energy;
    }

    /**
     * performs the given workout. 
     * After completing an exercise for the workout, the method also updates the record for the exercise if records were broken.
     * @param workout given workout to perform.
     */
    public void performWorkout (Workout workout) {
        System.out.println("== " + this.name +" attempts to perform workout `" + workout.getName() + "` ==");
        
        for (Exercise exercise : workout.getExercises()) {
            // TODO: Retrieve the record for the exercise (if it exists)
            ExerciseRecord record = new ExerciseRecord(name) ;
            if (record == null) {
                record = new ExerciseRecord(exercise.getName());
                records.add(record);
            }

            System.out.println();
            System.out.println("----- Performing exercise " + exercise.getName() + ". -----");
            int setCount = 1;
            // Perform sets of the exercise
            for (Set set : exercise.getSets()) {
                System.out.println(" - Set " + setCount + " || Weight: " + set.getWeight() + " || Target: " + set.getRepGoal() + " reps - ");
                // Perform repetitions until the person no longer have enough energy or the set is completed
                while (this.energy > 0 && !set.isDone()) {
                    set.addRep();
                    this.energy -= exercise.getEnergyUse() * (set.getWeight() / 4);
                }
                System.out.println("\t" + this.name + " performed " + set.getCurReps() + " reps." );
                // TODO: Insert the code that increments the number of completed sets to the appropriate line
                if (set.isDone()) {
                    System.out.println("Set completed. Target repetitions reached.");

                } else {
                    System.out.println("Failed to complete the set. " + this.name + " ran out of energy.");

                }

                // Rest to replenish energy after the set (if applicable)
                this.energy += exercise.getRestTimer() * 5;
                setCount += 1;
            }

            // Check whether the total volume for the exercise exceeds the total volume record. 
            // If so, set the new max volume to the current total volume.
            double totalVolume = exercise.getTotalVolume();
            if (totalVolume > record.getMaxVolume())
                record.setMaxVolume(totalVolume);
        }
    }

    // TODO: Implement the logic for finding an exercise record given the exercise name
    /**
     * finds an exercise record of the person given the name of the exercise.
     * @param name the name of the exercise to find the record of
     * @return the exercise record from the given name. returns null if not found
     */
    private ExerciseRecord findRecord (String name) {
        if(name)

        return record;
    }

    /**
     * displays all exercise records that the person have. 
     * Does not return anything -- the information are printed directly into the console.
     */
    public void displayRecords() {
        if (records.size() == 0) {
            System.out.println("-- " + this.name + " has no records.--");
            return;
        }

        System.out.println("-- Displaying " + this.name + "'s records: --");
        System.out.println();
        for (ExerciseRecord record : records) {
            System.out.println("- Exercise `" + record.getName() + "` -");
            System.out.println("Number of sets completed: " + record.getNumSetCompleted());
            System.out.println("Maximum weight volume: " + record.getMaxVolume());
            System.out.println();
        }
        System.out.println();
    }

    /**
     * displays information regarding a specific exercise record given the exercise name (if it exists).
     * @param name the name of the exercise to display the record information for
     */
    public void displayExerciseRecord(String name) {
        // TODO: Retrieve the record for the exercise (if it exists)
        ExerciseRecord record = new ArrayList<Exercise>();

        if (record == null) {
            System.out.println("-- " + this.name + "'s record for exercise '"+  name + "' is not found. --");
            return;
        }
        System.out.println("-- Displaying " + this.name + "'s record for exercise '" + name + "': --");
        System.out.println("Number of sets completed: " + record.getNumSetCompleted());
        System.out.println("Maximum weight volume: " + record.getMaxVolume());
        System.out.println();
    }

    // TODO: Implement the logic for the setEnergy method
    /**
     * sets the energy of the person to the given amount
     * @param energy the amount of energy to set to the person
     */
    public void setEnergy(double energy) {

    }
}
