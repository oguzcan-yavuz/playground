/* 
1- Klavyeden 10 adet tam sayiyi okuyarak bir diziye atayiniz. Daha sonra diziye girilen sayilarin ters sirada diziye tekrar yerlestiren 
programi yaziniz. Bu islem icin sadece 1 dizi kullaniniz. 
*/

#include <stdio.h>

int main(){
    int dizi[10]={};
    for(int a=0;a<10;a++){
        scanf("%d",&dizi[a]);
    }

    for(int a=0,b=9;a<5;a++,b--){
        int g = dizi[b];
        dizi[b]=dizi[a];
        dizi[a]=g;
        
        
    }
    
    for(int a=0;a<10;a++){
        printf("degerler%d\n",dizi[a]);
        
    }
    
    return 0;
    
}