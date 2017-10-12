// boyu, eni ve alani olan bir halinin alanini property kullanarak yaziniz.

using System;

class Hali {
    private int alan;
    public Hali(int x, int y) {
        alan = x * y;
    }
    public int Alan {
        get {
            return alan;
        }
    }
}

class MainClass {
    public static void Main(string[] args) {
        Hali hali = new Hali(50, 20);
        Console.WriteLine("Alan: {0}", hali.Alan);
    }
}
