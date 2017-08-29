// ekrandan girilen sayi degerinin kac oldugunu ve asal sayi olup olmadigini, olmadiysa nedenini ekrana yazdiran programi yaziniz...
/*


int i = 0;
while (i != 5) {
  printf("%d\n", i);
  i++;
}


for(; i != 5; ) {
i++
int i = 0
  printf("%d\n", i);

for(int i = 0; i != 5; i++) {
  printf("%d\n", i);
}
*/

#include <stdio.h>

int main(){
  int sayi,test=2;
  
  scanf("%d",&sayi);
  
  
  for(;sayi>test;){
      if(sayi%test==0) {
      printf("bu sayi asal degildir\n");
      return 0;
        
      }
    
    test++;
    
      
    
  }
  
  printf("sayi asaldir");
}


