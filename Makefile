SOURCE_DIR=src
BUILD_DIR=build
OUTPUT=passkeeper

SOURCES=$(notdir $(basename $(wildcard $(SOURCE_DIR)/*.c)))
OBJECTS=$(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(SOURCES)))

SODIUM_OPTIONS=-L/usr/local/lib/libsodium.so -lsodium


$(BUILD_DIR)/$(OUTPUT): $(OBJECTS)
	gcc $^ -o $@ $(SODIUM_OPTIONS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(SOURCE_DIR)/%.h | $(BUILD_DIR)
	gcc -c $< -o $@ $(SODIUM_OPTIONS)

$(BUILD_DIR):
	mkdir build

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
