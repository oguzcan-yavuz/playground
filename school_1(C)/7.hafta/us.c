#include <stdio.h>
int us(int taban, int us1)
{
    int sonuc = 1;
    for (int i = 0; i < us1; i++) {
        sonuc *= taban;
    }
    return sonuc;
}

int main() {
    int taban, us1;
    printf("tabanı gir : ");
    scanf("%d", &taban);
    printf("us gir : ");
    scanf("%d", &us1);
    printf ("sonuc %d\n",us(taban, us1));
    return 0;
}