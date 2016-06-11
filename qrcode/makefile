CXX=g++ -std=gnu++14


OBJ_DIR=./objs

TARGET=qrcode
OBJECTS= $(OBJ_DIR)/OpenCVLuminanceSource.o $(OBJ_DIR)/xQRCodeReader.o $(OBJ_DIR)/xGlobalHistogramBinarizer.o $(OBJ_DIR)/utility.o $(OBJ_DIR)/QRCodeDecoder.o
SOURCE = qr.cpp

CFLAGS=-I ./include -L./lib -lzxing -o
OPENCV = `pkg-config --cflags --libs opencv`

$(TARGET):chkobjdir $(SOURCE) $(OBJECTS)
	$(CXX) $(SOURCE) $(OBJECTS) $(CFLAGS) $(TARGET) $(OPENCV)

$(OBJ_DIR)/OpenCVLuminanceSource.o:OpenCVLuminanceSource.h
	$(CXX) -c -o  $(OBJ_DIR)/OpenCVLuminanceSource.o OpenCVLuminanceSource.cpp
$(OBJ_DIR)/xGlobalHistogramBinarizer.o:xGlobalHistogramBinarizer.h
	$(CXX) -c -o  $(OBJ_DIR)/xGlobalHistogramBinarizer.o xGlobalHistogramBinarizer.cpp
$(OBJ_DIR)/xQRCodeReader.o:xQRCodeReader.h
	$(CXX) -c -o  $(OBJ_DIR)/xQRCodeReader.o xQRCodeReader.cpp
$(OBJ_DIR)/utility.o:utility.h
	$(CXX) -c -o  $(OBJ_DIR)/utility.o utility.cpp
$(OBJ_DIR)/zxingdecoder.o:QRCodeDecoder.h OpenCVLuminanceSource.h
	$(CXX) -c -o  $(OBJ_DIR)/QRCodeDecoder.o QRCodeDecoder.cpp	

chkobjdir:
	@if test ! -d $(OBJ_DIR);\
	then \
		mkdir $(OBJ_DIR);\
	fi
	


.PHONY:clean
clean:
	rm -f -r $(TARGET) $(BIN_DIR) $(OBJ_DIR)
