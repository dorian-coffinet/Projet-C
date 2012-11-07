CC = gcc
OBJS = main.o list_etu.o annuaire.o 
CFLAGS = -g -c -Wall -ansi -pedantic  
LDFLAGS = 
PGM = programme

$(PGM): $(OBJS)
	$(CC) -o $(PGM) $(LDFLAGS) $(OBJS)

main.o:	main.c  list_etu.h annuaire.h
	$(CC) $(CFLAGS) main.c

list_etu.o: list_etu.c list_etu.h
	$(CC) $(CFLAGS) list_etu.c

annuaire.o:	annuaire.c annuaire.h list_etu.h
	$(CC) $(CFLAGS) annuaire.c	

clean:	
	rm -f $(OBJS)
	rm -f *~
