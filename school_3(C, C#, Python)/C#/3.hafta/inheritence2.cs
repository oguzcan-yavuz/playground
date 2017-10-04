using System;

public class Parent {

    string parentString;

    public Parent() {
        Console.WriteLine("Parent constructor works!");
    }

    public Parent(string myString) {
        parentString = myString;
        Console.WriteLine(myString);
    }

    public void Print() {
        Console.WriteLine("Parent Class Print method");
    }
}

public class Child : Parent {

    public Child() :base("From Derived") {
        Console.WriteLine("Child Constructor");
    }

    public new void Print() {
        base.Print();
        Console.WriteLine("Child Class Print method");
    }

    public static void Main() {
        Child child = new Child();
        child.Print();
        ((Parent)child).Print();        // parent'in kendi instance'i olmadigi icin
                                        // child instance'inin referansindan parent'a
                                        // ulasiyoruz
    }
}
