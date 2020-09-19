#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class ReadImage 
{
public:
	Mat Img;
	string Path, WindowName;
	ReadImage(string path, string windowName)
	{
		Path = path;
		WindowName = windowName;
		Img = imread(path);
		if (Img.empty())
		{
			cout << "Could not open or find the image" << endl;
			cin.get();
		}
	}
	void WriteImageConsole()
	{
		bool next = false;
		for (int i = 0; i < Img.rows; i++) {
			for (int j = 0; j < Img.cols; j++) {
				int r = (int)Img.at<Vec3b>(i, j)[0];
				int g = (int)Img.at<Vec3b>(i, j)[1];
				int b = (int)Img.at<Vec3b>(i, j)[2];
				if ((r == 255) && (g == 255) && (b == 255)) {cout << 'O';}
				else if ((r > 0) && (g > 0) && (b > 0)) {cout << '2';}
				else {cout << '1';}
				next = false;
				if ((j % 40 == 0) && (next == false)) {cout << endl; next = true;}
			}
		}
		namedWindow(WindowName);
		imshow(WindowName, Img);
		waitKey(0);
		destroyWindow(WindowName);
	}
};
