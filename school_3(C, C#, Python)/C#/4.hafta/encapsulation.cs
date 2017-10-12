using System;

class Araba {
    private string marka = "VOLVO";
    // public string Marka { get => marka; set => marka = value; };
    public string Marka {
        get {
            return marka;
        }
        set {
            marka = value;
        }
    }
    public string traditional_get {
        get {
            return marka;
        }
    }
    public string traditional_set {
        set {
            marka = value;
        }
    }

}

class MainClass {
    public static void Main(string[] args) {
        Araba araba = new Araba();
        Console.WriteLine(araba.Marka);
        araba.Marka = "FIAT";
        Console.WriteLine(araba.Marka);
        Console.WriteLine(araba.traditional_get);
        araba.traditional_set = "AUDI";
        Console.WriteLine(araba.Marka);
    }
}
