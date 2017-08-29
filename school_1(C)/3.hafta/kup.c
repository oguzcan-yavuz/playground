// yaricapi, 1 kupun kenar uzunluguna esit olan kurenin hacminin kupun hacmine olan oranini bulan programi yaziniz.

#include <stdio.h>

int main() {
    int r=2, KupunHacmi=0 ; 
    float pi=3.14,Oran=0,KureHacmi=0;
    
    KupunHacmi = r*r*r;
    KureHacmi  = 4.0/3.0*pi*KupunHacmi;
    
    Oran = KureHacmi/KupunHacmi;
    printf ("adasda:%f\n",Oran);
    
    return 0;
}