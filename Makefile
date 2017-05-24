
PROJECT := BlackJack
TARGET := main

FRAMEWORK_DIR := carteado/src/p3
INCLUDE_DIRS := . carteado/p3 carteado/src/p3
CXX := g++
CXXFLAGS := -Wall -std=c++14 -Wshadow -Wextra
DBG := gdb
DBGFLAGS := -g
MEMCHECK := valgrind
MEMCHECKPARAMS := 
MEMCHECKFLAGS := -v

DEPS := $(shell find $(FRAMEWORK_DIR) -type f -name '*.h')
DEPS += $(shell find $(PROJECT) -type f -name '*.h')
CODE := $(patsubst %.cpp, %.o, $(shell find $(FRAMEWORK_DIR) -type f -name '*.cpp'))
CODE += $(patsubst %.cpp, %.o, $(shell find $(PROJECT) -type f -name '*.cpp'))

CXXFLAGS += $(addprefix -I, $(INCLUDE_DIRS))

all: $(TARGET)

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(CODE)
	$(CXX) -o $@ $^ $(CXXFLAGS)

compile: $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: debug_flags $(TARGET)
	$(DBG) ./$(TARGET)
	
debug_flags:
	$(eval CXXFLAGS += $(DBGFLAGS))

memcheck: memcheck_flags $(TARGET)
	$(MEMCHECK) ./$(TARGET) $(MEMCHECKPARAMS)
	
memcheck_flags:
	$(eval CXXFLAGS += $(MEMCHECKFLAGS))

clean:
	find . -type f -executable -exec rm {} +
	find . -type f -name '*.o' -exec rm {} +





