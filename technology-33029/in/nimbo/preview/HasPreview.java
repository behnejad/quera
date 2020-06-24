package in.nimbo.preview;

import java.io.InputStream;

/**
 * If our system can preview this file, this interface should be implemented.
 *
 * @param <T> type of preview content
 */
public interface HasPreview<T> {

    Preview<T> preview(InputStream in);
}
