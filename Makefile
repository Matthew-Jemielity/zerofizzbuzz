CC = gcc
BASE_CFLAGS = -Wall -Wextra -ansi -pedantic -O2
SOURCES = $(shell find src -name "*.c")
OBJECTS = $(SOURCES:.c=.o)
BINARY = fizzbuzz
TEST = check

all: $(BINARY)

$(BINARY): out $(OBJECTS)
	@$(CC) $(BASE_CFLAGS) $(CFLAGS) $(LDFLAGS) out/$(shell basename $(OBJECTS)) -o $(shell basename $@)

.c.o: out
	@$(CC) $(BASE_CFLAGS) $(CFLAGS) -c $< -o out/$(shell basename $@)

clean:
	@rm -rf out $(BINARY) $(TEST)

out:
	@mkdir -p $@

check:
	@$(CC) $(BASE_CFLAGS) $(CFLAGS) $(LDFLAGS) test/test.c -o $(TEST) && ./$(TEST) && rm $(TEST)

