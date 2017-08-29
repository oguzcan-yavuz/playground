// notTakipProgrami.c
// 14.04.2003

#include <stdio.h>

void notYazdir(int, int);
void tumNotlariYazdir();
double sinavOrtalamasiBul(int);
int enYuksekNotuBul(int);
int enDusukNotuBul(int);
void yeniNot(int, int, int, int);

int edebiyatNotlari[15][4] = {
    {112,12,63,94},    // 1. ogrenci
    {113,67,21,78},    // 2. ogrenci
    {114,90,42,76},    // 3. ogrenci
    {115,54,12,65},    // 4. ogrenci
    {116,100,70,87},   // 5. ogrenci
    {117,98,34,67},    // 6. ogrenci
    {118,56,12,32},    // 7. ogrenci
    {119,12,65,30},    // 8. ogrenci
    {120,87,32,10},    // 9. ogrenci
    {121,12,78,34},    // 10. ogrenci
    {122,87,34,12},    // 11. ogrenci
    {123,99,87,17},    // 12. ogrenci
    {124,30,40,50},    // 13. ogrenci
    {125,54,100,45},   // 14. ogrenci
    {126,32,15,61},    // 15. ogrenci
};

void notYazdir(int ogrenciNo, int hangiNot) {

  // verilen ogrenci numarasini dizi icinde ara:
  int i=0,j=0;
  for(i=0;i<15;i++) {
    if (edebiyatNotlari[i][0]==ogrenciNo) {
     // numara bulundu, istenilen notu yazdir:
      printf("\nnumarasi: %d\n",edebiyatNotlari[i][0]);
      if (hangiNot>0 && hangiNot<4) { // istenilen not 1-3 arasindaysa:
        printf("%d. notu: %d",hangiNot, edebiyatNotlari[i][hangiNot]);
      } else {  // istenilen not 1-3 arasinda degilse tum notlari yazdir:
        printf("notlari:  ");
        for(j=1;j<4;j++) {
          printf("%d  ",edebiyatNotlari[i][j]);
        }
      }
     return;
    }
  }

  printf("aradiginiz kayit bulunamadi!\n");
}

void tumNotlariYazdir() {
  int i=0,j=0;
  printf("no\ts1  s2  s3\n");
  printf("--\t--  --  --\n\n");
  for(i=0;i<15;i++) {
    // once numarayi yaz:
    printf("%d\t",edebiyatNotlari[i][0]);
    // 3 notu da yanyana yaz:
    for(j=1;j<4;j++) {
      printf("%d  ",edebiyatNotlari[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}

double sinavOrtalamasiBul(int hangiSinav) {
  int i=0;
  double ort=0;
  int toplam=0;

  // parametreyi kontrol et:
  if (hangiSinav<1 ||hangiSinav>3) {
    printf("1-3 arasinda bir deger girmelisiniz!\n");
    return -1;
  }

  // tum ogrencilerin sinav notlarini topla:
  for(i=0;i<15;i++) {
    toplam+=edebiyatNotlari[i][hangiSinav];
  }
  ort = toplam / 15;
  return ort;
}

int enYuksekNotuBul(int hangiSinav) {
  int i=0;
  int max=0;

  // tum ogrencilerin sinavlarina bak:
  for(i=0;i<15;i++) {
    if (edebiyatNotlari[i][hangiSinav]>max) {
      max=edebiyatNotlari[i][hangiSinav];
    }
  }
  return max;
}

int enDusukNotuBul(int hangiSinav) {
  int i=0;
  int min=100;

  // tum ogrencilerin sinavlarina bak:
  for(i=0;i<15;i++) {
    if (edebiyatNotlari[i][hangiSinav]<min) {
      min=edebiyatNotlari[i][hangiSinav];
    }
  }
  return min;
}

void yeniNot(int ogrenci, int not1, int not2, int not3) {
    
    printf("%d numarali ogrencinin 1.sinavi: %d\n2.sinavi: %d\n3.sinavi: %d\n", ogrenci, edebiyatNotlari[ogrenci][not1 - 1], edebiyatNotlari[ogrenci][not2 - 1], edebiyatNotlari[ogrenci][not3 - 1]);
    
}

int main() {

  // fonksiyonlarimizi kullanarak
  // dizi uzerinde istedigimiz isleri yaptirabiliriz.

  // once tum notlari ekrana yazdir:
  tumNotlariYazdir();

  // 123 nolu ogrencinin 2. sinav notunu yazdir:
  notYazdir(123,2);

  // 1. sinavin ortalamasini yazdir:
  printf("1. sinav ortalamasi: %f\n",sinavOrtalamasiBul(1));

  // 3. sinavin en yuksek notunu bul:
  printf("3. sinavin en yuksek notu: %i\n",enYuksekNotuBul(3));

  // 2. sinavin en dusuk notunu bul:
  printf("2. sinavin en dusuk notu: %i\n",enDusukNotuBul(2));

    printf("lolz-------------------------XDXDXD\n");
    yeniNot(5, 1, 2, 3);
  return 0;
}
