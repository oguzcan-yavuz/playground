using System;

public class A {
    public A(int value) {
        Console.WriteLine("Base Constructor A");
    }
    ~A() {  // destructor method
        Console.WriteLine("Destructor A!");
    }
}

public class B : A {
    public B(int value):base(value) {
        // base constructor is called first
        // then this code executed
        Console.WriteLine("Derived Constructor B");
    }
    ~B() {
        Console.WriteLine("Destructor B!");
    }
}

class MainClass {
    public static void Main(string[] args) {
        A a = new A(1);
        B b = new B(2);
        /* Output:
            Base Constructor A
            Base Constructor A
            Derived Constructor B
            Destructor A!
            Destructor B!
            Destructor A!
        */
    }
}
