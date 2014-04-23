#ifndef HEROSTATS_H
#define HEROSTATS_H 
#include <iostream>
#include <fstream>
using namespace std;

/********************************************************************
 * Class: hero
 * Purpose: stores information about the hero character and checks to
 * see if he dies from damage
 ********************************************************************/
class hero
{
protected:
	int sword, health, magic, MAX_HEALTH, potions, level;//stats that will be used by hero to store values
	string name;
public:
	hero() : sword(1), magic(1), MAX_HEALTH(10), name(" "), potions(0), level(1) //initialize values
	   {
		   health = MAX_HEALTH;//sets health
		   
	   }
	////////////////////////////////////////////////
	~hero()//detructer
	{
	}
	/////////////////////////////////////////////
	/***********************************************
	* Function: newHero()
	* Furpose: makes a new hero object and gets name
	**************************************************/
	void newHero()
	{
		system("cls");
		cout << "Enter your charecter's name!\n\n";
		getline(cin, name);
		cout << "\n\n Your name is " << name << "!\n\n";
		system("PAUSE");
	}
	//////////////////////////////////////////////
	/***********************************************
	* Function: showName()
	* Furpose: displays name
	**************************************************/
	string showName()
	{
		return(name);
	}
	/////////////////////////////////////////////
	/***********************************************
	* Function: heroSheet()
	* Furpose: displays info about the hero
	**************************************************/
	void heroSheet()
	{
		char choice = ' ';
		do
		{
			system("cls");
			cout << name << "'s information!\n\n";
			cout << "Your health is " << health << " out of " << MAX_HEALTH << "\n";
			cout << "Your sword power is " << swordAttack() << "\n";
			cout << "Your magic power is " << magicAttack() << "\n";
			cout << "You have " << potions << " potions left!" << "\n";
			cout << "\nPress 1. to use a potion, 2. to SAVE or 3. to exit!\n";
			bool heroIsDead = false;
			choice = _getche();
			switch(choice)
			{
				case '1':
					if(potions > 0)
					{
					hurt(-50, heroIsDead);
					potions--;
					cout << "Healed!\n\n";
					system("PAUSE");
					}
					else
					{
						cout << "You have no potions!\n\n";
						system("PAUSE");
					}
					break;
				case '2':
					save();
					break;

				default:
					cout << "\n\nPlease select a correct choice";
			}

		}while(choice != '3');
	}
	//////////////////////////////////////////////
	/***********************************************
	* Function: potionFound()
	* Furpose: adds a healing potion when found
	**************************************************/
	void potionFound()
	{
		system("cls");
		cout << name << " found a potion! It can heal up to 50 health!";
		potions++;
		system("PAUSE");
	}
	//////////////////////////////////////////////
	/***********************************************
	* Function: powerUp()
	* Furpose: powers up the hero
	**************************************************/
	void powerUp()//allows hero growth
	{
		char choice = ' ';//stores user input for power up
		do//do untill a choice is made
		{
		system("cls");
		
		std:: cout << "You got a power up!\nPower up your Sword! 1.\nPower uo your Magic! 2.\n";//gives directions
		choice = _getche();//gets user input
		switch(choice)
		{
		case '1':// sword power up is chosen 
			sword++;// increase sword power by one
			break;
		case '2':// magic power up is chosen 
			magic++;// increase magic power by one
			break;
		default:// if the did not choose a valid choice tell them
			cout << "\n Select a valid choice!\n";//displays info
			system("PAUSE");

		}
		}while(choice != '1' && choice != '2');//do untill a valid choice is made
	}
	/////////////////////////////////////////////////
	/***********************************************
	* Function: hurt(int, bool)
	* Furpose: deals damage to the hero
	**************************************************/
	void hurt(int damage, bool& heroIsDead)// when the hero is hurt or healed modify health
	{
		health = health - damage;// modify health
		if(health > MAX_HEALTH)//if heath is healed past max amount set it equal to max amount
		{
			health = MAX_HEALTH;//set it equal to max amount
		}
		else if(health <= 0)// if health is 0 or less hero is dead
		{
			heroIsDead = true;//set hero to dead
		}

	}
	//////////////////////////////////////////
	/***********************************************
	* Function: swordAttack()
	* Furpose: returns attack
	**************************************************/
	int swordAttack()//gets info about heros sword attack
	{
		return(sword);//returns it to be used
	}
	///////////////////////////////////////////////
	/***********************************************
	* Function: magicAttack()
	* Furpose: returns magic
	**************************************************/
	int magicAttack()//gets info about heros magic attack
	{
		return(magic);//returns it to be used
	}
	///////////////////////////////////
	/***********************************************
	* Function: showHealth()
	* Furpose: returns health
	**************************************************/
	int showHealth()//gets info about heros health
	{
		return(health);//returns it to be used
	}
	///////////////////////////////////////////
	/***********************************************
	* Function: showLevel()
	* Furpose: displays current level
	**************************************************/
	int showLevel()
	{
		return(level);
	}
	///////////////////////////////////////////
	/***********************************************
	* Function: showMAX()
	* Furpose: displays MAX_HEALTH
	**************************************************/
	int showMAX()
	{
		return(MAX_HEALTH);
	}
	///////////////////////////////////////////
	/***********************************************
	* Function: showPotions()
	* Furpose: displays amount of potions
	**************************************************/
	int showPotions()
	{
		return(potions);
	}
	////////////////////////////////////////
	/***********************************************
	* Function: nextLevel()
	* Furpose: increments the level for save feature
	**************************************************/
	void nextLevel()
	{
		level++;
	}
	////////////////////////////////////////
	/***********************************************
	* Function: save()
	* Furpose: saves information aout the hero
	**************************************************/
	void save()
	{
		system("cls");
		ofstream file;
		file.open(name + ".DAT");
        file.clear();
        file << name << " " << health << " " << MAX_HEALTH << " " << level << " " << sword << " " << magic << " " << potions;
        file.close();
		cout << name << " was saved!\n";
		system("PAUSE");
	}
	////////////////////////////////////////
	/***********************************************
	* Function: load()
	* Furpose: load a hero used need lots of tender love and care
	**************************************************/
	int load()// needs TLC
	{
		system("cls");
        string heroName;
        cout << "Enter the name of the hero you want to load.\n";
        cin >> heroName;
		fstream file;
        try
        {
            file.open(heroName + ".DAT");
            cout << "\nHero " + heroName +" was found\n";
            file >> name >> health >> MAX_HEALTH >> level >> sword >> magic >> potions;
            
            
        }
        catch (bool i)
        {
            cout << "\n the hero " + heroName + " was not found! \n";
            newHero();
        }
		
		system("PAUSE");
		return(0);
		

	}
};


#endif