import java.util.ArrayList;

/**
 * Classroom class that holds an ArrayList of Student class given a limit.
 */
public class Classroom {
   
   /**
    * 2 attributes of the class
    */
   private ArrayList<Student> studentList;
   private int classLimit;

   /**
    * The sole constructor of a Classroom class.
    * @param classLimit - integer value indicating the limit of Student instances the Classroom can hold
    */
   public Classroom(int classLimit) {
      this.classLimit = classLimit;
      this.studentList = new ArrayList<Student>();
   }

   // Aggregation style of an element addition
   /**
    * addStudent method that accepts a Student instance and adds it to the ArrayList
    * as long as within classLimit
    *
    * @param s - a Student instance
    * @return result - boolean value that corresponds to the operation's success
    */
   public boolean addStudent(Student s) {
      boolean result = false;

      if(this.studentList.size() < this.classLimit) {
         studentList.add(s);
         result = true;
      } 

      return result;
   }
   
   /* Composition style of an element addition 
      (not based on the current scenario)
      public boolean addStudent(String name, double grade) {
         boolean result = false;

         if(studentList.size() < this.classLimit) {
            studentList.add(new Student(name, grade));
            result = true;
         } 

         return result;
      }
   */

   /**
    * removeStudent method that deletes a Student instance from the ArrayList
    * 
    * @param index - the integer position of Student instance to remove
    * @return result - boolean value that corresponds to the operation's success
    */
   public boolean removeStudent(int index) {
      boolean result = false;

      if(index >= 0 && index < this.studentList.size()) {
         this.studentList.remove(index);
         result = true;
      }

      return result;
   }

   /**
    * removeStudent method that overloads the previous method
    *
    * @param name - String name value to delete from the ArrayList
    * @return result - boolean value that corresponds to the operation's success
    */
   public boolean removeStudent(String name) {
      boolean result = false;

      for(Student s : this.studentList) {
         if(s.getName().equals(name)) {
            this.studentList.remove(s);
            result = true;
            break;
         }
      }

      return result;
   }

   /**
    * A getter method for the studentList attribute
    *
    * @return studentList - all Student instances beloging to the Classroom in ArrayList format
    */
   public ArrayList<Student> getStudentList() {
      return this.studentList;
   }

   /**
    * getHighestStudent method to look for the Student instance with the highest grade
    *
    * @return highestSTudent - Student instance with the highest grade from the list
    */
   public Student getHighestStudent() {
      double highestGrade = 0.0;
      int index = 0;
      Student highestStudent;

      for(Student s : this.studentList) {
         if(s.getGrade() > highestGrade) {
            index = this.studentList.indexOf(s);
            highestGrade = this.studentList.get(index).getGrade();
         }
      }
      highestStudent = this.studentList.get(index);

      return highestStudent;
   }
   
   /**
    * computeClassAverage method to compute the overall average of all Student instances in the list
    *
    * @return average - computed average of grades in double value
    */
   public double computeClassAverage() {
      double sum = 0.0, average;

      for(Student s : this.studentList) {
         sum += s.getGrade();
      }
      average = sum / this.studentList.size();

      return average;
   }

}