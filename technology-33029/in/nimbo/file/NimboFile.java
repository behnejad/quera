package in.nimbo.file;

import java.util.Objects;

/**
 * Represents a file in system.
 */
public abstract class NimboFile {

    private String name;
    private String directory;
    private int size;
    private String owner;

    public NimboFile(String name, String directory, int size, String owner) {
        this.name = name;
        this.directory = directory;
        this.size = size;
        this.owner = owner;
    }

    public String getOwner() {
        return owner;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public String getDirectory() {
        return directory;
    }

    public void setDirectory(String directory) {
        this.directory = directory;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
        NimboFile nimboFile = (NimboFile) o;
        return name.equals(nimboFile.name) && directory.equals(nimboFile.directory);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, directory);
    }

    // Your Code

    @Override
    public String toString() {
        return name;
    }
}
