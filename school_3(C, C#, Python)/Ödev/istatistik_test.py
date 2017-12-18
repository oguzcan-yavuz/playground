# -*- coding: utf-8 -*-
from istatistik import istatistik
import random

# data = [24, 80, 52, 65, 40, 40, 65, 50, 36, 60, 75, 40, 60, 95, 50, 30, 52, 24, 40, 75]
# random veri grubu olustur
data = [random.randrange(1, 20) for _ in range(0, 40)]
print("Tamsayılardan oluşan listemiz:")
print(data)

# Basit Seri
basit = istatistik.BasitSeri()
print("\nListemizi basit seriye çeviriyoruz:")
basit_seri = basit.basit_seri(data)
print(basit_seri)
basit_ort = basit.aritmetik_ortalama(data)
print("\nBasit serinin aritmetik ortalamasi: {}".format(basit_ort))

# Frekans Serisi
frekans = istatistik.FrekansSerisi()
print("\nListemizi frekans serisine çeviriyoruz:")
frekans_serisi = frekans.frekans_serisi(data)
print(sorted(frekans_serisi))
kismi_frekans = frekans.kismi_frekans(frekans_serisi)
print("\nFrekans serisinin kısmi frekansı: {}".format(kismi_frekans))
kum_rel_frekans = frekans.kumulatif_relatif_frekans(kismi_frekans, len(data))
print("\nFrekans serisinin kümülatif relatif frekansı: {}".format(kum_rel_frekans))
frekans_ort = frekans.aritmetik_ortalama(data)
print("\nFrekans serisinin aritmetik ortalamasi: {}".format(frekans_ort))

# Gruplandirilmis seri
grup = istatistik.GruplandirilmisSeri()
grup_sayisi = 5
print("\nListemizi gruplandırılmış seriye çeviriyoruz:")
gruplandirilmis_seri = grup.gruplandirilmis_seri(data, grup_sayisi)
print(gruplandirilmis_seri)
grup_temsili = grup.temsili_datalar(gruplandirilmis_seri)
print("\nGruplandırılmış serinin temsili değerleri:")
print(grup_temsili)
print("\nGruplandırılmış serinin frekans değerleri:")
grup_frekans = frekans.frekans_serisi(data, gruplandirilmis_seri, gruplar=True)
print(grup_frekans)
grup_kumulatif_frekans = grup.kumulatif_frekans(grup_frekans, len(data))
print("\nGruplandırılmış serinin kümülatif frekansları:")
print(grup_kumulatif_frekans)
grup_birikimli_azalan = grup.birikimli_azalan(grup_frekans)
print("\nGruplandırılmış serinin birikimli azalan değerleri:")
print(grup_birikimli_azalan)
print("\nGruplandırılmış serinin aritmetik ortalaması: {}".format(grup.aritmetik_ortalama(data, grup_sayisi)))
