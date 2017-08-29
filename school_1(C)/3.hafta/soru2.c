// yaricapi, 1 kupun kenar uzunluguna esit olan kurenin hacminin kupun hacmine olan oranini bulan programi yaziniz.

#include <stdio.h>

int main() {
	float r, kup, kure;	
	
	printf("Yaricapi giriniz... \n");
	scanf("%f", &r);

	kup = r * r * r;
	kure = (4 * 3.14 * kup) / 3;

	printf("Kurenin hacminin kupun hacmine orani: %f / %f = %f\n", kure, kup, kure / kup);

	return 0;	
}
