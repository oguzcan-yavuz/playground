#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node_t;

node_t *root = NULL;

int say() {
    int node_sayisi = 0;
    node_t *temp = root;
    while(temp) {
        node_sayisi++;
        temp = temp -> next;
    }
    return node_sayisi;
}

void sona_ekle(int data) {
    node_t *yeni_node = malloc(sizeof(node_t));
    if(yeni_node == NULL) return;
    yeni_node -> data = data;

    if(root == NULL) {      // ilk defa bir node olusturuluyor ise
        yeni_node -> prev = NULL;
        yeni_node -> next = NULL;
        root = yeni_node;
    } else {        // yeni olusturulan node'dan once olusturulmus baska node veya node'lar varsa
        node_t *son_node = root;
        // son node'u bul
        while(son_node -> next) {
            son_node = son_node -> next;
        }
        // eski LinkedList'lerdeki son node'un next degerine yeni olusturdugumuz node'un adresini, yeni olusturdugumuz node'un prev degerine
        // eski LinkedList'lerdeki son node'un adresini atadik. yeni olusturdugumuz node'un next degeri, artik son eleman oldugu icin NULL olur.
        son_node -> next = yeni_node;
        yeni_node -> prev = son_node;
        yeni_node -> next = NULL;
    }
}

void listele() {
    node_t *temp = root;
    while(temp) {
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
}

void araya_ekle(int data, int index) {
    // su anki node'larin toplam sayisi
    int size = say();
    int user_index = index;
    // yeni node olustur
    node_t *yeni_node = malloc(sizeof(node_t));
    yeni_node -> data = data;

    node_t *verilen_index_node = root;
    // verilen index'teki son node'u bul. Eger size'dan buyuk index degeri verilirse, en son node'a dan sonrasina gitmez.
    for(; verilen_index_node -> next && user_index > 0; user_index--) {
        verilen_index_node = verilen_index_node -> next;
    }
    // node'larin prev ve next degerlerini guncelle
    if(index == 0) {    // 0.indexe ekleme durumu, yeni node root olur.
        yeni_node -> prev = NULL;
        yeni_node -> next = verilen_index_node;
        verilen_index_node -> prev = yeni_node;
        root = yeni_node;
    } else if(index >= size) {     // sona eklenme durumu. yeni eklenen node en sona eklenir.
        yeni_node -> prev = verilen_index_node;
        yeni_node -> next = NULL;
        verilen_index_node -> next = yeni_node;
    } else {
        // araya ekleme durumu
        yeni_node -> prev = verilen_index_node -> prev;
        yeni_node -> next = verilen_index_node;
        verilen_index_node -> prev -> next = yeni_node;
        verilen_index_node -> prev = yeni_node;
    }
}

int bul(int data) {
    int index = 0;
    node_t *temp = root;
    while(temp) {
        if(temp -> data == data)
            return index;
        temp = temp -> next;
        index++;
    }
    return -1;
}

void sil(int data) {
    printf("verilen veri: %d\nVerilen veriye sahip olan node siliniyor.\n", data);
    int index = bul(data);
    // eger data bulunamazsa bir sey yapma
    if(index == -1) {
        printf("Verilen veriye sahip bir node bulunamadi.\n");
        return;
    }
    // verilen data'ya sahip olan node'a git
    node_t *temp = root;
    for(; index > 0; index--) {
        temp = temp -> next;
    }
    // baglantilari guncelle. kendisinden oncekinin next'ini, kendisinden sonraki node'a, kendisinden sonraki node'un prev'ini kendisinden onceki
    // node'a esitle
    if(temp -> prev == NULL) {     // root'un silinmesi durumu
        if(temp -> next != NULL) {      // tek elemanli LinkedList'in silinmesi durumu
            temp -> next -> prev = NULL;
            root = root -> next;
        } else {
            root = NULL;
        }
        return;
    } else {    // silinen root degilse, silinen node'dan onceki node'un next degerini guncelle
        temp -> prev -> next = temp -> next;
    }
    if(temp -> next == NULL) {      // tail (son node)'un silinmesi durumu
        temp -> prev -> next = NULL;
        temp = temp -> prev;
        return;
    } else {    // silinen tail degilse, node'dan sonraki node'un prev degerini guncelle
        temp -> next -> prev = temp -> prev;
    }
    // else'ler icin ortak durum, temp'teki node'un silinmesi.
    temp = NULL;
    free(temp);
}

void yok_et() {
    while(root -> next) {
        root = root -> next;
        root -> prev = NULL;
        free(root -> prev);
    }
    // donguden ciktiginda en son root kaliyor, next degeri olmadigi icin dongu devam etmiyor. onu da asagida siliyoruz.
    root = NULL;
    free(root);
    printf("Yok etme basarili.\n");
}

void ekle_sonra(int data, int pivot) {
    node_t *yeni_node = malloc(sizeof(node_t));
    yeni_node -> data = data;
    int pivot_index = bul(pivot);
    // verilen data'ya sahip olan node'a git
    node_t *temp = root;
    for(; pivot_index > 0; pivot_index--) {
        temp = temp -> next;
    }
    // baglantilari guncelle
    yeni_node -> next = temp -> next;
    yeni_node -> prev = temp;
    temp -> next = yeni_node;
    yeni_node -> next -> prev = yeni_node;
}

void degistir(int data_1, int data_2) {
    int index_1 = bul(data_1);
    int index_2 = bul(data_2);
    // index_1'deki node'u bul ve bir pointer'a ata
    node_t *node_1 = root;
    for(; index_1 > 0; index_1--)
        node_1 = node_1 -> next;
    // index_2'deki node'u bul ve bir pointer'a ata
    node_t *node_2 = root;
    for(; index_2 > 0; index_2--)
        node_2 = node_2 -> next;
    // verileri swapla
    node_1 -> data = data_2;
    node_2 -> data = data_1;
}

