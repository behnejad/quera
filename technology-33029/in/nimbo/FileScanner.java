package in.nimbo;

import in.nimbo.file.NimboFile;


public interface FileScanner {

    /**
     * @param file scans given file.
     * @throws MalformedFileException if file is not normal.
     */
    void scanFile(NimboFile file) throws MalformedFileException;

    class MalformedFileException extends Exception {
    }
}
