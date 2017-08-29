#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"

int n;
int adim=1;
void print_array(int arr[][n], int length){
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            printf("%d ", arr[i][j]);
        }
            printf("\n");
    }
}
int feriha(int i,int matrix[][n],int p2){
    if(matrix[i][p2]==1 && matrix[p2][i]==1){
        adim++;
        return adim;
    }
    else{
        for(int j = i+1 ; j < n ; j++){
            if(matrix[i][j] == 1 && matrix[j][i]==1){
                adim++;
                feriha(j,matrix,p2);
            }
            if( j == n-1 )
            {
                return 0;
            }
        }
    }
    return 0;
}
int check(int matrix[][n], int p1, int p2) {
    if(matrix[p1][p2] == 1 && matrix[p2][p1] == 1)
    {
        return 1;
    }
    else {
        for(int i=0 ; i < n ; i++){
            if(feriha(i,matrix,p2)!=0){
                return adim;
            }
            else if(n-1==i){
                return -1;
            }
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
    int tut;
    int p1 = GetInt();
    int p2 = GetInt();
    if(p1>p2){
        tut=p1;
        p1=p2;
        p2=tut;
    }
    printf("%d\n",check(matrix,p1,p2));
	return 0;
}
