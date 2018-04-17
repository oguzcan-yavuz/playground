const ay = 30;
const hafta = 7;
const dersGunleri = 4;

function ulasim() {
    const minibusParasi = 1.25;
    let yurunenGunler = 2;
    return ay * ((dersGunleri - yurunenGunler) / hafta) * minibusParasi * 2;
}

function sosyalGiderler() {
    return 0;
}

function barinma() {
    const kira = 685;
    let ortFaturalar = {
        internet: 72,
        elektrik: 80,
        su: 30
    };
    let ortDigerEvGiderleri = 20;
    return (kira + Object.values(ortFaturalar).reduce((acc, cur) => acc + cur) + ortDigerEvGiderleri) / 3;
}

function beslenmeButcesi(bakiye) {
    const ogunSayisi = 3;
    const toplamOgun = ogunSayisi * ay;
    return bakiye / toplamOgun;
}

function gururuHesapla(aylikBakiye) {
    const maksimumOgunUcreti = 10;
    let ogunBasinaKalanButce = beslenmeButcesi(aylikBakiye);
    console.log("Gunde 3 ogun yemek yedigini varsayarsak ortalama bir ogun icin butcen: " + ogunBasinaKalanButce.toFixed(2) + "TL");
    if(ogunBasinaKalanButce <= 1) {
        return "gurur seviyen 9000'in uzerinde. bu gidisle oleceksin.";
    } else if(ogunBasinaKalanButce > maksimumOgunUcreti) {
        return "bu ne yuzsuzluk amk";
    } else {
        let gurur = maksimumOgunUcreti - (maksimumOgunUcreti * Math.log(ogunBasinaKalanButce) / Math.log(maksimumOgunUcreti));
        return "10 uzerinden gurur katsayin: " + gurur.toFixed(2);
    }
}

function yasa(aylikBakiye) {
    let sabitGiderFonksiyonlari = [ulasim, sosyalGiderler, barinma];
    sabitGiderFonksiyonlari.map((fonk) => {
        aylikBakiye -= fonk();
    });
    return gururuHesapla(aylikBakiye);
}

function main() {
    let istemeyeYuzuOlunanPara = 500;
    console.log(yasa(istemeyeYuzuOlunanPara));
}

main();
