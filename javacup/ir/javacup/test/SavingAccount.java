package ir.javacup.test;

public class SavingAccount  extends BankAccount {
    public SavingAccount(String customerNationalId, String accountNumber, double balance, double interestAmount) {
        super(customerNationalId, accountNumber, balance);
        this.interestAmount = interestAmount;
    }

    public void addInterest() {
        this.balance *= (1 + interestAmount);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof SavingAccount) {
            return ((SavingAccount) obj).accountNumber.equals(accountNumber) && ((SavingAccount) obj).customerNationalId.equals(customerNationalId);
        } else {
            return false;
        }
    }
}
