// bir yayinevinde kitap siparis ediliyor. siparis edilen kitabin adeti girildiginde
// kitaplarin toplam adeti uzerinden indirimsiz tutar, indirim tutari ve siparislerin toplam tutarini ekrana yazdiran
// programi yaziniz.

#include <stdio.h>

int main() {

	int siparis;

	printf("siparis adetini giriniz...\n");
	scanf("%d", &siparis);
	
	float indirim;

	if(siparis > 50) {
		indirim = 0.3;
	} else if(siparis > 20) {
		indirim = 0.2;
	} else if(siparis > 10) {
		indirim = 0.02;
	} else {
		indirim = 1;
	}
	
	int fiyat = 10;
	float toplam = (siparis * fiyat) - (siparis * fiyat * indirim);
	float miktar = siparis * fiyat * indirim;
	float indirimsiz = siparis * fiyat;
	
	printf("indirimli fiyat: %f\n", toplam);
	printf("indirimsiz fiyat: %f\n", indirimsiz);
	printf("indirim miktari: %f\n", miktar);

	return 0;

}
