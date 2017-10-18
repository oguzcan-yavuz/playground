using System;

class BankAccountPublic {
// BankaAccountPublic.cs
    public decimal GetAmount() {
        return 1000.0m;
    }
}

class BankAccountPrivate {
    private string customerName;

    public string CustomerName {
        get { return customerName; }
        set { customerName = value; }
    }
}

class BankAccountProtected {
    public void CloseAccount() {
        ApplyPenalties();
        CalculateFinalInterest();
        DeleteAccountDB();
    }

    protected internal virtual void ApplyPenalties() {
        // deduct from account
    }

    protected virtual void CalculateFinalInterest() {
        // add from account
    }

    protected internal virtual void DeleteAccountDB() {
        // send notification to data entry personal
        Console.WriteLine("Protected DeleteAccountDB method!");
    }
}

class SavingAccounts : BankAccountProtected {

    protected internal override void ApplyPenalties() {
        Console.WriteLine("Saving Account Applying Penalties");
    }

    protected override void CalculateFinalInterest() {
        Console.WriteLine("Saving Account calculating interest");
    }

    protected internal override void DeleteAccountDB() {
        base.DeleteAccountDB();
        Console.WriteLine("Saving Account Delete Customer Info");
    }
}

class CheckingAccount : BankAccountProtected {

    protected internal override void ApplyPenalties() {
        Console.WriteLine("Checking Account Applying Penalties");
    }

    protected override void CalculateFinalInterest() {
        Console.WriteLine("Checking Account calculating interest");
    }

    protected internal override void DeleteAccountDB() {
        base.DeleteAccountDB();
        Console.WriteLine("Checking Account Delete Customer Info");
    }
}

class Program {
    public static void Main(string[] args) {
        BankAccountPublic bpublic = new BankAccountPublic();
        BankAccountProtected bprotected = new BankAccountProtected();
        BankAccountPrivate bprivate = new BankAccountPrivate();
        CheckingAccount check = new CheckingAccount();
        SavingAccounts save = new SavingAccounts();

        Decimal amount = bpublic.GetAmount();
        bprivate.CustomerName = "Mahmut";
        string customer = bprivate.CustomerName;
        Console.WriteLine("Amount: {0}", amount);
        Console.WriteLine("Customer Name: {0}", customer);
        save.DeleteAccountDB();
        check.ApplyPenalties();
        bprotected.CloseAccount();
        /* OUTPUT:
            Amount: 1000.0
            Customer Name: Mahmut
            Protected DeleteAccountDB method!
            Saving Account Delete Customer Info
            Checking Account Applying Penalties
            Protected DeleteAccountDB method!
        */
    }
}
