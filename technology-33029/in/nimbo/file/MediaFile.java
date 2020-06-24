package in.nimbo.file;

/**
 * Represents media files in system e.g. "mp3","mp4","mkv",...
 */
public class MediaFile extends NimboFile {
    private int duration;

    public MediaFile(String name, String directory, int size, String owner, int duration) {
        super(name, directory, size, owner);
        this.duration = duration;
    }

    public int getDuration() {
        return duration;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

}
