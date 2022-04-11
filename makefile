CC = gcc

ODIR = obj
_OBJ = main.o crypt.o key.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

CFLAGS = -Wall -pedantic -Wextra 


compile: $(OBJ)
	$(CC) $(OBJ) -o main $(CFLAGS)


$(ODIR)/%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f main $(ODIR)/*.o
