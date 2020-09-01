package ir.javacup.salary;

public class FmSalaryListCreator extends SalaryListCreator {
    public FmSalaryListCreator(Encoder encoder) {
        super(encoder);
    }

    @Override
    protected String doCreate(Employee[] employees) {
        String res = "";
        if (employees.length == 1) {
            return addZeroPrefix(String.valueOf(employees[0].getSalary()), 10) +
                    getItemSeparator() +
                    addZeroPrefix(employees[0].getCode(), 10);
        }
        for (int i = 0; i < employees.length - 1; ++i) {
            res += addZeroPrefix(String.valueOf(employees[i].getSalary()), 10) +
                    getItemSeparator() +
                    addZeroPrefix(employees[i].getCode(), 10) +
                    getRecordSeparator();
        }
        res += addZeroPrefix(String.valueOf(employees[employees.length - 1].getSalary()), 10) +
                getItemSeparator() +
                addZeroPrefix(employees[employees.length - 1].getCode(), 10);
        return res;
    }
}
