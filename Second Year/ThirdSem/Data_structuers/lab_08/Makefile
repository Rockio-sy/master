СС := gcc
CFLAGS := -std=c99 -Wall -Werror -Wextra -Wpedantic -I./inc
GCOVFLAGS := -O0 --coverage 
UTFLAGS := -lcheck

# Получение переменных с файлами

FUNC_DIR := func_tests

SRC_DIR := ./src
CFILES := $(wildcard $(SRC_DIR)/*.c)

INC_DIR := ./inc
INCLUDEFILES := $(wildcard $(INC_DIR)/*.h)

INCLUDE_C_FILES := $(filter-out $(INC_DIR)/check_%.h,$(INCLUDEFILES))
INCLUDE_UNIT_FILES := $(filter $(INC_DIR)/check_%.h,$(INCLUDEFILES))

UNIT_DIR := ./unit_tests
UNITFILES := $(wildcard $(UNIT_DIR)/*.c)

OUT_DIR := ./out
OBJFILES := $(CFILES:$(SRC_DIR)/%.c=$(OUT_DIR)/%.o)

UNIT_OBJ := $(UNITFILES:$(UNIT_DIR)/%.c=$(OUT_DIR)/%.o)
UNIT_OBJ += $(filter-out $(OUT_DIR)/main.o,$(OBJFILES))

# Функции
app.exe : $(OUT_DIR) $(OBJFILES)
	$(CC) -ggdb $(OBJFILES) -o $@

$(OUT_DIR):
	@mkdir -p $@

$(OUT_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDE_C_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

unit_tests.exe: $(OUT_DIR) $(UNIT_OBJ)
	$(CC) $(UNIT_OBJ) -o $@ $(UTFLAGS)

$(OUT_DIR)/%.o: $(UNIT_DIR)/%.c $(INCLUDE_UNIT_FILES) $(INCLUDE_C_FILES)
	$(CC) $(CFLAGS) $(UTFLAGS) -c $< -o $@

func_tests.exe: $(OUT_DIR) $(OBJFILES)
	$(CC) $(GCOVFLAGS) $(OBJFILES) -o $@

.PHONY : clean func unit flag

coverage: CFLAGS += $(GCOVFLAGS)
coverage: func_tests.exe

func: coverage func_tests.exe 
	cd $(FUNC_DIR) && ./all_test.sh
	gcov -f -r $(OUT_DIR)/*.gcno
	mv *.gcov $(OUT_DIR)

unit: unit_tests.exe
	./$^

clean:
	$(RM) *.o *.exe -rf $(OUT_DIR)
