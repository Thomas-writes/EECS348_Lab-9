# Compiler
CXX = g++

# Output executable
TARGET = program

# Source files
SRC = main.cpp matrix.cpp

# Default rule to compile everything in one step
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) -o $(TARGET).exe $(SRC)

# Clean up build files
clean:
	del /Q $(TARGET).exe

# Run the program
run: $(TARGET)
	$(TARGET).exe