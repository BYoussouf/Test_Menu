CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -std=c++17 -g 

MENU = MENU

$(MENU): main.o home.o 
	$(CXX) $(CXXFLAGS) main.o home.o  -o $(MENU)

main.o: main.cpp home.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

home.o: home.cpp home.hpp
	$(CXX) $(CXXFLAGS) -c home.cpp

clean:
	rm -f *.o $(MENU)