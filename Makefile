
all: hotzenplotz

hotzenplotz: hotzenplotz.c
	gcc -Wall -pedantic -o hotzenplotz hotzenplotz.c

clean:
	rm -f hotzenplotz
