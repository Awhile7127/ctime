CC=gcc
CFLAGS=-I.
FILES=src/*.c
OUTPUT=ctime

$(OUTPUT):
	$(CC) $(CFLAGS) $(FILES) -o $(OUTPUT)
