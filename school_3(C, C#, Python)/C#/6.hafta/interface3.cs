using System;

public interface IArayuz {

    void EkranaYaz();
    int Yas {
        get;
        set;
    }
    string Isim {
        get;
        set;
    }
}

public class Kisiler : IArayuz {
    private int y;
    private string i;

    public Kisiler() {
        y = 18;
        i = "Yok";
    }

    public Kisiler(string ad, int yas) {
        y = yas;
        i = ad;
    }

    public int Yas {
        get {
            return y;
        }
        set {
            y = value;
        }
    }

    public string Isim {
        get {
            return i;
        }
        set {
            i = value;
        }
    }

    public void EkranaYaz() {
        Console.WriteLine("Yas: {0}, Isim: {1}", y, i);
    }

    public static void Main() {
        Kisiler kisi = new Kisiler("Ahmet", 27);
        kisi.EkranaYaz();
    }
}
