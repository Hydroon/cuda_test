#include "Util.h"
#include <cuda_runtime.h>

extern "C" int pixelConvert8(uchar3* output_data, uchar* original_data, int width, int height);
extern "C" int pixelConvert16(uchar3* dev_output_data, ushort* dev_original_data, int width, int heightS, int rightShiftBits);

int main(int argc, char* argv[])
{
	return 0;
}