package in.nimbo;

import java.util.HashMap;
import java.util.Map;

/**
 * Manages user's storage size.
 */
public class UserStorageRepository {

    // Do not change this line!
    private Map<String, Integer> userStorageMap = new HashMap<>();

    /**
     * Increase storage of given user by given size. If given user does not exists, it creates the user.
     */
    public void increaseStorageOfUser(String user, int size) {
        if (userStorageMap.containsKey(user)) {
            userStorageMap.put(user, userStorageMap.get(user) + size);
        } else {
            userStorageMap.put(user, size);
        }
    }

    /**
     * Check if user has at least given storage. If user does not exits false is returned.
     */
    public boolean hasStorage(String user, int size) {
        if (userStorageMap.containsKey(user)) {
            return userStorageMap.get(user) >= size;
        } else {
            return false;
        }
    }

    /**
     * Decrease user storage by given size. If user does not have enough storage, should be deleted.
     */
    public void decreaseStorageOfUser(String user, int size) {
        if (userStorageMap.containsKey(user)) {
            if (userStorageMap.get(user) <= size) {
                userStorageMap.remove(user);
            } else {
                userStorageMap.put(user, userStorageMap.get(user) - size);
            }
        }
    }
}
