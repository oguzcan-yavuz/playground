// Bir insanin gunde ortalama kac kilometre yurudugu bilgisi ve yas bilgisi klavyeden girildiginde 
// kisinin bugune kadar yurudugu mesafeyi kilometre cinsinden bulan ve dunyanin cevresini kac defa dondugunu bulan programi yaziniz.

#include <stdio.h>

int main() {
	
	// declaring our variables
	float avg, age, r, res;
	r = 40075;

	// asks for average walk for a day to user
	printf("Gunde ortalama kac km. yuruyorsunuz?\n");
	scanf("%f", &avg);

	// asks for the time user has been walking
	printf("Kac yildir yuruyorsunuz?\n");
	scanf("%f", &age); 

	// calculates how much the user walked until today
	res = avg * age * 365;

	// prints results to the screen
	printf("Bugune kadar yurudugunuz toplam mesafe(km): %.f\n", res);
	printf("Bugune kadar dunyanin cevresini kac kez turladiginiz: %f\n", res / r);

	return 0;
}
