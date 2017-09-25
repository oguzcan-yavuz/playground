#include <stdio.h>
#include <stdlib.h>

typedef struct _ResizeableArray {
    int *arr;
    int size;           // dizinin icindeki eleman sayisi
    int capacity;       // Elimizdeki pointerin isletim sistemi tarafindan ayirilan alani
} ResizeableArray;

// Yeni bir yeniden boyutlandirilabilir dizi olustur.
ResizeableArray make_array(int n) {
    int* arr = (int*) malloc(n * sizeof(int));              // cast islemi yapma sebebi, malloc fonksiyonunun void array'i dondurmesi
    ResizeableArray resizeableArray = {arr, 0, n};
    return resizeableArray;
}

// yeniden boyutlandirma fonksiyonu
void resize_array(ResizeableArray *resizeableArray) {
    int newCapacity = resizeableArray->capacity * 2;
    resizeableArray->arr = realloc(resizeableArray->arr, newCapacity * sizeof(int));
    resizeableArray->capacity = newCapacity;
}

// verilen degeri yeniden boyutlandirilabilir diziye ekle, eger yer yoksa boyutu buyult

void add_to_array(ResizeableArray *resizeableArray, int value) {
    // *arr. veya arr-> (pointer oldugunu belli etmemiz gerek)
    if(resizeableArray->size < resizeableArray->capacity) {
        resizeableArray->arr[resizeableArray->size] = value;
        resizeableArray->size += 1;
    } else {
        resize_array(resizeableArray);
        add_to_array(resizeableArray, value);
    }

}

int main() {

    /* malloc (verdigimiz byte boyutunda isletim sisteminden yer ister)
       calloc (malloc haricinde istedigimiz boyutun degerini de belirtmemizi saglar. ornek: sayac yaparken dizinin bos elemanlarini 0 olarak istemek)
       realloc (daha once aldigimiz bir ram blogunu buyutur veya kucultur)

    Struct: Class yapisinin babasi.
    typedef: typedef int ahmet (int yerine ahmet yazarsak ayni islevi gorecek)
    */

    ResizeableArray arr = make_array(25);
    add_to_array(&arr, 73);
    printf("%p\n%d\n%d\n%d\n", arr.arr, arr.size, arr.capacity, arr.arr[0]);
    return 0;
}
