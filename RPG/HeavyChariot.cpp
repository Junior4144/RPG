#include <iostream>
#include "HeavyChariot.h"
using namespace std;



	HeavyChariot::HeavyChariot() {

		dodge = 90;
		stamina = 10;
		fortified = false;
	}

	HeavyChariot::HeavyChariot(string weapon_type, string armor_type, string name1,string type) :Character(weapon_type, armor_type, name1, type) {

		dodge = 90;
		stamina = 10;
		fortified = false;
		if (getWeapon() == "Light Spear") {
			attack = 20;
			stamina += 1;
			dodge -= 3;
		}
		if (getWeapon() == "Heavy Spear") {
			attack = 30;
			stamina -= 1;

		}
		if (getArmor() == "Light Armor") {
			health = 120;
			stamina += 1;
			dodge -= 3;
		}
		if (getArmor() == "Heavy Armor") {
			health = 130;
			stamina -= 1;
		}


	}
	void HeavyChariot::setFortified(bool x) {
		fortified = x;
	}
	void HeavyChariot::setPosition(string x) {
		string y;
		if (x == "1") {
			y = "hills";
			attack -= 10;
			stamina -= 5;
		}
		if (x == "2") {
			y = "plains";
			attack += 10;
		}
		position = y;
	}
	void HeavyChariot::setHealth(int damage) {
		health = health - damage;
	}
	void HeavyChariot::addHealth(int newHealth) {

		if (health + newHealth > 100) {
			health = 100;
		}
		else {
			health += newHealth;
		}


	}
	void HeavyChariot::setDodge(int x) {
		dodge = x;
	}
	void HeavyChariot::setStamina(int x) {
		stamina = x;
	}
	int HeavyChariot::getHealth() {
		return health;
	}
	int HeavyChariot::getAttack() {
		stamina -= 3;
		return attack;
	}
	int HeavyChariot::getDodge() {
		return dodge;
	}
	int HeavyChariot::getStamina() {
		return stamina;
	}
	bool HeavyChariot::getFortified() {
		return fortified;
	}
	string HeavyChariot::getPosition() {
		return position;
	}



	void HeavyChariot::print() {
		cout << "Warrior active" << endl;

	}



