PROGS := arrays dynamic_arr ranges test_myvect
CXX = g++
CXXFLAGS = -std=c++20 -Wall -O2

all: $(PROGS)

% : %.o
	$(CXX) $(CXXFLAGS)  $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

test_myvect: test_myvect.o myvect.o
	$(CXX) $(CXXFLAGS) $^ -o $@

myvect.o: myvect.cc myvect.hh
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm $(PROGS)