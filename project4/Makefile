CXX       := g++
CXX_FLAGS := -std=c++17 -ggdb

BIN     := bin
SRC     := src
INCLUDE := include

LIBRARIES   :=
EXECUTABLE  := main.exe


all: $(BIN)/$(EXECUTABLE)

run:	clean all
	clear
	./$(BIN)/$(EXECUTABLE).exe

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp main.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*