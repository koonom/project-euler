CXXFLAGS = -std=c++0x
LDFLAGS = -lgmpxx -lgmp

SRC = $(wildcard src/*.cpp)
PROB = $(patsubst %.cpp,%,$(notdir $(SRC)))
PROFILED = 

.PHONY: dodecahedron octahedron cube tetrahedron all

dodecahedron: $(wordlist 151,$(words $(PROB)),$(PROB))
octahedron: $(wordlist 101,150,$(PROB))
cube: $(wordlist 51,100,$(PROB))
tetrahedron: $(wordlist 1,50,$(PROB))

all: $(PROB)

$(PROFILED): CXXFLAGS += -pg

%: src/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(PROB)
