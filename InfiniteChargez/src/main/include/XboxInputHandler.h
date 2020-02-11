#ifndef YEET_XBOX_INPUT_HANDLER_H
#define YEET_XBOX_INPUT_HANDLER_H
#include "Pair2D.h"

#include <inttypes.h>

#include <frc/XboxController.h>
namespace utilities
{
    class XboxInputHandler
    {
    using joystick_t = utilities::Pair2D<double>;
    using bitmask_t = std::uint8_t;
    using buttonData_t = std::uint8_t;

    private:
    static constexpr bitmask_t ButtonStateMask{1 << 0};
    static constexpr bitmask_t ButtonPressed{1 << 1};
    static constexpr bitmask_t ButtonReleased{1 << 2};
    public:
        void operator=(frc::XboxController);

        void getAButton() {}
        void setJoystickLeft(joystick_t axis) {m_joystickLeft = axis;}
        joystick_t getJoystickLeft(){return m_joystickLeft;}

        void getJoystickRight(joystick_t axis ) {m_joystickRight = axis;}
        joystick_t getJoystickRight() {return m_joystickRight;}






    private:
        joystick_t m_joystickLeft{0, 0};
        joystick_t m_joystickRight{0, 0};

    };
}
#endif