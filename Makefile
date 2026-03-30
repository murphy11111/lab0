# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -fPIC
LDFLAGS = -shared

# Директории
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
LIB_DIR = lib

# Целевая библиотека
LIB_NAME = libsequence.so
TARGET_LIB = $(LIB_DIR)/$(LIB_NAME)

# Исходные файлы (только те, где есть явное инстанцирование)
SOURCES = $(SRC_DIR)/ArraySequence.cpp $(SRC_DIR)/ListSequence.cpp

# Объектные файлы
OBJECTS = $(BUILD_DIR)/ArraySequence.o $(BUILD_DIR)/ListSequence.o

# Флаги для поиска заголовочных файлов
INCLUDES = -I$(INCLUDE_DIR)

# Основная цель
all: $(TARGET_LIB)

# Создание директорий
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

# Создание динамической библиотеки
$(TARGET_LIB): $(LIB_DIR) $(BUILD_DIR) $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)
	@echo "Динамическая библиотека $(LIB_NAME) создана в $(LIB_DIR)"

# Компиляция ArraySequence.cpp
$(BUILD_DIR)/ArraySequence.o: $(SRC_DIR)/ArraySequence.cpp $(INCLUDE_DIR)/ArraySequence.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Компиляция ListSequence.cpp
$(BUILD_DIR)/ListSequence.o: $(SRC_DIR)/ListSequence.cpp $(INCLUDE_DIR)/ListSequence.h
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)

# Очистка и пересборка
rebuild: clean all

# Тестирование (если нужно скомпилировать main.cpp с библиотекой)
test: $(TARGET_LIB)
	$(CXX) -std=c++17 -I$(INCLUDE_DIR) -L$(LIB_DIR) -Wl,-rpath,$(LIB_DIR) main.cpp -o mylab0 -lsequence
	@echo "Тестовое приложение создано. Запустите ./mylab0"

.PHONY: all clean rebuild test
