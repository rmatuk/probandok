/*
Una empresa de repuestos tiene su sistema de stock organizado de la siguiente forma:
En un archivo secuencial “MOVIMIENTOS.TXT” agrupado por código de repuesto, todos
los movimientos del año, con la siguiente estructura.
MOVIMIENTOS.TXT
CODI_REP_MOVI Codigo del repuesto (entero) (Agrupado)
DIA_MOVI Dia del movimiento (entero)
MES_MOVI Mes del movimiento (entero)
ANI_MOVI Año del movimiento (entero)
TIPO_MOVI Tipo de movimiento (entero. 1: Compra 2: Venta)
CANTI_MOVI Cantidad que se compraron o vendieron (entero)
Considerar que el archivo ya está creado y almacenado en disco con todos los datos.
Realizar un programa en C completo y modularizado que:
1) Informe por pantalla un listado con el stock final de cada Repuesto (Comprados -
Vendidos).
2) Determine en que mes se vendio la mayor cantidad de repuestos.
3) Informe por pantalla cual es el repuesto con mayor stock.
NOTA: El archivo MOVIMIENTOS.TXT se debe leer por completo solo una vez en todo el
programa.
*/
#include <stdio.h>
#define MESES 12
//Muestra x pantalla los productos y los stocks por pantalla
void mostrar_stock(char n_archivo[]);
//Muestra por pantalla el mes con maxima cantidad de ventas
void mes_maxima_ventas(int venta_meses[]);

int main(void){
    mostrar_stock("MOVIMIENTOS.TXT");
    return 0;
}

void mostrar_stock(char n_archivo[]){
    FILE* fp;
    int codprod,dia,mes,anio,tipo,cantidad; //Para leer los campos
    int codprod_ant; //Para guardar el producto anterior y hacer el corte de control
    int stock_prod; //Acumulador de stock de un producto individual
    int stock_mayor_cant = -1000; //Para guardar el mayor stock (cantidad) 
    int stock_mayor_prod = -1000; //Para guardar el mayor stock (codigo de producto)
    int venta_mes[12] = {0}; //Vector para acumular las ventas en cada mes incializado a cero
    fp = fopen(n_archivo, "r"); //Abro archivo secuencial en modo lectura

    //Corte de control para mostrar los productos y los stocks
    //El archivo esta AGRUPADO por el campo codprod
    //Para hacer el corte de control necesito leer la primera linea del archivo
    fscanf(fp,"%d %d %d %d %d %d",&codprod,&dia,&mes,&anio,&tipo,&cantidad);
    //Mostrar encabezado por pantalla
    printf("Producto Stock\n");
    while(!feof(fp)){
        codprod_ant = codprod;
        stock_prod = 0;
        while (!feof(fp) && codprod_ant==codprod) //Salgo del ciclo porque cambie de producto o se termino el archivo
        {
            if (tipo==1)
                stock_prod += cantidad; //Es compra, tengo mas stock
            else {
                stock_prod -= cantidad; //Es venta, tengo menos stock
                venta_mes[mes-1]+= cantidad;
            }

            fscanf(fp,"%d %d %d %d %d %d",&codprod,&dia,&mes,&anio,&tipo,&cantidad);
            if (feof(fp))
                //Caso especial para procesar la ultima linea de un archivo no vacio 
                if (tipo==1)
                    stock_prod += cantidad; //Es compra, tengo mas stock
                else {
                    stock_prod -= cantidad; //Es venta, tengo menos stock
                    venta_mes[mes-1]+= cantidad;
                }
        }          
        printf("%d \t %d\n",codprod_ant,stock_prod); //Muestro el producto y el stock
        //Actualizo el mayor
        if (stock_prod>stock_mayor_cant){
            stock_mayor_cant = stock_prod;
            stock_mayor_prod = codprod_ant;
        }
    }
    printf("El producto con mayor stock es %d\n", stock_mayor_prod);
    mes_maxima_ventas(venta_mes);
    fclose(fp);
}

void mes_maxima_ventas(int venta_meses[]){
    int max_ventas_cant = -1000;
    int max_ventas_mes = -1000;
    for (int i = 0; i < MESES; i++)
        if (venta_meses[i] > max_ventas_cant){
            max_ventas_cant = venta_meses[i];
            max_ventas_mes = i+1;
        }
    printf("El mes con mayor cantidad de ventas es: %d\n", max_ventas_mes);
}
