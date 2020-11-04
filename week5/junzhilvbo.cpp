#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "���ܶ�ȡ" << std::endl;
		return -1;
	}
	Mat srcMat;
	cap >> srcMat;
	Mat dstMat;
	blur(srcMat, dstMat, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	imshow("ԭͼ", srcMat);
	imshow("��ֵ�˲�", dstMat);
	waitKey(0);
	return 0;
}