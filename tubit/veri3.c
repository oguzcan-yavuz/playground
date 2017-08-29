#include <stdio.h>
#include <stdlib.h>

typedef struct _LinkedList {
    int value;
    struct _LinkedList *next;
    
} LinkedList;

LinkedList* add_node(LinkedList *head, int value) {
    LinkedList *node = (LinkedList*) malloc(sizeof(LinkedList));
    // yeni olusturdugumuzun degeri, verilen parametreden geliyor.
    node->value = value;
    // yeni olusturdugumuz en son node, o uzden next = 0
    node->next = 0;
    // eger baslangic node'u yoksa yeni olusturdugumuz baslangic olur
    if(head == NULL) return node;
    
    // baslangic yoksa sonuncuyu bul
    while(head->next != NULL) head = head->next;
    
    // sonuncuya yeni olusturdugumuzun referansini ekle
    head->next = node;
    
    // en sonu dondur
    return node;
}

int main() {
    
    LinkedList *head = 0, *last;
    last = head = add_node(head, 73);
    
    for(int i = 0; i < 1024 * 256; i++) {
        add_node(head, i);
    }
    while(head != NULL) {
        printf("Deger: %d\n", head->value);
        head = head->next;
    }
    
    return 0;
}
