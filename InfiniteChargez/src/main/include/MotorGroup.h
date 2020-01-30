#ifndef YEET_YEET_YEET_MOTOR_GROUP_YEET_H
#define YEET_YEET_YEET_MOTOR_GROUP_YEET_H
#include <vector>
#include <initializer_list>

#include <frc/PWM.h>

namespace hardware
{
    class MotorGroup
    {
        protected:
            std::vector<frc::PWM*> m_motors;

        public:
            MotorGroup(std::size_t motorCount):
                m_motors{motorCount}
            {
            }

            MotorGroup(std::initializer_list<frc::PWM*> motorAddressList):
                MotorGroup{motorAddressList.size()}
            {
                for(auto motorAddress:motorAddressList)
                {
                    m_motors = motorAddressList;
                }
            }
    };
}
#endif