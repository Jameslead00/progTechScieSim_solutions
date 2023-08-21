#Makefile

CXX = g++
CXXFLAGS = -std=c++11 -O3 -DNDEBUG
CXXFLAGS += -Wall -Wextra -Wpedantic -fno-tree-vectorize -march=native

.PHONY: all
all: result/plot_a.pdf

result/plot_a.pdf: plot.py result/out.dat result
	python3 plot.py result/out.dat

result/out.dat: cache result
	./cache | tee result/out.dat

result:
	mkdir result

cache: cache.cpp

.PHONY: clean
clean:
	rm -rf result
	rm -f cache
