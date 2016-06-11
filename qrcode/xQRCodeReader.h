#ifndef _X_QRCODEREADER_H_
#define _X_QRCODEREADER_H_

#include <zxing/Reader.h>
#include <zxing/qrcode/decoder/Decoder.h>
#include <zxing/DecodeHints.h>

namespace zxing {
	namespace qrcode {

		class xQRCodeReader : public Reader {
		private:
			Decoder decoder_;

		protected:
			Decoder& getDecoder();

		public:
			xQRCodeReader();
			Ref<BitMatrix> bits_;

			virtual ~xQRCodeReader();

			Ref<Result> decode(Ref<BinaryBitmap> image, DecodeHints hints);
		};

	}
}

#endif