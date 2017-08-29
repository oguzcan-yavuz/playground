// sayinin basamaklarinin sayi degerlerini toplayip sonucu veren programi yaziniz

#include <stdio.h>

int main() {
	
	// declaring our variables
	int num, i, sum, len, num2;
	
	// asking for an input from the user
	printf("Bir sayi giriniz...\n");
	scanf("%d", &num);
	
	// calculating the length of the number
	num2 = num;
	while(num2 >= 10) {
		num2 /= 10;
		len++; 
	}
	
	// sums the modulos of 10 of the number
	for(i = 0; i < len; i++) {
		sum += num % 10;
		num /= 10; 
	}
	
	// prints the sums to the screen
	printf("Sayinin basamaklari degerleri toplami: %d\n", sum);
	
	return 0;
}
