#include <iostream>
#include "Warrior.h"
using namespace std;

	Warrior::Warrior() {

		dodge = 90;
		stamina = 10;
		fortified = false;
	}

	Warrior::Warrior(string weapon_type, string armor_type, string name1,string type) :Character(weapon_type, armor_type, name1, type) {

		dodge = 90;
		stamina = 10;
		fortified = false;
		if (getWeapon() == "Light Sword") {
			attack = 18;
			stamina += 1;
			dodge -= 10;
		}
		if (getWeapon() == "Heavy Sword") {
			attack = 28;
			stamina -= 1;

		}
		if (getArmor() == "Light Armor") {
			health = 110;
			stamina += 1;
			dodge -= 10;
		}
		if (getArmor() == "Heavy Armor") {
			health = 120;
			stamina -= 1;
		}


	}
	void Warrior::setFortified(bool x) {
		fortified = x;
	}
	void Warrior::setPosition(string x) {
		string y;
		if (x == "1") {
			y = "hills";
			attack += 10;
			stamina -= 3;
		}
		if (x == "2") {
			y = "plains";
			attack -= 10;
		}
		position = y;
	}
	void Warrior::setHealth(int damage) {
		health = health - damage;
	}
	void Warrior::addHealth(int newHealth) {

		if (health + newHealth > 100) {
			health = 100;
		}
		else {
			health += newHealth;
		}


	}
	void Warrior::setDodge(int x) {
		dodge = x;
	}
	void Warrior::setStamina(int x) {
		stamina = x;
	}
	int Warrior::getHealth() {
		return health;
	}
	int Warrior::getAttack() {
		stamina -= 2;
		return attack;
	}
	int Warrior::getDodge() {
		return dodge;
	}
	int Warrior::getStamina() {
		return stamina;
	}
	bool Warrior::getFortified() {
		return fortified;
	}
	string Warrior::getPosition() {
		return position;
	}



	void Warrior::print() {
		cout << "Warrior active" << endl;

	}

