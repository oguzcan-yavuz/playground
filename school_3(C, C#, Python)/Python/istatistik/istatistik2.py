from math import floor


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

    def gruplandirilmis_seri(self, retry=0):
        maximum, minimum = self.data[-1], self.data[0]
        aciklik = maximum - minimum + retry
        grup_genisligi = floor(aciklik / self.grup_sayisi + 1)
        last_group_start = self.data[0] + (grup_genisligi * (self.grup_sayisi- 1))
        if maximum < last_group_start or maximum >= last_group_start + grup_genisligi:
            return self.gruplandirilmis_seri(retry=1) if retry == 0 else "Gruplandirma yapilamiyor."
        return [
            [
                self.data[0] + (i * grup_genisligi) + i,
                self.data[0] + ((i + 1) * grup_genisligi) + i
            ] for i in range(self.grup_sayisi)
        ]

    def temsili_datalar(self, gruplar):
        return [(g[0] + g[1]) / 2 for g in gruplar]

    def kismi_frekans(self, frekanslar):
        return [(f / self.toplam_frekans) for _, f in frekanslar]

    def kumulatif_frekans(self, frekanslar):
        return [[sum([frekanslar[j][1] for j in range(i + 1)]) / self.toplam_frekans] for i in range(self.grup_sayisi)]

    # TODO: check if this function is for cumilative frequencies or partial frequency
    def kumulatif_relatif_frekans(self, kismi_frekanslar):
        return [kf / self.toplam_frekans for kf in kismi_frekanslar]

    def birikimli_azalan(self, frekanslar):
        return [[sum([frekanslar[j][1] for j in range(i, -1, -1)]) for i in range(self.grup_sayisi - 1, -1, -1)]]


class AritmetikOrtalama(Seri):
    def basit(self):
        return sum(self.data) / len(self.data)

    def frekans(self):
        frekans_serisi = self.frekans_serisi()
        return sum([s * f for s, f in frekans_serisi]) / sum([f for s, f in frekans_serisi])

    def gruplandirilmis(self):
        gruplandirilmis_seri = self.gruplandirilmis_seri()
        temsili_data = self.temsili_datalar(gruplandirilmis_seri)
        frekans_serisi = self.frekans_serisi(gruplandirilmis_seri)
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
