#include <stdio.h>
#include <string.h>

#include <stdlib.h>
int main() {
	char girdi[40];
    char *word;
    char *ptr;
    double A[4];
    double B[4];
    double yeniAx,yeniBx,yeniAy,yeniBy,uzunluk,genislik;
    fgets(girdi, 40, stdin);
   	word = strtok(girdi, "\n ");
    for(int i = 0 ; i < 4;i++){
    	A[i] = strtod(word, &ptr);
        word = strtok(NULL, " ");	
	}
	fgets(girdi, 40, stdin);
   	word = strtok(girdi, "\n ");
    for(int i = 0 ; i < 4;i++){
        B[i] = strtod(word, &ptr);
    	word = strtok(NULL, " ");	
	}
	yeniAx=A[0]+A[2];
	yeniBx=B[0]+B[2];
	yeniAy=A[1]+A[3];
	yeniBy=B[1]+B[3];
//Genislik
	if(B[0]<A[0]){
		if(A[0] <= yeniBx && yeniBx <= yeniAx){
			genislik = yeniBx - A[0];
		}else if(yeniAx < yeniBx){
			genislik=yeniAx - A[0];
		}
		else{
			genislik=0;
		}
	}
	else{
		if(B[0] <= yeniAx && yeniAx <= yeniBx){
			genislik = yeniAx - B[0];
		}else if(yeniBx < yeniAx){
			genislik=yeniBx - B[0];
		}
		else{
			genislik=0;
		}
	}
//Uzunluk	
	
	if(B[1]<A[1]){
		if(A[1] <= yeniBy && yeniBy <= yeniAy){
			uzunluk = yeniBy - A[1];
		}else if(yeniAy < yeniBy){
			uzunluk = yeniAy - A[1];
		}
		else{
			uzunluk=0;
		}
	}else{
		if(B[1] <= yeniAy && yeniAy <= yeniBy){
			uzunluk = yeniAy - B[1];
		}else if(yeniBy < yeniAy){
			uzunluk = yeniBy - B[1];
		}
		else{
			uzunluk=0;
		}
	}
	printf("%.2lf",(uzunluk*genislik));
    return 0;
}
