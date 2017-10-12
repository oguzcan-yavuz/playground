using System;

// base class
class Asker {
    public void selamver() {
        Console.WriteLine("Asker selam verdi!");
    }
}

// derived classes
class Er : Asker {
    public new void selamver() {
        Console.WriteLine("Er selam verdi!");
    }
}

class Yuzbasi : Asker {
    public new void selamver() {
        Console.WriteLine("Yuzbasi selam verdi!");
    }
}


// main class
class MainClass {
    public static void hazirOl(Asker a) {
        a.selamver();
    }

    public static void hazirOl(Er a) {
        a.selamver();
    }

    public static void hazirOl(Yuzbasi a) {
        a.selamver();
    }

    public static void Main(string[] args) {
        Asker a = new Asker();
        // Asker a = new Er();              upcasting
        // Asker a = new Yuzbasi();         upcasting
        Er e = new Er();
        Yuzbasi y = new Yuzbasi();
        hazirOl(a);
        hazirOl(e);
        hazirOl(y);
    }
}
