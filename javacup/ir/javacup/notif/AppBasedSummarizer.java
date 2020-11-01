package ir.javacup.notif;

import com.xos.Notification;
import com.xos.NotificationSummarizer;
import com.xos.Priority;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class AppBasedSummarizer implements NotificationSummarizer {

    @Override
    public List<Notification> summarize(List<Notification> notifications) {
        ArrayList<Notification> list = new ArrayList<>();

        HashSet<String> apps = new HashSet<>();
        for (Notification notification : notifications) {
            apps.add(notification.getApp());
        }

        for (String app : apps) {
            ArrayList<Notification> applist = new ArrayList<>();
            for (Notification n : notifications) {
                if (n.getApp().equals(app)) {
                    applist.add(n);
                }
            }

            applist.sort((o1, o2) -> {
                int oi1 = change(o1.getPriority());
                int oi2 = change(o2.getPriority());
                if (oi1 > oi2) {
                    return -1;
                } else if (oi1 < oi2) {
                    return 1;
                } else {
                    return o2.getTime().compareTo(o1.getTime());
                }
            });

            list.add(applist.get(0));
        }

        list.sort((o1, o2) -> {
            int oi1 = change(o1.getPriority());
            int oi2 = change(o2.getPriority());
            if (oi1 > oi2) {
                return -1;
            } else if (oi1 < oi2) {
                return 1;
            } else {
                return o2.getTime().compareTo(o1.getTime());
            }
        });

        return list;
    }

    private int change(Priority p) {
        switch (p) {
            case LOW:
                return 0;
            case DEFAULT:
                return 1;
            case HIGH:
                return 2;
            default:
                return -1;
        }
    }
}
