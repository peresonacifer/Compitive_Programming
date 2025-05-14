package ACJAVA;

public class BankAccount {
    private String accountNumber;
    private double balance;

    public BankAccount(String accountNumber) {
        this.accountNumber = accountNumber;
        this.balance = 0.0;
    }
    
    public BankAccount(String accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }
    
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            // System.out.println("成功存入：" + amount);
        } else {
            System.out.println("存款金額必須大於零。");
        }
    }

    public void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            System.out.println("提領金額必須大於零且小於或等於餘額才能提款");
        } else {
            balance -= amount;
            // System.out.println("成功提取：" + amount);
        }
    }
    
    public double getBalance() {
        return balance;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public static void main(String[] args) {

        BankAccount account1 = new BankAccount("account1");
        account1.deposit(1000.0);
        account1.withdraw(500.0);
        System.out.println("帳號：" + account1.getAccountNumber());
        System.out.println("餘額：" + account1.getBalance());

        BankAccount account2 = new BankAccount("account2", 2000.0);
        account2.deposit(1000.0);
        account2.withdraw(4000.0); // 會顯示錯誤訊息
        System.out.println("帳號：" + account2.getAccountNumber());
        System.out.println("餘額：" + account2.getBalance());
    }
}
