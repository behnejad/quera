package ir.javacup.db;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public abstract class AbstractRepository<U, T extends IEntity<U>> implements IRepository<U, T> {
    private Map<U, T> repo = new HashMap<>();
    private IdGenerator<U> idGenerator;

    public AbstractRepository(IdGenerator<U> idGenerator) {
        this.idGenerator = idGenerator;
    }

    @Override
    public void save(T entity) {
        if (entity == null) {
            throw new IllegalArgumentException();
        }
        U id = idGenerator.generate();
        entity.setId(id);
        repo.put(id, entity);
    }

    @Override
    public void update(T entity) {
        if (entity == null || entity.getId() == null) {
            throw new IllegalArgumentException();
        }
        if (!repo.containsKey(entity.getId())) {
            throw new RuntimeException();
        }
        repo.put(entity.getId(), entity);
    }

    @Override
    public T load(U id) {
        return repo.getOrDefault(id, null);
    }

    @Override
    public List loadAll() {
        return Arrays.asList(repo.values().toArray());
    }

    @Override
    public void delete(U id) {
        if (!repo.containsKey(id)) {
            throw new RuntimeException();
        }
        repo.remove(id);
    }

    @Override
    public void deleteAll() {
        repo.clear();
    }
}
