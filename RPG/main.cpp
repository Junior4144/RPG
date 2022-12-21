#include "Archer.h"
#include "Character.h"
#include "HeavyChariot.h"
#include "Warrior.h"


#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>
using namespace std;

void newGame();
void firstData();
void secondData();
void battle();
vector<Character*> user;
void attack(int);
int main();
void conPresviousGame();

void saveGame(int current, int other) {

	string gameFile;
	cout << "-----------------------------------------------" << endl;
	cout << "Please type the name of file that will store the game data" << endl;
	cout << "-----------------------------------------------" << endl;
	cin >> gameFile;
	cout << "-----------------------------------------------" << endl;
	gameFile.append(".txt");


	ofstream out(gameFile);
	
	out << "Game Verification" << endl;
	out << user[current]->getWeapon() << endl;
	out << user[current]->getArmor() << endl;
	out << user[current]->getName() << endl;
	out << user[current]->getAttack() << endl;
	out << user[current]->getHealth() << endl;
	out << user[current]->getStamina() << endl;
	out << user[current]->getDodge() << endl;
	out << user[current]->getFortified() << endl;
	out << user[current]->getPosition() << endl;
	out << user[other]->getWeapon() << endl;
	out << user[other]->getArmor() << endl;
	out << user[other]->getName() << endl;
	out << user[other]->getAttack() << endl;
	out << user[other]->getHealth() << endl;
	out << user[other]->getStamina() << endl;
	out << user[other]->getDodge() << endl;
	out << user[other]->getFortified() << endl;
	out << user[other]->getPosition() << endl;


	out.close();
	
	
}

void conData() {

	string firstFile;
	string verifiy;
	bool x = false;
	getline(cin, firstFile);
	//cin >> firstFile;

	firstFile.append(".txt");

	ifstream in;
	in.open(firstFile);

	getline(in, verifiy);
	if (verifiy == "Game Verification") {
		x = true;
	}

	
	if (x == true) {
		if (in.is_open()) {
			cout << "-----------------------------------------------" << endl;
			cout << endl;
			cout << endl;
			cout << "-----------------------------------------------" << endl;
			cout << "This game includes the following:" << endl;

			cout << "-----------------------------------------------" << endl;
			cout << "Character 1:" << endl;
			cout << "-----------------------------------------------" << endl;

			string class_type;
			getline(in, class_type);



			cout << "Character type: " << class_type << endl;
			cout << "-----------------------------------------------" << endl;




			//weapon
			string weapon_type;
			getline(in, weapon_type);
			cout << "Weapon: " << weapon_type << endl;
			cout << "-----------------------------------------------" << endl;

			//armor
			string armor_type;
			getline(in, armor_type);
			cout << "Armor: " << armor_type << endl;
			cout << "-----------------------------------------------" << endl;

			//name
			string name;
			getline(in, name);

			cout << "The name of first character is " << name << endl;

			cout << "-----------------------------------------------" << endl;


			string attack;
			getline(in, attack);
			cout << "Attack: " << attack << endl;
			cout << "-----------------------------------------------" << endl;
			string health;
			getline(in, health);
			cout << "Health: " << health << endl;
			cout << "-----------------------------------------------" << endl;
			string stamina;
			getline(in, stamina);
			cout << "Stamina: " << stamina << endl;
			cout << "-----------------------------------------------" << endl;

			string dodge;
			getline(in, dodge);

			string fortified;
			getline(in, fortified);

			string position;
			getline(in, position);
			cout << "Position: " << position << endl;
			cout << "-----------------------------------------------" << endl;

			cout << endl;




			if (class_type == "Archer") {

				user.push_back(new Archer(weapon_type, armor_type, name, class_type, attack, health, stamina, dodge, fortified, position));
			}
			if (class_type == "Warrior") {
				user.push_back(new Warrior(weapon_type, armor_type, name, class_type));
			}
			if (class_type == "Heavy Chariot") {
				user.push_back(new HeavyChariot(weapon_type, armor_type, name, class_type));

			}

			cout << "-----------------------------------------------" << endl;
			cout << "Character 2:" << endl;
			cout << "-----------------------------------------------" << endl;

			
			getline(in, class_type);



			cout << "Character type: " << class_type << endl;
			cout << "-----------------------------------------------" << endl;




			//weapon
			
			getline(in, weapon_type);
			cout << "Weapon: " << weapon_type << endl;
			cout << "-----------------------------------------------" << endl;

			//armor
			
			getline(in, armor_type);
			cout << "Armor: " << armor_type << endl;
			cout << "-----------------------------------------------" << endl;

			//name
			
			getline(in, name);

			cout << "The name of second character is " << name << endl;

			cout << "-----------------------------------------------" << endl;


			
			getline(in, attack);
			cout << "Attack: " << attack << endl;
			cout << "-----------------------------------------------" << endl;
			
			getline(in, health);
			cout << "Health: " << health << endl;
			cout << "-----------------------------------------------" << endl;
			
			getline(in, stamina);
			cout << "Stamina: " << stamina << endl;
			cout << "-----------------------------------------------" << endl;

			
			getline(in, dodge);

			
			getline(in, fortified);

			
			getline(in, position);
			cout << "Position: " << position << endl;
			cout << "-----------------------------------------------" << endl;

			cout << endl;




			if (class_type == "Archer") {

				user.push_back(new Archer(weapon_type, armor_type, name, class_type, attack, health, stamina, dodge, fortified, position));
			}
			if (class_type == "Warrior") {
				user.push_back(new Warrior(weapon_type, armor_type, name, class_type));
			}
			if (class_type == "Heavy Chariot") {
				user.push_back(new HeavyChariot(weapon_type, armor_type, name, class_type));
			}



			//Creation of the object 

			//added to vector 
			//this would allow for access of virtual function with each derived class I 
			//can access health, dodge, etc.
			// this would also make it easier to change between current player and next player
			//as this game is turn based.
			in.close();



		}
		else {
			cout << "-----------------------------------------------" << endl;
			cout << "unable to open game file" << endl;
			cout << "-----------------------------------------------" << endl;

			conPresviousGame();

		}
	}
	else {
	cout << "-----------------------------------------------" << endl;
	cout << "This file doesn't contain game information" << endl;
	cout << "-----------------------------------------------" << endl;
	conPresviousGame();
}
}

