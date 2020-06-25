package in.nimbo.file;

import in.nimbo.preview.HasPreview;
import in.nimbo.preview.Preview;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * Represents text files in system e.g. "txt","cpp","sh",...
 * Change this file and add preview to this class.
 */
public class TextFile extends NimboFile implements HasPreview<String> {

    public TextFile(String name, String directory, int size, String owner) {
        super(name, directory, size, owner);
    }

    @Override
    public Preview<String> preview(InputStream in) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        try {
            return new Preview<String>(reader.readLine());
        } catch (IOException e) {
            return null;
        }
    }
}
