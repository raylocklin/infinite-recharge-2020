#ifndef YEET_MOTOR_GROUPS_H
#define YEET_MOTOR_GROUPS_H
//These are all singletons, they should only be instanciated once.
namespace hardware
{
    class Intake
    {
    private:

        static constexpr double baseSpeed{1};

    public:
        static void in();
        static void out();
        static void stop();
    };
}

#endif