CXX = g++
CXXFLAGS = -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = canvas.cpp shapepp.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = main

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS) main.cpp
	$(CXX) main.cpp $(OBJS) -o $(TARGET) $(LDFLAGS)

canvas.o: canvas.cpp canvas.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

shapepp.o: shapepp.cpp shapepp.h ellipseshape.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
