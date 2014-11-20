jpeg_encoder
============

压缩bmp图像至jpg文件中。
这个工程是为我的博客中的一个系列文章准备的。
http://thecodeway.com/blog/?p=69
目的是为了解释jpeg压缩算法的过程，所以没有考虑优化，只可用来学习，不建议用在实际项目中。

使用方法

	#include "jpeg_encoder.h"
	
	JpegEncoder encoder;
	//输入的文件必须是24bit的bmp文件，尺寸必须是8的倍数
	encoder.readFromBMP(inputFileName);
	
	//第二个参数在1~199之间，代表文件压缩程度，数字越大，压缩后的文件体积越小
	encoder.encodeToJPG(outputFileName, 50);
	
