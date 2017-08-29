#include <stdio.h>
#include <cs50.h>

// This program calculates how much water has spent in shower
int main(void) {

    // Asking to user for input
    int mins;
    
    do {
        printf("minutes: ");
        mins = GetInt();
    }
    while (mins <= 0);
    
    printf("bottles: %d\n", mins * 12);

    return 0;
}
