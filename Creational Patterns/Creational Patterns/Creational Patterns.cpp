#include <iostream>
#include <string>
using namespace std;
class Character
{
public:
	virtual std::string getType() = 0;
	virtual void attack() = 0;

};
class Warrior : public Character {
public:
	string getType() override { return "Воин"; }
	void attack() override { cout << "воин атакует мечом!" << endl; }

};
class Mage : public Character {
public:
	string getType() override { return "Маг"; }
	void attack() override { cout << "Маг кастует перекрут яичек!" << endl; }
};
class Archer : public Character {
public:
	string getType() override { return "Лучник"; }
	void attack() override { cout << "Лучник стреляет из лука!" << endl; }
};
class CharacterFactory {
public:
	virtual Character* createCharacter() = 0;
	void spawnAndAttack() {
		Character* chara = createCharacter();
		cout << "Создан " << chara->getType() << ". ";
		chara->attack();
		delete chara;
	}
};
class WarriorFactory : public CharacterFactory {
public:
	Character* createCharacter() override { return new Warrior(); }
};

class MageFactory : public CharacterFactory {
public:
	Character* createCharacter() override { return new Mage(); }
};

class ArcherFactory : public CharacterFactory {
public:
	Character* createCharacter() override { return new Archer(); }
};

int main() {
	setlocale(0, "");
	CharacterFactory* factory = new WarriorFactory();
	factory->spawnAndAttack();
	delete factory;

	factory = new MageFactory();
	factory->spawnAndAttack();
	delete factory;

	factory = new ArcherFactory();
	factory->spawnAndAttack();
	
	delete factory;


}
