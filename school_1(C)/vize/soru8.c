/* TL , EURO , DOLAR para birimlerini istenilen para birimine dönüştüren program
yapınız.Kullanıcıdan gireceği para biriminin önce adını sonra para miktarını ondan sonrada
çevirmek istediği para biriminin adını girecek şekilde ayarlayınız.Fakat aynı para birimini aynı para
birimine dönüştürmek istediğinde tekrar para birimini yazmasını isteyecek.(TL nin TL cinsinden
değerini istediği anda program aynı para birimine çeviremezsiniz tekrar para birimini giriniz
diyecek.)
Örn: TL
500
DOLAR
Sonuç : 500 TL -> 194,25 DOLAR */

#include <stdio.h>
#include <string.h>

int main() {
    
    float tl = 1;
    float dolar = tl * 3.25574884;
    float euro = tl * 3.54323146;
    float para = 0;
    char birim1[128];
    char birim2[128];
    
    printf("Cevirmek istediginiz para birimini giriniz.\n");
    fgets(birim1, sizeof(birim1), stdin);
    printf("Hangi para birimine cevirmek istediginizi giriniz.\n");
    fgets(birim2, sizeof(birim2), stdin);
    printf("Para miktarini giriniz.\n");
    scanf("%f", &para);
    
    if(strcmp(birim1, "TL") == 10) {

        if (strcmp(birim2, "DOLAR") == 10) {
            printf("%f TL = %f DOLAR\n", para, para * dolar);
        } else if(strcmp(birim2, "EURO") == 10) {
            printf("%f TL = %f EURO\n", para, para * euro);
        }
    }
    
    if(strcmp(birim1, "DOLAR") == 10) {

        if (strcmp(birim2, "TL") == 10) {
            printf("%f DOLAR = %f TL\n", para, para / dolar);
        } else if(strcmp(birim2, "EURO") == 10) {
            printf("%f DOLAR = %f EURO\n", para, para / dolar * euro);
        }
    }
    
    if(strcmp(birim1, "EURO") == 10) {

        if (strcmp(birim2, "TL") == 10) {
            printf("%f EURO = %f TL\n", para, para / euro);
        } else if(strcmp(birim2, "DOLAR") == 10) {
            printf("%f EURO = %f DOLAR\n", para, para / euro * dolar);
        }
    }
    
    return 0;
}