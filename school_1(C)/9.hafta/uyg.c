/* 
1- Klavyeden 10 adet tam sayiyi okuyarak bir diziye atayiniz. Daha sonra diziye girilen sayilarin ters sirada diziye tekrar yerlestiren 
programi yaziniz. Bu islem icin sadece 1 dizi kullaniniz. 
*/

#include <stdio.h>

int main() {

    int dizi[10];
    
    for(int i = 0; i < 10; i++) {
        scanf("%d", &dizi[i]);
    }
    
    int j = 0;
    
    for(int k = 10; k > 4; k--, j++) {
        int temp = dizi[k];
        dizi[k] = dizi[j];
        dizi[j] = temp;
        //j++;
    }
    
    for(int l = 1; l <= 10; l++) {
        printf("%d. eleman: %d\n", l, dizi[l]);
    }
    return 0;    
}
