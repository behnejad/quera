package com.rahnema.isp.service.impl;

import com.rahnema.isp.dao.TrafficUsageDao;
import com.rahnema.isp.domain.TrafficUsage;
import com.rahnema.isp.domain.User;
import com.rahnema.isp.service.TrafficUsageService;

import java.util.*;

public class TrafficUsageServiceImpl implements TrafficUsageService {
    private List<TrafficUsage> l;

    public TrafficUsageServiceImpl(TrafficUsageDao dao) {
        l = dao.loadAll();
    }

    @Override
    public List<User> socialMediaLovers(int year, int month) {
        List<User> res = new ArrayList<>();
        Map<User, Integer> active = new HashMap<>();
        String d = String.format(Locale.US, "%02d/%02d/", year, month);
        for (TrafficUsage x : l) {
            if (x.getDate().startsWith(d)) {
                int value = !x.isInternal() ? x.getUsage() : 0;
                User user = x.getUser();
                if (active.containsKey(user)) {
                    active.put(user, active.get(user) + value);
                } else {
                    active.put(user, value);
                }
            }
        }

        if (active.isEmpty()) {
            return res;
        }

        List<Integer> usage = new ArrayList<>();
        for (Map.Entry<User, Integer> entry : active.entrySet()) {
            usage.add(entry.getValue());
        }

        if (usage.size() < 10) {
            return res;
        }

        Collections.sort(usage);
        int size = usage.size();
        int index = (9 * (size - 1)) / 10;

        for (Map.Entry<User, Integer> entry : active.entrySet()) {
            int user_use = entry.getValue();
            for (int i = index + 1; i < size; ++i) {
                if (user_use == usage.get(i)) {
                    res.add(entry.getKey());
                }
            }
        }

        return res;
    }

    @Override
    public List<User> downloadLovers(int year, int month) {
        List<User> res = new ArrayList<>();
        Map<User, Integer> night = new HashMap<>();
        Map<User, Integer> day = new HashMap<>();
        String d = String.format(Locale.US, "%02d/%02d/", year, month);
        for (TrafficUsage x : l) {
            if (x.getDate().startsWith(d)) {
                User user = x.getUser();
                if (!res.contains(user)) {
                    res.add(user);
                    night.put(user, 0);
                    day.put(user, 0);
                }
                if (x.isNightly()) {
                    night.put(user, night.get(user) + x.getUsage());
                } else {
                    day.put(user, day.get(user) + x.getUsage());
                }
            }
        }
        res.removeIf(x -> night.get(x) <= day.get(x));
        return res;
    }
}
