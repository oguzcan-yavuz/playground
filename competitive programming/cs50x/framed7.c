#include <stdio.h>
#include <string.h>

#include <stdlib.h>

int main() {
	char girdi[2000];
	char *kelimeler[20];
    char *word;
    int dongu=0,dongu2=0;
	int bosluk=0;
    int uzunluk=0;
    fgets(girdi, 2000, stdin);
   	word = strtok(girdi, "\n ");
   	while(word != NULL) {
        if(uzunluk<strlen(word)){
        	uzunluk=strlen(word);
        }
        kelimeler[dongu]=word;
        word = strtok(NULL, "\n ");
        dongu++;
    }
   	for(int i = 0 ; i < uzunluk +4; i++)
   		printf("#");
   	while(dongu2<dongu) {
        
        bosluk = uzunluk - strlen(kelimeler[dongu2]);
      	printf("\n# %s",kelimeler[dongu2]);
        for(int i=0;i<bosluk ; i++){
        	printf(" ");
        }
        printf(" #");
        dongu2++;
    }	
    printf("\n");
   	for(int i = 0 ; i < uzunluk +4; i++)
   		printf("#");
    
    return 0;
}
/*
input 
	word of the fucka
cıktı

#########
# word  #
# of    #
# the   #
# fucka #
#########
*/












