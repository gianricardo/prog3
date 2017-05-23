	
INCLUDE_DIRS := . src src/p3
CXX := g++
CXXFLAGS := -Wall -std=c++14
DBG := gdb
DBGFLAGS := -g
MEMCHECK := valgrind
MEMCHECKPARAMS := 
MEMCHECKFLAGS := -v
TARGET := main

DEPS := $(shell find . -type f -name '*.h')
CODE := $(addsuffix .o, $(basename $(shell find . -type f -name '*.cpp')))

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





