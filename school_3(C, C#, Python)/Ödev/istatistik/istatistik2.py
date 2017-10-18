# -*- coding: utf-8 -*-
from math import floor


# TODO: butun fonksiyonlari tekrar dene ve duzgunce dokumantasyonunu yap, unutuyorsun.
class BasitSeri(object):
    def __init__(self):
        pass

    @staticmethod
    def basit_seri(data):
        """
        Verilen veriyi küçükten büyüğe sıralar.
        :param data: Tek boyutlu bir liste.
        :returns: Verilen listenin küçükten büyüğe sıralanmış hali.
        """
        return sorted(data)


class FrekansSerisi(object):
    def __init__(self):
        pass

    @staticmethod
    def frekans_serisi(data, gruplar=False):
        # TODO: returns kismini tamamla
        """
        Verilen verinin frekans serisini döndürür.
        :param data: Tek boyutlu bir liste veya gruplandırılmış seri.
        :param gruplar: Eğer data gruplandırılmış seri ise bu parametre True yapılmalıdır.
        :returns: Gruplar parametresi False ise iki boyutlu, her bir elemanı
        (veri_noktası, frekans) olacak şekilde iki elemanlı tuple olan bir set döndürür.
            gruplar parametresi True ise...
        """
        if gruplar is False:
            return set([(i, data.count(i)) for i in data])
        else:
            return [[[g0, g1], sum([data.count(i) for i in range(g0, g1)])] for g0, g1 in data]

    def kismi_frekans(self, frekans_serisi):
        """
        Kısmi frekans, frekans serisindeki frekansların toplam frekansa bölümüdür.
        :param frekans_serisi: Tek boyutlu frekans serisi.
        :returns: Her bir index, frekans serisindeki verinin indexine denk gelecek şekilde
        verilerin kısmi frekanslarını içeren tek boyutlu bir liste.
        """
        toplam_frekans = sum([f for _, f in frekans_serisi])
        return [(f / toplam_frekans) for _, f in frekans_serisi]

    # TODO: check if this function is for cumilative frequencies or partial frequency
    # params:
    # toplam_frekans: toplam data sayisi.
    # kismi_frekanslar: kismi_frekans fonksiyonundan donen bir deger bekler
    def kumulatif_relatif_frekans(self, kismi_frekanslar, toplam_frekans):
        return [kf / toplam_frekans for kf in kismi_frekanslar]


class GruplandirilmisSeri(object):
    def __init__(self):
        pass

    @staticmethod
    def gruplandirilmis_seri(data, grup_sayisi, _retry=0):
        """
        Verilen verinin istenilen grup sayısında gruplandırılmış halini döndürür.
        Eğer istenilen sayıda gruplandırma yapılamıyorsa 'Gruplandırılma yapılamıyor!'
        string'ini döndürür
        :param data: Tek boyutlu veri.
        :param grup_sayisi: Verinin bölünmek istendiği grup sayısı
        :param _retry: Fonksiyonun kendi içerisinde genişliği kontrol etmek için kullandığı
        fonksiyonun kendisini çağırma sayısını tutan default parametre. Dokunmayın.
        :returns: İstenilen sayıda gruplandırılmış verinin liste halindeki alt ve üst sınırları
        her bir elemanını oluşturan bir liste.
        """
        maximum, minimum = data[-1], data[0]
        aciklik = maximum - minimum
        genislik = floor(aciklik / grup_sayisi + 1) + _retry
        son_grup_baslangici = data[0] + (genislik * (grup_sayisi - 1))
        if maximum < son_grup_baslangici or maximum >= son_grup_baslangici + genislik:
            err = "Gruplandırma yapılamıyor!"
            return GruplandirilmisSeri.gruplandirilmis_seri(data, grup_sayisi, _retry=1) if _retry == 0 else err
        return [[data[0] + (i * genislik) + i, data[0] + ((i + 1) * genislik) + i] for i in range(grup_sayisi)]

    def temsili_datalar(self, gruplar):
        """
        Gruplandırılmış serideki her bir grup için temsili değeri hesaplar.
        :param gruplar: Gruplandırılmış seri.
        :returns: Her grubun indexine karşılık gelecek şekilde temsili değerlerini tutan tek
        boyutlu bir liste.
        """
        return [(g[0] + g[1]) / 2 for g in gruplar]

    def kumulatif_frekans(self, grup_frekans, toplam_frekans):
        """

        :param grup_frekans: Gruplandırılmış frekans serisi.
        :param toplam_frekans: Verilen seride kaç tane veri olduğu.
        :return: Her bir index, verilen grupların indexine denk gelecek şekilde grupların
        kümülatif frekanslarını içeren tek boyutlu bir liste.
        """
        return [sum([grup_frekans[j][1] for j in range(i + 1)]) / toplam_frekans for i in range(len(grup_frekans))]

    def birikimli_azalan(self, grup_frekanslar):
        """

        :param grup_frekanslar: Gruplandırılmış frekans serisi.
        :returns: Her bir index, verilen grubun indexine denk gelecek şekilde o grubun
        birikimli azalan değerlerini barındıran tek boyutlu bir liste.
        """
        return [sum([grup_frekanslar[j][1] for j in range(i, -1, -1)]) for i in range(len(grup_frekanslar) - 1, -1, -1)]


class AritmetikOrtalama(object):
    def basit(self, data):
        return sum(data) / len(data)

    def frekans(self, data):
        _frekans_serisi = FrekansSerisi.frekans_serisi(data)
        return sum([s * f for s, f in frekans_serisi]) / sum([f for s, f in _frekans_serisi])

    def gruplandirilmis(self, data, grup_sayisi):
        _grup = GruplandirilmisSeri()
        _gruplandirilmis_seri = _grup.gruplandirilmis_seri(data, grup_sayisi)
        _temsili_data = _grup.temsili_datalar(_gruplandirilmis_seri)
        _frekans_serisi = FrekansSerisi.frekans_serisi(_gruplandirilmis_seri)
        result = 0
        # TODO: check if this needs to be zipped with x[1] of gruplandirilmis_seri
        data = zip(_temsili_data, [x[1] for x in _gruplandirilmis_seri])
        for i in data:
            result += i[0] * i[1]
        return result / sum([f for g, f in _frekans_serisi])


class Mod(object):
    def basit_mod_hesapla(self, data):
        # TODO: test et.
        _frekanslar = FrekansSerisi.frekans_serisi(data)
        max_frekans = max(_frekanslar, key=lambda n: n[1])
        modlar = []
        for data, frekans in _frekanslar:
            if frekans == max_frekans:
                modlar.append(data)
        return modlar if len(data) != len(modlar) else "Tüm verilerin frekansı eşit olduğundan mod yoktur!"

    def grup_mod_hesapla(self, data):
        # TODO: fonksiyonu tamamla.
        _frekanslar = FrekansSerisi.frekans_serisi(data, gruplar=True)
        return _frekanslar


class Medyan(object):
    # TODO: Yap.
    pass


notlar = [24, 80, 52, 65, 40, 40, 65, 50, 36, 60, 75, 40, 60, 95, 50, 30, 52, 24, 40, 75]

# print("basit seri: {0}".format(aritmetik.basit_seri()))
# print("frekans serisi: {0}".format(aritmetik.frekans_serisi()))
# print("gruplandirilmis seri: {0}".format(aritmetik.gruplandirilmis_seri()))
# print(aritmetik.gruplandirilmis())
grup = GruplandirilmisSeri()
frekans_serisi = FrekansSerisi.frekans_serisi(notlar)
grup_seri = grup.gruplandirilmis_seri(notlar, 5)
km = grup.kumulatif_frekans(grup_seri, len(notlar))
print(frekans_serisi)
print(grup_seri)
print(km)
# print(aritmetik.kumulatif_frekans(frekans_serisi, len(frekans_serisi), 6))
