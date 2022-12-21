#pragma once
#include "Character.h"

class Archer : public Character {

public:

	Archer();
	Archer(string, string, string,string);
	Archer(string, string, string, string, string, string, string, string, string, string);
	
	int getHealth();
	int getAttack();
	int getDodge();
	int getStamina();
	bool getFortified();
	string getPosition();

	void setHealth(int );
	void setDodge(int );
	void setStamina(int );
	void setFortified(bool);
	void setPosition(string);
	void addHealth(int);
	void print();


private:

	int attack;
	int health;
	int stamina;
	int dodge;
	bool fortified;
	string position;

};
