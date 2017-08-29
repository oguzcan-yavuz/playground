/* Kullanıcı doğduğu ayı “Mart” şeklinde girdiğinde kullanıcının burcunu ekrana yazdıran
programı ekrana yazdıran programı yapınız.(Kova , Balık ,Koç ,Boğa
İkizler,Yengeç,Aslan,Başak,Terazi,Akrep,Yay,Oğlak) */

#include <stdio.h>
#include <string.h>

int main() {
    
    char ay[256];
    
    printf("Dogdugunuz ayi giriniz...\n");
    fgets(ay, sizeof(ay), stdin);
    
    if(strcmp(ay, "Ocak") == 10) {
        printf("Kova\n");
    } else if(strcmp(ay, "Şubat") == 10) {
        printf("Balık\n");
    } else if(strcmp(ay, "Mart") == 10) {
        printf("Koç\n");
    } else if(strcmp(ay, "Nisan") == 10) {
        printf("Boğa\n");
    } else if(strcmp(ay, "Mayıs") == 10) {
        printf("İkizler\n");
    } else if(strcmp(ay, "Haziran") == 10) {
        printf("Yengeç\n");
    } else if(strcmp(ay, "Temmuz") == 10) {
        printf("Aslan\n");
    } else if(strcmp(ay, "Ağustos") == 10) {
        printf("Başak\n");
    } else if(strcmp(ay, "Eylül") == 10) {
        printf("Terazi\n");
    } else if(strcmp(ay, "Ekim") == 10) {
        printf("Akrep\n");
    } else if(strcmp(ay, "Kasım") == 10) {
        printf("Yay\n");
    } else if(strcmp(ay, "Aralık") == 10) {
        printf("Oğlak\n");
    }
    
    return 0;
    
}
