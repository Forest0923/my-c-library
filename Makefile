TARGET	= test
SRC		= src/mystring.c src/mysprintf.c src/mystdlib.c
H_PATH	= .

default:
	make run --no-print-directory

run:
	make compile
	./$(TARGET).o

compile: $(TARGET).c $(SRC)
	gcc -g -I $(H_PATH) -o $(TARGET).o $(TARGET).c $(SRC)

clean:
	rm -f *.o
