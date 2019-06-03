TARGET := a.out

CC := g++
CFLAGS := -std=c++11 -Wall -Wextra -g

$(TARGET): main.cpp str_blob.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: rebuild clean all
rebuild: clean all
all: $(TARGET)
clean:
	rm -rf *.o *.out
