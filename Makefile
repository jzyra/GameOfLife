CXX=g++
CXXFLAGS=-W -Wall
LDFLAGS=`sdl-config --cflags --libs` -ljson
EXEC=gameoflife

all: $(EXEC)

gameoflife: Config.o GameOfLife.o Window.o
	$(CXX) -o gameoflife Config.o GameOfLife.o Window.o main.cpp $(CXXFLAGS) $(LDFLAGS)

Config.o: Config.cpp
	$(CXX) -o Config.o -c Config.cpp $(CXXFLAGS) $(LDFLAGS)

GameOfLife.o: GameOfLife.cpp
	$(CXX) -o GameOfLife.o -c GameOfLife.cpp $(CXXFLAGS) $(LDFLAGS)

Window.o: Window.cpp
	$(CXX) -o Window.o -c Window.cpp $(CXXFLAGS) $(LDFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
