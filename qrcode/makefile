CC=g++ -std=gnu++11

BIN_DIR=./build
OBJ_DIR=./objs

TARGET=$(BIN_DIR)/qr-test
OBJECTS= $(OBJ_DIR)/opencvbitmapsource.o $(OBJ_DIR)/zxingdecoder.o 
SOURCE = qr.cpp

CFLAGS=-I ./include -L./lib -lzxing -o
OPENCV = `pkg-config --cflags --libs opencv`

$(TARGET):chkobjdir chkbindir $(SOURCE) $(OBJECTS)
	$(CC) $(SOURCE) $(OBJECTS) $(CFLAGS) $(TARGET) $(OPENCV)

$(OBJ_DIR)/opencvbitmapsource.o:opencvbitmapsource.h
	g++ -c -o  $(OBJ_DIR)/opencvbitmapsource.o opencvbitmapsource.cpp
$(OBJ_DIR)/zxingdecoder.o:zxingdecoder.h opencvbitmapsource.h
	g++ -c -o  $(OBJ_DIR)/zxingdecoder.o zxingdecoder.cpp	

chkobjdir:
	@if test ! -d $(OBJ_DIR);\
	then \
		mkdir $(OBJ_DIR);\
	fi
	
chkbindir:
	@if test ! -d $(BIN_DIR);\
	then \
		mkdir $(BIN_DIR);\
	fi	

.PHONY:clean
clean:
	rm -f -r $(TARGET) $(BIN_DIR) $(OBJ_DIR)
