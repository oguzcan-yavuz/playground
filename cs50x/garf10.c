#include "cs50.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *optimum(int toplam, int arr[],int arr2[], int len) {
    int max,max2;
    char *sonuc= malloc(1000);
    if(len >= 2) {
        max = arr[len - 1];
        max2 = arr2[len - 1];
    } else {
        sprintf(sonuc,"%d,%d",arr[len - 1],arr2[len - 1]);
        return sonuc;
    }
    int min = 0,min2=0;
    int pivot = len - 1;
    int res = 0,res2=0;
    for(int i = 1; i < len; i++) {
        res = arr[pivot];
        res2 = arr2[pivot];
        int second = pivot - 1;
        for(int j = 0; j < len; j++) {
            printf("Ne oluyor amk Res: %d Res2: %d Min: %d Min2: %d\n", res, res2, min, min2);
            res += arr[second - j];
            res2 += arr2[second - j];
            if(res > toplam) {
                if(res <= max) {
                    max = res;
                    max2 = res2;
                    res = arr[pivot];
                    res2 = arr2[pivot];
                }
                res = arr[pivot];
                res2 = arr2[pivot];
            } else if(res == toplam) {
                sprintf(sonuc,"%d,%d",res,res2);
                return sonuc;
            } else if(res < toplam) {
                while(j < len) {
                    if(second - j - 1 < 0) {
                        break;
                    }
                    if(res >= min) {
                        min = res;
                        min2 = res2;
                        printf("debug Res: %d Res2: %d Min: %d Min2: %d J:%d \n", res, res2, min, min2, j);
                    }
                    
                    res += arr[second - j - 1];
                    res2 += arr2[second - j - 1];
                    //printf("Arr debug: %d J: %d Second: %d\n", arr[second - j - 1], j, second);
                    //printf("Res2 debug: %d\n", res2);
                    if(res > toplam) {
                        res -= arr[second - j - 1];
                        res2 -= arr2[second - j - 1];
                    }
                    j++;
                }
            }
        }
        printf("FORdebug Res: %d Res2: %d Min: %d Min2: %d\n", res, res2, min, min2);
        pivot--;
    }
    int maxim = 0;
    if(max > min && max < toplam) {
        min = max;
        min2 = max2;
    }
    else if(max < toplam) {
        maxim = (max - toplam) * -2;
    } else {
        maxim = (max - toplam) * 2;
    }
    if(toplam - min <= maxim) {
        sprintf(sonuc,"%d,%d",min,min2);
        return sonuc;
    } else {
        sprintf(sonuc,"%d,%d",max,max2);
        return sonuc;
    }
}

void swap(int *arr,int *arr2, int i, int j){
    if(i == j) return;
    int temp = arr[i];
    int temp2 = arr2[i];
    arr[i] = arr[j];
    arr2[i] = arr2[j];
    arr[j] = temp;
    arr2[j] = temp2;
}

void quick_sort(int *arr,int *arr2,int length){
    if(length <= 0) return;

    int pivot = arr[length - 1], wall = 0;

    for(int i = 0; i < length - 1; i++)
        if(pivot > arr[i]) {
            swap(arr,arr2, wall, i);
            wall += 1;
        }

    swap(arr,arr2, wall, length - 1);
    quick_sort(arr + wall + 1,arr2 + wall + 1 , length - wall - 1);
    quick_sort(arr,arr2, wall);
}

int main() {
    int aclik;
    aclik = GetInt();
    int kacYemek;
    kacYemek= GetInt();
    char girdi[20];
    int sayilar[20];
    int doyurganlik[20];
    int S_Dmi=0;
    char *word;
    int topSayilar = 0 , topDoyurganlik = 0 ,mutluluk=0;
    
    
    for(int i = 0 ; i < kacYemek ; i++){
        fgets(girdi, 20, stdin);
        word = strtok(girdi, "\n ,");
        while(word != NULL) {
            if(S_Dmi == 0){
                sayilar[i] =(int) (strtol(word,NULL, 10));
                S_Dmi=1;
            }else{
                doyurganlik[i]=(int) (strtol(word,NULL, 10));
                S_Dmi=0;
            }
            word = strtok(NULL, "\n ,");
        }
        
    }
    
    quick_sort(sayilar,doyurganlik,kacYemek);
    char *optim=optimum(aclik,sayilar,doyurganlik,kacYemek);
    S_Dmi=0;
    word = strtok(optim, "\n ,");
    while(word != NULL) {
        if(S_Dmi == 0){
            topSayilar =(int) (strtol(word,NULL, 10));
            S_Dmi=1;
        }else{
            topDoyurganlik=(int) (strtol(word,NULL, 10));
            S_Dmi=0;
        }
        word = strtok(NULL, "\n ,");
    }
    if(aclik<=topSayilar){
        mutluluk=(topSayilar-aclik)*(-20);
    }
    else{
        mutluluk=(aclik-topSayilar)*(-10);
    }
    mutluluk+=topDoyurganlik;
    printf("%d\n",mutluluk);
    return 0;
}
