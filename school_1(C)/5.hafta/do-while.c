/* a kentinden b kentine giden iki aracimiz var. bu araclardan ortalama hizi 85km/s ve 40km/s oldugu biliniyor.
iki kent arasindaki mesafe 450km'dir. saatte 40km hizla giden arac a-b kentleri arasinda 120km'deyken, saatteki hizi 85km olan arac
a kentinden yola cikti. yazacagimiz program ile bu iki aracin her saat basindaki konumlarini ekrana yazdiran ve araclarin
hangi saatler icerisinde b kentine vardigini gosteren programi do-while kullanarak yaziniz.


not: tek bir seferlik if kodu nasil yazilir?

*/

#include <stdio.h>

int main() {

    int arac_1 = 40;
    int arac_2 = 85;
    int mesafe = 450;
    int aracbir_konum = 120;
    int araciki_konum = 0;
    int saat = 1;
    int bir_varis, iki_varis;
    
    printf("saat \t\t 1.arac \t 2.arac\n");
    
    do {
        printf("%d", saat);
        printf("\t\t %d", aracbir_konum);
        printf("\t\t %d\n", araciki_konum);
        
        saat++;
        aracbir_konum += arac_1;
        araciki_konum += arac_2;
        
        if (aracbir_konum >= mesafe) {
            bir_varis = saat + 3;
        }
        
        if (araciki_konum >= mesafe) {
            // surekli uzerine degisken atandigi icin duzgun calismiyor.
            iki_varis = saat;
        }
        
    } while (mesafe > aracbir_konum || mesafe > araciki_konum);
    
    printf("Birinci arac B sehrine %d. saatte vardi.\n", bir_varis);
    printf("Ikinci arac B sehrine %d. saatte vardi.\n", iki_varis);
    
    return 0;
}