# English-cards
Приложение для изучения английского по карточками с функцией озвучивания английских слов

# Стек технологий
- **QT** - GUI
- **eSpeak-NG** - движок синтеза речи
- **nlohmann/json** - работа с JSON
- **C++17** 

## Зависимости 
### Общие для всех платформ 

- **C++17** - или новее
- **Qt** - 6.x
- **nlohmann/json** - заголовочная библиотека 

### Платформенные зависимости
| ОС | Зависимости |
|----|-------------|
| **Linux** | `libespeak-ng-dev` |
| **Windows** | `libespeak-ng.dll` + `espeak-ng-data` |

## Сборка на Linux (Ubuntu/Debian)

### Устновка зависимостей
```bash
sudo apt update
sudo apt install -y build-essential qtbase5-dev libespeak-ng-dev
```

### Сборка проекта
```bash
git clone https://github.com/GreeAI/English-cards.git
cd English-cards
qmake
make -j$(nproc)
```

### Запуск
```bash
./EnglishCards
```

## Сборка для Windows
### Установите QT с qmake

### Установка [eSpeak-NG](https://github.com/espeak-ng/espeak-ng/releases/tag/1.52.0)

### Клонирование репозитория
```cmd
git clone https://github.com/GreeAI/English-cards.git
```

### Сборка через QT
1. Откройте файл .pro в Qt Creator.
2. Выберите комплект (Kit) с вашим компилятором (MinGW/MSVC).
3. Нажмите Собрать (Ctrl+B).
4. Запустите (Ctrl+R)

## Скачать установщик для приложения (Только Windows!)
### Установить [eSpeak-NG.msi](https://github.com/espeak-ng/espeak-ng/releases/tag/1.52.0)
### Установить программу [LEG_GreeAI](https://github.com/GreeAI/English-cards/releases/tag/1.0)

# Работа в приложение

## Перевод карточек
Чтобы получить API и Folder ключи, нужно зарегистрироваться в Yandex.Cloud и выполнить шаги, которые прописаны [здесь](https://yandex.cloud/ru/docs/translate/quickstart).

После регистрации вы получите:

API-ключ для доступа к сервису перевода

Folder ID (идентификатор каталога)

Эти данные потребуются для настройки функции перевода в приложении.
