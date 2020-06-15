#include<iostream>

#include "mynteyed/camera.h"
//#include "mynteyed/utils.h"

MYNTEYE_USE_NAMESPACE

int main(int argc, char const* argv[])
{
    std::cout << "*********************" << std::endl;
    Camera cam;
    std::cout << "*********************" << std::endl;
    DeviceInfo dev_info;
    std::cout << "*********************" << std::endl;
    cam.Open();
    if(!cam.IsOpened())
    {
        std::cerr << "open camera failed " << std::endl;
        return 1;
    }   

    return 0;
}