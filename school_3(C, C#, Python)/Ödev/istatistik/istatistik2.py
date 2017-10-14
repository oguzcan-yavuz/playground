# -*- coding: utf-8 -*-
from math import floor


class Seri:
    # TODO: butun fonksiyonlari tekrar dene ve duzgunce dokumantasyonunu yap, unutuyorsun.
    def __init__(self):
        pass

    def basit_seri(self, data):
        """Verilen veriyi küçükten büyüğe sıralar.
        :param data: Tek boyutlu bir liste.
        :returns: Verilen listenin küçükten büyüğe sıralanmış hali.
        """
        return sorted(data)

    def frekans_serisi(self, data, gruplar=False):
        """Verilen verinin frekans serisini döndürür.
        :param data: Tek boyutlu bir liste veya gruplandırılmış seri.
        :param gruplar: Eğer data gruplandırılmış seri ise bu parametre True yapılmalıdır.
        :returns: Gruplar parametresi False ise iki boyutlu, her bir elemanı
        (veri_noktası, frekans) olacak şekilde iki elemanlı tuple olan bir set döndürür.
            gruplar parametresi True ise...
        """
        if gruplar is False:
            # TODO: butun listeleri tuple'a donusturmek mantikli mi? yoksa sadece burada
            # mi tuple kalsin? yoksa uniq fonksiyonu olusturmak mi daha mantikli?
            return set([(i, data.count(i)) for i in data])
            # return [[i, data.count(i)] for i in data]
        else:
            return [[[g0, g1], sum([data.count(i) for i in range(g0, g1)])] for g0, g1 in data]

    def gruplandirilmis_seri(self, data, grup_sayisi, retry=0):
        """Verilen verinin istenilen grup sayısında gruplandırılmış halini döndürür.
        Eğer istenilen sayıda gruplandırma yapılamıyorsa 'Gruplandırılma yapılamıyor!'
        string'ini döndürür
        :param data: Tek boyutlu veri.
        :param grup_sayisi: Verinin bölünmek istendiği grup sayısı
        :param retry: Fonksiyonun kendi içerisinde genişliği kontrol etmek için kullandığı
        fonksiyonun kendisini çağırma sayısını tutan default parametre. Dokunmayın.
        :returns: İstenilen sayıda gruplandırılmış verinin liste halindeki alt ve üst sınırları
        her bir elemanını oluşturan bir liste.
        """
        maximum, minimum = data[-1], data[0]
        aciklik = maximum - minimum
        genislik = floor(aciklik / grup_sayisi + 1) + retry
        son_grup_baslangici = data[0] + (genislik * (grup_sayisi - 1))
        if maximum < son_grup_baslangici or maximum >= son_grup_baslangici + genislik:
            return self.gruplandirilmis_seri(data, grup_sayisi, retry=1) if retry == 0 else "Gruplandırma yapılamıyor!"
        return [[data[0] + (i * genislik) + i, data[0] + ((i + 1) * genislik) + i] for i in range(grup_sayisi)]

    def temsili_datalar(self, gruplar):
        """Gruplandırılmış serideki her bir grup için temsili değeri hesaplar.
        :param gruplar: Gruplandırılmış seri.
        :returns: Her grubun indexine karşılık gelecek şekilde temsili değerlerini tutan tek
        boyutlu bir dizi.
        """
        return [(g[0] + g[1]) / 2 for g in gruplar]

    # params:
    # frekans_serisi: frekans_serisi(gruplar=False) fonksiyonundan donen bir deger bekler
    # toplam_frekans: toplam data sayisi.
    def kismi_frekans(self, frekans_serisi, toplam_frekans):
        # TODO: toplam frekansi arguman olarak vermek mi yoksa fonk. icinde hesaplamak mi?
        """Kısmi frekans, frekans serisindeki frekansların toplam frekansa bölümüdür.
        """
        return [(f / toplam_frekans) for _, f in frekans_serisi]

    # params:
    # frekans_serisi: frekans_serisi(gruplar=False) fonksiyonundan donen bir deger bekler
    # toplam_frekans: toplam data sayisi.
    def kumulatif_frekans(self, frekans_serisi, toplam_frekans, grup_sayisi):
        # kf = self.kumulatif_frekans(self.frekans_serisi(data), len(data), grup_sayisi)
        return [[sum([frekans_serisi[j][1] for j in range(i + 1)]) / toplam_frekans] for i in range(grup_sayisi)]

    # TODO: check if this function is for cumilative frequencies or partial frequency
    # params:
    # toplam_frekans: toplam data sayisi.
    # kismi_frekanslar: kismi_frekans fonksiyonundan donen bir deger bekler
    def kumulatif_relatif_frekans(self, kismi_frekanslar, toplam_frekans):
        return [kf / toplam_frekans for kf in kismi_frekanslar]

    # params:
    # gruplandirilmis_frekanslar: frekans_serisi(gruplar=True) fonk. donus degeri bekler
    # grup_sayisi: grup sayisini belirler
    def birikimli_azalan(self, gruplandirilmis_frekanslar, grup_sayisi):
        return [[sum([gruplandirilmis_frekanslar[j][1] for j in range(i, -1, -1)]) for i in range(grup_sayisi - 1, -1, -1)]]


class AritmetikOrtalama(Seri):
    def basit(self, data):
        return sum(data) / len(data)

    def frekans(self, data):
        frekans_serisi = self.frekans_serisi(data)
        return sum([s * f for s, f in frekans_serisi]) / sum([f for s, f in frekans_serisi])

    def gruplandirilmis(self, data, grup_sayisi):
        gruplandirilmis_seri = self.gruplandirilmis_seri(data, grup_sayisi)
        temsili_data = self.temsili_datalar(gruplandirilmis_seri)
        frekans_serisi = self.frekans_serisi(gruplandirilmis_seri)
        result = 0
        # TODO: check if this needs to be zipped with x[1] of gruplandirilmis_seri
        data = zip(temsili_data, [x[1] for x in gruplandirilmis_seri])
        for i in data:
            result += i[0] * i[1]
        return result / sum([f for g, f in frekans_serisi])


class Mod(Seri):
    def basit_mod_hesapla(self, data):
        frekanslar = self.frekans_serisi(data)
        max_frekans = max(frekanslar, key=lambda n: n[1])
        modlar = []
        for data, frekans in frekanslar:
            if frekans == max_frekans:
                modlar.append(data)
        return modlar if len(data) != len(modlar) else "Tüm verilerin frekansı eşit olduğundan mod yoktur!"

    def grup_mod_hesapla(self, data):
        frekanslar = self.frekans_serisi(data, gruplar=True)
        return frekanslar


class Medyan(Seri):
    pass


notlar = [24, 80, 52, 65, 40, 40, 65, 50, 36, 60, 75, 40, 60, 95, 50, 30, 52, 24, 40, 75]
aritmetik = AritmetikOrtalama()

# print("basit seri: {0}".format(aritmetik.basit_seri()))
# print("frekans serisi: {0}".format(aritmetik.frekans_serisi()))
# print("gruplandirilmis seri: {0}".format(aritmetik.gruplandirilmis_seri()))
# print(aritmetik.gruplandirilmis())
print(aritmetik.gruplandirilmis_seri(notlar, 5))
frekans_serisi = aritmetik.frekans_serisi(notlar)
print(frekans_serisi)
# print(aritmetik.kumulatif_frekans(frekans_serisi, len(frekans_serisi), 6))
