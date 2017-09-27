#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//n is strarr size
char* longestConsec(char* strarr[], int n, int k) {
  if(n == 0 || k > n || k <= 0)
    return "";
  int total_length = 0;
  for(int i = 0; i < n; i++)
    total_length += strlen(strarr[i]);

  char *result = (char*) malloc(total_length + 1);
  memset(result, '\0', total_length + 1);

    int start_index = 0;
    int maximum_length = 0;
    for(int i = 0; i < n - k + 1; i++) {
        int length = 0;
        int start = i;
        for(int j = 0; j < k; j++) {
            length += strlen(strarr[start]);
            start++;
        }
        if(length > maximum_length) {
            maximum_length = length;
            start_index = i;
        }
    }

    for(int i = 0; i < k; i++) {
        strcat(result, strarr[start_index]);
        start_index++;
    }

  return result;
}


int main() {
    char* a1[] = {"it", "wkppv", "ixoyx", "3452", "zzzzzzzzzzzz"};
    printf(longestConsec(a1, 5, 3));
    return 0;
}
