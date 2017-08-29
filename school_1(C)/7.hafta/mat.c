/* Matematik fonksiyonlari programi: Menu opsiyonlu bir program. 1 ile 5 arasi bir rakam girerek hangi fonksiyonu calistirmak istedigini kullanici
belirleyecek. 
1. Iki sayinin minimum'u
2. Iki sayinin max'i
3. Kare (10 tabaninda logaritma)
4. Kup
5. Mutlak deger

NOT: LOGARITMA FONKSIYONU EKLENECEK.
*/

#include <stdio.h>
#include <math.h>

double min();
double max();
double logg();
double kup();
double mutlak();

int main() {
    
    int n;
    printf("Hangi islemi yapmak istiyorsaniz yanindaki rakami giriniz.\n1. Iki sayinin minimumunu bulma.\n2. Iki sayinin maximumunu bulma.\n3. Logaritma.\n4. Bir sayinin kupunu alma.\n5. Bir sayinin mutlak degerini alma.\nCikmak icin 1-5 disinda bir deger giriniz.\n");
    scanf("%d", &n);
    
    switch(n) {
        
        case 1:
            printf("%lf\n", min());
            break;
        case 2:
            printf("%lf\n", max());
            break;
        case 3:
            printf("%lf\n", logg());
            break;
        case 4:
            printf("%lf\n", kup());
            break;
        case 5:
            printf("%lf\n", mutlak());
            break;
        default:
            printf("Cikis yapiliyor.\n");
    }
    
}

double max() {
    double a, b;
    printf("Iki deger veriniz.\nEger iki deger esit ise 0.0 dondurulecek\n");
    scanf("%lf%lf", &a, &b);
    if(a > b) {
        return a;
    } else if (a == b) {
        return 0.0;
    } else {
        return b;
    }
}

double min() {
    double a, b;
    printf("Iki deger veriniz.\nEger iki deger esit ise 0.0 dondurulecek\n");
    scanf("%lf%lf", &a, &b);
    if(a < b) {
        return a;
    } else if (a == b) {
        return 0.0;
    } else {
        return b;
    }
}

double logg() {
    
    double n, t;
    printf("Logaritmasi alinacak bir deger ve taban veriniz.\n");
    scanf("%lf%lf", &n, &t);

    return log(n) / log(t);
}

double kup() {
    double a;
    printf("Kupu alinacak bir deger veriniz.\n");
    scanf("%lf", &a);
    return a * a * a;
}

double mutlak() {
    double a;
    printf("Mutlak degeri alinacak bir deger veriniz.\n");
    scanf("%lf", &a);
    if(a < 0) {
        return a * (- 1);
    } else {
        return a;
    }
}
