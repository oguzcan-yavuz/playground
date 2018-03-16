#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int results[n][2];
    int i = 0, keo = 0, elif = 0, start = 0, end = 0, j = 0;
    for(; i < n; ++i) {
        scanf("%d %d", &start, &end);
        for(; start < end; ++start) {
            if(start <= 10) {
                keo++;
            }
            else if(start > 10 && start < 100) {
                if(start / 10 == (start / 10) % 10) {
                    elif++;
                } else {
                    keo++;
                }
            }
        }
        results[i][0] = keo;
        results[i][1] = elif;
    }

    for(; j < n; ++j) {
        printf("%d %d\n", results[j][0], results[j][1]);
    }
    return 0;
}
