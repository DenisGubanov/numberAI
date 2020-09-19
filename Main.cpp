#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include "ReadImage.cpp"
#include "NeuralNetwork.cpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	ReadImage photo("C:/Users/DENIS/Downloads/test.png", "test.png");
	//photo.WriteImageConsole();
	//cout << Sigmoid(1);
	NeuralNetwork MainNeuralNetwork;
	//MainNeuralNetwork.InputDataNeuron(photo.Img);
	MainNeuralNetwork.WriteNetworkStat();
	return 0;
}

/*void InputDataNeuron(Mat photo)
	{
		int t;
		for (int i = 0; i < 40; i++) // 40
		{
			for (int j = 0; j < 40; j++) // 40
			{
				//int r = (int)photo.at<Vec3b>(i, j)[0];
				//int g = (int)photo.at<Vec3b>(i, j)[1];
				//int b = (int)photo.at<Vec3b>(i, j)[2];
				//LayerPixel[(i * j) + j].Value = 1; //(1 / (1 + pow(2.7, (-1) * sum))
			}
		}
		int tt;
	} */
