package in.nimbo;

import in.nimbo.file.BinaryFile;
import in.nimbo.file.NimboFile;

import java.util.List;

public class SampleMain {
    public static void main(String[] args) {
        UserStorageRepository storageRepository = new UserStorageRepository();
        FileScanner scanner = new FScanner();
        FileRepository fileRepository = new FileRepository(storageRepository, scanner);
        storageRepository.increaseStorageOfUser("username", 5000);
        NimboFile file = new BinaryFile("test-file.exe", "/user/ali/", 2500, "ali");
        fileRepository.addFile(file);
        List<NimboFile> fileList = fileRepository.searchByName("t-f");
        System.out.println(fileList);
    }
}

// Sample stupid implementation of File Scanner
class FScanner implements FileScanner {
    @Override
    public void scanFile(NimboFile file) throws MalformedFileException {
    }
}
