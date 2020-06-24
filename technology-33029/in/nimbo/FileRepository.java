package in.nimbo;

import in.nimbo.file.NimboFile;

import java.util.*;
import java.util.function.Consumer;
import java.util.function.Predicate;

/**
 * Manages users files.
 */
public class FileRepository {

    // Do not change properties!
    private FileScanner scanner;
    private UserStorageRepository storageRepository;
    private Set<NimboFile> files = new HashSet<>();

    public FileRepository(UserStorageRepository storageRepository, FileScanner scanner) {
        this.storageRepository = storageRepository;
        this.scanner = scanner;
    }

    /**
     * if user has enough storage, add the file to files list.
     *
     * @param file file to be added.
     * @throws IllegalArgumentException if user has not enough storage
     */
    public void addFile(NimboFile file) {
        // Your Code
        if (storageRepository.hasStorage(file.getOwner(), file.getSize())) {
            storageRepository.decreaseStorageOfUser(file.getOwner(), file.getSize());
            files.add(file);
        } else {
            throw new IllegalArgumentException();
        }
    }

    /**
     * returns files that their name match the search query. Search is case-insensitive. File Extension should be
     * ignored.
     *
     * @param name search query
     * @return list of files which match the search query
     */
    public List<NimboFile> searchByName(String name) {
        // Your Code
        List<NimboFile> res = new ArrayList<>();
        String i = name.toLowerCase();
        for (NimboFile x : files) {
            String j = x.getName();
            if (j.contains(".")) {
                int index = j.lastIndexOf(".");
                j = j.substring(0, index);
            }
            if (j.contains(i)) {
                res.add(x);
            }
        }
        return res;
    }

    /**
     * Scans all files with {@link FileScanner}. Removes malformed files and return storage to their owners.
     */
    public void scan() {
        for (NimboFile i : files) {
            try {
                scanner.scanFile(i);
            } catch (FileScanner.MalformedFileException e) {
                storageRepository.increaseStorageOfUser(i.getOwner(), i.getSize());
                files.remove(i);
            }
        }
    }

    /**
     * Sorts all files with respect of given comparator.
     *
     * @param comparator to be used in sort algorithm.
     * @return array of sorted files.
     */
    public NimboFile[] sort(Comparator<NimboFile> comparator) {
        // Your Code
        return null;
    }

    /**
     * Check if given file can be previewed or not.
     *
     * @return true if file can be previewed.
     */
    public boolean isPreviewable(NimboFile file) {
        // Your Code
        return false;
    }

    /**
     * Finds a media file with longest duration in the given directory.
     *
     * @param directory given directory to search in
     * @return one of longest media files wrapped in Optional if exists or Optional.empty()
     */
    public Optional<NimboFile> findLongestMediaInDirectory(String directory) {
        // Your Code
        return Optional.empty();
    }

    /**
     * Applies given function to all files that match the filter.
     *
     * @param filter   files are filtered by this Predicate
     * @param function functions which will be applied to files
     */
    public void applyToAllByFilter(Predicate<NimboFile> filter, Consumer<NimboFile> function) {
        // Your Code
    }
}
