onda.png: Solucion.dat
	python Ejercicio29.py

Solucion.dat : a.out
	./a.out

a.out: SierraAlexander_Ej29.cpp
	g++ SierraAlexander_Ej29.cpp
    