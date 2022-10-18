# IMPORTANTE: No modificar ni borrar ni renombrar este archivo

all: a.out
	./a.out a
	./a.out e
	./a.out s
	./a.out m
	./a.out f
	
a.out:
	gcc test_hw2.c -o a.out

agregar: a.out
	./a.out a

eliminar: a.out
	./a.out e

sumaprod_matriz: a.out
	./a.out s

minimo_elem_matriz: a.out
	./a.out m

suma_filas_col: a.out
	./a.out f

clean:
	rm a.out