#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Абстрактный базовый класс персонажа в игровой системе
 */
class Character {
public:
    /**
     * @brief Получить тип персонажа.
     * @return Строка с названием типа персонажа
     */
    virtual string getType() = 0;

    /**
     * @brief Получить имя персонажа.
     * @return Строка с именем персонажа (по умолчанию возвращает тип)
     */
    virtual string getName() { return getType(); }

    /**
     * @brief Выполнить атаку персонажа.
     */
    virtual void attack() = 0;

    /**
     * @brief Получить количество здоровья персонажа.
     * @return Целочисленное значение здоровья
     */
    virtual int getHealth() = 0;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Character() {}
};

/**
 * @brief Класс персонажа "Воин".
 */
class Warrior : public Character {
public:
    /**
     * @brief Получить тип персонажа.
     * @return Строка "Воин"
     */
    string getType() override { return "Воин"; }

    /**
     * @brief Выполнить атаку воина.
     * Выводит сообщение об атаке мечом.
     */
    void attack() override { cout << "Воин атакует мечом!" << endl; }

    /**
     * @brief Получить здоровье воина.
     * @return Значение здоровья (100)
     */
    int getHealth() override { return 100; }
};

/**
 * @brief Класс персонажа "Маг".
 */
class Mage : public Character {
public:
    /**
     * @brief Получить тип персонажа.
     * @return Строка "Маг"
     */
    string getType() override { return "Маг"; }

    /**
     * @brief Выполнить атаку мага.
     */
    void attack() override { cout << "Маг кастует огненный шар!" << endl; }

    /**
     * @brief Получить здоровье мага.
     * @return Значение здоровья (50)
     */
    int getHealth() override { return 50; }
};

/**
 * @brief Класс персонажа "Лучник".
 */
class Archer : public Character {
public:
    /**
     * @brief Получить тип персонажа.
     * @return Строка "Лучник"
     */
    string getType() override { return "Лучник"; }

    /**
     * @brief Выполнить атаку лучника.
     */
    void attack() override { cout << "Лучник стреляет из лука!" << endl; }

    /**
     * @brief Получить здоровье лучника.
     * @return Значение здоровья (70)
     */
    int getHealth() override { return 70; }
};

/**
 * @brief Класс персонажа "Рыцарь".
 */
class Knight : public Character {
public:
    /**
     * @brief Получить тип персонажа.
     * @return Строка "Рыцарь"
     */
    string getType() override { return "Рыцарь"; }

    /**
     * @brief Выполнить атаку рыцаря.
     */
    void attack() override { cout << "Рыцарь атакует копьём!" << endl; }

    /**
     * @brief Получить здоровье рыцаря.
     * @return Значение здоровья (80)
     */
    int getHealth() override { return 80; }
};

/**
 * @brief Абстрактная фабрика для создания персонажей.
 */
class CharacterFactory {
public:
    /**
     * @brief Создать персонажа.
     * @return Указатель на созданный объект персонажа
     */
    virtual Character* createCharacter() = 0;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~CharacterFactory() {}

    /**
     * @brief Создать персонажа и выполнить его атаку.
     */
    void spawnAndAttack() {
        Character* chara = createCharacter();
        cout << "Создан " << chara->getName() << " с здоровьем " << chara->getHealth() << ". ";
        chara->attack();
        delete chara;
    }
};

/**
 * @brief Фабрика для создания воинов.
 */
class WarriorFactory : public CharacterFactory {
public:
    /**
     * @brief Создать персонажа-воина.
     * @return Указатель на новый объект Warrior
     */
    Character* createCharacter() override { return new Warrior(); }
};

/**
 * @brief Фабрика для создания магов.
 */
class MageFactory : public CharacterFactory {
public:
    /**
     * @brief Создать персонажа-мага.
     * @return Указатель на новый объект Mage
     */
    Character* createCharacter() override { return new Mage(); }
};

/**
 * @brief Фабрика для создания лучников.
 */
class ArcherFactory : public CharacterFactory {
public:
    /**
     * @brief Создать персонажа-лучника.
     * @return Указатель на новый объект Archer
     */
    Character* createCharacter() override { return new Archer(); }
};

/**
 * @brief Фабрика для создания рыцарей.
 */
class KnightFactory : public CharacterFactory {
public:
    /**
     * @brief Создать персонажа-рыцаря.
     * @return Указатель на новый объект Knight
     */
    Character* createCharacter() override { return new Knight(); }
};

    int main() {
        setlocale(LC_ALL, "rus");

        CharacterFactory* factory = new WarriorFactory();
        factory->spawnAndAttack();
        delete factory;

        factory = new MageFactory();
        factory->spawnAndAttack();
        delete factory;

        factory = new ArcherFactory();
        factory->spawnAndAttack();
        delete factory;

        factory = new KnightFactory();
        factory->spawnAndAttack();
        delete factory;

        return 0;
    }