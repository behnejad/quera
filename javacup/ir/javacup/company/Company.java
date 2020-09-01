package ir.javacup.company;

public class Company {
    private Company() {

    }
    private String name = "JavaCup.co";
    private static Company c = new Company();
    public static Company getInstance() {
        return c;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
