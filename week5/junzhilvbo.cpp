#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能读取" << std::endl;
		return -1;
	}
	Mat srcMat;
	cap >> srcMat;
	Mat dstMat;
	blur(srcMat, dstMat, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	imshow("原图", srcMat);
	imshow("均值滤波", dstMat);
	waitKey(0);
	return 0;
}