from math import floor


class Seri:
    # TODO: yorumlari docstring'e(fonksiyon icerisinde """uctirnak""" icerisine yazilan yorumlar) cevir.
    # TODO: butun fonksiyonlari tekrar dene ve duzgunce dokumantasyonunu yap, unutuyorsun.
    def __init__(self):
        pass

    def basit_seri(self, data):
        return sorted(data)

    # params:
    # gruplar: eger data gruplandirilmis_seri datasi ise gruplar parametresini
    # True yap, eger False(default) ise tek boyutlu bir dizi icin calisir.
    def frekans_serisi(self, data, gruplar=False):
        # TODO: bu fonksiyon set dondursun.
        if not gruplar:
            return [[i, data.count(i)] for i in data]
        else:
            return [[[g0, g1], sum([data.count(i) for i in range(g0, g1)])] for g0, g1 in data]

    # params:
    # grup_sayisi: verinin kac gruba ayrilacagini belirler
    # retry = genislik hesabinda yukari yuvarlama basarisiz olursa bir fazlasini sadece
    # bir kere denemek icin fonksiyonun kendi icerisinde recursive olarak kullandigi bir parametre.
    def gruplandirilmis_seri(self, data, grup_sayisi, retry=0):
        maximum, minimum = data[-1], data[0]
        aciklik = maximum - minimum
        genislik = floor(aciklik / grup_sayisi + 1) + retry
        last_group_start = data[0] + (genislik * (grup_sayisi - 1))
        if maximum < last_group_start or maximum >= last_group_start + genislik:
            return self.gruplandirilmis_seri(data, grup_sayisi, retry=1) if retry == 0 else "Gruplandirma yapilamiyor."
        return [[data[0] + (i * genislik) + i, data[0] + ((i + 1) * genislik) + i] for i in range(grup_sayisi)]

    # params:
    # gruplar: gruplandirilmis_seri fonksiyonundan donen bir deger bekler
    def temsili_datalar(self, gruplar):
        return [(g[0] + g[1]) / 2 for g in gruplar]

    # params:
    # frekans_serisi: frekans_serisi(gruplar=False) fonksiyonundan donen bir deger bekler
    # toplam_frekans: toplam data sayisi.
    def kismi_frekans(self, frekans_serisi, toplam_frekans):
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


notlar = [24, 80, 52, 65, 40, 40, 65, 50, 36, 60, 75, 40, 60, 95, 50, 30, 52, 24, 40, 75]
aritmetik = AritmetikOrtalama()

# print("basit seri: {0}".format(aritmetik.basit_seri()))
# print("frekans serisi: {0}".format(aritmetik.frekans_serisi()))
# print("gruplandirilmis seri: {0}".format(aritmetik.gruplandirilmis_seri()))
# print(aritmetik.gruplandirilmis())
print(aritmetik.gruplandirilmis_seri(notlar, 5))
frekans_serisi = aritmetik.frekans_serisi(notlar)
print(aritmetik.kumulatif_frekans(frekans_serisi, len(frekans_serisi), 6))
