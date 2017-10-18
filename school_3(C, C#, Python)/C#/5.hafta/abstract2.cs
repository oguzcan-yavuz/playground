using System;

abstract class absclass {

    public int toplama(int sayi1, int sayi2) {
        return sayi1 + sayi2;
    }

    public abstract int carpma(int sayi1, int sayi2);
}

class absderived : absclass {

    static void Main() {
        absderived hesapla = new absderived();
        int topla = hesapla.toplama(10, 20);
        int carpma = hesapla.carpma(10, 20);
    }

    public override int carpma(int sayi1, int sayi2) {
        return sayi1 * sayi2;
    }
}
