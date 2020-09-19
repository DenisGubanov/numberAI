#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

class Neuron 
{
public:
	double Weight[10];
	double Value;
	Neuron()
	{
		Value = 0.5;
		for (int i = 0; i < 10; i++)
		{
			Weight[i] = 0.5;
		}
	}
};
