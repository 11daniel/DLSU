/**
 * Student class which stores a student's name and grade.
 * <br>
 * In creating a Student instance, name and grade should be supplied.
 */
public class Student {
	/**
	 * 2 attributes of the Student class:
	 * name cannot be edited
	 */
	private final String name;
	private double grade;

	/**
	 * The sole constructor of Student class.
	 * @param name - a string representation of a student's name
	 * @param grade - student's grade in double value
	 */
	public Student(String name, double grade) {
		this.name = name;
		this.grade = grade;
	}

	/**
	 * A getter method for the name attribute.
	 * @return returns the name in String format
	 */
	public String getName() {
		return this.name;
	}

	/**
	 * A getter method for the grade attribute.
	 * @return returns the grade in double value
	 */
	public double getGrade() {
		return this.grade;
	}

	/**
	 * A setter method for the grade attribute.
	 * @param grade - student's grade in double value
	 */
	public void setGrade(double grade) {
		this.grade = grade;
	}
}





