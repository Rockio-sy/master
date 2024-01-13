CC = gcc
CFLAGS = -Wall
SRC_DIR = src
INC_DIR = inc
SRC = $(SRC_DIR)/main.c
TARGET = app

$(SRC_DIR)/main.o: $(SRC)
	$(CC) $(CFLAGS) -o $@ -c $<

$(TARGET): $(SRC) $(INC_DIR)/errs.h
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(TARGET) main.o


