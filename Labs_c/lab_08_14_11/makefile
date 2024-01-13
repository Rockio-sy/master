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
release: $(OUTPATH)/release.lastbuildstate app.exe

debug: CFLAGS+= --coverage
debug: LFLAGS+= -g3
debug: $(OUTPATH)/debug.lastbuildstate app.exe

func: CFLAGS+= --coverage
func: LFLAGS+= -g3

OBJECTS_READ := $(OUT_DIR)/memory_matrix.o $(OUT_DIR)/checks.o $(OUT_DIR)/read_matrix.o $(OUT_DIR)/fprint_matrix.o
OBJECTS_OPERATIONS := $(OUT_DIR)/find_inverse_matrix.o $(OUT_DIR)/sum_matrix.o $(OUT_DIR)/multiplication_matrix.o $(OUT_DIR)/swap.o $(OUT_DIR)/copy_matrix.o
OBJECTS_MAIN := $(OUT_DIR)/main.o
OBJECTS_UNIT := $(OUT_DIR)/check_main.o $(OUT_DIR)/check_read.o $(OUT_DIR)/check_memory.o $(OUT_DIR)/check_swap.o $(OUT_DIR)/check_math_operations.o 

%.exe: $(OBJECTS_MAIN) $(OBJECTS_READ) $(OBJECTS_OPERATIONS)
	$(CC) $(LFLAGS) -ggdb -o $@ $^

unit_tests.exe: $(OBJECTS_READ) $(OBJECTS_OPERATIONS) $(OBJECTS_UNIT)
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