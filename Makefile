CC=gcc
CFLAGS=-Wall
TARGET=versions

all: $(TARGET)

$(TARGET): $(TARGET).c 
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c 

clean:
	rm -f $(TARGET)