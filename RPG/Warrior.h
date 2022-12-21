#pragma once

#include "Character.h"
class Warrior: public Character {

public:
	Warrior();
	Warrior(string, string, string,string);
	void print();

	int getHealth();
	int getAttack();
	int getDodge();
	int getStamina();
	bool getFortified();
	string getPosition();

	void setHealth(int);
	void setDodge(int);
	void setStamina(int);
	void setFortified(bool);
	void setPosition(string);
	void addHealth(int);



private:

	int attack;
	int health;
	int stamina;
	int dodge;
	bool fortified;
	string position;



};