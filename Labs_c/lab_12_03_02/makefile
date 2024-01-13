CC := gcc
CFLAGS := -std=c99 -Wall -Werror -pedantic

OBJ_DIR := ./out

LIB_DIR := ./lib
LIB_FILES := $(wildcard $(LIB_DIR)/*.c)

LIBS := $(LIB_FILES:$(LIB_DIR)/%.c=$(LIB_DIR)/lib_%.dll)

.PHONY : clean run lib

lib: $(LIBS)

$(OBJ_DIR):
	@mkdir -p $@

$(LIB_DIR)/lib_%.dll: $(OBJ_DIR)/%.o
	$(CC) -o $@ -shared $<

$(OBJ_DIR)/%.o: $(LIB_DIR)/%.c $(OBJ_DIR)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

run: lib
	python3 interface.py 
clean:
	$(RM) $(LIB_DIR)/*.dll 
	rm -rf ./out