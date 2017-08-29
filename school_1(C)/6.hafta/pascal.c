/* Pascal ucgeninin belirtilen siralarini ekrana yazdiran programi yaziniz. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // kullanıcıdan satır sayısını ister
    int n;
    printf("Yazdırılacak sıra sayısını giriniz...\n");
    scanf("%d", &n);

    // satırların sol tarafında bırakılacak boşluk sayısını hesaplar
    int sol = n - 1;
    int iki = -1;
    int *aktif = malloc(n * sizeof(int));
    int *aktif2 = malloc(n * sizeof(int));
    aktif[0] = 1;
    aktif2[0] = 1;
    int sira = 1;
    
    // her satır için
    for(int i = 0; i < n; i++) {
        // sol tarafta hesaplanan değer kadar boşluk bırak
        for(int j = 0; j < sol; j++) {
            printf(" ");
        }
        
        // sol taraftaki boşluktan sonra 1 üçgenin sol tarafındaki 1'i ekrana yazdır
        printf("%d", aktif[0]);
        
        // dizileri guncelle
        if(sira == 1) {
            for(int m = 0; m < iki; m++) {
                aktif[m + 1] = aktif2[m] + aktif2[m + 1];
            }
            sira = 0;
        } else {
            for(int m = 0; m < iki; m++) {
                aktif2[m + 1] = aktif[m] + aktif[m + 1];
            }
            sira = 1;
        }
        
        // dizilerin son elemanini 1 yap
        if(iki > 1) {
            aktif[iki] = 1;
            aktif2[iki] = 1;
        }
        
        // 3. satırdan itibaren 1'er kez artarak üçgen içerisindeki hesaplamaları yazdırır.
        if(sira == 1) {
            for(int k = 0; k < iki; k++) {
                printf(" %d", aktif2[k] + aktif2[k + 1]);
            }
        } else {
            for(int k = 0; k < iki; k++) {
                printf(" %d", aktif[k] + aktif[k + 1]);
            }
        }
        
        // üçgenin sağ tarafındaki 1'i ekrana yazdırır, eğer üçgenin ilk satırı yazılıyorsa sağ tarafta 1 olmayacağı için eklemez
        if(i != 0) {
            printf(" 1\n");
        } else {
            printf("\n");
        }
        
        // sol boşluğu her satır için 1'er azaltır ve satırlar içerisindeki döngüyü her satırda 1'er arttırır.
        sol -= 1;
        iki += 1;
    }
    return 0;
}
