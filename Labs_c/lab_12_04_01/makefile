SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

CC := gcc
CFLAGS := -std=c99 -Wall -Werror -Wpedantic -ggdb -I$(INC_DIR)
U_CFLAGS := -lcheck

FTESTS_DIR := ./func_tests
UTESTS_DIR := ./unit_tests

NAME_EXPLORE := ARR_EXPORTS
NAME_UNIT_EXE := unit_tests.exe
NAME_EXE := app.exe
DYNAMIC_LIB := dynamic_lib.dll
STATIC_LIB := static_lib.a

OBJECTS_DYN_ALL := $(OUT_DIR)/dynamic_read_create_print.o $(OUT_DIR)/dynamic_sort.o $(OUT_DIR)/dynamic_key.o
OBJECTS_DYN_MAIN := $(SRC_DIR)/dynamic_main.c
OBJECTS_DYN_LOAD := $(SRC_DIR)/dynamic_load_main.c $(SRC_DIR)/dynamic_load.c

OBJECTS_ALL := $(OUT_DIR)/read_create_print.o $(OUT_DIR)/sort.o $(OUT_DIR)/key.o
OBJECTS_MAIN := $(SRC_DIR)/main.c
OBJECTS_UNIT := $(OUT_DIR)/check_main.o $(OUT_DIR)/check_filter.o $(OUT_DIR)/check_sort.o $(OUT_DIR)/check_read.o
OBJECTS_DYN_UNIT := $(OUT_DIR)/dynamic_check_main.o $(OUT_DIR)/dynamic_check_filter.o $(OUT_DIR)/dynamic_check_sort.o $(OUT_DIR)/dynamic_check_read.o

dynamic_load: $(OBJECTS_DYN_LOAD) $(DYNAMIC_LIB)
	$(CC) $(CFLAGS) $^ -o $(NAME_EXE)

dynamic_link: $(OBJECTS_DYN_MAIN) $(DYNAMIC_LIB)
	$(CC) $(CFLAGS) $< -L. $(DYNAMIC_LIB) -o $(NAME_EXE)

static: $(OBJECTS_MAIN) $(STATIC_LIB)
	$(CC) $(CFLAGS) $^ -o $(NAME_EXE)

static_unit_tests: $(OBJECTS_UNIT) $(OBJECTS_ALL)
	$(CC) -o $(NAME_UNIT_EXE) $^ $(U_CFLAGS)

dynamic_unit_tests: $(OBJECTS_DYN_UNIT)
	$(CC) $^ -L. $(DYNAMIC_LIB) -o $(NAME_UNIT_EXE) $(U_CFLAGS)

$(DYNAMIC_LIB): $(OBJECTS_DYN_ALL)
	$(CC) -shared $^ -Wl,--subsystem,windows -o $@

$(OUT_DIR)/dynamic_%.o: ${SRC_DIR}/dynamic_%.c ${INC_DIR}/dynamic_*.h object_dir
	$(CC) $(CFLAGS) -D $(NAME_EXPLORE) -c $< -o $@
    
$(OUT_DIR)/dynamic_check_%.o: ${UTESTS_DIR}/check_%.c ${INC_DIR}/check_*.h object_dir
	$(CC) $(CFLAGS) -D DYNAMIC_UNIT -c $< -o $@
    
$(OUT_DIR)/check_%.o: ${UTESTS_DIR}/check_%.c ${INC_DIR}/check_*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

$(STATIC_LIB): $(OBJECTS_ALL)
	ar rc $@ $^
	ranlib $@

$(OUT_DIR)/%.o: ${SRC_DIR}/%.c ${INC_DIR}/*.h object_dir
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
	$(RM) *.a *.dll
	rm -rf $(OUT_DIR)


