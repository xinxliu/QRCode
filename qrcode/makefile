CC=g++ -std=gnu++11
TARGET=./build/qr-test
SOURCE = qr.cpp
OBJECTS= opencvbitmapsource.o zxingdecoder.o 
CFLAGS=-I ./include -L./lib -lzxing -o
OPENCV = `pkg-config --cflags --libs opencv`

all:$(SOURCE) $(OBJECTS)
	$(CC) $(SOURCE) $(OBJECTS) $(CFLAGS) $(TARGET) $(OPENCV)

opencvbitmapsource.o:opencvbitmapsource.h
zxingdecoder.o:zxingdecoder.h opencvbitmapsource.h
	g++ -c -o  zxingdecoder.o zxingdecoder.cpp	

clean:
	rm -f $(TARGET) $(OBJECTS)
