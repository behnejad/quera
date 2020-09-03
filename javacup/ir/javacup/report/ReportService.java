package ir.javacup.report;

import java.util.*;

public class ReportService {
    List<Information> informationList;

    public ReportService(InformationRepository repository) {
        informationList = repository.fetchAll();
    }

    public List<CityInformation> sumByCity(int year) {
        Map<String, Long> cityInformationSet = new HashMap<>();

        for (Information information : informationList) {
            if (Integer.parseInt(information.getDate().split("/")[0]) == year) {
                if (cityInformationSet.containsKey(information.getCity())) {
                    cityInformationSet.put(information.getCity(), cityInformationSet.get(information.getCity()) + information.getAmount());
                } else {
                    cityInformationSet.put(information.getCity(), information.getAmount());
                }
            }
        }

        ArrayList<String> names = new ArrayList<>(cityInformationSet.keySet());
        names.sort(String::compareToIgnoreCase);

        List<CityInformation> res = new ArrayList<>();
        for (String name : names) {
            CityInformation e = new CityInformation();
            e.setCity(name);
            e.setSum(cityInformationSet.get(name));
            res.add(e);
        }

        return res;
    }

    public List<CityMonthInformation> averageByCityAndMonth(int year) {
        HashMap<String, long[]> set = new HashMap<>();

        for (Information information : informationList) {
            String[] split = information.getDate().split("/");
            if (Integer.parseInt(split[0]) == year) {
                long[] a;
                if (set.containsKey(information.getCity())) {
                    a = set.get(information.getCity());
                    a[Integer.parseInt(split[1]) - 1] += information.getAmount();
                } else {
                    a = new long[12];
                    a[Integer.parseInt(split[1]) - 1] = information.getAmount();
                }
                set.put(information.getCity(), a);
            }
        }

        ArrayList<String> names = new ArrayList<>(set.keySet());
        names.sort(String::compareToIgnoreCase);

        List<CityMonthInformation> res = new ArrayList<>();
        for (String city : names) {
            long[] months = set.get(city);
            for (int i = 0; i < 12; ++i) {
                if (months[i] != 0) {
                    CityMonthInformation c = new CityMonthInformation();
                    c.setCity(city);
                    c.setMonth(i + 1);
                    if (i < 6) {
                        c.setAverage(months[i] / 31.0);
                    } else {
						c.setAverage(months[i] / 30.0);
                    }
                    res.add(c);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        ReportService service = new ReportService(new InformationRepository() {
            @Override
            public List<Information> fetchAll() {
                return Arrays.asList(
                        new Information("Kerman", "1395/03/11", 62L), new Information("Tehran", "1395/09/12", 90L),
                        new Information("Tehran", "1396/11/30", 31L), new Information("Semnan", "1396/01/13", 93L)
                );
            }
        });

        List<CityInformation> sumResults = service.sumByCity(1396);
        System.out.printf("sum total: %d%n", sumResults.size());
        CityInformation sumFirst = sumResults.get(0);
        System.out.printf("1: %s %d%n", sumFirst.getCity(), sumFirst.getSum());
        CityInformation sumSecond = sumResults.get(1);
        System.out.printf("2: %s %d%n", sumSecond.getCity(), sumSecond.getSum());

        List<CityMonthInformation> avgResults = service.averageByCityAndMonth(1395);
        System.out.printf("avg total: %d%n", avgResults.size());
        CityMonthInformation avgFirst = avgResults.get(0);
        System.out.printf("1: %s %d %f%n", avgFirst.getCity(), avgFirst.getMonth(), avgFirst.getAverage());
        CityMonthInformation avgSecond = avgResults.get(1);
        System.out.printf("2: %s %d %f%n", avgSecond.getCity(), avgSecond.getMonth(), avgSecond.getAverage());
    }

}
