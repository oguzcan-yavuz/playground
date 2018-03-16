#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"

int n;
int adim=0;
void print_array(int arr[][n], int length){
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            printf("%d ", arr[i][j]);
        }
            printf("\n");
    }
}
int feriha(int kaldi,int matrix[][n],int p2){
    if(matrix[kaldi][kaldi+1] == 1 && matrix[kaldi+1][kaldi]==1){
        admin++;
        return 0;
    }
    else {
        return -1;
    }
}
int check(int matrix[][n], int p1, int p2) {
    int kaldi=p1;
    if(matrix[p1][p2] == 1 && matrix[p2][p1] == 1)
        return 1;
    else {
        while(feriha(kaldi,matrix,p2)==0){
            kaldi++;
        }
    }
    return adim;
}

int main() {
    n = GetInt();
    char str[20];
    char* word;         
    int matrix[n][n];
    int j;
    
    for(int i = 0 ; i < n ; i++){
        j = 0;
        fgets(str, 20, stdin);
        word = strtok(str, "\n ,");
        while(word != NULL) {
            matrix[i][j] = (int) (strtol(word, NULL, 10));
            word = strtok(NULL, "\n ,");
            j++;
        }
    }
    int p1 = GetInt();
    int p2 = GetInt();
    printf("\n");
    printf("%d\n",check(matrix,p1,p2));
	return 0;
}
