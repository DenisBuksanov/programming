.PHONY: clean run all

CC = gcc
TARGET = main
SOURCE_DIR = src
INCLUDE_DIR = include
INCLUDES = -I./include
AR = ar

LIB = libcripto.a

all: $(TARGET)

$(TARGET): criptomain.o $(LIB)
	$(CC) -o $(TARGET) criptomain.o -L. -lcripto

$(LIB): cripto.o
	$(AR) rcs $(LIB) cripto.o

criptomain.o: $(SOURCE_DIR)/criptomain.c $(INCLUDE_DIR)/cripto.h
	$(CC) -c $(SOURCE_DIR)/criptomain.c -o criptomain.o $(INCLUDES)

cripto.o: $(SOURCE_DIR)/cripto.c $(INCLUDE_DIR)/cripto.h
	$(CC) -c $(SOURCE_DIR)/cripto.c -o cripto.o $(INCLUDES)

clean:
	rm -rf *.o $(TARGET) $(LIB)

run: all
	./$(TARGET)
