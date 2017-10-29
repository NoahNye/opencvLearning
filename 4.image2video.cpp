#include<iostream>
#include "cv.h"
#include "highgui.h"
int main(int argc, char *argv[])
{
	CvSize size = CvSize(480, 360);//定义视频大小                                                                
	double fps = 15;

	CvVideoWriter* write = cvCreateVideoWriter("C:\\Users\\noah\\Pictures\\Screenshots\\test.avi", CV_FOURCC('X', 'V', 'I', 'D'), fps, size);
	int image_id = 1;
	char filename[256];
	sprintf(filename, "C:\\Users\\noah\\Pictures\\Screenshots\\%d.png", image_id);
	IplImage* src = cvLoadImage(filename);
	if (!src)
	{

		return 0;
	}
	IplImage* src_size = cvCreateImage(size, 8, 3);

	cvNamedWindow("test.avi");
	while (src)
	{

		cvShowImage("test.avi", src_size);
		cvWaitKey(33);
		cvResize(src, src_size);
		cvWriteFrame(write, src_size);
		cvReleaseImage(&src);

		image_id++;
		sprintf(filename, "C:\\Users\\noah\\Pictures\\Screenshots\\%d.png", image_id);
		src = cvLoadImage(filename);
	}
}