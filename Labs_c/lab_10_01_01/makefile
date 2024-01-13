CC = gcc
SRC_DIR := ./src
INC_DIR := ./inc
OUT_DIR := ./out

FTESTS_DIR := ./func_tests
UTESTS_DIR := ./unit_tests

CFLAGS =-std=c99 -Wall -Werror -Wpedantic -ggdb -I$(INC_DIR)
LFLAGS =--coverage

func: CFLAGS+= --coverage
func: LFLAGS+= -g3

task_o := $(OUT_DIR)/memory_countries.o $(OUT_DIR)/read_countries.o $(OUT_DIR)/print_countries.o $(OUT_DIR)/checks.o $(OUT_DIR)/key_processor.o
list_o := $(OUT_DIR)/memory_list.o $(OUT_DIR)/operations_with_element_list.o $(OUT_DIR)/operations_with_list.o
main_o := $(OUT_DIR)/main.o
unit_o := $(OUT_DIR)/check_main.o $(OUT_DIR)/check_memory_list.o $(OUT_DIR)/check_list_operations.o
unit_t_o := $(OUT_DIR)/check_checks.o $(OUT_DIR)/check_memory_countries.o $(OUT_DIR)/check_read_countries.o

app : $(main_o) $(list_o) $(task_o)
	@$(CC) $(LFLAGS) -ggdb -o app.exe $^

unit_tests.exe: $(unit_o) $(unit_t_o) $(list_o) $(task_o)
	@$(CC) -o $@ $^

$(OUT_DIR)/check_%.o: $(UTESTS_DIR)/check_%.c | dir
	@$(CC) $(CFLAGS) -c $< -o $@

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | dir
	@$(CC) $(CFLAGS) -c $^ -o $@

$(OUT_DIR)/release.lastbuildstate: | dir
	@rm -rf *.exe $(OUT_DIR)/*.o $(OUT_DIR)/debug.lastbuildstate
	@touch $(OUT_DIR)/release.lastbuildstate

$(OUT_DIR)/debug.lastbuildstate: | dir
	@rm -rf *.exe $(OUT_DIR)/*.o $(OUT_DIR)/release.lastbuildstate
	@touch $(OUT_DIR)/debug.lastbuildstate

dir:
	@mkdir -p $(OUT_DIR)/

func:
	@cd $(FTESTS_DIR) && bash all_tests.sh

clean :
	@rm -f *.exe $(OUT_DIR)/*.o $(OUT_DIR)/*.gcno $(OUT_DIR)/*.gcda $(OUT_DIR)/*.lastbuildstate
.PHONY : clean dir release debug func

#.NOTPARALLEL: release debug
#
#release: CFLAGS+= -o2
#release: $(OUT_DIR)/release.lastbuildstate app.exe
#
#debug: CFLAGS+= --coverage
#debug: LFLAGS+= -g3
#debug: $(OUT_DIR)/debug.lastbuildstate app.exe
