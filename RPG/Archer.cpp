#include <iostream>
#include <string>
using namespace std;
#include "Archer.h"


Archer::Archer() {

	dodge = 80;
	stamina = 11;
	fortified = false;
}

Archer::Archer(string weapon_type,string armor_type,string name1,string type):Character(weapon_type, armor_type, name1, type) {

	dodge = 80;
	stamina = 12;
	fortified = false;
	if (getWeapon() == "Light Bow") {
		attack = 15;
		stamina += 1;
		dodge -= 10;
	}
	if (getWeapon() == "Heavy Bow") {
		attack = 20;
		stamina -= 1;
		
	}
	if (getArmor() == "Light Armor") {
		health = 100;
		stamina += 1;
		dodge -= 10;
	}
	if (getArmor() == "Heavy Armor") {
		health = 120;
		stamina -= 1;
	}


}
Archer::Archer(string weapon_type, string armor_type, string name1, string type, string attack, string health, string stamina, string dodge, string fortified, string position) :Character(weapon_type, armor_type, name1, type) {

	 this->attack = stoi(attack);
	 this->health = stoi(health);
	 this->stamina = stoi(stamina);
	 this->dodge = stoi(dodge);
	 this->fortified = stoi(fortified);
	 this->position = stoi(position);
}


void Archer::setFortified(bool x) {
	fortified = x;
}
void Archer::setPosition(string x) {
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
void Archer::setHealth(int damage) {
	health = health - damage;
}
void Archer::addHealth(int newHealth) {

	if (health + newHealth > 100) {
		health = 100;
	}
	else{
		health += newHealth;
	}
	

}
void Archer::setDodge(int x) {
	dodge = x;
}
void Archer::setStamina(int x) {
	stamina = x;
}
int Archer::getHealth() {
	return health;
}
int Archer::getAttack() {
	stamina -= 1;
	return attack;
}
int Archer::getDodge() {
	return dodge;
}
int Archer::getStamina() {
	return stamina;
}
bool Archer::getFortified() {
	return fortified;
}
string Archer::getPosition() {
	return position;
}



void Archer::print() {
	cout << "archer active" << endl;

}

