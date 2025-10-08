all: $(patsubst %.c,bin/%,$(wildcard *.c))

bin/%: %.c
	gcc-14 -std=c2x -g -Wall $< -o $@

clean:
	rm -rf bin
	mkdir bin
