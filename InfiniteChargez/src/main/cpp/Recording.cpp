#include "Robot.h"
#include "XboxInputHandler.h"

#include <thread>
#include <chrono>
#include <string>
#include <fstream>
void executeRecording(Robot *robot)
{
    std::ifstream recordingFile{robot->inputRecordFileName};
    std::string line{""};
    std::getline(robot->inputRecordFile, line);
    const Robot::duration_t frameDelta{std::stod(line)};

    while (std::getline(robot->inputRecordFile, line))
    {
        robot->leInputHandler = line;
        robot->checkAndExec(robot->leInputHandler);
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
        inputRecordFile.close();
    }

    if (isRecording)
    {
        meanDelta = (meanDelta + delta.count()) / 2;
        inputRecordFileBuffer << leInputHandler.getSnapshot() << '\n';
    }
}