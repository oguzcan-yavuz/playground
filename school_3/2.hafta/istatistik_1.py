from math import ceil


notlar = [24, 80, 52, 65, 40, 40, 65, 50, 36, 60, 75, 40, 60, 95, 50, 30, 52, 24, 40, 75]


def basit_seri(l):
    return sorted(l)


def frekans_serisi(l):
    # dictionary ile
    # sonuc = {}
    # for e in l:
    #     sonuc[e] = l.count(e)
    # return sonuc
    # liste ile [eleman, tekrar sayisi] seklinde
    return [[i, l.count(i)] for i in l]


def gruplandir(l, alt_sinir, grup_sayisi, grup_genisligi):
    gruplar = []
    for i in range(grup_sayisi):
        ust_sinir = alt_sinir + grup_genisligi - 1
        gruplar.append([
            [alt_sinir, ust_sinir],
            sum([l.count(i) for i in range(alt_sinir, ust_sinir)]),
            (alt_sinir + ust_sinir) / 2
        ])
        alt_sinir += grup_genisligi
    return gruplar


def gruplandirilmis_seri(l):
    n = len(l)
    minimum = min(l)
    maximum = max(l)
    aciklik = maximum - minimum
    grup_sayisi = 5     # biz belirliyoruz. genelde 5-15 arasi bir deger belirlenir.
    grup_genisligi = ceil(aciklik / grup_sayisi)
    sonuc = gruplandir(l, minimum, grup_sayisi, grup_genisligi)
    if sonuc[-1][0][1] != maximum:
        sonuc = gruplandir(l, minimum, grup_sayisi, grup_genisligi + 1)
    return sonuc


print("basit seri: {0}".format(basit_seri(notlar)))
print("frekans serisi: {0}".format(frekans_serisi(notlar)))
print("gruplandirilmis seri: {0}".format(gruplandirilmis_seri(notlar)))

