package ir.javacup.traffic;

import java.util.List;

public class Context<T, I> {
    Observable<T> observableArrayList;
    Transformer<T, I> transformerArrayList;

    public Context<T, I> observable(Observable<T> observable) {
        observableArrayList = observable;
        return this;
    }

    public Context<T, I> transformer(Transformer<T, I> transformer) {
        transformerArrayList = transformer;
        return this;
    }

    public Context<T, I> subscriber(Subscriber<T> subscriber1) {
        observableArrayList.subscribe(subscriber1);
        return this;
    }

    public void run(List<I> inputs) {
        for (I i : inputs) {
            observableArrayList.push(transformerArrayList.transform(i));
        }
    }
}
