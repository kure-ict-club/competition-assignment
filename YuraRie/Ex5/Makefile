

PROGRAM_NAME := $(shell basename `pwd`)
CMD := g++
CMD_OPTION := -O2 -lm
RM := rm

OUT_DIR := out
O_DIR := o

TARGET := Ex5

.PHONY: all

all: $(OUT_DIR)/$(TARGET).out

start: $(OUT_DIR)/$(TARGET).out
	$(OUT_DIR)/$(TARGET).out

$(OUT_DIR)/%.out: $(O_DIR)/%.o
	mkdir -p $(OUT_DIR)
	$(CMD) -o $@ $< $(CMD_OPTION)

$(O_DIR)/%.o: %.cpp
	mkdir -p $(O_DIR)
	$(CMD) -o $@ -c $< $(CMD_OPTION)





.PHONY : clean
clean:
	$(RM) -r $(OUT_DIR)
	$(RM) -r $(O_DIR)