void conPresviousGame() {


	cout << "-----------------------------------------------" << endl;
	cout << "Please type the name of the game file" << endl;
	cout << "-----------------------------------------------" << endl;




	conData();

	//Second player data
	

	battle();

	

}

void archerData() {
	cout << "-----------------------------------------------" << endl;
	cout << "The archer is a agile and movement based class." << endl;
	cout << "They produce weak attack power, however have high stamina and high dodge potential." << endl;
	cout << endl;
	cout << "Default archer health: 100" << endl;
	cout << "Default archer damage turn turn: 15" << endl;
	cout << "Default dodge chance: 20%" << endl;
	cout << "Default stamina: 12" << endl;
	cout << "-----------------------------------------------" << endl;
	
}
void warriorData() {
	cout << "-----------------------------------------------" << endl;
	cout << "The warrior is a mid ground class capable of speed and strength." << endl;
	cout << "They produce moderate attack power and have moderate stamina and dodge potential." << endl; 
	cout << endl;
	cout << "Default warrior health: 110" << endl;
	cout << "Default warrior damage turn turn: 18" << endl;
	cout << "Default warrior dodge chance: 10%" << endl;
	cout << "Default warrior stamina: 10" << endl;
	cout << "-----------------------------------------------" << endl;
}
void heavyChariotData() {
	cout << "-----------------------------------------------" << endl;
	cout << "The Heavy Chariot is a strength base class." << endl;
	cout << "They produce strong attack power and have modernate dodge potential." << endl;
	cout << "They have modernate stamina, however their attack cost are high." << endl; 
	cout << endl;
	cout << "Default Heavy Chariot  health: 120" << endl;
	cout << "Default Heavy Chariot  damage turn turn: 20" << endl;
	cout << "Default Heavy Chariot dodge chance: 10%" << endl;
	cout << "Default Heavy Chariot stamina: 10" << endl;
	cout << "-----------------------------------------------" << endl;

}
void addData() {

	string firstFile;
	
	getline(cin, firstFile);
	//cin >> firstFile;

	firstFile.append(".txt");

	ifstream in;
	in.open(firstFile);

	if (in.is_open()) {
		cout << "-----------------------------------------------" << endl;
		cout << endl;
		cout << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "This character includes the following:" << endl;
		cout << "-----------------------------------------------" << endl;


		string class_type;
		getline(in, class_type);
		


		cout << "Character type: " << class_type << endl;
		cout << "-----------------------------------------------" << endl;




		//weapon
		string weapon_type;
		getline(in, weapon_type);
		cout << "Weapon: " << weapon_type << endl;
		cout << "-----------------------------------------------" << endl;

		//armor
		string armor_type;
		getline(in, armor_type);
		cout << "Armor: " << armor_type << endl;
		cout << "-----------------------------------------------" << endl;

		//name
		string name;
		getline(in, name);

		cout << "The name of your character is " << name << endl;

		cout << "-----------------------------------------------" << endl;

		cout << endl;
		if (class_type == "Archer") {
			
			user.push_back(new Archer(weapon_type, armor_type, name, class_type));
		}
		if (class_type == "Warrior") {
			user.push_back(new Warrior(weapon_type, armor_type, name, class_type));
		}
		if (class_type == "Heavy Chariot") {
			user.push_back(new HeavyChariot(weapon_type, armor_type, name, class_type));
		}

		//Creation of the object 

		//added to vector 
		//this would allow for access of virtual function with each derived class I 
		//can access health, dodge, etc.
		// this would also make it easier to change between current player and next player
		//as this game is turn based.
		in.close();

		

	}
	else if (user.empty()) {
		cout << "-----------------------------------------------" << endl;
		cout << "unable to open character file" << endl;
		firstData();
	}
	else {
		cout << "-----------------------------------------------" << endl;
		cout << "unable to open character file" << endl;
		//in.close();

		secondData();

	}
}
void selectionMenu() {
	cout << "-----------------------------------------------" << endl;
	cout << "You are now in the character creation screen" << endl;
	cout << endl;
	cout << "Select a class" << endl;
	cout << "1.Archer" << endl;
	cout << "2.Warrior" << endl;
	cout << "3.Heavy Chariot" << endl;
	cout << "-1.Go back to the Main Menu" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Class details" << endl;
	cout << "4.Archer" << endl;
	cout << "5.Warrior" << endl;
	cout << "6.Heavy Chariot" << endl;
	cout << "-----------------------------------------------" << endl;
}

