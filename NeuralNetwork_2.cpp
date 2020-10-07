#include <opencv2/opencv.hpp>
#include <iostream> // Программа считывает пиксили фото и говорит какая цифра . Почти дописал 80% 20% программа пишет 3
#include "Neuron.cpp"
#include <fstream> // Нейронная сеть считывания по пискильной фотографии

using namespace std;
using namespace cv;

class NeuralNetwork // Класс сети
{
public:
	Neuron LayerPixel[40][40]; // Первый слой
	Neuron LayerElement[10]; // Второй слой
	double LayerNumber[10]; // Третий слой
	int SortElement[10]; // Прокаченный второй слой
	// Резервное копирование

	double Sigmoid(double X)
	{
		return 1 / (1 + exp((-1) * X));
	}
	NeuralNetwork() // Конструктор
	{
		for (int i = 0; i < 10; i++)
		{
			LayerNumber[i] = 0.5;
		}
	}
	void WriteNetworkStat() // Вывод статистики сети в консоль
	{
		cout << endl;
		cout.setf(ios::fixed);
		cout.precision(3);
		for (int i = 0; i < 10; i++)
		{
			cout << LayerElement[i].Value << " " << LayerNumber[i] << endl;
		}
		cout << endl;
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				cout << LayerPixel[i][j].Value << endl;
				for (int k = 0; k < 10; k++)
				{
					cout << " = " << LayerPixel[i][j].Weight[k];
				}
				cout << endl;
			}
		}
	}
	void InputDataNeuron(double matrix[40][40]) // Возбуждение нейронов первого слоя по фотографии
	{
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				LayerPixel[i][j].Value = matrix[i][j];
			}
		}
	}
	/*void SortElement()
	{
		double tempArray[10];
		for (int i = 0; i < 10; i++)
		{
			tempArray[i] = LayerElement[i].Value;
		}
		for (int i = 0; i < 10; i++)
		{
			double max = -1;
			int index = 0;
			for (int j = 0; j < 10; j++)
			{
				if (max < LayerElement[j].Value)
				{
					max = LayerElement[j].Value;
					index = j;
				}
			}
			SortElement[i] = LayerElement[index].Value;
			LayerElement[index].Value = -1;
		}
		for (int i = 0; i < 10; i++)
		{
			LayerElement[i].Value = tempArray[i];
		}
	}*/
	void DefaultLayerTraining(int trainingPoint) // Обучение второго слоя технически
	{
		cout << endl;
		cout << "Обучение началось";
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				double newupdate = LayerPixel[i][j].Value - 0.5;
				double leftupdate = LayerPixel[i][j].Weight[trainingPoint] - 0.5;
				LayerPixel[i][j].Weight[trainingPoint] = Sigmoid((newupdate)+(leftupdate * 2));
			}
		}
		cout << endl;
		cout << "Обучение прошло" << endl;
	}
	void DefaultNumberTraining()
	{
		for (int i = 0; i < 10; i++)
		{
			LayerNumber[i] = 0;
		}

	}
	void DeleteDataNeuralNetwork() // Удаление файла данных сети
	{
		cout << endl;
		if (remove("NeuralNetwork.txt") != 0)
			cout << "Ошибка удаления файлаn";
		else
			cout << "Файл успешно удалёнn";
	}
	void SavingDataNeuralNetwork(string pathNeuralNetwork) // Запись данных нейронной сети в файл
	{
		ofstream file(pathNeuralNetwork, ios::out);
		cout << "Сохранение" << endl;
		file.setf(ios::fixed);
		file.precision(3);
		for (int i = 0; i < 10; i++)
		{
			file << LayerElement[i].Value << endl;
			file << LayerNumber[i] << endl;
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				file << LayerElement[i].Weight[j] << endl;
			}
		}
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				file << LayerPixel[i][j].Value << endl;
				for (int k = 0; k < 10; k++)
				{
					file << LayerPixel[i][j].Weight[k] << endl;
				}
			}
		}
		file.close();
	}
	void UpdateDataNeuralNetwork(string pathNeuralNetwork) // Обновление нейронной сети по файлу
	{
		ifstream file(pathNeuralNetwork);
		string temp;
		for (int i = 0; i < 10; i++)
		{
			file >> LayerElement[i].Value;
			file >> LayerNumber[i];
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				file >> LayerElement[i].Weight[j];
			}
		}
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				file >> temp;
				for (int k = 0; k < 10; k++)
				{
					file >> LayerPixel[i][j].Weight[k];
				}
			}
		}
		file.close();
	}
	void CheckValueNeuralNetwork() {
		for (int k = 0; k < 10; k++)
		{
			for (int i = 0; i < 40; i++)
			{
				for (int j = 0; j < 40; j++)
				{
					LayerElement[k].Value += ((LayerPixel[i][j].Value + 0.5) * (LayerPixel[i][j].Weight[k]));
				}
			}
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				LayerNumber[i] += (LayerElement[j].Value) * (LayerElement[j].Weight[i]);
			}
		}
		int maxValue = -1;
		double max = -1;
		for (int i = 0; i < 10; i++)
		{
			if (max < LayerNumber[i])
			{
				max = LayerNumber[i];
				maxValue = i;
			}
		}
		cout << endl << ((maxValue+1) % 10) << endl;
	}
};
