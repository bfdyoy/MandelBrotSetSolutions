#ifndef CPU_MANDELBROT_H
#define CPU_MANDELBROT_H

#include <iostream>
#include <fstream>
#include <complex>

class CPU_Mandelbrot
{
private:
	float _imageWidth;
	float _imageHeight;
public:

	CPU_Mandelbrot(float imageWidth, float imageHeight);
	int ComputePixelValue(int x, int y);

	void ImageToFile(const std::string& imageFileName);
};

#endif