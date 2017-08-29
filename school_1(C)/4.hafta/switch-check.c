// bir satis temsilcisi haftanin hangi gunu kac satis yapmistir ekrana yazdiriniz

#include <stdio.h>

int gun;

int check() {
		if(gun <= 0 || gun >= 8) {
			printf("girdiginiz gun yanlis, tekrar giriniz...\n");
			scanf("%d", &gun);
			check();
		}

		return 0;
}

int main(int argc, char *argv[]) {

	printf("hangi gunu gormek istediginizi 1 ve 7 arasinda bir rakam girerek gosteriniz...\n");
	scanf("%d", &gun);
	
	check();
	
	switch(gun) {
		case 1:
			printf("Pazartesi gunu satis miktari: %d\n", 5);
			break;
		case 2:
			printf("Sali gunu satis miktari: %d\n", 6);
			break;
		case 3:
			printf("Carsamba gunu satis miktari: %d\n", 10);
			break;
		case 4:
			printf("Persembe gunu satis miktari: %d\n", 11);
			break;
		case 5:
			printf("Cuma gunu satis miktari: %d\n", 20);
			break;
		case 6:
			printf("Cumartesi gunu satis miktari: %d\n", 25);
			break;
		case 7:
			printf("Pazar gunu satis miktari: %d\n", 20);
			break;
	}
	
	return 0;

}
