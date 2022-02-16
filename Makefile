CC = gcc
TARGET = bin/mtfuji
OBJS = src/mtfuji.o src/data.o src/func.o src/optimize.o src/qsort.o
LIBS = m
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -l$(LIBS)

.PHONY: clean
clean: 
		rm src/*.o bin/mtfuji
