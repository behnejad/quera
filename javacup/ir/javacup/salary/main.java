package ir.javacup.salary;

public class main {
    public static void main(String[] args) {
        HrmSalaryListCreator creator = new HrmSalaryListCreator(new Encoder() {
            @Override
            public String encode(String str) {
                return super.encode(str);
            }
        });
        Employee[] employees = new Employee[2];
        employees[0] = new Employee("71235", 1_500_000);
        employees[1] = new Employee("03451", 3_200_000);
        System.out.println(creator.doCreate(employees));

//        FmSalaryListCreator creator = new FmSalaryListCreator(new Encoder() {
//            @Override
//            public String encode(String str) {
//                return super.encode(str);
//            }
//        });
//        Employee[] employees = new Employee[2];
//        employees[0] = new Employee("31235", 2_000_000);
//        employees[1] = new Employee("00531", 1_200_000);
//        System.out.println(creator.doCreate(employees));
    }
}
