#include "highgui.h"
#include "cv.h"
int g_position = 0;
int speed = 33;
int frame_count = 0;

int frames;
CvCapture* capture = NULL;
void position(int pos)
{
	cvSetCaptureProperty(capture, CV_CAP_PROP_POS_FRAMES, pos);
	frame_count = pos;
}


int main()
{
	IplImage* frame;
	cvNamedWindow("win");
	capture = cvCreateFileCapture("D:\\camera.mp4");
	frames = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
	if (frames != 0)
	{
		cvCreateTrackbar("capture", "win", &g_position, frames, position);
	}
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)break;
		cvShowImage("win", frame);

		char i = cvWaitKey(33);
		if (i == 27) { break; }

		cvSetTrackbarPos("capture", "win", frame_count);
		frame_count++;

	}


	cvReleaseCapture(&capture);
	cvDestroyWindow("win");




}