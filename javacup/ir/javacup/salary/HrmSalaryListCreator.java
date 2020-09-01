package ir.javacup.salary;

public class HrmSalaryListCreator extends SalaryListCreator {
    public HrmSalaryListCreator(Encoder encoder) {
        super(encoder);
    }

    @Override
    protected String doCreate(Employee[] employees) {
        String res = "";
        if (employees.length == 1) {
            return addZeroPrefix(employees[0].getCode(), 8) +
                    getItemSeparator() +
                    addZeroPrefix(String.valueOf(employees[0].getSalary()), 10);
        }
        for (int i = 0; i < employees.length - 1; ++i) {
            res += addZeroPrefix(employees[i].getCode(), 8) +
                    getItemSeparator() +
                    addZeroPrefix(String.valueOf(employees[i].getSalary()), 10) +
                    getRecordSeparator();
        }
        res += addZeroPrefix(employees[employees.length - 1].getCode(), 8) +
                getItemSeparator() +
                addZeroPrefix(String.valueOf(employees[employees.length - 1].getSalary()), 10);
        return res;
    }
}
