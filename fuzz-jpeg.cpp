#include <stdio.h>
#include "jpeg_encoder.h"

//-------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("Usage: %s inputFile\n\tInput file must be 24bit bitmap file.\n", argv[0]);
		return 1;
	}

	const char* inputFileName = argv[1];

	JpegEncoder encoder;
	if(!encoder.readFromBMP(inputFileName))
	{
		return 1;
	}

	if(!encoder.encodeToJPG("out.jpg", 50))
	{
		return 1;
	}
	return 0;
}
