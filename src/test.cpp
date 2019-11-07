#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/calib3d/calib3d.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat image, image_gray;      //��������Mat���������ڴ洢ÿһ֡��ͼ��
	VideoCapture capture(0);    //������ͷ������Ƶ

	while (1)                  //ѭ����ʾÿһ֡
	{
		capture >> image;     //��ȡ��ǰ֡

		//image = imread("F://1.png");
		//imshow("ԭͼ", image);

		cvtColor(image, image_gray, COLOR_BGR2GRAY);//תΪ�Ҷ�ͼ
		equalizeHist(image_gray, image_gray);//ֱ��ͼ���⻯�����ӶԱȶȷ��㴦��

		CascadeClassifier eye_Classifier;  //���������
		CascadeClassifier face_cascade;    //���������

		//���ط���ѵ������OpenCv�ٷ��ĵ��ṩ��xml�ĵ�������ֱ�ӵ���
		//xml�ĵ�·��  opencv\sources\data\haarcascades 
		if (!eye_Classifier.load("haarcascade_eye.xml"))  //��Ҫ��xml�ĵ������Լ�ָ����·����
		{
			cout << "Load haarcascade_eye.xml failed!" << endl;
			return 0;
		}

		if (!face_cascade.load("haarcascade_frontalface_alt2.xml"))
		{
			cout << "Load haarcascade_frontalface_alt failed!" << endl;
			return 0;
		}

		//vector �Ǹ���ģ�� ��Ҫ�ṩ��ȷ��ģ��ʵ�� vector<Rect>���Ǹ�ȷ������ ģ���ʵ����
		vector<Rect> eyeRect;
		vector<Rect> faceRect;

		//�������۾���λλ��
		eye_Classifier.detectMultiScale(image_gray, eyeRect, 1.1, 2, 0 | 2, Size(30, 30));//���
		for (size_t eyeIdx = 0; eyeIdx < eyeRect.size(); eyeIdx++)
		{
			rectangle(image, eyeRect[eyeIdx], Scalar(0, 0, 255));   //�þ��λ�����⵽��λ��
		}

		//����������λ��
		face_cascade.detectMultiScale(image_gray, faceRect, 1.1, 2, 0 | 2, Size(30, 30));//���
		for (size_t i = 0; i < faceRect.size(); i++)
		{
			rectangle(image, faceRect[i], Scalar(0, 0, 255));      //�þ��λ�����⵽��λ��
		}

		imshow("����ʶ��ͼ", image);         //��ʾ��ǰ֡
		char c = waitKey(30);         //��ʱ30ms����ÿ�벥��33֡ͼ��
		if (c == 27)  break;
	}

	return 0;
}

