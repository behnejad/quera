package in.nimbo.preview;

public class Preview<T> {

    private T content;

    public Preview(T content) {
        this.content = content;
    }

    public T getContent() {
        return content;
    }
}
