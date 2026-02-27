#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Абстрактный базовый класс напитка.
 */
class Beverage {
public:
    /**
     * @brief Получить описание напитка.
     * @return Строка с описанием напитка
     */
    virtual string getDescription() = 0;

    /**
     * @brief Получить стоимость напитка.
     * @return Стоимость напитка в долларах
     */
    virtual double cost() = 0;

    /**
     * @brief Виртуальный деструктор.
     */
    virtual ~Beverage() {}
};

/**
 * @brief Конкретный напиток "Эспрессо".
 */
class Espresso : public Beverage {
public:
    /**
     * @brief Получить описание эспрессо.
     * @return Строка "Эспрессо"
     */
    string getDescription() override { return "Эспрессо"; }

    /**
     * @brief Получить стоимость эспрессо.
     * @return Стоимость 1.99
     */
    double cost() override { return 1.99; }
};

/**
 * @brief Конкретный напиток "Чай".
 *
 * Базовая реализация чая без добавок.
 */
class Tea : public Beverage {
public:
    /**
     * @brief Получить описание чая.
     * @return Строка "Чай"
     */
    string getDescription() override { return "Чай"; }

    /**
     * @brief Получить стоимость чая.
     * @return Стоимость 1.50
     */
    double cost() override { return 1.50; }
};

/**
 * @brief Абстрактный базовый класс декоратора для добавок.
 */
class CondimentDecorator : public Beverage {
protected:
    Beverage* beverage;  

public:
    /**
     * @brief Конструктор декоратора.
     * @param b Указатель на напиток, который нужно декорировать
     */
    CondimentDecorator(Beverage* b) : beverage(b) {}

    /**
     * @brief Получить описание декорируемого напитка.
     * @return Описание базового напитка
     */
    string getDescription() override { return beverage->getDescription(); }

    /**
     * @brief Получить стоимость декорируемого напитка.
     * @return Стоимость базового напитка
     */
    double cost() override { return beverage->cost(); }
};

/**
 * @brief Декоратор "Молоко".
 *
 * Добавляет молоко к напитку.
 * Увеличивает стоимость на 0.10 и добавляет соответствующее описание.
 */
class Milk : public CondimentDecorator {
public:
    /**
     * @brief Конструктор декоратора молока.
     * @param b Указатель на напиток, к которому добавляется молоко
     */
    Milk(Beverage* b) : CondimentDecorator(b) {}

    /**
     * @brief Получить описание напитка с молоком.
     * @return Описание базового напитка с добавкой ", Молоко"
     */
    string getDescription() override { return beverage->getDescription() + ", Молоко"; }

    /**
     * @brief Получить стоимость напитка с молоком.
     * @return Стоимость базового напитка + 0.10
     */
    double cost() override { return beverage->cost() + 0.10; }
};

/**
 * @brief Декоратор "Сахар".
 *
 * Добавляет сахар к напитку.
 * Увеличивает стоимость на 0.05 и добавляет соответствующее описание.
 */
class Sugar : public CondimentDecorator {
public:
    /**
     * @brief Конструктор декоратора сахара.
     * @param b Указатель на напиток, к которому добавляется сахар
     */
    Sugar(Beverage* b) : CondimentDecorator(b) {}

    /**
     * @brief Получить описание напитка с сахаром.
     * @return Описание базового напитка с добавкой ", Сахар"
     */
    string getDescription() override { return beverage->getDescription() + ", Сахар"; }

    /**
     * @brief Получить стоимость напитка с сахаром.
     * @return Стоимость базового напитка + 0.05
     */
    double cost() override { return beverage->cost() + 0.05; }
};

/**
 * @brief Декоратор "Сироп".
 *
 * Добавляет сироп к напитку.
 * Увеличивает стоимость на 0.15 и добавляет соответствующее описание.
 */
class Syrup : public CondimentDecorator {
public:
    /**
     * @brief Конструктор декоратора сиропа.
     * @param b Указатель на напиток, к которому добавляется сироп
     */
    Syrup(Beverage* b) : CondimentDecorator(b) {}

    /**
     * @brief Получить описание напитка с сиропом.
     * @return Описание базового напитка с добавкой ", Сироп"
     */
    string getDescription() override { return beverage->getDescription() + ", Сироп"; }

    /**
     * @brief Получить стоимость напитка с сиропом.
     * @return Стоимость базового напитка + 0.15
     */
    double cost() override { return beverage->cost() + 0.15; }
};

/**
 * @brief Декоратор "Шоколад".
 *
 * Добавляет шоколад к напитку.
 * Увеличивает стоимость на 0.20 и добавляет соответствующее описание.
 */
class Chocolate : public CondimentDecorator {
public:
    /**
     * @brief Конструктор декоратора шоколада.
     * @param b Указатель на напиток, к которому добавляется шоколад
     */
    Chocolate(Beverage* b) : CondimentDecorator(b) {}

    /**
     * @brief Получить описание напитка с шоколадом.
     * @return Описание базового напитка с добавкой ", Шоколад"
     */
    string getDescription() override { return beverage->getDescription() + ", Шоколад"; }

    /**
     * @brief Получить стоимость напитка с шоколадом.
     * @return Стоимость базового напитка + 0.20
     */
    double cost() override { return beverage->cost() + 0.20; }
};
int main()
{
    setlocale(LC_ALL, "rus");
    Beverage* drink1 = new Espresso();
    drink1 = new Milk(drink1);
    drink1 = new Sugar(drink1);
    drink1 = new Chocolate(drink1);
    cout << drink1->getDescription() << " стоит $" << drink1->cost() << endl;
    Beverage* drink2 = new Tea();
    drink2 = new Milk(drink2);
    drink2 = new Syrup(drink2);
    cout << drink2->getDescription() << " стоит $" << drink2->cost() << endl;
    Beverage* simpleTea = new Tea();
    cout << simpleTea->getDescription() << " стоит $" << simpleTea->cost() << endl;
    delete drink1;
    delete drink2;
    delete simpleTea;
    return 0;
}