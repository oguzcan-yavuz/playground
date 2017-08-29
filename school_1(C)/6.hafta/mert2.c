#include <stdio.h>

int main() 
{
    int sayi, m;
    printf("Sayi giriniz = ");
    scanf("%d",&sayi);
    int i;
    for(i=1;i<=sayi;i++)
    {
        for(m=1;m<=i;m++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int c = sayi;c > 1;c--)
    {
        for(int k = sayi;k > 1;k--)
        {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}