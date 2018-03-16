/*
ID: oguzcan1
PROG: namenum
LANG: C
*/

#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE *fin = fopen("namenum.in", "r");
    FILE *dic = fopen("valid_names.txt", "r");
    FILE *fout = fopen("namenum.out", "w");
    int n = fscanf(fin, "%d ", &n);
    printf("%d\n", n);

    return 0;
}
