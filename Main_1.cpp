#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include "ReadImage.cpp"
#include "NeuralNetwork.cpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	cout << "v1.10" << endl;
	string pathNetwork = "C:\\Main Data\\VS2019\\Part2\\HOME_19_09_20\\NeuralNetwork.txt";
	//string pathBackUp = "C:\\Main Data\\VS2019\\Part2\\HOME_19_09_20\\BackUpNeuralNetwork.txt";
	NeuralNetwork MainNeuralNetwork;
	//NeuralNetwork MainBackUpNeuralNetwork;
	ReadImage photo("C:/Users/DENIS/Downloads/test.png", "test.png");
	photo.WriteImageConsole();
	MainNeuralNetwork.InputDataNeuron(photo.Matrix);
	MainNeuralNetwork.UpdateDataNeuralNetwork(pathNetwork);
	MainNeuralNetwork.DeleteDataNeuralNetwork();
	int track = 9;
	MainNeuralNetwork.DefaultLayerTraining(track);
	MainNeuralNetwork.DefaultLayerTraining(track);
	MainNeuralNetwork.DefaultLayerTraining(track);
	MainNeuralNetwork.DefaultLayerTraining(track);
	MainNeuralNetwork.DefaultLayerTraining(track);
	MainNeuralNetwork.DefaultLayerTraining(track);
	MainNeuralNetwork.DefaultLayerTraining(track);
	MainNeuralNetwork.CheckValueNeuralNetwork();
	MainNeuralNetwork.SavingDataNeuralNetwork(pathNetwork);
	MainNeuralNetwork.WriteNetworkStat();
	return 0;
}
