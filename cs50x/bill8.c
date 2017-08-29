#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cs50.h"

int n;

void print_array(int arr[][n], int length){
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            printf("%d ", arr[i][j]);
        }
            printf("\n");
    }
}

int check(int matrix[][n], int p1, int p2) {
    // bu sadece p1'in p2'den kucuk oldugu durumlarda calisir. cunku dongu matrix icin soldan saga dogru gidiyor
    // p1 eger p2'den buyuk olursa, dongunun sagdan sola dogru gitmesi gerek.
    //knk bugun uyandıktan sonra biraz uğraştım kodlar yunus1 de bide 0.60 puan aldık ondan
    // gordum :D
    // p1 p2den buyukse ters cevirmek yerine dongu sagdan sola giderse daha iyi olur
    // olabilir ama for dongusunu nasıl ters cevirecen bi düşün bakalım
    //bende daha iyi bişey bulursam denicem sen devam et 
    // en amelece çözüm: if içerisinde küçükten büyüğe giden bir döngü, else içerisinde büyükten küçüğe giden döngü
    int result = 0;
    for(int i = 0; i <= p2; i++) {
        if(i == p1)
            continue;
        if(matrix[i][p2] == 1 && matrix[i][p1] == 1)
            result++;
        else
            return -1;
    }
    return result;
}

int check_caller(int matrix[][n], int p1, int p2) {
    if(matrix[p1][p2] == 1 || matrix[p2][p1] == 1)
        return 1;
    else
        return check(matrix, p1, p2);
}

int main() {
    n = GetInt();
    char str[20];
    char* word;         
    int matrix[n][n];
    int j;
    
    // converts the matrix input from string to an integer array
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
    
    // connections to check
    int p1 = GetInt();
    int p2 = GetInt();
    
    printf("Result: %d\n", check_caller(matrix, p1, p2));
	return 0;
}
