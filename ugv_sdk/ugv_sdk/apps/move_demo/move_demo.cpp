#include "ugv_sdk/scout/scout_base.hpp"

using namespace westonrobot;

int main(int argc, char **argv)
{
    std::string device_name;
    int32_t baud_rate = 0;
    device_name = {argv[1]};
    ScoutBase scout;
    scout.Connect(device_name, baud_rate);

    scout.EnableCommandedMode();
    size_t count = 500;
   for (size_t i = 0; i < count; i++)
   {
        std::cout << "Motor:0.2,1" << std::endl;
        scout.SetMotionCommand(2, 1.0); //设定线速度为0.2

        usleep(20000);//挂起两万微秒,20毫秒
   }
    for (size_t i = 0; i < count; i++)
   {
        std::cout << "Motor:0.2,-1" << std::endl;
        scout.SetMotionCommand(2, -1.0); //设定线速度为0.2

        usleep(20000);//挂起两万微秒,20毫秒
   }
    for (size_t i = 0; i < count; i++)
   {
        std::cout << "Motor:0.2,-1" << std::endl;
        scout.SetMotionCommand(2, 0.1); //设定线速度为0.2

        usleep(20000);//挂起两万微秒,20毫秒
   }
    return 0;
}
