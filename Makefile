ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif
ifeq ($(detected_OS),Darwin)
	CXX = /opt/homebrew/bin/g++-14
	LIB_PATH = /opt/homebrew/lib
endif
ifeq ($(detected_OS),Linux)
	CXX = /usr/bin/g++-14
	LIB_PATH = /usr/lib
        # CXX = /usr/bin/g++
endif

CXX_FLAGS := -D DEBUG -std=c++23

PROJ_DIR := $(CURDIR)
BUILD_DIR := $(PROJ_DIR)/build

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: nstd.cpp main.cpp
	${CXX} -std=c++23 -fmodules-ts -o $@ $^ -L${LIB_PATH}

clean:
	rm -rf $(BUILD_DIR)/*
	rm -rf gcm.cache