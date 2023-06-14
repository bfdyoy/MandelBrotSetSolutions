#include "cpu_mandelbrot.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	// (0) sequential application .
	auto start = high_resolution_clock::now();
	
	CPU_Mandelbrot cpu_set(240, 240);
	cpu_set.ImageToFile("image-7640x7640.ppm");
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	cout << (double) duration.count() / 1000;

	return 0;
}