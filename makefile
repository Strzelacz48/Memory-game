CC = gcc
CFLAGS = -Wall -Wextra -xc -Werror -Wno-unused-parameter  `pkg-config gtk+-3.0 --cflags`

LFLAGS = `pkg-config gtk+-3.0 --libs`

final:
	$(CC) $(CFLAGS) main.c -o MemoryGame funkcje.c $(LFLAGS)
clean:
	rm MemoryGame