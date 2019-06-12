TARGET := a.out

CC := g++
LD := g++
CFLAGS := -std=c++11 -Wall -Wextra -Wpedantic -g

$(TARGET): main.o quote.o
	$(LD) -o $@ $^

main.o: main.cpp quote.h
	$(CC) $(CFLAGS) -c -o $@ $<

quote.o: quote.cpp quote.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: rebuild clean all
rebuild: clean all
all: $(TARGET)
clean:
	rm -rf *.o *.out *.dSYM
