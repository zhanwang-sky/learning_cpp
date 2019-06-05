TARGET := a.out

CC := g++
CFLAGS := -std=c++11 -Wall -Wextra -Wpedantic -g

$(TARGET): main.cpp hasptr.cpp message.cpp strvec.cpp string.cpp
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: rebuild clean all
rebuild: clean all
all: $(TARGET)
clean:
	rm -rf *.o *.out *.dSYM
