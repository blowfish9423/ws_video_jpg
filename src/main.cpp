#include <iostream>
#include <vector>
//#include <getopt.h>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
    1.  修改成输入参数的形式
            参数 输入视频文件名 输出目录 默认true(自动增加序号)
        help       
*/
int main(int argc, char **argv)
{
    std::cout << "argc:" << argc << std::endl;
    printf(CV_VERSION);
    std::string source_video_path = "F:/Data/object_detection_and_track_data/20250415/";
    std::string dst_image_path = "F:/Data/images/";

    cv::VideoCapture capture;
    capture.open(source_video_path+"10M_1.MP4");
    if (!capture.isOpened())
    {
        std::cout << "Read video Failed !" << std::endl;
        return 0;
    }

    cv::Mat frame;
    int frame_num = capture.get(cv::CAP_PROP_FRAME_COUNT);
    std::cout << "total frame number is: " << frame_num << std::endl;

    char jpgstr[256];
    int index = 1;
    for (int i=0; i < frame_num - 1; i++)
    {
        capture >> frame;
        if (i % 5 == 0)
        {
            sprintf(jpgstr, "ws_%08d.jpg", index);
            cv::imwrite(dst_image_path + jpgstr, frame);
            index++;
            std::cout << "index:" << i << "(" << frame_num << ")" << std::endl;
        }
    }
    std::cout << "Finish!!! " << std::endl;
    capture.release();
    return 0;
}
