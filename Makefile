CC := gcc 
files := $(wildcard *.c)
CFLAGS := -Wall -Wextra -O3 -march=native -mtune=native -ffast-math
DCFLAGS := -Wall -Wextra -g

main: $(files)
	gcc $(CFLAGS) $(files) -o bin/$@ #output "main" as it's the target name

info:$(files)
	ls -la $(files)
clean:
	rm -rf bin/*
debug:
	$(CC) $(DCFLAGS) $(files) -o bin/debug
