SOURCE_DIR=src
BUILD_DIR=build
OUTPUT=passkeeper

SODIUM_OPTIONS=-L/usr/local/lib/libsodium.so -lsodium


$(BUILD_DIR)/$(OUTPUT): $(BUILD_DIR)/main.o $(BUILD_DIR)/generate.o $(BUILD_DIR)/store.o
	gcc $^ -o $@ $(SODIUM_OPTIONS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.c $(SOURCE_DIR)/%.h | $(BUILD_DIR)
	gcc -c $< -o $@ $(SODIUM_OPTIONS)

$(BUILD_DIR):
	mkdir build

clean:
	rm -rf $(BUILD_DIR)
