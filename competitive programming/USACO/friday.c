/*
ID: oguzcan1
PROG: friday
LANG: C
*/
#include <stdio.h>

int main() {
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "w");
    int year;
    fscanf(fin, "%d", &year);
    int days[7] = {0, 0, 0, 0, 0, 0, 0};
    int total_days = (365 * year) + (year / 4);
    int index = 1, months = 0, month_days, temp, current_year;
    while(total_days >= 30) {
        months += 1;
        // if the months is February
        if(months % 12 == 2) {
            // also check for leap
            current_year = months / 12;
            if((current_year + 1900) % 100 == 0) {
                if((current_year + 1900) % 400 == 0) {
                    month_days = 29;
                } else {
                    month_days = 28;
                }
            } else if(current_year % 4 == 0) {
                month_days = 29;
            } else {
                month_days = 28;
            }

        } else if(months % 12 == 4 || months % 12 == 6 || months % 12 == 9 || months % 12 == 11) {
            month_days = 30;
        } else {
            month_days = 31;
        }
        index %= 7;
        total_days -= month_days;
        temp = index;
        index += 13 % 7;
        index %= 7;
        days[index] += 1;
        index = temp;
        index += month_days % 7;
    }
    // writes the results to the output file
    for(int i = 0; i < 7; i++) {
        fprintf(fout, "%d", days[i]);
        if(i < 6)
            fprintf(fout, " ");
    }
    fprintf(fout, "\n");
    return 0;
}


/* USACO SOLUTION:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int
isleap(int y)
{
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int mtab[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/* return length of month m in year y
int
mlen(int y, int m)
{
    if(m == 1)    /* february
        return mtab[m]+isleap(y);
    else
        return mtab[m];
}

void
main(void)
{
    FILE *fin, *fout;
    int i, m, dow, n, y;
    int ndow[7];

    fin = fopen("friday.in", "r");
    fout = fopen("friday.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d", &n);

    for(i=0; i<7; i++)
        ndow[i] = 0;

    dow = 0;    /* day of week: January 13, 1900 was a Saturday = 0
    for(y=1900; y<1900+n; y++) {
        for(m=0; m<12; m++) {
            ndow[dow]++;
            dow = (dow+mlen(y, m)) % 7;
        }
    }

    for(i=0; i<7; i++) {
        if(i)
            fprintf(fout, " ");
        fprintf(fout, "%d", ndow[i]);
    }
    fprintf(fout, "\n");

    exit(0);
}

*/
