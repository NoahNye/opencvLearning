#include "cv.h"
#include "highgui.h"
#include "cxcore.h"
int main()
{
	cvNamedWindow("win");			 //创建窗口
	CvCapture* capture = cvCreateFileCapture("D:\\camera.mp4");//创建一个结构体接受视频帧
	IplImage* frame;					//创建一个IplImage存储视频帧
	while (1)
	{
		frame=cvQueryFrame(capture);  //下一帧预存
		if (!frame)break;			 //如果IplImage为空，跳出

		cvShowImage("win", frame);	//显示窗口
		char c = cvWaitKey(33);		//创建CHAR函数接受输入的cvWaitKey(33)的ASCALL码
		if (c == 27)				//ESC的ASCALL码为27
			break;

	}
	
	
	cvReleaseCapture(&capture);//释放视频帧内存
	cvDestroyWindow("win");		//释放窗口内存

}