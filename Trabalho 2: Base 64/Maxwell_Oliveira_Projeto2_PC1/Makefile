main: main.o codificador.o decodificador.o utilitarios.o
	cc -Wall main.o codificador.o decodificador.o utilitarios.o -o base64

main.o: main.c
	cc -c -Wall main.c

codificador.o: codificador.c codificador.h
	cc -c -Wall codificador.c

decodificador.o: decodificador.c decodificador.h
	cc -c -Wall decodificador.c

utilitarios.o: utilitarios.c utilitarios.h
	cc -c -Wall utilitarios.c

clean:
	rm main.o codificador.o decodificador.o utilitarios.o