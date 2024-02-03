SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -ggdb -I$(INC_DIR)
U_CFLAGS := -lcheck

FTESTS_DIR := ./func_tests
UTESTS_DIR := ./unit_tests

OBJECTS_ALL := $(OUT_DIR)/read_create_print.o $(OUT_DIR)/sort.o $(OUT_DIR)/key.o
OBJECTS_MAIN := $(OUT_DIR)/main.o
OBJECTS_UNIT := $(OUT_DIR)/check_main.o $(OUT_DIR)/check_filter.o $(OUT_DIR)/check_sort.o $(OUT_DIR)/check_read.o


%.exe: $(OBJECTS_MAIN) $(OBJECTS_ALL)
	$(CC) -o $@ $^

unit_tests.exe: $(OBJECTS_UNIT) $(OBJECTS_ALL)
	$(CC) -o $@ $^ $(U_CFLAGS)

time.exe: $(OUT_DIR)/time.o $(OUT_DIR)/sort.o
	$(CC) -o $@ $^

$(OUT_DIR)/time.o: ./time/time.c object_dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/check_%.o: ${UTESTS_DIR}/check_%.c ${INC_DIR}/*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: ${SRC_DIR}/%.c ${INC_DIR}/check_*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: func
func:
	cd $(FTESTS_DIR) && bash all_tests.sh

.PHONY: object_dir
object_dir:
	@mkdir -p $(OUT_DIR)

.PHONY: clean
clean:
	$(RM) $(OUT_DIR)/*.o
	$(RM) *.exe
	$(RM) *.o
	rm -rf $(OUT_DIR)


