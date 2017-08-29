// ucBoyutluDizi.c
// 14.04.2003

#include <stdio.h>

void satislariEkranaYaz();
void satislariOku();

int satislar[6][2][2];

void satislariOku() {

  int i=0,j=0,k=0;

  // her satis temsilcisinin kac kitap sattigini
  // kullanicidan oku ve diziye yaz:

  for(i=0;i<6;i++) {   // 6 satis temsilcisi icin
    printf("%d. satis temsilcisi\n",i+1);
    for(j=0;j<2;j++) { // 2 kitap turu: teknik ve psikoloji
      if (j==0) printf("\tteknik kitap\n"); 
	else printf("\tpsikoloji kitabi\n");
      for(k=0;k<2;k++) {  // 2 farkli yer: uni. ve kirtasi.
        if (k==0) printf("\t\tuniversiteye "); 
	  else printf("\t\tkirtasiyeye ");
          printf("kac adet satti: ");
          scanf("%d",&satislar[i][j][k]);
      }
    }
    printf("\n");
  }
}

void satislariEkranaYaz() {
  int i=0,j=0;
  int uniToplam=0;
  int kirtasiyeToplam=0;
  int teknikKitapToplam=0;
  int psiKitapToplam=0;

  for(i=0;i<6;i++) {   // 6 satis temsilcisi icin

    for(j=0;j<2;j++) { // 2 kitap turu: teknik ve psikoloji
      uniToplam+=satislar[i][j][0];
      kirtasiyeToplam+=satislar[i][j][1];
    }
    for(j=0;j<2;j++) { // 2 farkli yer: uni. ve kirtasiyeye
      teknikKitapToplam+= satislar[i][0][j];
      psiKitapToplam+=    satislar[i][1][j];
    }
  }

  // satislari yaz:
  printf("\nuni. toplam %d kitap satildi.\n",uniToplam);
  printf("kirtasiyeye toplam %d kitap satildi.\n\n",kirtasiyeToplam);
  printf("toplam %d teknik kitap satildi.\n",teknikKitapToplam);
  printf("toplam %d psikoloji kitabi satildi.\n",psiKitapToplam);
}
int main() {
  satislariOku();
  satislariEkranaYaz();
  
  return 0;
}