void battleMenu() {
	cout << "-----------------------------------------------" << endl;
	cout << "1.Attack" << endl;
	cout << "2.Fortify" << endl;
	cout << "3.Reposition" << endl;
	cout << "4.End turn" << endl;
	cout << "5.End and save game" << endl;
	cout << "-1.End Game" << endl;
	
	cout << "-----------------------------------------------" << endl;

}
void firstData() {

	cout << "-----------------------------------------------" << endl;
	cout << "Please import your first character" << endl;
	cout << "-----------------------------------------------" << endl;
	addData();
}
void secondData() {
	
	cout << "-----------------------------------------------" << endl;
	cout << "Please import your second character" << endl;
	cout << "-----------------------------------------------" << endl;

	addData();
}

void attack(int currentPlayer) {

	
	if (user[currentPlayer]->getType() == "Archer") {
		cout << user[currentPlayer]->getName() << " draws their bow and releases their arrow" << endl;
	}
	if (user[currentPlayer]->getType() == "Warrior") {
		cout << user[currentPlayer]->getName() << " draws their sword and swings" << endl;
	}
	if (user[currentPlayer]->getType() == "Heavy Chariot") {
		cout << user[currentPlayer]->getName() << " dashes forwards and firmly hold their spears" << endl;
	}
	cout << endl;
}

