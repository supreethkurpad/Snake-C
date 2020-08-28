a.out: client.o server.o
	gcc client.o server.o -o a.out -lncurses
client.o: client.c server.h
	gcc -c client.c server.h 
server.o: server.c server.h
	gcc -c server.c server.h
