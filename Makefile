CC = g++
CFLAGS = -g -Wall
TARGET = vi
all : $(TARGET)
vi: vi.o editor.o text.o
	$(CC) $(CFLAGS) -o vi vi.o editor.o text.o
vi.o : src/vi.cpp
	$(CC) $(CFLAGS) -c src/vi.cpp
editor.o : src/editor.cpp
	$(CC) $(CFLAGS) -c src/editor.cpp
text.o : src/text.cpp
	$(CC) $(CFLAGS) -c src/text.cpp
.PHONY: clean
clean:
	$(RM) *.o $(TARGET)