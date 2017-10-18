using System;

class BankAccountProtected {
    public void CloseAccount() {
        ApplyPenalties();
        CalculateFinalInterest();
        DeleteAccountDB();
    }

    protected virtual void ApplyPenalties() {
        // deduct from account
    }

    protected virtual void CalculateFinalInterest() {
        // add from account
    }

    protected virtual void DeleteAccountDB() {
        // send notification to data entry personal
    }
}
