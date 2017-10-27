//读取图像
#include "cv.h"
#include "highgui.h"
#include "cxcore.h"

int main()
{
	IplImage* src = cvLoadImage("d:\\pic.jpg",1);//创建一个变量赋予图像内容
	cvNamedWindow("win");						 //创建显示窗口
	cvShowImage("win", src);					 //显示图像
	cvWaitKey(0);								 //设置停留时间	
	cvReleaseImage(&src);						 //释放图像内存	
	cvDestroyWindow("win");						 //释放窗口内存
	return 0;
}
