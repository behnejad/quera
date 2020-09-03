package ir.javacup.traffic.impl;

import ir.javacup.traffic.Observable;
import ir.javacup.traffic.Subscriber;

import java.util.ArrayList;

public class TrafficObservable implements Observable<TrafficInfo> {
    ArrayList<Subscriber<TrafficInfo>> arrayList = new ArrayList<>();
    @Override
    public void push(TrafficInfo obj) {
        for (Subscriber<TrafficInfo> i : arrayList) {
            i.onNext(obj);
        }
    }

    @Override
    public void subscribe(Subscriber<TrafficInfo> subscriber) {
        arrayList.add(subscriber);
    }
}
