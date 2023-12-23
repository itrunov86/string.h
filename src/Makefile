# НАстройки компилятора
CC = gcc
CFLAGS_COMMON = -Wall -Werror -Wextra -std=c11 -I.
GCOV_FLAGS = -fprofile-arcs -ftest-coverage --coverage
LIBSFLAGS = -lcheck -lsubunit -lm -lgcov
CPPFLAGS = -I. --enable=all --suppress=missingIncludeSystem --std=c11 --check-config
VALGRIND_FLAGS = --tool=memcheck --leak-check=yes
STYLE_BASE = --style=Google

# Директории
FUNCTION_DIR = functions
OBJ_DIR = OBJ
TEST_DIR = unit_tests
ADD_FUNCTION_DIR = add_files

# Исходные файлы
FUNCTION_SRCS = $(wildcard $(FUNCTION_DIR)/*.c)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.c)
ADD_FUNCTION_SRCS = $(wildcard $(ADD_FUNCTION_DIR)/*.c)

# Объектные файлы
FUNCTION_OBJS = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%.o, $(FUNCTION_SRCS))
ADD_FUNCTION_OBJ = $(patsubst $(ADD_FUNCTION_DIR)/%.c, $(OBJ_DIR)/%.o, $(ADD_FUNCTION_SRCS))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_SRCS))
FUNCTION_OBJS_COV = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%_gcov.o, $(FUNCTION_SRCS))
ADD_FUNCTION_OBJS_COV = $(patsubst $(ADD_FUNCTION_DIR)/%.c, $(OBJ_DIR)/%_gcov.o, $(ADD_FUNCTION_SRCS))
FUNCTION_GCDA = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%.gcda, $(FUNCTION_SRCS))
#FUNCTION_GCOV_REPORT = $(patsubst $(FUNCTION_DIR)/%.c, $(OBJ_DIR)/%_gcov_report, $(FUNCTION_SRCS))
GCOV_OBJ = $(OBJ_DIR)/s21_test*.o

# Финальные библиотеки
LIB = s21_math.a
LIB_GCOV = s21_math_gcov.a

RM = rm -rf

all: $(LIB)
#Временная цель для тестирования
math:
	gcc -I. $(FUNCTION_DIR)/*c $(ADD_FUNCTION_DIR)/*.c -o math -lm
	./math
	rm math

# Создание директории объектных файлов
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

peer: clean gcov_html

# Создание статической библиотеки s21_math.a
$(LIB): $(FUNCTION_OBJS) $(ADD_FUNCTION_OBJ)
	ar rcs $@ $(FUNCTION_OBJS) $(ADD_FUNCTION_OBJ)

# Компиляция исходных файлов функций для s21_math.a
$(OBJ_DIR)/%.o: $(FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) -c $< -o $@
$(OBJ_DIR)/%.o: $(ADD_FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) -c $< -o $@

# Компиляция исходных файлов тестов
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) -c $< -o $@

# Запуск тестов с использованием библиотеки check без флагов покрытия
test: CFLAGS := $(CFLAGS_COMMON)
test: clean $(LIB) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o s21_test_math $(TEST_OBJS) -L. -l:s21_math.a $(LIBSFLAGS)
	./s21_test_math

# Открытие отчета о покрытии кода в браузере
gcov_html: gcov_report
	xdg-open coverage_report.html

# Создание отчета о покрытии кода с использованием gcovr
gcov_report: CFLAGS := $(CFLAGS_COMMON) $(CFLAGS_COVERAGE)
gcov_report: clean $(LIB_GCOV) $(FUNCTION_GCDA) $(GCOV_OBJ)
	$(CC) $(CFLAGS) -I$(FUNCTION_DIR) -o s21_test_math $(GCOV_OBJ) -L. -l:s21_math_gcov.a $(LIBSFLAGS)
	rm -rf ./OBJ/s21_test* ./OBJ/*factorial* ./OBJ/*fmodl* ./OBJ/*powl* ./OBJ/*cosl* ./OBJ/*sinl*
	rm -rf ./OBJ/*expl* ./OBJ/*fabsl* ./OBJ/*logl*
	./s21_test_math
	~/.local/bin/gcovr -r . --html-details -o coverage_report.html

# Создание статической библиотеки s21_math_gcov.a
$(LIB_GCOV): $(FUNCTION_OBJS_COV) $(ADD_FUNCTION_OBJS_COV)
	ar rcs $@ $(FUNCTION_OBJS_COV) $(ADD_FUNCTION_OBJS_COV)

# Компиляция исходных файлов функций с флагами покрытия для s21_math_gcov.a
$(OBJ_DIR)/%_gcov.o: $(FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) $(GCOV_FLAGS) -c $< -o $@
$(OBJ_DIR)/%_gcov.o: $(ADD_FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) $(GCOV_FLAGS) -c $< -o $@

# Компиляция исходных файлов функций с флагами покрытия для gcov_report
$(OBJ_DIR)/%.gcda: $(FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) $(GCOV_FLAGS) -c $< -o $@
$(OBJ_DIR)/%.gcda: $(ADD_FUNCTION_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS_COMMON) $(GCOV_FLAGS) -c $< -o $@

# Компиляция файлов тестов для цели gcov_report
$(GCOV_OBJ): $(TEST_SRCS) | $(OBJ_DIR)
	$(foreach file,$(TEST_SRCS),$(CC) $(CFLAGS_COMMON) $(GCOV_FLAGS) -c $(file) -o $(OBJ_DIR)/$(notdir $(basename $(file))).o;)

# Открытие отчета о покрытии кода в браузере
gcov_html: gcov_report
	xdg-open coverage_report.html	

check:
	clang-format $(STYLE_BASE) -n $(TEST_DIR)/*.c $(TEST_DIR)/*.h
	clang-format $(STYLE_BASE) -n $(FUNCTION_DIR)/*.c
	clang-format $(STYLE_BASE) -n $(ADD_FUNCTION_DIR)/*.c
	clang-format $(STYLE_BASE) -n *.h
fix:
	clang-format $(STYLE_BASE) -i $(TEST_DIR)/*.c $(TEST_DIR)/*.h
	clang-format $(STYLE_BASE) -i $(FUNCTION_DIR)/*.c
	clang-format $(STYLE_BASE) -i $(ADD_FUNCTION_DIR)/*.c
	clang-format $(STYLE_BASE) -i *.h
cpp:
	cppcheck ${CPPFLAGS} .

valgrind: test
	valgrind --tool=memcheck --leak-check=yes --log-file="l.log" ./s21_test_math


clean:
	${RM} $(OBJ_DIR)/*.o
	${RM} $(LIB)
	${RM} s21_test_math
	${RM} $(OBJ_DIR)/*.gcda
	${RM} $(OBJ_DIR)/*.gcno
	${RM} *.html
	${RM} $(LIB_GCOV)
	${RM} *.css
	${RM} *.log
	