void battle() {
	
	cout << endl;
	cout << endl;

	int playerAction;


	cout << "-----------------------------------------------" << endl;
	cout << "You are now in the battle arena" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Player 1 will start the battle" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Player 1, select your first move" << endl;
	cout << "-----------------------------------------------" << endl;
	battleMenu();

	cin >> playerAction;
	int damage;
	int currentPlayer = 0;
	int otherPlayer = 1;
	int player = 1;
	int nextPlayer = 2;
	bool retry = false;
	bool death = false;
	int userSelection;

	
	while (playerAction != -1 && playerAction != 10 && playerAction != 20 && death != true && playerAction != -5) {

		//ATTACK-------------
		if (playerAction == 1 && user[currentPlayer]->getFortified() != true) {

			cout << "-----------------------------------------------" << endl;
			damage = user[currentPlayer]->getAttack();

			attack(currentPlayer);

			//DODGE-------------------
			random_device rd;
			uniform_int_distribution<int> dist(1, 100);

			if (dist(rd) > user[otherPlayer]->getDodge()) {
				cout << endl;
				//cout << "dodge : " << user[otherPlayer]->getDodge() << endl;
				damage = 0;
				cout << user[otherPlayer]->getName() << " dodged the attack" << endl;
				cout << endl;
			}
			else {
				cout << user[otherPlayer]->getName() << " was hit!" << endl;
			}
			cout << endl;
			//Damage-----------------------------
			
			cout << user[currentPlayer]->getName() << " did " << damage << " damage!" << endl;

			cout << user[currentPlayer]->getName() << " has " << user[currentPlayer]->getStamina() << " Stamina left!" << endl;
			cout << endl;
			user[otherPlayer]->setHealth(damage);

			cout << user[otherPlayer]->getName() << " has " << user[otherPlayer]->getHealth() << " health left!" << endl;

		}
		if (playerAction == 1 && user[currentPlayer]->getFortified() == true) {

			cout << "-----------------------------------------------" << endl;
			cout << "You are unable to attack because you are Fortified" << endl;
			cout << "-----------------------------------------------" << endl;
			retry = true;
		}
		//FORTIFY
		if (playerAction == 2) {
			cout << "-----------------------------------------------" << endl;
			cout << "Choice one" << endl;
			cout << "1.Fortify" << endl;
			cout << "2.Unfortify" << endl;
			cout << "-----------------------------------------------" << endl;
			cin >> userSelection;

			if (userSelection == 1) {

				if (user[currentPlayer]->getPosition() != "Hill" && user[currentPlayer]->getFortified() != true) {
					user[currentPlayer]->setFortified(true);
					cout << "-----------------------------------------------" << endl;
					cout << "Player " << player << " is now fortified" << endl;
					cout << "You are now unable to attack untill you unfortify" << endl;

				}
				else {
					cout << "-----------------------------------------------" << endl;
					cout << "You are unable to fortify because either on a hill or already fortified" << endl;
					retry = true;

				}
			}
			if (userSelection == 2 && user[currentPlayer]->getFortified() != false) {

				user[currentPlayer]->setFortified(false);
				cout << "-----------------------------------------------" << endl;
				cout << "Player " << player << " is now unfortified" << endl;
				cout << "You are now able to attack on your next turn" << endl;
				cout << "-----------------------------------------------" << endl;
				
			}
			else {
				cout << "-----------------------------------------------" << endl;
				cout << "Player " << player << " is unable to unfortified because " << user[currentPlayer]->getName() << " is already unfortified" << endl;
				cout << "-----------------------------------------------" << endl;
				cout << "Please select your next move" << endl;
				retry = true;
			}




		}
		//REPOSITION
		if (playerAction == 3 && user[currentPlayer]->getFortified() != true) {
			string location;
			cout << "-----------------------------------------------" << endl;
			cout << "Please select location" << endl;
			cout << "1.Hills" << endl;
			cout << "2.Plains" << endl;
			cout << "-----------------------------------------------" << endl;
			cin >> location;



			user[currentPlayer]->setPosition(location);
			cout << "-----------------------------------------------" << endl;
			cout << user[currentPlayer]->getName() << " is now located on " << user[currentPlayer]->getPosition() << endl;
			cout << "You have gain a +10 damage buff" << endl;



		}
		if (playerAction == 3 && user[currentPlayer]->getFortified() == true) {

			cout << "-----------------------------------------------" << endl;
			cout << "You are unable to reposition because you are Fortified" << endl;
			cout << "-----------------------------------------------" << endl;
			retry = true;
		}
		if (playerAction == 4) {
			cout << "-----------------------------------------------" << endl;
			cout << user[currentPlayer]->getName() << " has skipped their turn" << endl;
		}
		if (playerAction == 5) {
			cout << "-----------------------------------------------" << endl;
			cout << "The battle has stopped and the game will now be saved" << endl;
			saveGame(currentPlayer, otherPlayer);
			playerAction = -5;
			retry = true;

		}
		//winner conditions
		if (user[otherPlayer]->getHealth() <= 0) {
			playerAction = 10;
			death = true;
		}
		if (user[otherPlayer]->getStamina() <= 0 || user[currentPlayer]->getStamina() <= 0) {
			playerAction = 20;
			death = true;
		}

		if (retry == false && death != true && playerAction != 5) {

			//Fortified buff
			if (user[otherPlayer]->getFortified() == true && retry == false) {
				cout << "-----------------------------------------------" << endl;
				user[currentPlayer]->addHealth(15);
				cout << user[currentPlayer]->getName() << " has gain 15 health because they are currently foritifed" << endl;
			}
			cout << "-----------------------------------------------" << endl;
			cout << "Player " << player << " turn has ended" << endl;
			cout << endl;
			cout << "Player " << nextPlayer << " please select on of the options:" << endl;

			if (currentPlayer == 0) {
				currentPlayer = 1;
				otherPlayer = 0;
				player = 2;
				nextPlayer = 1;

			}
			else if (currentPlayer == 1) {
				currentPlayer = 0;
				otherPlayer = 1;
				player = 1;
				nextPlayer = 2;
			}



			battleMenu();
			cin >> playerAction;
		}
		if (retry == true && playerAction != -5) {
			battleMenu();
			cin >> playerAction;
			retry = false;

		}


	}
	if (playerAction == -1) {
		cout << "-----------------------------------------------" << endl;
		cout << "The game has been stopped by a player" << endl;
		cout << "-----------------------------------------------" << endl;
		
	}
	
	if (playerAction == 10) {
		cout << "-----------------------------------------------" << endl;
		cout << "The game has concluded" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << user[otherPlayer]->getName() << " has been defeated" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << user[currentPlayer]->getName() << " is the winner" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << user[otherPlayer]->getName() << " died due to insignificant amount of health" << endl;
		
		
	}
	if (playerAction == 20) {
		cout << "-----------------------------------------------" << endl;
		cout << "The game has concluded" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << user[otherPlayer]->getName() << " has been defeated" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << user[currentPlayer]->getName() << " is the winner" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << user[otherPlayer]->getName() << " died due to exhaustion" << endl;
		
		
	}

}


