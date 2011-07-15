CXXFLAGS = -std=c++0x
LDFLAGS = -lgmpxx -lgmp

SRC = $(wildcard src/*.cpp)
PROB = $(patsubst %.cpp,%,$(notdir $(SRC)))
PROFILED = 

.PHONY: cube tetrahedron all

cube: $(wordlist 51,$(words $(PROB)),$(PROB))

tetrahedron: $(wordlist 1,50,$(PROB))

all: $(PROB)

$(PROFILED): CXXFLAGS += -pg

%: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(PROB)
