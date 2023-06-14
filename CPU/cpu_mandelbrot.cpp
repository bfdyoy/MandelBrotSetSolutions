#include "cpu_mandelbrot.h"

using namespace std;

CPU_Mandelbrot::CPU_Mandelbrot(float width, float height): _imageWidth(width), _imageHeight(height)
{ }

int CPU_Mandelbrot::ComputePixelValue(int x, int y)
{
	// divide the point by the image dimension so 0 < {x,y} < 1 and apply a translation
	complex<float> point((float)x / _imageWidth - 1.5, (float)y / _imageHeight - 0.5);

	complex<float> z(0, 0);
	unsigned int number_iterations = 0;

	while ((abs(z) < 2))
	{
		z = z * z + point;
		number_iterations++;
	}

	if (number_iterations < 256)
		return (255 * number_iterations) / 256;
	return 255;
}

void CPU_Mandelbrot::ImageToFile(const string& img_name)
{
	ofstream image(img_name);
	if (image.is_open())
	{ 
		image << "P3\n" << _imageWidth << " " << _imageHeight << " 255\n";
		for (int row = 0; row < (int)_imageWidth; row++)
		{
			for (int col = 0; col < (int)_imageHeight; col++)
			{
				int current_value = ComputePixelValue(row, col);
				image << 0 << " " << current_value << " " << current_value << "\n";
			}
		}
		image.close();
	}
	else
	{
		cout << "Can not open the file !\n";
		exit(1);
	}
}