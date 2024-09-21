CC = g++
CFLAGS = -g -Wall
TARGET = vi
all : $(TARGET)
vi: vi.o
	$(CC) $(CFLAGS) -o vi vi.o
vi.o : src/vi.cpp
	$(CC) $(CFLAGS) -c src/vi.cpp
.PHONY: clean
clean:
	$(RM) *.o $(TARGET)