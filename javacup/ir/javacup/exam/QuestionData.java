package ir.javacup.exam;

public class QuestionData {
    public final Medium source;
    public final Medium destination;

    public QuestionData(Medium source) {
        this(source, null);
    }

    public QuestionData(Medium underTest, Medium dest) {
        this.source = underTest;
        this.destination = dest;
    }
}
