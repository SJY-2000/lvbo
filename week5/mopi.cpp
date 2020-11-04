#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	//0-180
	//��ɫ
	double i_minH = 0;
	double i_maxH = 20;
	//0-255
	double i_minS = 43;
	double i_maxS = 255;
	//0-255
	double i_minV = 55;
	double i_maxV = 255;

	Mat srcMat, dstMat;     //ԭͼ�����ͼ��
	Mat hsvMat;             //ԭͼ��hsv��ʽ
	Mat mask;               //��Ĥ
	Mat skinMat, otherMat;  //Ƥ������ͼ�񡢷�Ƥ������ͼ��
	Mat mopiMat;         //ĥƤ������Ƥ��ͼ��

	srcMat = imread("G:/picture/15.jpg");
	cvtColor(srcMat, hsvMat, COLOR_BGR2HSV);    //��ԭͼת��hsv��ʽ
	cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), mask); //������ֵ��Χ��ֵ��

	srcMat.copyTo(skinMat, mask);               //��Ĥ����Ƥ������ͼ��skinMat
	srcMat.copyTo(otherMat, (255 - mask));        //����Ƥ������ͼ���Ƶ�otherMat

	bilateralFilter(skinMat, mopiMat, 25, 50, 35);      //˫���˲�ĥƤ

	dstMat = mopiMat + otherMat;             //�ϳ�ĥƤ������ͼ��

	imshow("ԭͼ��", srcMat);
	imshow("ĥƤ��ͼ��", dstMat);

	waitKey(0);

	return 0;
}
