#include "ugv_sdk/scout/scout_base.hpp" //使用小车上的sdk版本

using namespace westonrobot;

int main(int argc, char **argv)
{
    std::cout << argv[0] << std::endl;
    std::string device_name;
    int32_t baud_rate = 0;

	device_name = {argv[1]};
    ScoutBase scout;
    scout.Connect(device_name, baud_rate);
  
    while(true) 
     {
        auto state = scout.GetScoutState(); //获取小车状态

        std::cout << "车灯状态：";
        if(state.front_light_state.mode == LIGHT_MODE_BREATH){
            std::cout << "呼吸模式" << std::endl;
        }
        else if(state.front_light_state.mode == LIGHT_MODE_CONST_ON){
            std::cout << "灯光打开" << std::endl;
        }
        else if(state.front_light_state.mode == LIGHT_MODE_CONST_OFF){
            std::cout << "灯光关闭" << std::endl;
        }
        else if(state.front_light_state.mode == LIGHT_MODE_CUSTOM){
            std::cout << "可编程模式" << std::endl;
        }

        //电池
        std::cout << "电池电压：" 
                    << state.battery_voltage << std::endl; 

        //电机
        std::cout <<"电机数量：" << (unsigned int)state.motor_num << std::endl;
	std::cout<<"电机电流："<<state.actuator_states->motor_current<<std::endl;
        std::cout<<"电机转速："<<state.actuator_states->motor_rpm<<std::endl;
        std::cout<<"电机脉冲数："<<state.actuator_states->motor_pulses<<std::endl;
        std::cout<<"电机温度："<<state.actuator_states->motor_temperature<<std::endl;
        std::cout<<"驱动器电压："<<state.actuator_states->driver_voltage<<std::endl;
        std::cout<<"驱动器状态："<<(unsigned int)state.actuator_states->driver_state<<std::endl;
        std::cout<<"驱动器温度："<<state.actuator_states->driver_temperature<<std::endl;

        //运动状态
        std::cout << "运动状态" <<std::endl
                    << "线速度：" << state.linear_velocity << std::endl
                    << "角速度：" << state.angular_velocity << std::endl
                    << std::endl;
        usleep(20000);
    }

    return 0;
}
