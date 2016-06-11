#include "xQRCodeReader.h"
#include <zxing/qrcode/detector/Detector.h>

#include <iostream>

namespace zxing {
	namespace qrcode {

		using namespace std;

		xQRCodeReader::xQRCodeReader() :decoder_() {
		}
		//TODO: see if any of the other files in the qrcode tree need tryHarder
		Ref<Result> xQRCodeReader::decode(Ref<BinaryBitmap> image, DecodeHints hints) {
			Detector detector(image->getBlackMatrix());
			Ref<DetectorResult> detectorResult(detector.detect(hints));
			ArrayRef< Ref<ResultPoint> > points(detectorResult->getPoints());
			//»ñÈ¡bits_
			bits_ = detectorResult->getBits();
			Ref<DecoderResult> decoderResult(decoder_.decode(bits_));
			Ref<Result> result(
				new Result(decoderResult->getText(), decoderResult->getRawBytes(), points, BarcodeFormat::QR_CODE));
			return result;
		}

		xQRCodeReader::~xQRCodeReader() {
		}

		Decoder& xQRCodeReader::getDecoder() {
			return decoder_;
		}
	}
}
