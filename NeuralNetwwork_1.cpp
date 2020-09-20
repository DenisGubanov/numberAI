#include <opencv2/opencv.hpp>
#include <iostream>
#include "Neuron.cpp"

using namespace std; 
using namespace cv;

class NeuralNetwork 
{
public:
	
	Neuron LayerPixel[40][40];
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
		cout << endl;
		cout.setf(ios::fixed);  
		cout.precision(3);
		for (int i = 0; i < 10; i++)
		{
			cout << LayerElement[i].Value << " " << LayerPatern[i].Value << " " << LayerNumber[i] << endl;
		}
		cout << endl;
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << LayerPixel[i][j].Value << endl;
			}
		}
	}
	void InputDataNeuron(double matrix[40][40])
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				LayerPixel[i][j].Value = matrix[i][j];
			}
		}
	}
};
