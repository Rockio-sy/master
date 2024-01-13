CC = gcc
SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

FTESTS_DIR := ./func_tests
UTESTS_DIR := ./unit_tests

CFLAGS =-std=c99 -Wall -Werror -Wpedantic -ggdb -I$(INC_DIR)
LFLAGS =--coverage
.PHONY : clean dir release debug func
.NOTPARALLEL: release debug

release: CFLAGS+= -o2
release: $(OUT_DIR)/release.lastbuildstate app.exe

debug: CFLAGS+= --coverage
debug: LFLAGS+= -g3
debug: $(OUT_DIR)/debug.lastbuildstate app.exe

func: CFLAGS+= --coverage
func: LFLAGS+= -g3

OBJECTS_ALL := $(OUT_DIR)/memory.o $(OUT_DIR)/check_prime.o $(OUT_DIR)/read_action_and_num.o $(OUT_DIR)/math_operation_list.o $(OUT_DIR)/print_list.o $(OUT_DIR)/action_processor.o
OBJECTS_MAIN := $(OUT_DIR)/main.o
OBJECTS_UNIT := $(OUT_DIR)/check_main.o $(OUT_DIR)/check_memory.o $(OUT_DIR)/check_math_operations.o

%.exe: $(OBJECTS_MAIN) $(OBJECTS_ALL)
	$(CC) $(LFLAGS) -ggdb -o $@ $^

unit_tests.exe: $(OBJECTS_UNIT) $(OBJECTS_ALL)
	$(CC) -o $@ $^

$(OUT_DIR)/check_%.o: $(UTESTS_DIR)/check_%.c | dir
	$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | dir
	$(CC) $(CFLAGS) -c $^ -o $@

$(OUT_DIR)/release.lastbuildstate: | dir
	rm -rf *.exe $(OUT_DIR)/*.o $(OUT_DIR)/debug.lastbuildstate
	touch $(OUT_DIR)/release.lastbuildstate

$(OUT_DIR)/debug.lastbuildstate: | dir
	rm -rf *.exe $(OUT_DIR)/*.o $(OUT_DIR)/release.lastbuildstate
	touch $(OUT_DIR)/debug.lastbuildstate

dir:
	mkdir -p $(OUT_DIR)/

func:
	cd $(FTESTS_DIR) && bash all_tests.sh

clean :
	rm -fv *.exe
	rm -fv $(OUT_DIR)/*.o
	rm -fv $(OUT_DIR)/*.gcno
	rm -fv $(OUT_DIR)/*.gcda
	rm -rf $(OUT_DIR)/*.lastbuildstate
	rm -rf $(OUT_DIR)