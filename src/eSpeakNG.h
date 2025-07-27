#ifndef ESPEAKNG_H
#define ESPEAKNG_H

#include <iostream>
#include <string>
#include <espeak-ng/speak_lib.h>

void speakText(const std::string &text) {
    if (espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, nullptr, 0) == -1) {
        std::cerr << "Ошибка инициализации eSpeak NG!" << std::endl;
        return;
    }

    espeak_SetVoiceByName("en");
    espeak_SetParameter(espeakRATE, 150, 0); // Скорость воспроизведения
    espeak_SetParameter(espeakPITCH, 48, 0); // Тон голоса

    // Озвучивание текста
    espeak_Synth(
        text.c_str(),       // Текст для озвучки
        text.size() + 1,    // Длина текста (+1 для нуль-терминатора)
        0,                  // Позиция начала (0 — с начала)
        POS_CHARACTER,      // Тип позиционирования (по символам)
        0,                  // Явный конец речи (0 — автоматически)
        espeakCHARS_AUTO,   // Флаги (автоопределение кодировки)
        nullptr,            // Уникальный идентификатор сообщения
        nullptr             // Пользовательские данные
        );

    // Ожидание завершения воспроизведения
    espeak_Synchronize();

    // Завершение работы eSpeak NG
    espeak_Terminate();
}


#endif // ESPEAKNG_H
