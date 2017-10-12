using System;

class EarlyBinding {
    // Compiler Time
    public int NumbersAdd(int a, int b) {
        return a + b;
    }
    public int NumbersAdd(int a, int b, int c) {
        return a + b + c;
    }
}

class LateBindingBase {
    // needs to be override when this class inheritenced.
    public virtual void Sample1() {
        Console.WriteLine("Base Class");
    }
}

class LateBindingDerived : LateBindingBase {
    // overriding the virtual method in base class.
    // Late-Binding / Override / Dynamic Binding
    public override void Sample1() {
        Console.WriteLine("Derived Class");
    }
}


class MainClass {
    public static void Main(string[] args) {
        EarlyBinding early = new EarlyBinding();
        LateBindingDerived late = new LateBindingDerived();

        Console.WriteLine(early.NumbersAdd(3, 5));
        Console.WriteLine(early.NumbersAdd(3, 5, 7));

        late.Sample1();

    }
}
