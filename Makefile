OUTPUT = libspklog.a

BUILD_DIR = build

DEP_DIR = depend

SRC_DIR = src
SUB_DIR = ui

SOURCE = $(wildcard $(SRC_DIR)/*.cpp $(foreach sd, $(SUB_DIR), $(SRC_DIR)/$(sd)/*.cpp))

DEPEND = $(patsubst $(SRC_DIR)/%.cpp, $(DEP_DIR)/%.d, $(SOURCE))

OBJECT = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCE))

TEST = test_prog

COMPILE_FLAG = -std=c++20 -Wextra
INCLUDE_FLAG = -Iinclude
DEPEND_FLAG = -MT $@ -MMD -MP -MF 
COMPILE = g++ $(COMPILE_FLAG) $(INCLUDE_FLAG)

.PHONY: all
all: $(OUTPUT) $(TEST)

.PHONY: test
test: $(TEST)
	chmod +x tests/test.sh
	./tests/test.sh

$(TEST): tests/test.cpp $(OUTPUT)
	$(COMPILE) $< -o $@ -L. -lspklog

$(OUTPUT): $(OBJECT)
	ar r $@ $^
	ranlib $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEP_DIR)/%.d
	mkdir -p $(@D) $(patsubst $(BUILD_DIR)%, $(DEP_DIR)%, $(@D))
	$(COMPILE) $(INCLUDE_FLAG) $(DEPEND_FLAG) $(DEP_DIR)/$*.d -c $< -o $@

$(DEPEND):

include $(wildcard $(DEPEND))

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(DEP_DIR) $(OUTPUT) $(TEST)
