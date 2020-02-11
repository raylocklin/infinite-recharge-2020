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
    using button_t = std::uint8_t;

    private:
    static constexpr bitmask_t ButtonStateMask{1 << 0};
    static constexpr bitmask_t ButtonPressedMask{1 << 1};
    static constexpr bitmask_t ButtonReleasedMask{1 << 2};
    public:
        void operator=(frc::XboxController);

        void getAButton() {}
        void setJoystickLeft(joystick_t axis) {m_joystickLeft = axis;}
        joystick_t getJoystickLeft(){return m_joystickLeft;}

        void getJoystickRight(joystick_t axis ) {m_joystickRight = axis;}
        joystick_t getJoystickRight() {return m_joystickRight;}
        
        //Button Functions
        //Button A
        void setButtonAState(bool state) {(state) ? m_buttonA |= ButtonStateMask : m_buttonA &= ~ButtonStateMask;}
        bool getButtonAState(bool state) {return m_buttonA & ButtonStateMask;}

        void setButtonAPressed(bool state) {(state) ? m_buttonA |= ButtonPressedMask : m_buttonA &= ~ButtonPressedMask;}
        bool getButtonAPressed(bool state) {return m_buttonA & ButtonPressedMask;}

        void setButtonAReleased(bool state) {(state) ? m_buttonA |= ButtonReleasedMask : m_buttonA &= ~ButtonReleasedMask;}
        bool getButtonAReleased(bool state) {return m_buttonA & ButtonReleasedMask;}

        //ButtonB
        void setButtonBState(bool state) {(state) ? m_buttonB |= ButtonStateMask : m_buttonB &= ~ButtonStateMask;}
        bool getButtonBState(bool state) {return m_buttonB & ButtonStateMask;}

        void setButtonBPressed(bool state) {(state) ? m_buttonB |= ButtonPressedMask : m_buttonB &= ~ButtonPressedMask;}
        bool getButtonBPressed(bool state) {return m_buttonB & ButtonPressedMask;}

        void setButtonBReleased(bool state) {(state) ? m_buttonB |= ButtonReleasedMask : m_buttonB &= ~ButtonReleasedMask;}
        bool getButtonBReleased(bool state) {return m_buttonB & ButtonReleasedMask;}

	//ButtonX
        void setButtonXState(bool state) {(state) ? m_buttonX |= ButtonStateMask : m_buttonX &= ~ButtonStateMask;}
        bool getButtonXState(bool state) {return m_buttonX & ButtonStateMask;}

        void setButtonXPressed(bool state) {(state) ? m_buttonX |= ButtonPressedMask : m_buttonX &= ~ButtonPressedMask;}
        bool getButtonXPressed(bool state) {return m_buttonX & ButtonPressedMask;}

        void setButtonXReleased(bool state) {(state) ? m_buttonX |= ButtonReleasedMask : m_buttonX &= ~ButtonReleasedMask;}
        bool getButtonXReleased(bool state) {return m_buttonX & ButtonReleasedMask;}

	//ButtonY
        void setButtonYState(bool state) {(state) ? m_buttonY |= ButtonStateMask : m_buttonY &= ~ButtonStateMask;}
        bool getButtonYState(bool state) {return m_buttonY & ButtonStateMask;}

        void setButtonYPressed(bool state) {(state) ? m_buttonY |= ButtonPressedMask : m_buttonY &= ~ButtonPressedMask;}
        bool getButtonYPressed(bool state) {return m_buttonY & ButtonPressedMask;}

        void setButtonYReleased(bool state) {(state) ? m_buttonY |= ButtonReleasedMask : m_buttonY &= ~ButtonReleasedMask;}
        bool getButtonYReleased(bool state) {return m_buttonY & ButtonReleasedMask;}







    private:
        joystick_t m_joystickLeft{0, 0};
        joystick_t m_joystickRight{0, 0};

        button_t m_buttonA{0};
        button_t m_buttonB{0};
        button_t m_buttonX{0};
        button_t m_buttonY{0};

    };
}
#endif
