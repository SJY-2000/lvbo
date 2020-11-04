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
	Mat srcMat ;
	cap >> srcMat;
	Mat dstMat;
	medianBlur(srcMat, dstMat, 3);
	imshow("ԭͼ", srcMat);
	imshow("��ֵ�˲�", dstMat);
	waitKey(0);
	return 0;
}