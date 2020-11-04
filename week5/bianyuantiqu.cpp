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
	Mat dstMatx;
	Mat dstMaty;
	Sobel(srcMat, dstMatx, CV_8UC1, 1,0,3);
	Sobel(srcMat, dstMaty, CV_8UC1, 0,1,3);
	imshow("ԭͼ", srcMat);
	imshow("��Ե��ȡx", dstMatx);
	imshow("��Ե��ȡy", dstMaty);
	waitKey(0);
	return 0;
}