CC = gcc

EXEC1 = first
EXEC2 = second

all: $(EXEC1).c $(EXEC2).c
	$(CC) $(EXEC1).c -o $(EXEC1) 
	$(CC) $(EXEC2).c -o $(EXEC2)

