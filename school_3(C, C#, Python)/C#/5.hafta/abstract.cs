using System;

abstract class Calisan {

    public abstract void calis();       // ozet metot
    public string pozisyon = "calisan";

    public void Zamiste() {     // ozet olmayan metot
        Console.WriteLine("Zam Iste");
    }
}

class Mudur : Calisan {

    public Mudur() {
        pozisyon = "Mudur";
    }
    public override void calis() {
        Console.WriteLine("Mudur Calisiyor");
    }
}

class Yazilimci : Calisan {

    public Yazilimci() {
        pozisyon = "Yazilimci";
    }

    public override void calis() {
        Console.WriteLine("Yazilimci Calisiyor");
    }

    public new void Zamiste() {
        Console.WriteLine("Yazilimci zam istiyor.");
    }
}

public class ISYERI {

    static void mesaibasla(Calisan[] c) {
        for(int i = 0; i < c.Length; i++) {
            c[i].calis();
        }
    }

    public static void Main(string[] args) {
        Calisan[] c = new Calisan[2];
        c[0] = new Mudur();     // up
        c[1] = new Yazilimci(); // up

        mesaibasla(c);
    }
}
