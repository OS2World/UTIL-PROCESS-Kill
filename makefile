CFLAGS=-O -Wall
CC=gcc $(CFLAGS)

all:		kill.obj kill.exe shutdown.obj shutdown.exe

kill.obj:	kill.c
		$(CC) -c kill.c

kill.exe:	kill.obj
		link386/PM:VIO kill.obj,,,,,

shutdown.obj:	shutdown.c
		$(CC) -c shutdown.c

shutdown.exe:	shutdown.obj
		link386/PM:VIO shutdown.obj,,,,,
