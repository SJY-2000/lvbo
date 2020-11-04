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
	Mat srcMat ;
	cap >> srcMat;
	Mat dstMat;
	medianBlur(srcMat, dstMat, 3);
	imshow("原图", srcMat);
	imshow("中值滤波", dstMat);
	waitKey(0);
	return 0;
}