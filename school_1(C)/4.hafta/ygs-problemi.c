// ygsye hazirlanan bir ogrencinin mat. sosyal. turkce, fen netlerini okuyarak
// adayin yaklasik olarak sayisal sozel ve esit agirlik puanlarini hesaplayan bir prog yaziniz.

#include <stdio.h>

int main() {

	float turkce, mat, sosyal, fen, ygs1, ygs2, ygs3, ygs4, ygs5, ygs6;

	printf("turkce net sayinizi giriniz...\n");
	scanf("%f", &turkce);

	printf("matematik net sayinizi giriniz...\n");
	scanf("%f", &mat);

	printf("sosyal net sayinizi giriniz...\n");
	scanf("%f", &sosyal);

	printf("fen net sayinizi giriniz...\n");
	scanf("%f", &fen);

	// hesaplamalar
	ygs1 = (mat * 4) + (fen * 3) + (sosyal * 2) + turkce;
	printf("ygs1 puaniniz: %f\n", ygs1);

	ygs2 = (mat * 4) + (fen * 3) + (turkce * 2) + sosyal;
	printf("ygs2 puaniniz: %f\n", ygs2);

    ygs3 = (mat * 1) + (fen * 2) + (turkce * 4) + (sosyal * 3) + 100;
    printf("ygs3 puaniniz: %f\n", ygs3);
    
    ygs4 = (mat * 2) + (fen * 1) + (turkce * 4) + (sosyal * 3) + 100;
    printf("ygs4 puaniniz: %f\n", ygs4);
    
    ygs5 = (mat * 3) + (turkce * 4) + (sosyal * 1) + (fen * 2) + 100;
    printf("ygs5 puaniniz: %f\n", ygs5);

    ygs6 = (mat * 3) + (turkce * 4) + (sosyal * 2) + (fen * 1) + 100;
    printf("ygs6 puaniniz: %f\n", ygs6);
    
    return 0;
}
