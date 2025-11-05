TARGET = 1
SOURCES = main.cpp class.cpp
GXX = g++

$(TARGET): $(SOURCES)
	$(GXX) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)