import java.util.ArrayList;

public class ClassroomTestScripts {

	public void addStudentToClassroom(Classroom c, Student s) {
		System.out.println("=========");
		System.out.println("Adding " + s.getName() + " ("+s.getGrade()+") to classroom...");
		boolean result = c.addStudent(s);
		System.out.println("Result: " + result);
	}

	public void displayGradeInfo(Classroom c) {
		System.out.println("==========");
		Student s = c.getHighestStudent();
		System.out.println("Highest grade of classroom belongs to " + s.getName() + " (" + s.getGrade() + ")");
		System.out.println("Class average: " + c.computeClassAverage());
	}

	public void printAllStudents(ArrayList<Student> studentList) {
		System.out.println("-----");
		for(Student s : studentList) {
			System.out.println(s.getName() + " - " + s.getGrade());
		}
	}

	public void removeStudents(Classroom c) {
		System.out.println("==========");
		System.out.println("Class before removal...");
		printAllStudents(c.getStudentList());

		System.out.println("-----");
		System.out.println("Removing index 3; status: " + c.removeStudent(3));
		System.out.println("Removing index 3; status: " + c.removeStudent(3));
		System.out.println("Removing Griffth; status: " + c.removeStudent("Griffth"));
		System.out.println("Removing Corkus; status: " + c.removeStudent("Corkus"));
		
		System.out.println("-----");
		System.out.println("Class after removal...");
		printAllStudents(c.getStudentList());
	}

	public void runTestScript() {
		Classroom classroom1 = new Classroom(20);

		Student s1 = new Student("Guts", 95.0);
		Student s2 = new Student("Griffth", 64.5);
		Student s3 = new Student("Casca", 100.0);
		Student s4 = new Student("Rickert", 85.9);
		
		addStudentToClassroom(classroom1, s1);
		addStudentToClassroom(classroom1, s2);
		addStudentToClassroom(classroom1, s3);
		addStudentToClassroom(classroom1, s4);

		displayGradeInfo(classroom1);
		removeStudents(classroom1);

		Classroom classroom2 = new Classroom(3);

		Student s5 = new Student("Judeau", 99.0);
		Student s6 = new Student("Pippin", 99.0);
		Student s7 = new Student("Corkus", 99.0);
		Student s8 = new Student("Gaston", 99.0);

		addStudentToClassroom(classroom2, s5);
		addStudentToClassroom(classroom2, s6);
		addStudentToClassroom(classroom2, s7);
		addStudentToClassroom(classroom2, s8);

		displayGradeInfo(classroom2);
		removeStudents(classroom2);
	}
}