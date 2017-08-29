#include <stdio.h>
#include <cs50.h>

int main() {
    // asks for an input and gets it as long
    printf("Number: ");
    long num = GetLongLong();
    
    // gets the length of the credit card number
    int len = 0;
    long num2 = num;
    while (num2 >= 10) {
        num2 = num2 / 10;
        len++;
    }
    
    // variables for the algorithm
    int i, mod, sums = 0;
    long num3 = num;
    long num4 = num;
    
    // deletes the last digit of num3
    num3 /= 10;
    
    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
    for(i = 0; i < len; i++) {
        // it gets the mod 10 of the number and multiplies it with 2
        mod = (num3 % 10) * 2;
        // if result is great equal to 10, it adds the mod % 10 + 1 to 'sums'
        if(mod >= 10) {
            sums += (mod % 10) + 1;
        // if result is less than 10, it adds the mod to 'sums'
        } else {
            sums += mod;
        }
        // deletes the last 2 digits of the number
        num3 /= 100;
    }
    
    int j;
    
    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    for(j = 0; j < len; j++) {
        // it gets the mod 10 of the number and adds it to 'sums'
        sums += num4 % 10;
        // deletes the last 2 digits of the number
        num4 /= 100;
    }
    
    // Checks if the total’s last digit is 0
    if(sums % 10 == 0) {
        // if it's valid, checks for AMEX
        if(len == 14) {
            if(num / 10000000000000 == 34 || num / 10000000000000 == 37) {
                printf("AMEX\n");
            }
        }
        // if it's valid, checks for MASTERCARD
        if(len == 15) {
            if(num / 100000000000000 == 51 || num / 100000000000000 == 52 || num / 100000000000000 == 53 || num / 100000000000000 == 54 || num / 100000000000000 == 55) {
                printf("MASTERCARD\n");
            }
            // also checks for VISA len 16
            if(num / 1000000000000000 == 4) {
                printf("VISA\n");
            }
        }
        // if it's valid, checks for VISA len 13
        if(len == 12) {
            if(num / 1000000000000 == 4) {
                printf("VISA\n");
            }
        }
        // if card is invalid, prints INVALID to the screen
    } else {
        printf("INVALID\n");
    }
    
    return 0;
}
