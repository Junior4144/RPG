#include <iostream>
#include "Character.h"
using namespace std;

Character::Character() {


}

Character::Character(string weapon_type, string armor_type, string name1, string type1) {

	weapon = weapon_type;
	armor = armor_type;
	name = name1;
	type = type1;
}
string Character::getWeapon() {
	return weapon;

}
string Character::getArmor() {

	return armor;
}
string Character::getName() {


	return name;
}
string Character::getType() {
	return type;
}

void Character::setWeapon(string x) {

	weapon = x;

}
void Character::setArmor(string x) {

	armor = x;

}
void Character::setName(string x) {
	
	name = x;

}
void Character::setType(string x) {
	type = x;
}