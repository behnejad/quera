package ir.javacup.test;

public class CheckingAccount extends BankAccount {
    public CheckingAccount(String customerNationalId, String accountNumber, double balance, double overdraftAmount) {
        super(customerNationalId, accountNumber, balance);
        this.overdraftAmount = overdraftAmount;
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof CheckingAccount) {
            return ((CheckingAccount) obj).accountNumber.equals(accountNumber) && ((CheckingAccount) obj).customerNationalId.equals(customerNationalId);
        } else {
            return false;
        }
    }
}
