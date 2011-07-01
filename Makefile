CXXFLAGS = -std=c++0x
LDFLAGS = -lgmpxx -lgmp

SRC = $(wildcard src/*.cpp)
PROB = $(patsubst %.cpp,%,$(notdir $(SRC)))
PROFILED = 

.PHONY: all

all: $(PROB)

$(PROFILED): CXXFLAGS += -pg

%: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(PROB)
