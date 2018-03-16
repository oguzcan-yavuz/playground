/*
ID: oguzcan1
PROG: transform
LANG: C
*/

#include <stdio.h>

int check(int length, char result[length][length + 1], char after[length][length + 1], int status) {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if(result[i][j] != after[i][j])
                return 0;
        }
    }
    return status;
}

int rotate(int length, char before[length][length + 1], char after[length][length + 1], int status) {
    char result[length][length + 1];
    int n = length - 1;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if(status == 1) {
            result[i][j] = before[length - 1 - j][i];
            } else if(status == 2) {
                result[i][j] = before[n][length - j - 1];
            } else {
                result[i][j] = before[j][n];
            }
        }
        n--;
    }
    return check(length, result, after, status);
}

int reflection(int length, char before[length][length + 1], char after[length][length + 1]) {
    char result[length][length + 1];
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            result[i][j] = before[i][length - 1 - j];
        }
    }
    if(check(length, result, after, 4) == 4) {
        return 4;
    } else if(rotate(length, result, after, 1) == 1 || rotate(length, result, after, 2) == 2 || rotate(length, result, after, 3) == 3) {
        return 5;
    } else {
        return 0;
    }
}


int convert(int length, char before[length][length + 1], char after[length][length + 1]) {
    /* (30 mayis 2017) sadece fonksiyonun ici optimize edilmeye calisildi, cok ugrasilmadi. goz ucuyla yapildi.
    for(int i = 1; i < 7; i++) {
        if(rotate(length, before, after, i) == i)
            return i;
    }
    return 7;*/
    // #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
    if(rotate(length, before, after, 1) == 1)
        return 1;
    // #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
    if(rotate(length, before, after, 2) == 2)
        return 2;
    // #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
    if(rotate(length, before, after, 3) == 3)
        return 3;
    // #4: Reflection: The pattern was reflected horizontally
    // (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
    // #5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
    if(reflection(length, before, after) == 4) {
        return 4;
    } else if(reflection(length, before,after) == 5) {
        return 5;
    }
    // #6: No Change: The original pattern was not changed.
    if(check(length, before, after, 6) == 6) {
        return 6;
    } else {
        return 7;
    }
}


int main() {
    FILE *fin = fopen("transform.in", "r");
    FILE *fout = fopen("transform.out", "w");
    int n;
    fscanf(fin, "%d ", &n);
    char before[n + 1][n + 1];
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%s ", before[i]);
    }
    char after[n + 1][n + 1];
    for(int i = 0; i < n; i++) {
        fscanf(fin, "%s ", after[i]);
    }
    int result = convert(n, before, after);
    fprintf(fout, "%d\n", result);
    return 0;
}

/* USACO SOLUTION:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXN 10

typedef struct Board Board;
struct Board {
    int n;
    char b[MAXN][MAXN];
};

 rotate 90 degree clockwise: [r, c] -> [c, n - r]
Board
rotate(Board b)
{
    Board nb;
    int r, c;

    nb.n = b.n;
    for(r=0; r<b.n; r++)
        for(c=0; c<b.n; c++)
            nb.b[c][b.n-1 - r] = b.b[r][c];
    return nb;
}

 reflect board horizontally: [r, c] -> [r, n-1 -c] 
Board
reflect(Board b)
{
    Board nb;
    int r, c;

    nb.n = b.n;
    for(r=0; r<b.n; r++)
        for(c=0; c<b.n; c++)
            nb.b[r][b.n-1 - c] = b.b[r][c];
    return nb;
}

return non-zero if and only if boards are equal 
int
eqboard(Board b, Board bb)
{
    int r, c;

    if(b.n != bb.n)
        return 0;
    for(r=0; r<b.n; r++)
        for(c=0; c<b.n; c++)
            if(b.b[r][c] != bb.b[r][c])
                return 0;
    return 1;
}

Board
rdboard(FILE *fin, int n)
{
    Board b;
    int r, c;

    b.n = n;
    for(r=0; r<n; r++) {
        for(c=0; c<n; c++)
            b.b[r][c] = getc(fin);
        assert(getc(fin) == '\n');
    }
    return b;
}

void
main(void)
{
    FILE *fin, *fout;
    Board b, nb;
    int n, change;

    fin = fopen("transform.in", "r");
    fout = fopen("transform.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d\n", &n);
    b = rdboard(fin, n);
    nb = rdboard(fin, n);

    if(eqboard(nb, rotate(b)))
        change = 1;
    else if(eqboard(nb, rotate(rotate(b))))
        change = 2;
    else if(eqboard(nb, rotate(rotate(rotate(b)))))
        change = 3;
    else if(eqboard(nb, reflect(b)))
        change = 4;
    else if(eqboard(nb, rotate(reflect(b)))
         || eqboard(nb, rotate(rotate(reflect(b))))
         || eqboard(nb, rotate(rotate(rotate(reflect(b))))))
        change = 5;
    else if(eqboard(nb, b))
        change = 6;
    else
        change = 7;

    fprintf(fout, "%d\n", change);

    exit(0);
}
*/