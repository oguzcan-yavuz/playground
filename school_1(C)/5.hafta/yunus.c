/* 3 farkli universitenin bir ogrenciyi yuksek lisans programina kabul etme sartlari su sekildedir:
a universitesi: ales'ten 70 puan veya not ort: min 3.00 ve mulakattan en az 60
veya ygs en az 70 veya tofu: 220
b universitesi: ales'ten 50 puan veya not ort: min 2.5 ve mulakattan en az 70 puan ve ygs 60 veya tofu: 180 ve disiplin sucu bulunmama
c universitesi: ales 40 puan veya not ort: min 2.20 ve mulakattan en az 80 puan ve ygs en az 85 veya tofu: 250

bu kosullar altinda kullanicidan ales, ygs, tofu sinav sonuclari, mulakat sonucu, not ort ve disiplin durumunu okuyarak bu universitelerden 
hangilerine girebilecegine karar veren bir program yaziniz.
*/

#include <stdio.h>

int main() {
 int ales,mulakat,disiplin,yds,tofu;
 float ort;
 
 printf("Sırasıyla ales, ortalama notunuz, mulakat, yds,tofu ve disiplin sucunuz varsa 1 yoksa 0 giriniz.\n");
 scanf("%d%f%d%d%d%d", &ales,&ort,&mulakat,&yds,&tofu,&disiplin);
 
 if((ales>=70 || ort>=3.00) && (mulakat>=60 || yds>=70 || tofu>=220)) {
     printf("A universitesini kazandiniz.\n");
     
 }
 if((ales>=50 || ort>=2.50) && (mulakat>=70 || yds>=60 || tofu>=180) && (disiplin==0)) {
    printf("B universitesini kazandiniz.\n");
     
 }
 if((ales>=40 || ort>=2.20) && (mulakat>=80 || yds>=80 || tofu>=250)) {
     printf("C universitesini kazandiniz.\n");
 }
 else{
     printf("Bir universiteye yerlesemediniz.\n");
 }
 
    return 0;
}
