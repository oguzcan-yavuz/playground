using System;

class SavingAccounts : BankAccountProtected {

    protected override void ApplyPenalties() {
        Console.WriteLine("Saving Account Applying Penalties");
    }

    protected override void CalculateFinalInterest() {
        Console.WriteLine("Saving Account calculating interest");
    }

    protected override void DeleteAccountDB() {
        base.DeleteAccountDB();
        Console.WriteLine("Saving Account Delete Customer Info");
    }
}
