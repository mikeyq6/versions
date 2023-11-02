CC=gcc
CFLAGS=-Wall
TARGET=versions
OTHERS=argparse.c

all: $(TARGET)

$(TARGET): $(TARGET).c 
	$(CC) $(CFLAGS) -o $(TARGET) $(OTHERS) $(TARGET).c

clean:
	rm -f $(TARGET)
