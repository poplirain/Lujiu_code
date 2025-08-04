CC = gcc
SRC_FILES = $(wildcard *.c)       # 获取所有.c文件
OBJ_FILES = $(patsubst %.c,%.o,$(SRC_FILES))  # 修正：使用 % 通配符
TARGET = humanmatch

$(TARGET): $(OBJ_FILES)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o $(TARGET)




