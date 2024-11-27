CXX = g++
CXXFLAGS = -Wall -std=c++11 -O2 -g
LDFLAGS = -lGL -lGLU -lGLEW -lglfw

TARGET = menger_sponge
OBJS = main.o rendering.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

main.o: main.cpp menger_sponge.h
	$(CXX) $(CXXFLAGS) -c main.cpp

rendering.o: rendering.cpp menger_sponge.h
	$(CXX) $(CXXFLAGS) -c rendering.cpp

clean:
	rm -f $(OBJS) $(TARGET)