void newGame() {


	cout << "-----------------------------------------------" << endl;
	cout << "You will now import two characters into the battle simulator" << endl;
	cout << "-----------------------------------------------" << endl;

	//First player data
	
	firstData();
	
	//Second player data
	secondData();

	battle();

}
void successCreation() {
	cout << "-----------------------------------------------" << endl;
	cout << "You have successfully created a new character" << endl;
	cout << "-----------------------------------------------" << endl;
}

void CharacterCmenu() {

	//cout << "character menu" << endl;


	string selection;
	int count = 0;
	string weapon = "";
	string armor = "";
	string type = "";
	string selectWeapon;
	string selectArmor;
	string characterName;
	bool retry = false;
	

	selectionMenu();
	
	

	cin >> selection;

	while (selection != "-1") {


		if (selection == "1") {

			cout << "-----------------------------------------------" << endl;
			cout << "You have selected the Archer class" << endl;
			cout << "-----------------------------------------------" << endl;
			//character archer

			//add attribute to a variable add to constructor later
			type = "Archer";

			cout << "-----------------------------------------------" << endl;
			cout << "Select a Weapon" << endl;
			cout << endl;
			cout << "1.Light Bow" << endl;
			cout << "2.Heavy Bow" << endl;
			cout << "-1.Reselect class" << endl;
			cout << "-----------------------------------------------" << endl;

			cin >> selectWeapon;

			if (selectWeapon == "-1") {
				CharacterCmenu();
				retry = true;
			}

			while (selectWeapon != "-1") {


				if (selectWeapon == "1") {
					cout << "-----------------------------------------------" << endl;
					cout << "You have selected the Light Bow as your weapon" << endl;
					cout << "-----------------------------------------------" << endl;
					//add attribute to a variable add to constructor later
					weapon = "Light Bow";
					selectWeapon = "-1";
				}
				else if (selectWeapon == "2") {
					cout << "-----------------------------------------------" << endl;
					cout << "You have selected the Heavy Bow as your weapon" << endl;
					cout << "-----------------------------------------------" << endl;
					//add attribute to a variable add to constructor later
					weapon = "Heavy Bow";
					selectWeapon = "-1";
				}
				else if (selectWeapon != "-1") {
					cout << "-----------------------------------------------" << endl;
					cout << "-----------------------------------------------" << endl;
					cout << "Option unavailable" << endl;

					cout << "-----------------------------------------------" << endl;
					cout << "Select a Weapon" << endl;
					cout << endl;
					cout << "1.Light Bow" << endl;
					cout << "2.Heavy Bow" << endl;
					cout << "-1.Reselect class" << endl;
					cout << "-----------------------------------------------" << endl;
					cin >> selectWeapon;
				}
				else if (selectWeapon == "-1") {
					CharacterCmenu();
					retry = true;
				}
			}




			if (retry == false) {

				cout << "-----------------------------------------------" << endl;
				cout << "Select type of Armor" << endl;
				cout << endl;
				cout << "1.Light Armor" << endl;
				cout << "2.Heavy Armor" << endl;
				cout << "-1.Reselect class" << endl;
				cout << "-----------------------------------------------" << endl;
				cin >> selectArmor;

				if (selectArmor == "-1") {
					CharacterCmenu();
					retry = true;
				}

				while (selectArmor != "-1") {



					if (selectArmor == "1") {
						cout << "-----------------------------------------------" << endl;
						cout << "You have a selected the Light Armor as your armor" << endl;
						cout << "-----------------------------------------------" << endl;
						//add attribute to a variable add to constructor later
						armor = "Light Armor";
						selectArmor = "-1";
					}
					else if (selectArmor == "2") {
						cout << "-----------------------------------------------" << endl;
						cout << "You have a selected the Heavy Armor as your armor" << endl;
						cout << "-----------------------------------------------" << endl;
						//add attribute to a variable add to constructor later
						armor = "Heavy Armor";
						selectArmor = "-1";
					}
					
					else if(selectArmor != "-1") {
						cout << "-----------------------------------------------" << endl;
						cout << "-----------------------------------------------" << endl;
						cout << "Option unavailable" << endl;

						cout << "-----------------------------------------------" << endl;
						cout << "Select a type of Armor" << endl;
						cout << endl;
						cout << "1.Light Armor" << endl;
						cout << "2.Heavy Armor" << endl;
						cout << "-1.Reselect class" << endl;
						cout << "-----------------------------------------------" << endl;
						cin >> selectArmor;
					}
					else if (selectArmor == "-1") {
						CharacterCmenu();
						retry = true;
					}
					
				}
			}
			if (retry == false) {

				cout << "-----------------------------------------------" << endl;
				cout << "Please enter the name of your character" << endl;
				cout << "-----------------------------------------------" << endl;
				cin >> characterName;
				string name = characterName;
				characterName.append(".txt");

				ofstream out;
				out.open(characterName);

				out << type << endl;
				out << weapon << endl;
				out << armor << endl;
				out << name << endl;

				out.close();

				successCreation();
				

				selection = "-1";
			}
			
				selection = "-1";
			
		}

		else if (selection == "2") {
			cout << "-----------------------------------------------" << endl;
			cout << "You have selected the Warrior class" << endl;
			cout << "-----------------------------------------------" << endl;
			//character archer

			//add attribute to a variable add to constructor later
			type = "Warrior";

			cout << "-----------------------------------------------" << endl;
			cout << "Select a Weapon" << endl;
			cout << endl;
			cout << "1.Light Sword" << endl;
			cout << "2.Heavy Sword" << endl;
			cout << "-1.Reselect class" << endl;
			cout << "-----------------------------------------------" << endl;
			// add descriptions
			cin >> selectWeapon;

			if (selectWeapon == "-1") {
				CharacterCmenu();
				retry = true;
			}
			while (selectWeapon != "-1") {

				if (selectWeapon == "1") {
					cout << "-----------------------------------------------" << endl;
					cout << "You have selected the Light Sword as your weapon" << endl;
					cout << "-----------------------------------------------" << endl;
					//add attribute to a variable add to constructor later
					weapon = "Light Sword";
					selectWeapon = "-1";
				}
				else if (selectWeapon == "2") {
					cout << "-----------------------------------------------" << endl;
					cout << "You have selected the Heavy Sword as your weapon" << endl;
					cout << "-----------------------------------------------" << endl;
					//add attribute to a variable add to constructor later
					weapon = "Heavy Sword";
					selectWeapon = "-1";
				}
				else if (selectWeapon != "-1") {
					cout << "-----------------------------------------------" << endl;
					cout << "-----------------------------------------------" << endl;
					cout << "Option unavailable" << endl;

					cout << "-----------------------------------------------" << endl;
					cout << "Select a Weapon" << endl;
					cout << endl;
					cout << "1.Light Sword" << endl;
					cout << "2.Heavy Sword" << endl;
					cout << "-1.Reselect class" << endl;
					cout << "-----------------------------------------------" << endl;
					cin >> selectWeapon;
				}
				else if (selectWeapon == "-1") {
					CharacterCmenu();
					retry = true;
				}
			}

			if (retry == false) {

				cout << "-----------------------------------------------" << endl;
				cout << "Select type of Armor" << endl;
				cout << endl;
				cout << "1.Light Armor" << endl;
				cout << "2.Heavy Armor" << endl;
				cout << "-1.Reselect class" << endl;
				cout << "-----------------------------------------------" << endl;

				cin >> selectArmor;

				if (selectArmor == "-1") {
					CharacterCmenu();
					retry = true;
				}

				while (selectArmor != "-1") {

					if (selectArmor == "1") {
						cout << "-----------------------------------------------" << endl;
						cout << "You have a selected the light armor as your armor" << endl;
						cout << "-----------------------------------------------" << endl;
						//add attribute to a variable add to constructor later
						armor = "Light Armor";
						selectArmor = "-1";
					}
					else if (selectArmor == "2") {
						cout << "-----------------------------------------------" << endl;
						cout << "You have a selected the heavy armor as your armor" << endl;
						cout << "-----------------------------------------------" << endl;
						//add attribute to a variable add to constructor later
						armor = "Heavy armor";
						selectArmor = "-1";
					}
					else if (selectArmor != "-1") {
						cout << "-----------------------------------------------" << endl;
						cout << "-----------------------------------------------" << endl;
						cout << "Option unavailable" << endl;

						cout << "-----------------------------------------------" << endl;
						cout << "Select a type of Armor" << endl;
						cout << endl;
						cout << "1.Light Armor" << endl;
						cout << "2.Heavy Armor" << endl;
						cout << "-1.Reselect class" << endl;
						cout << "-----------------------------------------------" << endl;
						cin >> selectArmor;
					}
					else if (selectArmor == "-1") {
						CharacterCmenu();
						retry = true;
					}
				}
			}
			if (retry == false) {

				cout << "-----------------------------------------------" << endl;
				cout << "Please enter the name of your new character" << endl;
				cout << "-----------------------------------------------" << endl;
				cin >> characterName;
				string name = characterName;
				characterName.append(".txt");

				ofstream out;
				out.open(characterName);

				out << type << endl;
				out << weapon << endl;
				out << armor << endl;
				out << name << endl;

				out.close();

				successCreation();
				selection = "-1";
			}
			selection = "-1";
		}

		else if (selection == "3") {
			cout << "-----------------------------------------------" << endl;
			cout << "You have selected the Heavy Chariot class" << endl;
			cout << "-----------------------------------------------" << endl;
			//character archer
			cout << endl;
			//add attribute to a variable add to constructor later
			type = "Heavy Chariot";

			cout << "-----------------------------------------------" << endl;
			cout << "Select a weapon" << endl;
			cout << endl;
			cout << "1.Light Spear" << endl;
			cout << "2.Heavy Spear" << endl;
			cout << "-1.Reselect class" << endl;
			cout << "-----------------------------------------------" << endl;
			// add descriptions
			cin >> selectWeapon;

			if (selectWeapon == "-1") {
				CharacterCmenu();
				retry = true;
			}

			while (selectWeapon != "-1") {

				if (selectWeapon == "1") {
					cout << "-----------------------------------------------" << endl;
					cout << "You have selected the light spear as your weapon" << endl;
					cout << "-----------------------------------------------" << endl;
					//add attribute to a variable add to constructor later
					weapon = "Light Spear";
					selectWeapon = "-1";
				}
				else if (selectWeapon == "2") {
					cout << "-----------------------------------------------" << endl;
					cout << "You have selected the heavy spear as your weapon" << endl;
					cout << "-----------------------------------------------" << endl;
					//add attribute to a variable add to constructor later
					weapon = "Heavy Spear";
					selectWeapon = "-1";
				}
				else if (selectWeapon != "-1") {
					cout << "-----------------------------------------------" << endl;
					cout << "-----------------------------------------------" << endl;
					cout << "Option unavailable" << endl;

					cout << "-----------------------------------------------" << endl;
					cout << "Select a Weapon" << endl;
					cout << endl;
					cout << "1.Light Spear" << endl;
					cout << "2.Heavy Spear" << endl;
					cout << "-1.Reselect class" << endl;
					cout << "-----------------------------------------------" << endl;
					cin >> selectWeapon;
				}
				else if (selectWeapon == "-1") {
					CharacterCmenu();
					retry = true;
				}
			}
		


			if (retry == false) {
				cout << "-----------------------------------------------" << endl;
				cout << "Select type of Armor" << endl;
				cout << endl;
				cout << "1.Light Armor" << endl;
				cout << "2.Heavy Heavy" << endl;
				cout << "-1.Reselect class" << endl;
				cout << "-----------------------------------------------" << endl;
				cin >> selectArmor;

				if (selectArmor == "-1") {
					CharacterCmenu();
					retry = true;
				}

				while (selectArmor != "-1") {

					if (selectArmor == "1") {
						cout << "-----------------------------------------------" << endl;
						cout << "You have a selected the Light Armor as your armor" << endl;
						cout << "-----------------------------------------------" << endl;
						//add attribute to a variable add to constructor later
						armor = "Light Armor";
						selectArmor = "-1";
					}
					else if (selectArmor == "2") {
						cout << "-----------------------------------------------" << endl;
						cout << "You have a selected the heavy armor as your armor" << endl;
						cout << "-----------------------------------------------" << endl;
						//add attribute to a variable add to constructor later
						armor = "Heavy Armor";
						selectArmor = "-1";
					}
					else if (selectArmor != "-1") {
						cout << "-----------------------------------------------" << endl;
						cout << "-----------------------------------------------" << endl;
						cout << "Option unavailable" << endl;

						cout << "-----------------------------------------------" << endl;
						cout << "Select a type of Armor" << endl;
						cout << endl;
						cout << "1.Light Armor" << endl;
						cout << "2.Heavy Armor" << endl;
						cout << "-1.Reselect class" << endl;
						cout << "-----------------------------------------------" << endl;
						cin >> selectArmor;
					}
					else if (selectArmor == "-1") {
						CharacterCmenu();
						retry = true;
					}
				}
			}

			if (retry == false) {

				cout << "-----------------------------------------------" << endl;
				cout << "Please enter the name of your new character" << endl;
				cout << "-----------------------------------------------" << endl;
				cin >> characterName;
				string name = characterName;
				characterName.append(".txt");

				ofstream out;
				out.open(characterName);

				out << type << endl;
				out << weapon << endl;
				out << armor << endl;
				out << name << endl;

				out.close();

				successCreation();
				selection = "-1";
			}
			selection = "-1";
		}
		else if (selection == "4") {
		archerData();
		cout << "-----------------------------------------------" << endl;
		selectionMenu();
		cin >> selection;
		}
		else if (selection == "5") {
		warriorData();
		cout << "-----------------------------------------------" << endl;
		selectionMenu();
		cin >> selection;
		}
		else if (selection == "6") {
		heavyChariotData();
		cout << "-----------------------------------------------" << endl;
		selectionMenu();
		cin >> selection;
		}
		

		else {
		cout << "-----------------------------------------------" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Option unavailable" << endl;
		
		cout << "-----------------------------------------------" << endl;
		cout << "Reselect one of the options below" << endl;
		cout << endl;
		cout << "Select a class" << endl;
		cout << "1.Archer" << endl;
		cout << "2.Warrior" << endl;
		cout << "3.Heavy Chariot" << endl;
		cout << "-1.Go back to the Main Menu" << endl;
		cout << "-----------------------------------------------" << endl;
		cin >> selection;
		}

		

	}
	if (selection == "-1" && retry == false) {
		main();
	}
	
	

}




