#pragma once

#include <iostream>
using namespace std;

class Character {

public:
	Character();
	Character(string,string,string,string);
	void setWeapon(string);
	void setArmor(string);
	void setName(string);
	void setType(string);
	string getWeapon();
	string getArmor();
	string getName();
	string getType();
	virtual int getAttack() = 0;

	virtual int getHealth() = 0;
	virtual void setHealth(int ) = 0;

	virtual int getStamina() = 0;
	virtual void setStamina(int) = 0;

	virtual int getDodge() = 0;
	virtual void setDodge(int) = 0;

	virtual bool getFortified() = 0;
	virtual void setFortified(bool) = 0;

	virtual string getPosition() = 0;
	virtual void setPosition(string) = 0;

	virtual void addHealth(int) = 0;

	

private:

	string weapon;
	string armor;
	string name;
	string type;
	
	//maybe add mode and Position


};
