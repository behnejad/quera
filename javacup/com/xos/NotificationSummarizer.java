package com.xos;

import java.util.List;

public interface NotificationSummarizer {

    List<Notification> summarize(List<Notification> notifications);

}
