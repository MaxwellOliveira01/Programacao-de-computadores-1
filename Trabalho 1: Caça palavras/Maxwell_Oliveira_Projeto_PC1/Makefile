main: main.o leitura.o processamento.o saida.o
	cc -Wall main.o leitura.o processamento.o saida.o -o main

main.o: main.c
	cc -c -Wall main.c

leitura.o: leitura.c leitura.h
	cc -c -Wall leitura.c

saida.o: saida.c saida.h
	cc -c -Wall saida.c

processamento.o: processamento.c processamento.h
	cc -c -Wall processamento.c

clean:
	rm main.o leitura.o saida.o processamento.o