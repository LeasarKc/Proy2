#Headers
headers = lib.h

#Ejecutable

proy2: proy2.o func.o
	gcc proy2.o func.o -o proy2

#Objetos

func.o: $(headers) func.c
	gcc -c func.c

proy2.o: $(headers) proy2.c
	gcc -c proy2.c


