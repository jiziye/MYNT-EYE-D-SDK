#include<iostream>

#include "mynteyed/camera.h"
//#include "mynteyed/utils.h"
#include<opencv2/highgui/highgui.hpp>


MYNTEYE_USE_NAMESPACE

int main(int argc, char const* argv[])
{
    std::cout << "111111111111" << std::endl;
    Camera cam;
    std::cout << "222222222222" << std::endl;
    DeviceInfo dev_info;
    std::cout << "333333333333" << std::endl;

    OpenParams params(dev_info.index);

        params.framerate = 10;
        params.color_mode = ColorMode::COLOR_RAW;
        params.stream_mode = StreamMode::STREAM_2560x720;
        params.ir_intensity = 3;
    

    cam.Open(params);
    if(!cam.IsOpened())
    {
        std::cerr << "open camera failed " << std::endl;
        return 1;
    }   

    bool is_left_ok = cam.IsStreamDataEnabled(ImageType::IMAGE_LEFT_COLOR);
    bool is_right_ok = cam.IsStreamDataEnabled(ImageType::IMAGE_RIGHT_COLOR);

    for(;;)
    {
        cam.WaitForStream();

        if(is_left_ok)
        {
            auto left_stream =  cam.GetStreamData(ImageType::IMAGE_LEFT_COLOR);
            if(left_stream.img)
            {
                cv::Mat left_mat = left_stream.img->To(ImageFormat::COLOR_BGR)->ToMat();
                cv::imshow("left",left_mat);
            }
        }

        if(is_right_ok)
        {
            auto right_stream = cam.GetStreamData(ImageType::IMAGE_RIGHT_COLOR);
            if(right_stream.img)
            {
                cv::Mat right_mat = right_stream.img->To(ImageFormat::COLOR_BGR)->ToMat();
                cv::imshow("right",right_mat);
            }
        }

        char key = cvWaitKey(1);
        if(key == 'q' || key == 27){
            break;
        }

    }

    cam.Close();
    return 0;
}