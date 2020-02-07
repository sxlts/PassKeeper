SOURCE_DIR=src
BUILD_DIR=build
OPT_DIR=opt
TEST_DIR=test
OUTPUT=passkeeper

SOURCES=$(notdir $(basename $(wildcard $(SOURCE_DIR)/*.c)))
OBJECTS=$(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(SOURCES)))

SODIUM_OPTIONS=-L/usr/local/lib/libsodium.so -lsodium
CHAINSAW=$(OPT_DIR)/chainsaw
TESTFUNC=$(SOURCE_DIR)/generate.c $(SOURCE_DIR)/generate.h $(SOURCE_DIR)/store.c $(SOURCE_DIR)/store.h


$(BUILD_DIR)/$(OUTPUT): $(OBJECTS)
	gcc $^ -o $@ $(SODIUM_OPTIONS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(SOURCE_DIR)/%.h | $(BUILD_DIR)
	gcc -c $< -o $@ $(SODIUM_OPTIONS)

$(BUILD_DIR)/%.test: $(TEST_DIR)/%.test.c $(TESTFUNC) | $(CHAINSAW) $(BUILD_DIR)
	gcc $^ $(CHAINSAW)/src/unittest/*.c -I$(OPT_DIR)/chainsaw/include -I$(SOURCE_DIR) -o $@ $(SODIUM_OPTIONS)
	./build/check.test
	rm ./test.bin

$(CHAINSAW): $(OPT_DIR)
	git clone git@github.com:soleni/chainsaw.git $(CHAINSAW)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(OPT_DIR):
	mkdir $(OPT_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
