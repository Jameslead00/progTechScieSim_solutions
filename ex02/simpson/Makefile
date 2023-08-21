#define tools and variables
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall -Wextra -Wpedantic
CXXFLAGS += -O3
LDFLAGS = -Lintegrator
LDLIBS = -lintegrate

export

#compile the code and generate exe with lib
print_integrals: main.cpp integrator/libintegrate.a
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS) $(LDLIBS)

integrator/libintegrate.a:
	$(MAKE) -C integrator

#clean up
.PHONY: clean
clean: 
	rm -f print_integrals
	rm -f *.o *.a
	rm -rf data
	$(MAKE) -C integrator clean