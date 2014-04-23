#ifndef COMBAT_H
#define COMBAT_H 
#include <iostream>
#include "heroStats.h"
#include "monsters.h"
using namespace std;
/********************************************************************
 * Class: monsterFight
 * Purpose: creates battle backdrop and allows for actions to be taken
 * until enemy is dead or the hero, if the hero dies it kills the 
 * program. this uses some function templates to take several types
 * monstersto do battle.
 ********************************************************************/
class monsterFight
{
private:
	int damage;
	char screen[6][12];// holds screen graphics
public:
	monsterFight() : damage(0)
	{
		char pic[6][12] = {//sets a simple ascii battle screen graphic
			{'_','_','_','_','_','_','_','_','_','_','_','_'},
			{'|',' ',' ',' ',' ',' ',' ',' ',' ','\\','q','|'},
			{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
			{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
			{'|','P','/',' ',' ',' ',' ',' ',' ',' ',' ','|'},
			{'_','_','_','_','_','_','_','_','_','_','_','_'}};
		
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 12; j++)
			{
				screen[i][j] = pic[i][j];//copies it over to screen to be displayed
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////
	template <class battler, class mBattler>// uses the template feature to accept several different monster objects
	/***********************************************
	* Function: printScreen(battler&, mBattler&)
	* Furpose: prints battle graphics and displays 
	* hero and monster info
	**************************************************/
	void printScreen(battler& fighter, mBattler& monster)//gets info about the hero and monster by reference so values can be modified
	{
		system("cls");// clears and build the battle screen
		for(int q = 0; q < 6; q++)
		{
			for(int p = 0; p < 12; p++)
			{
				cout << screen[q][p]; //prints it out
			}
			cout << endl;
		}
		
		
		cout << "Battle Time!\n\n";	//informs the user of a battle
		cout << "\n\nEnemy's health is ";// displays the heros and the enemys health
		
		cout << monster.showHealth() << "\nYour health is ";
		 
		cout << fighter.showHealth() << "\n\n1. Attack with sword.\n2. Attack with magic.\n3. Quit.\n\n";//displays attack choices

	}
	////////////////////////////////////////////////////////
	/***********************************************
	* Function: heroLost()
	* Furpose: exit when the hero dies
	**************************************************/
	void heroLost()// exits the program when the hero lost
	{
		system("cls");
		char lost[6][13] = 
		{
			{'\\',' ','/','/','-','\\','|',' ','|',' ',' ',' ','|'},
			{' ','|',' ','|',' ','|','|',' ','|',' ',' ',' ','|'},
			{' ','|',' ','\\','_','/','\\','_','/',' ',' ',' ','|'},
			{'|',' ',' ','/','-','\\',' ','/','\\','-','-','-','|'},
			{'|',' ',' ','|',' ','|',' ','\\',' ',' ','|',' ','|'},
			{'|','_','_','\\','_','/','\\','/',' ',' ','|',' ','o'}
		};
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 13; j++)
			{
				cout << lost[i][j];
			}
			cout << endl;
		}
		//cout << "\nYou lost!\n";//diplay info
		system("PAUSE");
		exit(0);//exits
	}
	//////////////////////////////////////////////////////
	template <class battler, class mBattler>//uses templates to handle several different monster object
	/***********************************************
	* Function: runBattle(battler&, mBattler&)
	* Furpose: runs battle loop
	**************************************************/
	int runBattle( battler& fighter, mBattler& monster)// runs basic battle functions like dealing correct damage types
	{
		
		char selection = ' ';// holds user input

		bool heroIsDead = false;//when a battle begins no one is dead
		bool monsterIsDead = false;

		printScreen(fighter, monster);// prints battle graphic

		do// do battle untill either are dead
		{

			
			selection = _getche();// gets user input
			if(selection == '1')// uses heros sword attack to deal damage
			{
				monster.hurtSword(fighter.swordAttack(), monsterIsDead);//deals damage to monster and checks if he is dead
				fighter.hurt(monster.mAttack(), heroIsDead);//deals damage to a hero and checks if he is dead
			}
			else if(selection == '2')//uses heros magic to deal damage
			{
				monster.hurtMagic(fighter.magicAttack(), monsterIsDead);//deals damage to monster and checks if he is dead
				fighter.hurt(monster.mAttack(), heroIsDead);//deals damage to a hero and checks if he is dead
			}
			else if(selection == '3')//quits program available only for testing
			{
				return(0);
			}
			else//if the did not enter a valid choice tell them
			{
				cout << "\nPlease enter a correct number\n";
				system("PAUSE");
			}
			printScreen(fighter, monster);// updates the screen
	
		}while(heroIsDead != true && monsterIsDead != true);// do battle untl either are dead
		if(heroIsDead == true)//if the hero died tell user
		{
			heroLost();//hero lost screen
		}
		cout << "\nYou won!\n";// tell them the won
		system("PAUSE");
		return(0);
	}
};
#endif