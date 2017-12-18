# -*- coding: utf-8 -*-
from math import floor


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

    def aritmetik_ortalama(self, data):
        return sum(data) / len(data)


class FrekansSerisi(object):
    def __init__(self):
        pass

    @staticmethod
    def frekans_serisi(data, gruplandirilmis_seri=None, gruplar=False):
        """
        Verilen verinin frekans serisini döndürür.
        :param data: Tek boyutlu bir liste veya gruplandırılmış seri.
        :param gruplar: Eğer data gruplandırılmış seri ise bu parametre True yapılmalıdır.
        :returns: Gruplar parametresi False ise iki boyutlu, her bir elemanı
        (veri_noktası, frekans) olacak şekilde iki elemanlı tuple olan bir set döndürür.
        'gruplar' parametresi True ise gruplandirilmis seriyi grup araliklarinin frekans
        degerleri ile birlikte dondurur...
        """
        if gruplar is False:
            return set([(i, data.count(i)) for i in data])
        else:
            return [[[g0, g1], sum([data.count(i) for i in range(g0, g1)])] for g0, g1 in gruplandirilmis_seri]

    def kismi_frekans(self, frekans_serisi):
        """
        Kısmi frekans, frekans serisindeki frekansların toplam frekansa bölümüdür.
        :param frekans_serisi: Tek boyutlu frekans serisi.
        :returns: Her bir index, frekans serisindeki verinin indexine denk gelecek şekilde
        verilerin kısmi frekanslarını içeren tek boyutlu bir liste.
        """
        toplam_frekans = sum([f for _, f in frekans_serisi])
        return [(f / toplam_frekans) for _, f in frekans_serisi]

    def kumulatif_relatif_frekans(self, kismi_frekanslar, toplam_frekans):
        """
        :param kismi_frekanslar: kismi_frekans fonksiyonundan donen bir deger bekler.
        :param toplam_frekans: toplam data sayisi
        :returns: Verilen frekans serisinin kumulatif relatif frekans degerini dondurur.
        """
        return [kf / toplam_frekans for kf in kismi_frekanslar]

    def aritmetik_ortalama(self, data):
        _frekans_serisi = self.frekans_serisi(data)
        return sum([s * f for s, f in _frekans_serisi]) / sum([f for s, f in _frekans_serisi])


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
        maximum, minimum = max(data), min(data)
        aciklik = maximum - minimum
        genislik = floor(aciklik / grup_sayisi + 1) + _retry
        son_grup_baslangici = minimum + (genislik * (grup_sayisi - 1))
        if maximum < son_grup_baslangici or maximum >= son_grup_baslangici + genislik:
            if _retry == 0:
                return GruplandirilmisSeri.gruplandirilmis_seri(data, grup_sayisi, _retry=1)
            else:
                print("Gruplandirma yapilamiyor!")
                return []
        return [[minimum + (i * genislik) + i, minimum + ((i + 1) * genislik) + i] for i in range(grup_sayisi)]

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

    def aritmetik_ortalama(self, data, grup_sayisi):
        # TODO: 0 ile bolunme durumu veya bos liste gelme durumunu yakala
        _gruplandirilmis_seri = GruplandirilmisSeri.gruplandirilmis_seri(data, grup_sayisi)
        _temsili_data = self.temsili_datalar(_gruplandirilmis_seri)
        _frekans_serisi = FrekansSerisi.frekans_serisi(data, _gruplandirilmis_seri, gruplar=True)
        result = 0
        data = zip(_temsili_data, [x[1] for x in _gruplandirilmis_seri])
        for i in data:
            result += i[0] * i[1]
        return result / sum([f for g, f in _frekans_serisi])
