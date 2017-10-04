using System;

class MainClass {
    static void DegerTipi(ref int Deger, out int Deger2) {
        Deger = 50;
        Deger2 = 60;
    }

    static void DiziTipi(string[] deger) {
        // dizinin herhangi bir elemanini degistirmek, dizinin orijinalini de degistirir.
        deger[0] = "20";
    }

    public static void Main(string[] args) {
        int a = 10;
        int y;
        Console.WriteLine(a);
        DegerTipi(ref a, out y);
        Console.WriteLine("{0}, {1}", a, y);

        string[] b = {"10", "50"};
        DiziTipi(b);            // dizinin sadece bellekteki adresini gosteren referans
                                // fonksiyona parametre olarak yollanir.
                                // bu sekilde parametre aktarimina referans ile parametre
                                // aktarimi (call by reference) denir.
        Console.WriteLine(b[0]);
    }
}
