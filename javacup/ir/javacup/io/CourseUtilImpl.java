package ir.javacup.io;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.ArrayList;

public class CourseUtilImpl implements CourseUtil {
    ArrayList<Grade> a = new ArrayList<>();
    ByteArrayOutputStream out;
    @Override
    public void setOutputStream(ByteArrayOutputStream out) {
        a.clear();
        this.out = out;
        String[] lines = out.toString().split(System.lineSeparator());
        for (String l : lines) {
            String[] ls = l.split(" ");
            Grade e = new Grade();
            e.setStudentId(ls[0]);
            e.setCourseCode(Integer.parseInt(ls[1]));
            e.setScore(Double.parseDouble(ls[2]));
            a.add(e);
        }
    }

    @Override
    public Grade load(int lineNumber) {
        if (lineNumber > a.size())
            return null;
        else
            return a.get(lineNumber - 1);
    }

    @Override
    public void save(Grade score) {
        if (a.contains(score)) {
            return;
        }

        for (Grade g : a) {
            if (g.equals(score)) {
                return;
            }
        }

        a.add(score);
        try {
            out.write(System.lineSeparator().getBytes());
            out.write(score.getStudentId().getBytes());
            out.write(" ".getBytes());
            out.write(Integer.toString(score.getCourseCode()).getBytes());
            out.write(" ".getBytes());
            out.write(Double.toString(score.getScore()).getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public double calcCourseAverage(int courseCode) {
        double sum = 0;
        int count = 0;
        for (Grade g : a) {
            if (g.getCourseCode() == courseCode) {
                ++count;
                sum += g.getScore();
            }
        }
        return sum / count;
    }

    @Override
    public double calcStudentAverage(String studentId) {
        double sum = 0;
        int count = 0;
        for (Grade g : a) {
            if (g.getStudentId().equals(studentId)) {
                ++count;
                sum += g.getScore();
            }
        }
        return sum / count;
    }

    @Override
    public int count() {
        return a.size();
    }
}
