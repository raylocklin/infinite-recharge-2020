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
        std::cout << line << '\n';
        robot->leInputHandler = line;
        robot->checkAndExec(robot->leInputHandler);
        std::this_thread::sleep_for(frameDelta);
    }
}

void Robot::recordActionsExec(utilities::XboxInputHandler &leInputHandler, duration_t delta, std::ofstream &recordBuffer)
{
    if (leInputHandler.getButtonStartState() && recordingEnabled)
    {
        isRecording = true;
        recordingEnabled = false;
        meanDelta = delta.count();
    }
    if (leInputHandler.getButtonBackState() && isRecording) //Do not use elseif!!! If is for better response!!!
    {
        recordBuffer.close();
        std::ifstream recordBufferRead{recordBufferName};
        isRecording = false;
        std::string line;
        std::ofstream recordFile{inputRecordFileName};

        recordFile << std::to_string(meanDelta) << '\n';

        while (std::getline(recordBufferRead, line))
        {
            recordFile << line << '\n';
        }
        recordFile.close();
        recordBuffer.close();
    }

    if (isRecording)
    {
        std::cout << "recording" << '\n';
        meanDelta = (meanDelta + delta.count()) / 2;
        recordBuffer << leInputHandler.getSnapshot() << '\n';
    }
}