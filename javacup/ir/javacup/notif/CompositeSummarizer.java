package ir.javacup.notif;

import com.xos.Notification;
import com.xos.NotificationSummarizer;

import java.util.List;

public class CompositeSummarizer implements NotificationSummarizer {
    List<NotificationSummarizer> summarizers;

    public CompositeSummarizer(List<NotificationSummarizer> summarizers) {
        this.summarizers = summarizers;
    }

    @Override
    public List<Notification> summarize(List<Notification> notifications) {
        List<Notification> res = notifications;
        for (NotificationSummarizer summarizer : summarizers) {
            res = summarizer.summarize(res);
        }

        return res;
    }

}
