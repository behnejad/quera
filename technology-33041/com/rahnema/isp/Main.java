package com.rahnema.isp;

import java.util.Arrays;
import java.util.List;

import com.rahnema.isp.dao.TrafficUsageDao;
import com.rahnema.isp.domain.TrafficUsage;
import com.rahnema.isp.domain.User;
import com.rahnema.isp.service.TrafficUsageService;
import com.rahnema.isp.service.impl.TrafficUsageServiceImpl;

public class Main {

    public static void main(String[] args) {
        TrafficUsageService service = new TrafficUsageServiceImpl(new TrafficUsageDao() {
            User a100 = new User("a100", "Ali", 20);
            User a101 = new User("a101", "Hasan", 19);
            User a102 = new User("a102", "Mehri", 35);
            User a103 = new User("a103", "Babak", 54);
            User a104 = new User("a104", "Sara", 22);
            User a105 = new User("a105", "Reza", 33);
            User a106 = new User("a106", "Javad", 44);
            User a107 = new User("a107", "Mohammad", 55);
            User a108 = new User("a108", "Ali", 18);
            User a109 = new User("a109", "Elahe", 29);

            @Override
            public List<TrafficUsage> loadAll() {
                return Arrays.asList(
                        new TrafficUsage(a100, true, false, 100, "97/04/01"),
                        new TrafficUsage(a100, false, true, 150, "97/04/01"),
                        new TrafficUsage(a100, false, false, 100, "97/04/03"),
                        new TrafficUsage(a100, true, true, 100, "97/04/04"),
                        new TrafficUsage(a100, true, false, 100, "97/06/01"),
                        new TrafficUsage(a100, false, true, 150, "97/06/01"),

                        new TrafficUsage(a101, true, false, 90, "97/04/01"),
                        new TrafficUsage(a101, false, true, 100, "97/04/01"),
                        new TrafficUsage(a101, true, false, 90, "97/05/01"),
                        new TrafficUsage(a101, false, true, 100, "97/05/01"),

                        new TrafficUsage(a102, true, false, 90, "97/04/01"),
                        new TrafficUsage(a102, false, true, 100, "97/04/01"),
                        new TrafficUsage(a102, true, false, 90, "97/05/01"),
                        new TrafficUsage(a102, false, true, 100, "97/05/01"),

                        new TrafficUsage(a103, true, false, 100, "97/04/01"),
                        new TrafficUsage(a103, false, true, 100, "97/04/01"),
                        new TrafficUsage(a103, true, false, 100, "97/05/01"),
                        new TrafficUsage(a103, false, true, 100, "97/05/01"),

                        new TrafficUsage(a104, true, false, 100, "97/04/01"),
                        new TrafficUsage(a104, false, true, 100, "97/04/01"),
                        new TrafficUsage(a104, true, false, 100, "97/05/01"),
                        new TrafficUsage(a104, false, true, 100, "97/05/01"),

                        new TrafficUsage(a105, true, false, 100, "97/04/01"),
                        new TrafficUsage(a105, false, true, 100, "97/04/01"),
                        new TrafficUsage(a105, true, false, 100, "97/05/01"),
                        new TrafficUsage(a105, false, true, 100, "97/05/01"),
                        new TrafficUsage(a105, true, false, 100, "97/06/01"),
                        new TrafficUsage(a105, false, true, 100, "97/06/01"),

                        new TrafficUsage(a106, true, false, 100, "97/04/01"),
                        new TrafficUsage(a106, false, true, 100, "97/04/01"),
                        new TrafficUsage(a106, true, false, 100, "97/05/01"),
                        new TrafficUsage(a106, false, true, 100, "97/05/01"),

                        new TrafficUsage(a107, true, false, 100, "97/04/01"),
                        new TrafficUsage(a107, false, true, 100, "97/04/01"),
                        new TrafficUsage(a107, true, false, 100, "97/05/01"),
                        new TrafficUsage(a107, false, true, 100, "97/05/01"),

                        new TrafficUsage(a108, true, false, 100, "97/04/01"),
                        new TrafficUsage(a108, false, true, 100, "97/04/01"),
                        new TrafficUsage(a108, true, false, 100, "97/05/01"),
                        new TrafficUsage(a108, false, true, 100, "97/05/01"),

                        new TrafficUsage(a109, true, false, 400, "97/04/01"),
                        new TrafficUsage(a109, false, true, 200, "97/04/01"),
                        new TrafficUsage(a109, true, false, 100, "97/05/01"),
                        new TrafficUsage(a109, false, true, 300, "97/05/01")
                );
            }
        });

        List<User> socialMediaLovers = service.socialMediaLovers(97, 4);
        System.out.println("socialMediaLovers:");
        for (User user : socialMediaLovers) {
            System.out.println(user.getUserName());
        }

        List<User> downloadLovers = service.downloadLovers(97, 4);
        System.out.println("downloadLovers:");
        for (User user : downloadLovers) {
            System.out.println(user.getUserName());
        }
    }
}
