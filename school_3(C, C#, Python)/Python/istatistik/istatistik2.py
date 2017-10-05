from math import ceil


class Seri:
    def __init__(self, data, grup_sayisi):
        self.data = sorted(data)
        self.grup_sayisi = grup_sayisi
        self.toplam_frekans = len(data)

    def basit_seri(self):
        return self.data

    def frekans_serisi(self, gruplar=None):
        if gruplar is None:
            return [[i, self.data.count(i)] for i in self.data]
        else:
            return [[[g0, g1], sum([self.data.count(i) for i in range(g0, g1)])] for g0, g1 in gruplar]

    def gruplandir(self, grup_genisligi):
        gruplar, alt_sinir = [], self.data[0]
        for i in range(self.grup_sayisi):
            ust_sinir = alt_sinir + grup_genisligi - 1
            gruplar.append([alt_sinir, ust_sinir])
            alt_sinir += grup_genisligi
        return gruplar

    def grup_kontrol(self, maximum, aciklik):
        grup_genisligi = aciklik / self.grup_sayisi
        if type(grup_genisligi) is int:
            grup_genisligi += 1
        grup_genisligi = ceil(grup_genisligi)
        sonuc = self.gruplandir(grup_genisligi)
        son_grup_menzili = range(sonuc[-1][0], sonuc[-1][1])
        if maximum not in son_grup_menzili:
            grup_genisligi += 1
            sonuc = self.gruplandir(grup_genisligi)
        if maximum not in son_grup_menzili:
            return "Gruplandirma yapilamiyor!"
        else:
            return sonuc

    def temsili_datalar(self, gruplar):
        return [(g[0] + g[1]) / 2 for g in gruplar]

    def kismi_frekans(self, frekanslar):
        return [(f / self.toplam_frekans) for k, f in frekanslar]

    def kumulatif_frekans(self, frekanslar):
        return [[sum([frekanslar[j][1] for j in range(i + 1)]) / self.toplam_frekans] for i in range(self.grup_sayisi)]

    def kumulatif_relatif_frekans(self, kismi_frekanslar):
        return [kf / self.toplam_frekans for kf in kismi_frekanslar]

    def birikimli_azalan(self, frekanslar):
        return [[sum([frekanslar[j][1] for j in range(i, -1, -1)]) for i in range(self.grup_sayisi - 1, -1, -1)]]

    # bunu ayri class haline getir, seriyi miras alsin.
    def gruplandirilmis_seri(self, temsili=True, kismi=True, kumulatif=True, kumulatif_relatif=True, birikimli_az=True):
        minimum = self.data[0]
        maximum = self.data[-1]
        aciklik = maximum - minimum
        gruplar = self.grup_kontrol(maximum, aciklik)
        temsili_data = self.temsili_datalar(gruplar)
        gruplandirilmis_frekanslar = self.frekans_serisi(gruplar=gruplar)
        kismi_frekanslar = self.kismi_frekans(gruplandirilmis_frekanslar)
        kumulatif_frekanslar = self.kumulatif_frekans(gruplandirilmis_frekanslar)
        kum_rel_frekanslar = self.kumulatif_relatif_frekans(kismi_frekanslar)
        birikimli_azalanlar = self.birikimli_azalan(gruplandirilmis_frekanslar)
        return gruplar, temsili_data


class AritmetikOrtalama(Seri):
    def basit(self):
        return sum(self.data) / len(self.data)

    def frekans(self):
        frekans_serisi = self.frekans_serisi()
        return sum([s * f for s, f in frekans_serisi]) / sum([f for s, f in frekans_serisi])

    def gruplandirilmis(self):
        gruplandirilmis_seri, temsili_data = self.gruplandirilmis_seri()
        frekans_serisi = self.frekans_serisi(gruplar=gruplandirilmis_seri)
        result = 0
        data = zip(temsili_data, [x[1] for x in gruplandirilmis_seri])
        for i in data:
            result += i[0] * i[1]
        return result / sum([f for g, f in frekans_serisi])


notlar = [24, 80, 52, 65, 40, 40, 65, 50, 36, 60, 75, 40, 60, 95, 50, 30, 52, 24, 40, 75]
hesap = AritmetikOrtalama(notlar, 5)

print("basit seri: {0}".format(hesap.basit_seri()))
print("frekans serisi: {0}".format(hesap.frekans_serisi()))
print("gruplandirilmis seri: {0}".format(hesap.gruplandirilmis_seri()))
print(hesap.gruplandirilmis())
