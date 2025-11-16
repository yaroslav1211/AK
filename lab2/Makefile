CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17
OBJ = calculator.o
LIB = libcalc.a
TARGET = main

all: $(LIB) $(TARGET)

$(LIB): $(OBJ)
	ar rcs $@ $^

calculator.o: calculator.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
	
$(TARGET): main.cpp $(LIB)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o $(LIB) $(TARGET)
