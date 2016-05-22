CXX=g++ -std=gnu++14


OBJ_DIR=./objs

TARGET=qrcode
OBJECTS= $(OBJ_DIR)/OpenCVLuminanceSource.o $(OBJ_DIR)/zxingdecoder.o 
SOURCE = qr.cpp

CFLAGS=-I ./include -L./lib -lzxing -o
OPENCV = `pkg-config --cflags --libs opencv`

$(TARGET):chkobjdir $(SOURCE) $(OBJECTS)
	$(CXX) $(SOURCE) $(OBJECTS) $(CFLAGS) $(TARGET) $(OPENCV)

$(OBJ_DIR)/OpenCVLuminanceSource.o:OpenCVLuminanceSource.h
	$(CXX) -c -o  $(OBJ_DIR)/OpenCVLuminanceSource.o OpenCVLuminanceSource.cpp
$(OBJ_DIR)/zxingdecoder.o:zxingdecoder.h OpenCVLuminanceSource.h
	$(CXX) -c -o  $(OBJ_DIR)/zxingdecoder.o zxingdecoder.cpp	

chkobjdir:
	@if test ! -d $(OBJ_DIR);\
	then \
		mkdir $(OBJ_DIR);\
	fi
	


.PHONY:clean
clean:
	rm -f -r $(TARGET) $(BIN_DIR) $(OBJ_DIR)
