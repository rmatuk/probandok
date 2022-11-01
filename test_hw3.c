/* test_hw3.c 
   IMPORTANTE: No modificar ni borrar ni renombrar este archivo 
   Tests del HW3 - Programacion 1, Universidad Nacional de Lujan */

/* 1 includes */
#include "hw3.c"
#include "assert.h"
#include <stdio.h>
/* 2 defines */
// Testings sin lluvias (s), umbral (u), maximo calor (c), dia mas frio (f), promedio lluvia (p)
#define OPTSTR "s:u:c:f:p"
/* 3 external declarations */
/* 4 typedefs */
/* 5 global variable declarations */
/* 6 function prototypes */
void test_sin_lluvias();
void test_llovio_umbral();
void test_contador_dias_maximo_calor();
void test_dia_mas_frio_mes();
void test_promedio_lluvias_mes();
void test_all();

int main(int argc, char *argv[]) {
// /* 7 command-line parsing */
    if(argc==1)
        test_all();

    if(argc>=2)
    {
        int opt = *(argv[1]);
        switch (opt)
        {
        case 's':
            test_sin_lluvias();
            break;

        case 'u':
            test_llovio_umbral();
            break;

        case 'c':
            test_contador_dias_maximo_calor();
            break;

        case 'f':
            test_dia_mas_frio_mes();
            break;

        case 'p':
            test_promedio_lluvias_mes();
            break;

        default:
            printf("Ese parametro de linea no existe!\n");
            return 1;
        }
    }
    return 0;
}

/* 8 function declarations */

// Funciones de tests de archivos
void test_sin_lluvias(){
    FILE* fp;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_sin_lluvias...");
    assert(sin_lluvias(fp, 1)==2);
    assert(sin_lluvias(fp, 2)==4);
    assert(sin_lluvias(fp, 3)==8);
    assert(sin_lluvias(fp, 4)==0);
    printf("Paso!\n");
    fclose(fp);
}

void test_llovio_umbral(){
    FILE* fp;
    int lluvias_menor_x, lluvias_mayorigual_x;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_llovio_umbral... ");
    llovio_umbral(fp, 10, &lluvias_menor_x, &lluvias_mayorigual_x);
    assert(lluvias_menor_x==34);
    assert(lluvias_mayorigual_x==86);
    llovio_umbral(fp, 20, &lluvias_menor_x, &lluvias_mayorigual_x);
    assert(lluvias_menor_x==56);
    assert(lluvias_mayorigual_x==64);
    printf("Paso!\n");
    fclose(fp);
}

void test_contador_dias_maximo_calor(){
    FILE* fp;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_contador_dias_maximo_calor... ");
    assert(contador_dias_maximo_calor(fp, 1)==2);
    assert(contador_dias_maximo_calor(fp, 2)==2);
    assert(contador_dias_maximo_calor(fp, 3)==5);
    assert(contador_dias_maximo_calor(fp, 4)==4);
    printf("Paso!\n");
    fclose(fp);
}

void test_dia_mas_frio_mes(){
    FILE* fp;
    int dia, temp_minima;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_dia_mas_frio_mes... ");
    dia_mas_frio_mes(fp, 1, &dia, &temp_minima);
    assert(dia ==2);
    assert(temp_minima==5);
    dia_mas_frio_mes(fp, 2, &dia, &temp_minima);
    assert(dia ==4);
    assert(temp_minima==6);
    dia_mas_frio_mes(fp, 3, &dia, &temp_minima);
    assert(dia ==21);
    assert(temp_minima==5);
    dia_mas_frio_mes(fp, 4, &dia, &temp_minima);
    assert(dia ==25);
    assert(temp_minima==5);
    printf("Paso!\n");
    fclose(fp);
}

void test_promedio_lluvias_mes(){
    FILE* fp;
    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_promedio_lluvias_mes... ");
    assert((int)promedio_lluvias_mes(fp, 1)==25);
    assert((int)promedio_lluvias_mes(fp, 2)==20);
    assert((int)promedio_lluvias_mes(fp, 3)==17);
    assert((int)promedio_lluvias_mes(fp, 4)==22);
    printf("Paso!\n");
    fclose(fp);
}

void test_all(){
    printf("Testear todo...\n");
    test_sin_lluvias();
    test_llovio_umbral();
    test_contador_dias_maximo_calor();
    test_dia_mas_frio_mes();
    test_promedio_lluvias_mes();
    printf("Pasaste todos los tests. Felicitaciones!!\n");
}