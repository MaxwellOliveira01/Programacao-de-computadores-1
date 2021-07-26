main: main.o aloca.o leitura.o processamento.o saida.o
	cc -Wall main.o aloca.o leitura.o processamento.o saida.o -o main

main.o: main.c
	cc -c -Wall main.c

aloca.o: aloca.c aloca.h
	cc -c -Wall aloca.c

leitura.o: leitura.c leitura.h
	cc -c -Wall leitura.c

processamento.o: processamento.c processamento.h
	cc -c -Wall processamento.c

saida.o: saida.c saida.h
	cc -c -Wall saida.c

clean:
	rm main.o aloca.o leitura.o processamento.o saida.o

