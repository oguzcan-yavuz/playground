using System;

interface IArayuz {
    int Metot1();
    int Metot2();
    int ozellik1 {
        set;
        get;
    }
    // indexer
    int this[int indeks] {
        get;
    }
}

interface IArayuz2 {
    int Metot2();
}

interface IArayuz3 : IArayuz1, IArayuz2 {
    double Metot3();
}

interface IArayuz4 : IArayuz3 {
    new double Metot3();
}

class A : IArayuz {
    // bu sinif IArayuz'deki tum elemanlari icermelidir
}

class A : IArayuz, IArayuz2 {
    // hem IArayuz hem de IArayuz2'nin tum elemanlarini icermelidir.
}
