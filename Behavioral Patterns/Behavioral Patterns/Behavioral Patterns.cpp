#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
* @brief класс компьютера 
*/
class ComputerSystem {
public:
    /*
    * @brief открывает файл 
    */
    void openFile(const string& file) { cout << "Открываем файл: " << file << endl; }
    /*
    * @brief выключает файл 
    */
    void shutdown() { cout << "Выключаем компьютер" << endl; }
    /*
        @brief nзапускает браузер
    */
    void launchBrowser() { cout << "Запускаем браузер" << endl; }
};

class Command {
public:
    virtual void execute() = 0;
    /*
    * @brief функция отмены команды
    */
    virtual void undo() = 0; 
};
/*
* @brief класс открытия файла
*/
/*
 * @brief Команда открытия файла в компьютерной системе.
 */
    class OpenFileCommand : public Command {
    private:
        ComputerSystem* system;     ///< Указатель на компьютерную систему, в которой выполняется команда
        string filename;            ///< Имя файла для открытия

    public:
        /**
         * @brief Конструктор команды открытия файла.
         * @param s Указатель на компьютерную систему
         * @param fn Имя файла для открытия
         */
        OpenFileCommand(ComputerSystem* s, const string& fn) : system(s), filename(fn) {}

        /**
         * @brief Выполняет команду открытия файла.
         * Делегирует выполнение операции методу openFile компьютерной системы.
         */
        void execute() override {
            system->openFile(filename);
        }

        /**
         * @brief Отменяет выполнение команды открытия файла.
         * Выводит сообщение о закрытии файла (имитация отмены операции).
         */
        void undo() override { cout << "Закрываем файл " << filename << endl; }
};

/**
 * @brief Команда выключения компьютерной системы.
 */
class ShutdownCommand : public Command {
private:
    ComputerSystem* system;

public:
    /**
     * @brief Конструктор команды выключения.
     * @param s Указатель на компьютерную систему
     */
    ShutdownCommand(ComputerSystem* s) : system(s) {}

    /**
     * @brief Выполняет команду выключения системы.
     */
    void execute() override { system->shutdown(); }

    /**
     * @brief Отменяет выключение системы.
     */
    void undo() override { cout << "Отмена: Включаем компьютер обратно" << endl; }
};

/**
 * @brief Команда запуска веб-браузера.
 */
class LaunchBrowserCommand : public Command {
private:
    ComputerSystem* system;     ///< Указатель на компьютерную систему

public:
    /**
     * @brief Конструктор команды запуска браузера.
     * @param s Указатель на компьютерную систему
     */
    LaunchBrowserCommand(ComputerSystem* s) : system(s) {}

    /**
     * @brief Выполняет команду запуска браузера.
     */
    void execute() override { system->launchBrowser(); }

    /**
     * @brief Отменяет запуск браузера.
     */
    void undo() override { cout << "Закрываем браузер" << endl; }
};

/**
 * @brief Пульт дистанционного управления для выполнения команд.
 *
 */
class RemoteControl {
private:
    vector<Command*> commands;  ///< Вектор указателей на команды для выполнения

public:
    /**
     * @brief Добавляет новую команду в список выполняемых.
     * @param cmd Указатель на команду для добавления
     */
    void addCommand(Command* cmd) { commands.push_back(cmd); }

    /**
     * @brief Выполняет все добавленные команды последовательно.
     */
    void pressButton() {
        for (auto cmd : commands)
        {
            cmd->execute();
        }
    }

    /**
     * @brief Отменяет последнюю выполненную команду.
     */
    void undoLast() {
        if (!commands.empty())
        {
            commands.back()->undo();
            commands.pop_back();
        }
    }
};
```

int main()
{
    setlocale(LC_ALL, "ru");
    ComputerSystem system;
    Command* openCmd = new OpenFileCommand(&system, "document.txt");
    Command* shutdownCmd = new ShutdownCommand(&system);
    Command* browserCmd = new LaunchBrowserCommand(&system);
    RemoteControl remote;
    remote.addCommand(openCmd);
    remote.addCommand(browserCmd);
    remote.addCommand(shutdownCmd);
    remote.pressButton();  
    remote.undoLast();
    delete openCmd;
    delete shutdownCmd;
    delete browserCmd;
}