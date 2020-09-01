package ir.javacup.test;

public class s {
    public static void main(String[] args) {
        BankAccount sa = new SavingAccount("111", "222", 200.0, 0.2);
        BankAccount ca = new CheckingAccount("111", "222", 400.0, 100.0);
        System.out.println(sa.equals(ca));
        BankAccount ba1 = new BankAccount("111", "222", 200.0);
        BankAccount ba2 = new BankAccount("111", "222", 400.0);
        System.out.println(ba1.equals(ba2));
        ba1 = new BankAccount("111", "222", 200.0);
        ba2 = new BankAccount("111", "333", 300.0);
        System.out.println(ba1.equals(ba2));
        ba1 = new BankAccount("111", "222", 200.0);
        ba2 = new BankAccount("222", "222", 300.0);
        System.out.println(ba1.equals(ba2));
    }
}
