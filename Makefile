CC=gcc
CFLAGS=-std=c99

bf: bf.c
	$(CC) ${CFLAGS} -obf bf.c
