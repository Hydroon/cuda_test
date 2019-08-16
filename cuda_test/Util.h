#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#define _CUDA_LAUNCH_SUCCESS 0
#define _CUDA_LAUNCH_FAILURE -1

#define GCAMP_CHANNEL       0x01
#define RFP_CHANNEL         0x02
#define IMAGING_CHANNEL_LEN 0x09

typedef unsigned char uchar;
typedef unsigned short ushort;

enum DeviceStatus { OPENED, CONNECTED, DISCONNECTED };
enum SerialStatus { SERIAL_OPENED, SERIAL_CLOSED };
enum DATATYPE { UCHAR_TYPE, USHORT_TYPE };
enum DisplayWindowFlag { HAMAMATSU_WINDOW, IO_WINDOW, FLIR_WINDOW };
enum DisplayWindowOrientation { NORMAL, FLIP_UP_DOWN, FLIP_LEFT_RIGHT, FLIP_BOTH, ROT_90, ROT_180, ROT_270 };
enum PixelEncodingType { Mono8, Mono10, Mono12, Mono12Packed, Mono16, InvalidType };
enum DataRightShift { BIT_0, BIT_1, BIT_2, BIT_3, BIT_4£¬BIT_5, BIT_6, BIT_7, BIT_8 };

//display window information
struct WindowInfo
{
	int isLive;
	int imageWidth;
	int imageHeight;
	int imageStride;
	void* imageData;
	DATATYPE imageDataType;
	PixelEncodingType image_pixelEncoding;
	DataRightShift dataRightShift;
	DisplayWindowFlag windowFlag;
	DisplayWindowOrientation windowOrientation;
};

struct ImageBuffer
{
	long long timestamp;
	int imageWidth;
	int imageHeight;
	void* imageData;
	DATATYPE imageDataType;
};

struct ImageSize
{
	int width;
	int height;
	int stride;
};

struct ImageRegion
{
	int x_offset;
	int y_offset;
	int width;
	int height;
};

struct Range
{
	double max;
	double min;
	double current;
};

struct PositionStatus
{
	DisplayWindowFlag windowFlag;
	int currentRow;
	int currentCol;
	int value;
};

inline string GetErrorString(const string object, const string source, const string description)
{
	return (object + "::" + source + ":" + description + "\n");
}

inline double Square(double value)
{
	return value * value;
}

void CopyData(DATATYPE type, uchar* data, uchar* dst, int width, int height);

#endif // !_UTIL_H_


