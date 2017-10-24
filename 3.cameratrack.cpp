#include "highgui.h"
#include "cv.h"
int g_slider_position=0;// 全局变量
CvCapture* capture =NULL;
int i=0;//记录第二个trackbar被调用的次数，i为奇数则暂停，偶数则播放
int speed=33;//控制播放的速度

void onTrackbarSlide1(int pos)//第一个回调函数，控制视频在任意位置播放
{
    cvSetCaptureProperty(capture,CV_CAP_PROP_POS_FRAMES,pos);
}
void onTrackbarSlide2(int pos)//第二个回调函数
{
        i=i+1;  
}
int main()
{
    capture=cvCreateFileCapture("math.avi");//加载视频
    IplImage* frame;
    int frames=(int) cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_COUNT);
    cvNamedWindow("math.avi");
    if(frames!=0)
    {
      cvCreateTrackbar("trackbar1","math.avi",&g_slider_position,frames,onTrackbarSlide1);//创建第一个trackbar
      cvCreateTrackbar("trackbar2","math.avi",&g_slider_position,frames,onTrackbarSlide2);//创建第二个trackbar
    }   
    while(1)
       { 
            if(i%2==0)//判断当前是播放还是暂停，如果播放则执行
            {
                frame=cvQueryFrame(capture);//继续读取capture
                if(!frame)break;
                cvShowImage("math.avi",frame);//显示
            }
            else //如果是暂停状态，则不读取capture，只显示当前帧，是不是很naive
            {
                cvShowImage("math.avi",frame);
            }
            char c=cvWaitKey(speed);
            if(c==27)break;

        }

    }