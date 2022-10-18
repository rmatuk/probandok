/* test_hw2.c 
   IMPORTANTE: No modificar ni borrar ni renombrar este archivo 
   Tests del HW2 - Programacion 1, Universidad Nacional de Lujan */

/* 1 includes */
#include "hw2.c"
#include "assert.h"
#include <stdio.h>
/* 2 defines */
// Testings agregar (a), eliminar (e), minimo matriz (m), sumaprod (s), sumafilcol (f)
#define OPTSTR "a:e:m:s:f"
/* 3 external declarations */
/* 4 typedefs */
/* 5 global variable declarations */
/* 6 function prototypes */
int compareArrays(int a[], int b[], int n);
void testeando_agregar();
void testeando_eliminar();
void testeando_sumaprod_matriz();
void testeando_minimo_elem_matriz();
void testeando_suma_filascol();


int main(int argc, char *argv[]) {
// /* 7 command-line parsing */

    testeando_agregar();
    testeando_eliminar();
    testeando_minimo_elem_matriz();
    testeando_sumaprod_matriz();
    testeando_suma_filascol();
    return 0;
}

/* 8 function declarations */
// Funciones auxiliares
// Si los arrays son iguales devuelve true (o sea, 1). Sino, retorna falso (0).
int compareArrays(int a[], int b[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

//Funciones de tests de vectores 

void testeando_agregar(){
    // Defino algunos vectores para probar 
    int arr1[] = {1,3,0};
    int arr2[] = {1,2,0};
    int arr3[] = {1,2,4};
    int util_arr1 = 1;
    int ok; 
    int elem1 = 2;
    int elem2 = 4;
    // s1 is the size of array 1
    int s1 = sizeof(arr1) / sizeof(arr1[0]);

    ok = agregar(arr1, s1, &util_arr1, elem1);
    assert(compareArrays(arr1, arr2, s1));
    assert(util_arr1==2);
    assert(ok==0);
    ok = agregar(arr1, s1, &util_arr1, elem2);
    assert(compareArrays(arr1, arr3, s1));
    assert(util_arr1==3);
    assert(ok==0);
    ok = agregar(arr1, s1, &util_arr1, elem2);
    assert(compareArrays(arr1, arr3, s1));
    assert(util_arr1==3);
    assert(ok==1);
}

void testeando_eliminar(){
    // Defino algunos vectores para probar 
    int arr3[] = {1,2,4};
    int arr4[] = {1,4,4};
    int arr5[] = {4,4,4};
    int arr6[] = {1,2,4,9};
    int arr7[] = {1,4,4,9};
    int util_arr3 = 3;
    int util_arr6 = 3;
    int ok; 
    int pos0 = 0;
    int pos1 = 1;
    int s3 = sizeof(arr3) / sizeof(arr3[0]);
    int s6 = sizeof(arr6) / sizeof(arr6[0]);   

    ok = eliminar(arr3, s3, &util_arr3, pos1);
    assert(compareArrays(arr3, arr4, s3));
    assert(util_arr3==2);
    assert(ok==0);
    ok = eliminar(arr3, s3, &util_arr3, pos0);
    assert(compareArrays(arr3, arr5, s3));
    assert(util_arr3==1);
    assert(ok==0);
    ok = eliminar(arr3, s3, &util_arr3, pos1);
    assert(compareArrays(arr3, arr5, s3));
    assert(util_arr3==1);
    assert(ok==1); 
    ok = eliminar(arr6, s6, &util_arr6, pos1);
    assert(compareArrays(arr6, arr7, s6));
    assert(util_arr6==2);
    assert(ok==0);
}

// Funciones de tests de matrices 

void testeando_sumaprod_matriz(){
    // Defino dos matrices para los casos de test de matrices
    #define m1 2
    #define n1 3
    int mat1[m1][n1] = {{1,3,0},{1,1,0}};
    #define m2 3
    #define n2 2
    int mat2[m2][n2] = {{1,1},{2,1},{1,1}};

    assert(sumaprod_matriz(m1, n1, mat1)==0);   
    assert(sumaprod_matriz(m2, n2, mat2)==7); 
}

void testeando_minimo_elem_matriz(){
    // Defino dos matrices para los casos de test de matrices
    #define m1 2
    #define n1 3
    int mat1[m1][n1] = {{1,3,0},{1,1,0}};
    #define m2 3
    #define n2 2
    int mat2[m2][n2] = {{1,1},{2,1},{1,1}};

    assert(minimo_elem_matriz(m1, n1, mat1)==0);   
    assert(minimo_elem_matriz(m2, n2, mat2)==1); 
}

void testeando_suma_filascol(){
    // Defino dos matrices para los casos de test de matrices
    #define m1 2
    #define n1 3
    int mat1[m1][n1] = {{1,3,0},{1,1,0}};
    #define m2 3
    #define n2 2
    int mat2[m2][n2] = {{1,1},{2,1},{1,1}};

    // Defino 2 vectores para el ejercicio de sumar filas y columnas
    int v1[m1];
    int w1[n1];
    int v2[m2];
    int w2[n2];

    int r_v1[m1] ={4,2};
    int r_w1[n1] ={2,4,0};
    int r_v2[m2] ={2,3,2};
    int r_w2[n2] ={4,3};

    // Obtengo la longitud de los vectores
    int sv1 = sizeof(v1) / sizeof(v1[0]);
    int sw1 = sizeof(w1) / sizeof(w1[0]);

    suma_filas_col(m1, n1, mat1, v1, w1);
    suma_filas_col(m2, n2, mat2, v2, w2);
    assert(compareArrays(v1, r_v1, sv1));   
    assert(compareArrays(w1, r_w1, sw1)); 
    assert(compareArrays(v2, r_v2, sw1));  
    assert(compareArrays(w2, r_w2, sv1));  
}