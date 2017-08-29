// this program calculates the area of circle

#include <stdio.h>

int main() {
    
    // variables
    float pi = 3.1415;
    float r, toplam;
    
    // asks for an input to user
    printf("yaricapi giriniz:\n");
    
    // assigns the input to r variable
    scanf("%f", &r);
    
    toplam = pi * r * r;
    // returns the area of circle
    printf("alan: %f\n", toplam);
    return 0; 
}
