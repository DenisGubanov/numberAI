#include <opencv2/opencv.hpp>
#include <iostream>
#include "Neuron.cpp"

using namespace std; 
using namespace cv;

class NeuralNetwork 
{
public:
	
	Neuron LayerPixel[1600];
	Neuron LayerElement[10];
	Neuron LayerPatern[10];
	double LayerNumber[10];
	
	NeuralNetwork()
	{
		for (int i = 0; i < 10; i++)
		{
			LayerNumber[i] = 0.5;
		}
	}
	
	void WriteNetworkStat()
	{
		cout.setf(ios::fixed);  
		cout.precision(3);
		for (int i = 0; i < 10; i++)
		{
			cout << LayerPixel[i].Value << " " << LayerElement[i].Value << " " << LayerPatern[i].Value << " " << LayerNumber[i] << endl;
		}
		for (int i = 10; i < 1600; i++)
		{
			cout << LayerPixel[i].Value << endl;
		}
	}
};
