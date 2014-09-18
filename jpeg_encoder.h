#ifndef __JPEG_ENCODER_HEADER__
#define __JPEG_ENCODER_HEADER__


class JpegEncoder
{
public:
	/** 清理数据 */
	void clean(void);

	/** 从BMP文件中读取文件，仅支持24bit，长度是8的倍数的文件 */
	bool readFromBMP(const char* fileName);

	/** 压缩到jpg文件中，quality_scale表示质量，取值范围(0,100), 数字越大压缩比例越高*/
	bool encodeToJPG(const char* fileName, int quality_scale);

private:
	int				m_width;
	int				m_height;
	unsigned char*	m_rgbBuffer;
	
	unsigned char	m_YTable[64];
	unsigned char	m_CbCrTable[64];

	struct BitString
	{
		int length;	
		int value;
	};

	BitString m_Y_DC_Huffman_Table[12];
	BitString m_Y_AC_Huffman_Table[256];

	BitString m_CbCr_DC_Huffman_Table[12];
	BitString m_CbCr_AC_Huffman_Table[256];

private:
	void _initHuffmanTables(void);
	void _initCategoryAndBitcode(void);
	void _initQualityTables(int quality);
	void _computeHuffmanTable(const char* nr_codes, const unsigned char* std_table, BitString* huffman_table);
	BitString _getBitCode(int value);

	void _convertColorSpace(int xPos, int yPos, char* yData, char* cbData, char* crData);
	void _foword_FDC(const char* channel_data, short* fdc_data);
	void _doHuffmanEncoding(const short* DU, short& prevDC, const BitString* HTDC, const BitString* HTAC, 
		BitString* outputBitString, int& bitStringCounts);

private:
	void _write_jpeg_header(FILE* fp);
	void _write_byte_(unsigned char value, FILE* fp);
	void _write_word_(unsigned short value, FILE* fp);
	void _write_bitstring_(const BitString* bs, int counts, int& newByte, int& newBytePos, FILE* fp);
	void _write_(const void* p, int byteSize, FILE* fp);

public:
	JpegEncoder();
	~JpegEncoder();
};

#endif
