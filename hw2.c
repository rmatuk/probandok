/*
Nombre de archivo: hw2.c (No cambiar el nombre de este archivo)
El repositorio donde esta tu HW2 es: github.com/unlu-edu-ar/prog1-2022-hw-2-TuNombreDeUsuarioGithub
Importante: No cambiar el nombre del archivo

Completa con tu nombre, apellido y DNI
Nombre y Apellido:
DNI:
*/


/* Programe una funcion para agregar un elemento al final de un vector.
INPUT: v (vector de numeros enteros), n (entero), util (int*), elem (int) 
OUTPUT: s (int)
siendo v el vector al que se desea agregar un elemento, n la longitud maxima del
vector v, util un puntero a la variable que almacena la cantidad de elementos 
actualmente utilizados de v, y elem el elemento a agregar.
La funcion debera agregar elem al final de los elmentos utilizados del vector v, 
e incrementar el valor de la variable apuntada por util en 1.
La función debe retonar cero si pudo agregar exitosamente el elemento, y 1 en 
el caso de que el vector v este lleno y no se pueda agregar el elemento al vector.

Ejemplo: 
Si v = {3,4,1,8}, n = 4, *util = 2, elem = 7, tras llamar a la funcion debe quedar
   v = {3,4,7,8}, *util = 3, s = 0
Si v = {3,4,1,8}, n = 4, *util = 4, elem = 7, tras llamar a la funcion debe quedar
   v = {3,4,1,8}, *util = 4, s = 1
*/
int agregar(int v[], int n, int* util, int elem){ 
	// Programar la funcion aqui
}


/* Programe una funcion para eliminar el elemento en el indice pos de un vector.
INPUT: v (vector de numeros enteros), n (entero), util (int*), pos (int) 
OUTPUT: s (int)
siendo v el vector al que se desea eliminar un elemento, n la longitud maxima del
vector v, util un puntero a la variable que almacena la cantidad de elementos 
actualmente utilizados de v, y pos el indice del elemento a eliminar.
Para eliminar el elemento de la posición pos, la funcion debe mover los elementos 
utilizados una posicion hacia la izquierda (hasta la posicion pos).
La funcion tambien debe decrementar en 1 la variable apuntada por util.
La función debe retonar cero si pudo eliminar exitosamente el elemento, y 1 en 
el caso de que no haya podido eliminar el elemento.

Ejemplo: 
Si v = {3,4,1,8}, n = 4, *util = 3, pos = 1, tras llamar a la funcion debe quedar
   v = {3,1,1,8}, *util = 2, s = 0
Si v = {3,4,1,8}, n = 4, *util = 1, pos = 2, tras llamar a la funcion debe quedar
   v = {3,4,1,8}, *util = 1, s = 1
 */
int eliminar(int v[], int n, int* util, int pos){ 
	// Programar la funcion aqui
}


/* Programe una funcion que reciba una matriz de enteros, de m filas por n 
columnas como entrada. Si su cantidad de filas es mayor o igual que su
cantidad de columnas, la funcion debe retornar la sumatoria de los elementos
de la matriz. Si su cantidad de filas es menor que su cantidad de columnas, 
la funcion debe retornar la productoria de los elementos de la matriz. 
INPUT: m (int), n (int), arr (matriz de numeros enteros de mxn)
OUTPUT: s (int) 
*/
int sumaprod_matriz(int m, int n, int arr[m][n]){ 
	// Programar la funcion aqui
}


/* Programe una funcion que reciba una matriz de enteros, de m filas por n 
columnas como entrada, y retorne el minimo de los elementos de la matriz.
INPUT: m (int), n (int), arr (matriz de numeros enteros de mxn)
OUTPUT: minimo (int) 
*/
int minimo_elem_matriz(int m, int n, int arr[m][n]){ 
	// Programar la funcion aqui
}


/*
Programe una funcion que reciba una matriz de enteros, de m filas por n 
columnas como entrada, un vector v de dimension m, y un vector w de 
dimension n, y coloque la sumatoria de sus elementos de sus filas en
el vector v, y la sumatoria de los elementos de sus columnas en w.
INPUT: m (int), n (int), arr (matriz de numeros enteros de mxn), 
v (vector de enteros), w (vector de enteros)
OUTPUT: void 
*/
void suma_filas_col(int m, int n, int arr[m][n], int v[m], int w[n]){ 
	// Programar la funcion aqui
}