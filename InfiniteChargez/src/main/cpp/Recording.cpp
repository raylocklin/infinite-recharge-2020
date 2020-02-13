#include "Robot.h"
#include "XboxInputHandler.h"

#include <thread>
#include <chrono>
#include <string>
void Robot::executeRecording(std::fstream &recordingFile)
{
    std::string line{""};
    std::getline(inputRecordFile, line);
    const duration_t frameDelta{std::stod(line)};

    while (std::getline(inputRecordFile, line))
    {
        leInputHandler = line;
        checkAndExec(leInputHandler);
        std::this_thread::sleep_for(frameDelta);
    }
}

void Robot::recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta)
{
    if (leInputHandler.getButtonStartState() && recordingEnabled)
    {
        isRecording = true;
        recordingEnabled = false;
        meanDelta = delta.count();
    }
    if (leInputHandler.getButtonBackState()) //Do not use elseif!!! If is for better response!!!
    {
        isRecording = false;
        std::string line;
        inputRecordFile << std::to_string(meanDelta) << '\n';
        while (std::getline(inputRecordFileBuffer, line))
        {
            inputRecordFile << line << '\n';
        }
    }

    if (isRecording)
    {
        meanDelta = (meanDelta + delta.count()) / 2;
        inputRecordFileBuffer << leInputHandler.getSnapshot() << '\n';
    }
