CC = clang
CFLAGS = -Wall -Wextra -std=c11

all: simulador

simulador: main.c artemis.c validaciones.c
	$(CC) $(CFLAGS) -o simulador main.c artemis.c validaciones.c

clean:
	rm -f simulador

