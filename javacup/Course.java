import java.util.ArrayList;

public class Course {
	private String name;
	private ArrayList<Student> a = new ArrayList<>(10);

	public boolean register(Student s) {
		if (a.size() == 10) {
			return false;
		} else {
			a.add(s);
			return true;
		}
	}

	public int getNumOfStudents() {
		return a.size();
	}

	public Student[] getStudents() {
		return (Student[]) a.toArray();
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	
}

