CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic
SOURCES = $(shell find src -name "*.c")
OBJECTS = $(SOURCES:.c=.o)
BINARY = fizzbuzz

all: $(BINARY)

$(BINARY): out $(OBJECTS)
	@$(CC) $(CFLAGS) $(LDFLAGS) out/$(shell basename $(OBJECTS)) -o $(shell basename $@)

.c.o: out
	@$(CC) $(CFLAGS) -c $< -o out/$(shell basename $@)

clean:
	@rm -rf out $(BINARY)

out:
	@mkdir -p $@

