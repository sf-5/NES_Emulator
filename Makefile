CC = gcc
CFLAGS = -Wall -std=c99 -g

main: main.o cpu.o

main.o: main.c cpu.h
cpu.o: cpu.c cpu.h