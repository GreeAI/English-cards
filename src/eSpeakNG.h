#ifndef ESPEAKNG_H
#define ESPEAKNG_H

#include <ctime>
#include <espeak-ng/speak_lib.h>
#include <fstream>
#include <iostream>
#include <string>

void logError(const std::string& message)
{
    std::ofstream logFile("espeak_error.log", std::ios::app);
    if (logFile.is_open()) {
        std::time_t now = std::time(nullptr);
        std::tm* timeInfo = std::localtime(&now);
        char timeStr[20];
        std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", timeInfo);

        logFile << "[" << timeStr << "] ERROR: " << message << std::endl;
        logFile.close();
    }
}

void speakText(const std::string &text) {

    if (espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, nullptr, 0) == -1) {
        logError("Failed to espeak initialize");
        return;
    }
    try {
        if (espeak_SetVoiceByName("en+f3") != EE_OK) {
            logError("Failed to set voice 'en+f3'");
            return;
        }

        espeak_SetParameter(espeakRATE, 140, 0);

        espeak_SetParameter(espeakPITCH, 48, 0);

        int synthStatus = espeak_Synth(text.c_str(),
                                       text.size() + 1,
                                       0,
                                       POS_CHARACTER,
                                       0,
                                       espeakCHARS_AUTO,
                                       nullptr,
                                       nullptr);

        if (synthStatus != EE_OK) {
            logError("espeak_Synth failed with status: " + std::to_string(synthStatus));
            return;
        }

        // Ожидание завершения
        espeak_Synchronize();

    } catch (const std::exception& e) {
        logError(std::string("Exception caught: ") + e.what());
    } catch (...) {
        logError("Unknown exception occurred");
    }

    espeak_Terminate();
}

#endif // ESPEAKNG_H
