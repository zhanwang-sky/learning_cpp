TARGET := a.out

CC := g++
LD := g++
CPPFLAGS := -std=c++11 -Wall -Wextra -Wpedantic -g

$(TARGET): main.o blob.o sales_data.o
	$(LD) -o $@ $^

main.o: main.cpp util.h blob.h sales_data.h
	$(CC) $(CPPFLAGS) -c -o $@ $<

blob.o: blob.cpp blob.h
	$(CC) $(CPPFLAGS) -c -o $@ $<

sales_data.o: sales_data.cpp sales_data.h
	$(CC) $(CPPFLAGS) -c -o $@ $<

.PHONY: rebuild clean all
rebuild: clean all
all: $(TARGET)
clean:
	rm -rf *.o *.out *.dSYM
