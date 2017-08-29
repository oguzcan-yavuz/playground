#include <stdio.h>

int main() {
    
    int dizi[4 * 1024] = {0};  // bu örnekle stack RAM kullanıldığı için en fazla 4MB civarı bir RAM ayırabiliyoruz.
    //int* dizi = (int*) malloc(sizeof(int) * 4);  // burada ise 2GB kadar yer alabiliyoruz.
    
    printf("%p icerisinde %d degeri var.\n", &dizi[0], dizi[0]);
    return 0;
}
