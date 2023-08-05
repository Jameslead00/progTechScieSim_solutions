#create a library from the object code
libintegrate.a: simpson.o
	ar crs $@ $^

#object code depending on header and implementation
simpson.o: simpson.cpp simpson.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#clean up
.PHONY: clean
clean:
	rm -f *.o *.a