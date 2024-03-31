G++ = g++
G++_FLAGS = -c -Wall
LD_FLAGS = -L /usr/local/lib

OBJECTS = main.o libphonechecker.a
TARGET =  program

all: $(TARGET)

$(TARGET): $(OBJECTS)
	g++ -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

%.o : %.cpp
	$(G++) $(G++_FLAGS) $<

libphonechecker.a: calculator.o reader.o
	ar rcs libphonechecker.a calculator.o reader.o

clean:
	rm -f $(TARGET) $(OBJECTS) calculator.o reader.o

.PHONY: all clean