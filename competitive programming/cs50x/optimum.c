#include <stdio.h>

int optimum(int toplam, int arr[], int len) {
    int max;
    if(len >= 2) {
        max = arr[len - 1];
        printf("Max: %d\n", max);
    } else {
        return arr[len - 1];
    }
    int min = 0;
    int pivot = len - 1;
    int res = 0;
    for(int i = 1; i < len; i++) {
        res = arr[pivot];
        int second = pivot - 1;
        for(int j = 0; j < len; j++) {
            if(second - j < 0) {
                break;
            }
            res += arr[second - j];
            if(res > toplam) {
                if(res <= max) {
                    max = res;
                    res = arr[pivot];
                }
                res = arr[pivot];
            } else if(res == toplam) {
                return res;
            } else if(res < toplam) {
                while(j < len) {
                    if(res >= min) {
                        min = res;
                        printf("debug Res: %d Min: %d J:%d \n", res, min, j);
                    }
                    if(second - j - 1 < 0) {
                        break;
                    }
                    printf("Arr debug: %d J: %d Second: %d\n", arr[second - j - 1], j, second);
                    res += arr[second - j - 1];
                    if(res > toplam) {
                        res -= arr[second - j - 1];
                    }
                    j++;
                }
            }
        }
        pivot--;
    }
    int maxim = 0;
    if(max > min && max < toplam) {
        min = max;
    }else if(max < toplam) {
        maxim = (max - toplam) * -2;
    } else {
        maxim = (max - toplam) * 2;
    }
    if(toplam - min <= maxim) {
        return min;
    } else {
        return max;
    }
}

int main() {
    
    int dizi[] = { 3,5,6}; 
    printf("Sonuc: %d\n", optimum(10, dizi, 3));
    
    return 0;
}
