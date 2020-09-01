package ir.javacup.test;

public class BankAccount {
    protected String customerNationalId;
    protected String accountNumber;
    protected double interestAmount;
    protected double balance;
    protected double overdraftAmount;

    public BankAccount(String customerNationalId, String accountNumber, double balance) {
        this.customerNationalId = customerNationalId;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public String getCustomerNationalId() {
        return customerNationalId;
    }

    public double getInterestAmount() {
        return interestAmount;
    }

    public double getBalance() {
        return balance;
    }

    public double getOverdraftAmount() {
        return overdraftAmount;
    }

    public void withdraw(double v) {
        if (v < 0) {
            throw new IllegalArgumentException("Sorry, you can not withdraw a negative amount");
        }
        if (v > balance) {
            throw new RuntimeException("Your balance is not enough");
        }
        balance -= v;
    }

    public void deposit(double v) {
        if (v > 0) {
            balance += v;
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof BankAccount) {
            return ((BankAccount) obj).accountNumber.equals(accountNumber) && ((BankAccount) obj).customerNationalId.equals(customerNationalId);
        } else {
            return false;
        }
    }
}
