using System;

class Ev {

    public string adres;
    public int alan;

    public Ev(string adres, int alan) {
        this.adres = adres;
        this.alan = alan;
    }

    virtual public void EvGoster() {    // virtual metotlar, derived class'larda override edilmek zorundadir.
        Console.WriteLine("alan: {0}\nAdres: {1}\n\n", this.alan, this.adres);
    }
}

class KiralikEv : Ev {

    int kira;

    public KiralikEv(int alan, string adres, int kira) :base(adres, alan) {
        this.kira = kira;
    }

    public override void EvGoster() {
        Console.WriteLine("alan: {0}\nAdres: {1}\nKira: {2}\n\n", this.alan, this.adres, this.kira);
    }
}

class SatilikEv : Ev {

    int fiyat;

    public SatilikEv(int alan, string adres, int fiyat) :base(adres, alan) {
        this.fiyat = fiyat;
    }

    public override void EvGoster() {
        Console.WriteLine("alan: {0}\nAdres: {1}\nFiyat: {2}\n\n", this.alan, this.adres, this.fiyat);
    }
}

class MainClass {

    public static void Main(string[] args) {

        Ev ev = new Ev("adresimiz-base", 120);
        ev.EvGoster();

        KiralikEv kira = new KiralikEv(120, "adresimiz-kira", 650);
        kira.EvGoster();

        SatilikEv satilik = new SatilikEv(120, "adresimiz-satilik", 65000);
        satilik.EvGoster();

        ev = kira;
        ev.EvGoster();
    }
}
