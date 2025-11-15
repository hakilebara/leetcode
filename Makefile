all: $(patsubst %.c,bin/%,$(wildcard *.c))

bin/%: %.c
	clang -fsanitize=address -std=c23 -g -O0 -Wall $< -o $@

clean:
	rm -rf bin
	mkdir bin
