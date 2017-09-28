using System;

class Referans {
    public int a;
}

class MainClass {
    public static void Main(string[] args) {
        Referans ref1 = new Referans();
        ref1.a = 5;
        Referans ref2 = ref1;
        Console.WriteLine("ref2.a = {0}", ref2.a);
        ref1.a = 6;
        Console.WriteLine("after chancing ref1.a; ref2.a = {0}", ref2.a);
    }
}
