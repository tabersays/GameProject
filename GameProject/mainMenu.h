#ifndef MAINMENU_H
#define MAINMENU_H 
#include <iostream>
#include <string>
#include "newGame.h"
#include "levelSelecter.h"
using namespace std;

/********************************************************************
 * Class: mainMenu
 * Purpose: creates the title screen and displays your choices
 * choices are new game, save , and quit.
 ********************************************************************/
class mainMenu
{
private:
	char title[6][15];//creates a string to display the title welcome text
	char action;//used to see what choice was pressed
	string info;
    
public:
	mainMenu(): action(' ')//initializes variable that will be used to hold user input
	{
		info = "\n\nWelcome to Taber's game!\n\nPress the number corresponding to the action you wish to take. \n\n1. New game\n2. Load game\n3. Quit\n";//save a variable with directions
		char setUptitle[6][15] = 
		{
			{'-','-','-','-','-','|','-','-','\\',' ','|','-','-','\\',' '},
			{' ',' ','|',' ',' ','|',' ',' ',' ','|','|',' ',' ',' ','|'},
			{' ',' ','|',' ',' ','|','_','_','/',' ','|','_','_','/',' '},
			{' ',' ','|',' ',' ','|','\\',' ',' ',' ','|',' ',' ',' ',' '},
			{' ',' ','|',' ',' ','|',' ','\\',' ',' ','|',' ',' ',' ',' '},
			{' ',' ','|',' ',' ','|',' ',' ','\\',' ','|',' ',' ',' ',' '}
		};
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 15; j++)
			{
				title[i][j] = setUptitle[i][j];
			}
		}
	}
	///////////////////////////////////
	~mainMenu()//destructor
	{
	}
	///////////////////////////////////////
	/************************************
	* Function: titleScreen
	* Furpose: builds the title screen when the game starts
	************************************/
	void titleScreen()// displays the title and waits for user input
	{	
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 15; j++)
			{
				cout << title[i][j];
			}
			cout << endl;
		}//prompts user and gives directions
		cout << info;
		while(action != '3')// loop this while action does not equal 3 quit
		{
			action = _getche();// gets input from user

			switch (action)// checks user input 
			{
			case '1'://
				{
					cout << "\nYou pressed New game.\n";//tells user what they selected
					system("PAUSE");
					newGame();
					break;
				}
			case '2':
				{
					cout << "\nYou pressed Load game.\n";
					system("PAUSE");
					loadGame();
					break;
				}
			case '3':
				{
					cout << "\nYou pressed Quit!\n";
					system("PAUSE");
					
					break;
				}
			default:
				{
					cout << "\n\nPlease enter a valid number!\n";
					system("PAUSE");
					break;
				}
			}
		}
		
	}
	//////////////////////////////////////////////
	/***********************************************
	* Function: newGame()
	* Furpose: creates a new hero and game object then runs the level
	**************************************************/
	void newGame()
	{
		
		hero fighter;// creates a hero object
		levelOne game;//creates new game object
		fighter.newHero();
		game.runGame(fighter);//runs the game
        while (true)
        {
            levelSelecter anotherLevel;
            anotherLevel.levelDecide(fighter);
        }
		
	}
	//////////////////////////////////////////////
	/***********************************************
	* Function: showName()
	* Furpose: displays name
	**************************************************/
	void loadGame()
	{
		hero fighter;
		fighter.load();
		system("cls");
		cout << fighter.showName();
		system("PAUSE");

        while (true)
        {
            levelSelecter anotherLevel;
            anotherLevel.levelDecide(fighter);
        }
	}
};
#endif