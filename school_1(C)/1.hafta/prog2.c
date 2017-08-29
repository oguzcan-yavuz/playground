// this program reads more than one data with scanf

#include <stdio.h>

int main() {
    
    // variables
    int sayi1, sayi2, sayi3;
    
    // asks for an input
    printf("Lutfen 3 tamsayi giriniz:\n");
    
    // gets the numbers and passes them to our variables
    scanf("%d%d%d", &sayi1, &sayi2, &sayi3);
    
    // prints the results to the screen
    printf("bugun %d m yuzdum, %d m kostum, %d m kurek cektim.\n", sayi1, sayi2, sayi3);
    return 0;
}