/* 2- 3x3'luk bir matrisi klavyeden okutunuz. Okuttugunuz bu matrisin tersini alip ekrana yazdiran programi yaziniz. */

#include <stdio.h>

int main() {
    
    // bos bir 3x3 matris olustur
    float matris[3][3] = {};
    
    // kullaniciya matrisin elementlerini girmesini soyle
    printf("3x3'luk matrisin elementlerini sirayla giriniz...\n");
    
    // kullanicidan sirayla matrisin elementlerini al ve matris dizisine yerlestir
    for(int i = 1; i < 4; i++) {
        for(int k = 1; k < 4; k++) {
            printf("Matris elementi: %d,%d giriniz: ", i, k);
            scanf("%f", &matris[i - 1][k - 1]);
        }
    }
    
    // bosluk birak
    printf("\n");
    
    // matrisin elementlerini degiskenlere ata.
    float a = matris[0][0];
    float b = matris[0][1];
    float c = matris[0][2];
    float d = matris[1][0];
    float e = matris[1][1];
    float f = matris[1][2];
    float g = matris[2][0];
    float h = matris[2][1];
    float k = matris[2][2];
    
    // Determinant'i hesapla: detA=a11a22a33+a21a32a13+a31a12a23-a11a32a23-a31a22a13-a21a12a33
    float det = (a * e * k) + (d * h * c) + (g * b * f) - (a * h * f) - (g * e * c) - (d * b * k);
    printf("Determinant: %.0f\n\n---Matrisin Tersi--- \n\n", det);
    
    // Eger determinant 0'a esitse matrisin tersi yoktur. Programdan cikis yap.
    if(det == 0) {
        printf("Matrisin determinanti 0'a esit oldugundan dolayi tersi yoktur.\n");
        return 0;
    }
    
    // Ters matrisin elementlerini hesapla
    float a1 = ((e * k) - (f * h)) * 1 / det;
    float b1 = ((c * h) - (b * k)) * 1 / det;
    float c1 = ((b * f) - (c * e)) * 1 / det;
    float d1 = ((f * g) - (d * k)) * 1 / det;
    float e1 = ((a * k) - (c * g)) * 1 / det;
    float f1 = ((c * d) - (a * f)) * 1 / det;
    float g1 = ((d * h) - (e * g)) * 1 / det;
    float h1 = ((b * g) - (a * h)) * 1 / det;
    float k1 = ((a * e) - (b * d)) * 1 / det;
    
    // ters matrisin elementlerini yerlerine yerlestir
    float ters_matris[3][3] = {
        {a1, b1, c1},
        {d1, e1, f1},
        {g1, h1, k1}
    };
    
    // ters matrisi ekrana yazdir
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%.03f\t\t", ters_matris[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
