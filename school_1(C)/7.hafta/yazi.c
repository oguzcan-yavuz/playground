// ekrandan girilen 4 basamakli sayiyi yaziyla yazan programi yaziniz.

#include <stdio.h>

void binler(int a) {
    int bin = a / 1000;
    switch(bin) {
        case 1:
            printf("bin ");
            break;
        case 2:
            printf("iki bin ");
            break;
        case 3:
            printf("uc bin ");
            break;
        case 4:
            printf("dort bin ");
            break;
        case 5:
            printf("bes bin ");
            break;
        case 6:
            printf("alti bin ");
            break;
        case 7:
            printf("yedi bin ");
            break;
        case 8:
            printf("sekiz bin ");
            break;
        case 9:
            printf("dokuz bin ");
            break;
    }
}

void yuzler(int a) {
    int yuz = a / 100;
    yuz %= 10;
    switch(yuz) {
        case 1:
            printf("yuz ");
            break;
        case 2:
            printf("iki yuz ");
            break;
        case 3:
            printf("uc yuz ");
            break;
        case 4:
            printf("dort yuz ");
            break;
        case 5:
            printf("bes yuz ");
            break;
        case 6:
            printf("alti yuz ");
            break;
        case 7:
            printf("yedi yuz ");
            break;
        case 8:
            printf("sekiz yuz ");
            break;
        case 9:
            printf("dokuz yuz ");
            break;
    }
}

void onlar(int a) {
    int on = a % 100;
    on /= 10;
    switch(on) {
        case 1:
            printf("on ");
            break;
        case 2:
            printf("yirmi ");
            break;
        case 3:
            printf("otuz ");
            break;
        case 4:
            printf("kirk ");
            break;
        case 5:
            printf("elli ");
            break;
        case 6:
            printf("atmis ");
            break;
        case 7:
            printf("yetmis ");
            break;
        case 8:
            printf("seksen ");
            break;
        case 9:
            printf("doksan ");
            break;
    }
}

void birler(int a) {
    int bir = a % 10;
    
    switch(bir) {
        case 1:
            printf("bir\n");
            break;
        case 2:
            printf("iki\n");
            break;
        case 3:
            printf("uc\n");
            break;
        case 4:
            printf("dort\n");
            break;
        case 5:
            printf("bes\n");
            break;
        case 6:
            printf("alti\n");
            break;
        case 7:
            printf("yedi\n");
            break;
        case 8:
            printf("sekiz\n");
            break;
        case 9:
            printf("dokuz\n");
            break;
    }
}

int main() {
    
    int n;
    
    printf("Bir sayi giriniz.\n");
    scanf("%d", &n);
    
    binler(n);
    yuzler(n);
    onlar(n);
    birler(n);
    
    return 0;
}
