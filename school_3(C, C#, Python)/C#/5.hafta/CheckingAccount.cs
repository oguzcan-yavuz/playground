using System;

class CheckingAccount : BankAccountProtected {

    protected override void ApplyPenalties() {
        Console.WriteLine("Checking Account Applying Penalties");
    }

    protected override void CalculateFinalInterest() {
        Console.WriteLine("Checking Account calculating interest");
    }

    protected override void DeleteAccountDB() {
        base.DeleteAccountDB();
        Console.WriteLine("Checking Account Delete Customer Info");
    }
}
