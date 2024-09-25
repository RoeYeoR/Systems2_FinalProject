# all: compile link

# compile:
# 	g++ -c main.cpp -I"C:\Users\Roi\Documents\Libraries\SFML-2.6.1\include" -DSFML_STATIC

# link:
# 	g++ main.o -o main -L"C:\Users\Roi\Documents\Libraries\SFML-2.6.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows

all: monopol
# Compiler
CXX = g++
CXXFLAGS = -std=c++14 -Wall -g  # Use C++14, enable all warnings, and debug info

# Target executable name
TARGET = monopol

# Source files
SRC = \
    Board.cpp \
    Chance.cpp \
    CommunityChest.cpp \
    EdgeSquare.cpp \
    ElectricCompany.cpp \
    Monopol.cpp \
    MonopolManager.cpp \
    Player.cpp \
    Point2D.cpp \
    Street.cpp \
    Tax.cpp \
    Train.cpp \
    WaterCompany.cpp

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Header files
HEADERS = \
    Board.hpp \
    Chance.hpp \
    ColorEnum.hpp \
    CommunityChest.hpp \
    EdgeSquare.hpp \
    ElectricCompany.hpp \
    MonopolManager.hpp \
    Player.hpp \
    Point2D.hpp \
    Square.hpp \
    Street.hpp \
    Tax.hpp \
    Train.hpp \
    WaterCompany.hpp

# Default rule to build the target
monopol: $(OBJ)
	$(CXX) $(CXXFLAGS) -o monopol $(OBJ)

# Rule to compile .cpp files to .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(OBJ) monopol
