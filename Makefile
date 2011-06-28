CXXFLAGS = -std=c++0x
LDFLAGS = -lgmpxx -lgmp

SRC = $(wildcard src/*.cpp)
PROB = $(patsubst %.cpp,%,$(notdir $(SRC)))

.PHONY: all

all: $(PROB)

%: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(PROB)
