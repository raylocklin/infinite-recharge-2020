#include "Robot.h"
#include <thread>
#include <chrono>
#include <string>
void Robot::executeRecording(std::fstream &recordingFile)
{
    std::string line{""};
    std::getline(inputRecordFile, line);
    const duration_t frameDelta{std::stod(line)};

    while(std::getline(inputRecordFile, line))
    {
        leInputHandler = line;
        checkAndExec(leInputHandler);
        std::this_thread::sleep_for(frameDelta);
    }
}
