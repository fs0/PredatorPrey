CC = gcc
OBJ = main.o predator.o prey.o functions.o
TARGET = predprey
LIBS = -lrt

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@ $(LIBS)

%.o: %.c
	$(CC) -c -g -O3 $< 
clean:
	rm -f *.o
