/*
ID: oguzcan1
PROG: ride
LANG: C
*/
#include <stdio.h>
#include <string.h>

int calculate_multiply(char arr[]) {
    char alph[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    
    int res = 1;
    
    for(int i = 0; i < strlen(arr); i++) {
        for(int j = 0; j < 26; j++) {
            if(arr[i] == alph[j]) {
                res *= (j + 1);
                break;
            }
        }
    }
    return res;
}

int main() {
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    char first[8];
    char second[8];
    fscanf(fin, "%s %s", first, second);
    
    int sum1 = calculate_multiply(first); 
    int sum2 = calculate_multiply(second);
    
    char go[3] = "GO";
    char stay[5] = "STAY";
    
    if(sum1 % 47 == sum2 % 47) {
        fprintf(fout, "%s\n", go);
    } else {
        fprintf(fout, "%s\n", stay);
    }
    
    return 0;
}
