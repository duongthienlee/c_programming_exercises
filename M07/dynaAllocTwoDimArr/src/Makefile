SRC_FILES=dynaAllocTwoDimArr.c main.c
HEADER_FILES=dynaAllocTwoDimArr.h
CFLAGS += -std=c99 -g -Wall -Wextra -Wno-missing-field-initializers

all: main

main: $(SRC_FILES) $(HEADER_FILES)
	gcc $(CFLAGS) -o $@ $(SRC_FILES) -lm

clean:
	rm -f main

run: main
	# Running our main function from file main.c
	./main
