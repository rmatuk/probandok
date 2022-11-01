# IMPORTANTE: No modificar ni borrar ni renombrar este archivo

all: a.out
	./a.out
	
a.out:
	gcc test_hw3.c -o a.out

sin_lluvias: a.out
	./a.out s

llovio_umbral: a.out
	./a.out u

contador_dias_maximo_calor: a.out
	./a.out c

dia_mas_frio_mes: a.out
	./a.out f

promedio_lluvias_mes: a.out
	./a.out p

clean:
	rm a.out