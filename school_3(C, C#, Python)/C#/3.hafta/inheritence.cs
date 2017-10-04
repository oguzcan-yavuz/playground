using System;

public class ParentClass {

    public ParentClass() {      // yapici metot, class ile ayni isme sahip
        Console.WriteLine("Parent constructor");
    }

    public void Print() {
        Console.WriteLine("Parent Class Print Method");
    }

}

public class ChildClass : ParentClass {

    public ChildClass() {
        Console.WriteLine("Child constructor");
    }

    public static void Main() {
        ChildClass child = new ChildClass();
        child.Print();      // base class'a ait bir metot, child'dan cagiriliyor.
    }
}
