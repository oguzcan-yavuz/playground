#include <stdio.h>

int main() 
{
    int sayi;
    int m = 0;
    int e = 1;
    int k = 1;
    
    printf("Bir sayi giriniz = ");
    scanf("%d",&sayi);
    int i;
    for(i=1;i<sayi;i++)
    {
        if(i < 2) {
            printf("%d %d ", e, k);
        } else {
            m = e + k;
            printf("%d ",m);
            k = e;
            e = m;
        }
        
        
    }
    printf("\n");
    return 0;
}