int main() {

string userAction;
cout << "-----------------------------------------------" << endl;
cout << "Welcome to the Game" << endl;

cout << "Please select a numerical value" << endl;
cout << endl;

cout << "1.Start a new game" << endl;
//cout << "2.Continue off a previous game" << endl;
cout << "2.Create a character" << endl;
cout << "3.Continue off a previous game" << endl;
cout << "-1.Exit game" << endl;
cout << "-----------------------------------------------" << endl;
getline(cin, userAction);


while (userAction != "-1") {

	if (userAction == "1") {
		newGame();
		userAction = "-1";
	}
	/*
	else if (userAction == 2) {
		cout << "Please import saved game" << endl;
	}
	*/
	else if (userAction == "2") {

		CharacterCmenu();
		userAction = "-1";
	}
	else if (userAction == "3") {

		conPresviousGame();
		userAction = "-1";
	}
	if (userAction != "-1") {
		cout << "-----------------------------------------------" << endl;
		cout << "Option unavailable" << endl;
		cout << "-----------------------------------------------" << endl;
		cout << "Please reselect an numerical value" << endl;
		cout << endl;
		cout << "1.Start a new game" << endl;
		//cout << "2.Continue off a previous game" << endl;
		cout << "2.Create a character" << endl;
		cout << "3.Continue off a previous game" << endl;
		cout << "-1.Exit game" << endl;
		cout << "-----------------------------------------------" << endl;
		cin >> userAction;
	}
	
	
}




cout << "-----------------------------------------------" << endl;
return 0;
}
