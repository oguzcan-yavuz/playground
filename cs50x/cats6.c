/* 

bir tane kedi varmis. bu kedinin kac tane baligi oldugunu ve gunde kac tane yemeyi planladigini verecekler bize
daha sonra da her gun kacar tane yemis onun bilgisini verecek
eger kedinin baligi bitmezse ekrana Happy Cat yazdiracaksin
eger kedinin baligi bitmisse, kacinci gunde bittigini ekrana yazdiracaksin

Ornek:

input:

40  => kedinin sahip oldugu toplam balik sayisi (F)
5   => kac gun boyunca yemeyi planliyor         (D)
10  => 0.gun kac tane yemis
7   => 1.gun
30  => 2.gun
5   => 3.gun
5   => 4.gun

output:

2

aciklamasi: 0.gun 10 tane yemis, kaldi 30. 1.gun 7 daha, kaldi 23. 2.gun 30 tane yemis aq oburu, -7 kalmis yani balik bitmis
burada programin sadece 2 yazmasi gerekiyor ekrana.

sinirlamalar:
MAX_INT degeri <= balik sayisi(F) ve gun plan sayisi(D) <= 0

*/
#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (){
    int balikSayisi;
    int plan;
    int gunler[20];
    int indeks=-1;
    balikSayisi = GetInt();
    plan = GetInt();
    for (int i = 0 ; i < plan ; i++){
        gunler[i] = GetInt();
        balikSayisi -= gunler[i];
        if(balikSayisi<=0 && indeks==-1){
            indeks=i;
        }
    }
    if(indeks != -1){
        printf("%d",indeks);
    }
    else{
        printf("Happy Cat!");
    }
        return 0;
}

#include <stdio.h>

int main(){
    
    int fish=0,day=0,i=1,val=0,total=0,control=0;
    
    scanf("%d\n",&fish);
    scanf("%d\n",&day);
    
    for(i ; i<day ; i++){
        scanf("%d\n",&val);
        total +=val;
        if(total>fish){
            if(control<1){
            day=i;
            control=1;
            }
        }
    }    
    
    if(control<1){
        printf("Happy Cat\n");
    }else{
        printf("%d\n",day);
    }
    
    return 0;
}



