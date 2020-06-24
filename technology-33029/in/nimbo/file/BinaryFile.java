package in.nimbo.file;

/**
 * Represents binary files in system e.g. "exe","o","lib",...
 */
public class BinaryFile extends NimboFile {

    public BinaryFile(String name, String directory, int size, String owner) {
        super(name, directory, size, owner);
    }
}
