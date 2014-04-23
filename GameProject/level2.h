#include "newGame.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
/********************************************************************
 * Class: levelTwo
 * Purpose: To store the grid and the current x and y position of the
 * user. Also has memeber functions to intialize the grid and print it.
 * Allows the user to move around the grid and checks for enemys and 
 * items. 
 ********************************************************************/
class levelTwo 
{
protected:
	  //The grid to print to the screen
      char Screen[20][40]; 
	  //The current x and y position of the users cursor on the grid
      int xPos, yPos; 
public:
	levelTwo() : xPos(1), yPos(40 - 2)
      {
           level(); //Initalize the grid
      }
	  /////////////////////////////////////////////////////////////////
	  //destructor
	  ~levelTwo()
	  {
	  }
	
	void level()
	{
		//creates the level
		  char level[20][40] = 
					   {{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'},
						{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','@','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ',' ','_','_','_','_','_','_','_','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|','_','_','_','_','_','_','_','_',' ',' ',' ','_','|','M','|','_','_','_','_','_','_','_','_','_','_','_','_','_','|',' ','|','_','_','_','_','_','_','_','|'},
						{'|','H',' ',' ',' ',' ',' ',' ','|',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','S','|'},
						{'|','_','_','_','_','_',' ',' ','|',' ',' ','|',' ',' ','_','_','_','_','_','_','_','_','_','_',' ',' ',' ','_','_','_','_','_','_','_','_','_','_','_','_','|'},
						{'|',' ',' ',' ',' ',' ','|',' ','|',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ','|',' ','|',' ',' ','|','M','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ','|',' ','|',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ','|',' ','|',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','M','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ','|',' ','_','_','_','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ','|',' ',' ','B',' ',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ','|','_','_','_','_',' ',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|',' ','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','M','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|','o','|',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','|'},
						{'_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_'}};
		  for(int i = 0; i < 20; i++)
		  {
			  for(int j = 0; j < 40; j++)
			  {
				  Screen[i][j] = level[i][j];
			  }
		  }
		  //Set the users initial cursor position			
           Screen[xPos][yPos] = '<';
	}
	////////////////////////////////////////////////////////////////////////////////
      //Print the grid to the screen
      void Print()
      {
           for(int height = 0; height < 20; height++) {
                for(int width = 0; width < 40; width++) {
					//Print the character at this location in the grid
                     cout << Screen[height][width]; 
                }
				//After each row is printed, print a newline character
                cout << endl; 
           }
      }
///////////////////////////////////////////////////////////////////////////////////////
      //Take in user input to move around the grid and take a reference to the hero
	  void Move(char Direction, hero& fighter)
      {
		  if(Direction == 'c' || Direction == 'C')// it they pressed c show the hero sheet
		  {
			  //show hero sheet
			  fighter.heroSheet();
		  }
           switch(static_cast<int>(Direction)) //Don't know the ASCII characters for the arrow keys so use the ASCII numbers
           {
                case 72: //Up arrow
                     Screen[xPos][yPos] = ' '; //Wipe out the users current cursor
                     xPos--; //Move the users x position on the grid
					 if(Screen[xPos][yPos] == 'H')
					 {
						 nextLevel(fighter);
					 }
					 if(Screen[xPos][yPos] == 'o')
					 {
						 //increments your amount of potions
						 fighter.potionFound();
					 }
					 if(Screen[xPos][yPos] == '@')//check for a power up char
					 {
						 fighter.powerUp();//powers up and gives you a choice
					 }
					 if(Screen[xPos][yPos] == 'B')//check to see if you encounter the boss
					 {
						 
						 monsterBoss monster;//creates a monster boss object
						 system("cls");//clears the screen
						 cout << "Battle Time!\n This is the BOSS!!!\n\n";//displays battle info
						 
						 system("PAUSE");
						 monsterFight battle;// creates a monster fight object
						 battle.runBattle(fighter, monster);// runs a battle
					 }
					 if(Screen[xPos][yPos] == 'M')//checks to see if there is a sword monster
					 {
						 
						 monsterSword monster;//creates a sword monster object
						 system("cls");
						 cout << "Battle Time!\n\n";//displays info
						 
						 system("PAUSE");
						 monsterFight battle;// creates a new monster fight object
						 battle.runBattle(fighter, monster);//runs a battle
					 }
					 if(Screen[xPos][yPos] == 'S')// checks to see if there is a magic monster
					 {
						 
						 monsterMagic monster;// creates a magic monster object
						 system("cls");
						 cout << "Battle Time!\n\n";//displays info
						 
						 system("PAUSE");
						 monsterFight battle;// creates a new monster fight object
						 battle.runBattle(fighter, monster);//runs a battle
					 }
					 if(xPos <= 0 || Screen[xPos][yPos] == '|' || Screen[xPos][yPos] == '_' || Screen[xPos][yPos] == '-')//checks for a wall
					 {
						 xPos++;//if a wall is encountered push charater back
					 }
                     Screen[xPos][yPos] = '^'; //Move the users cursor
                     break;
                case 80: //Down arrow
                     Screen[xPos][yPos] = ' ';
                     xPos++;
					 if(Screen[xPos][yPos] == 'H')
					 {
						 nextLevel(fighter);
					 }
					 if(Screen[xPos][yPos] == 'o')
					 {
						 fighter.potionFound();
					 }
					 if(Screen[xPos][yPos] == '@')
					 {
						 fighter.powerUp();
					 }
					  if(Screen[xPos][yPos] == 'B')
					 {
						 
						 monsterBoss monster;
						 system("cls");
						 cout << "Battle Time!\n This is the BOSS!!!\n\n";
						 
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					 if(Screen[xPos][yPos] == 'M')
					 {
						 
						 monsterSword monster;
						 system("cls");
						 cout << "Battle Time!\n\n";
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					 if(Screen[xPos][yPos] == 'S')
					 {
						 
						 monsterMagic monster;
						 system("cls");
						 cout << "Battle Time!\n\n";
						 
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					 if(xPos >= 20 || Screen[xPos][yPos] == '|' || Screen[xPos][yPos] == '_')
					 {
						 xPos--;
					 }
                     Screen[xPos][yPos] = 'V';
                     break;
                case 75: //Left arrow
                     Screen[xPos][yPos] = ' ';
                     yPos--;
					 if(Screen[xPos][yPos] == 'H')
					 {
						 nextLevel(fighter);
					 }
					 if(Screen[xPos][yPos] == 'o')
					 {
						 fighter.potionFound();
					 }
					 if(Screen[xPos][yPos] == '@')
					 {
						 fighter.powerUp();
					 }
					  if(Screen[xPos][yPos] == 'B')
					 {
						 
						 monsterBoss monster;
						 system("cls");
						 cout << "Battle Time!\n This is the BOSS!!!\n\n";
						 
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					 if(Screen[xPos][yPos] == 'M')
					 {
						 
						 monsterSword monster;
						 system("cls");
						 cout << "Battle Time!\n\n";
						 
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					 if(Screen[xPos][yPos] == 'S')
					 {
						 
						 monsterMagic monster;
						 system("cls");
						 cout << "Battle Time!\n\n";
						 
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					  if(yPos <= 0 || Screen[xPos][yPos] == '|' || Screen[xPos][yPos] == '_')
					 {
						 yPos++;
					 }
                     Screen[xPos][yPos] = '<';
                     break;
                case 77: //Right arrow
                     Screen[xPos][yPos] = ' ';
                     yPos++;
					 if(Screen[xPos][yPos] == 'H')
					 {
						 nextLevel(fighter);
					 }
					 if(Screen[xPos][yPos] == 'o')
					 {
						 fighter.potionFound();
					 }
					 if(Screen[xPos][yPos] == '@')
					 {
						 fighter.powerUp();
					 }
					  if(Screen[xPos][yPos] == 'B')
					 {
						 
						 monsterBoss monster;
						 system("cls");
						 cout << "Battle Time!\n This is the BOSS!!!\n\n";
						 
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					 if(Screen[xPos][yPos] == 'M')
					 {
						 
						 monsterSword monster;
						 system("cls");
						 cout << "Battle Time!\n\n";
						 
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					 if(Screen[xPos][yPos] == 'S')
					 {
						 
						 monsterMagic monster;
						 system("cls");
						 cout << "Battle Time!\n\n";
						 
						 system("PAUSE");
						 monsterFight battle;
						 battle.runBattle(fighter, monster);
					 }
					 if(yPos >= 40 || Screen[xPos][yPos] == '|' || Screen[xPos][yPos] == '_')
					 {
						 yPos--;
					 }
                     Screen[xPos][yPos] = '>';
                     break;
           }
      }
	  ////////////////////////////////////////////////////////////////////////////////
	 /***********************************************
	* Function: nextLevel(hero&)
	* Furpose: goes to the next level
	**************************************************/
	  void nextLevel(hero& fighter)
	  {
		  cout << "You Helped me!";
		  /*levelTwo level2;
		  level2.runGame(fighter);*/
	  }
	  ///////////////////////////////////////////////////////////////////////////
	/***********************************************
	* Function: runGame()
	* Furpose: runs a new game
	**************************************************/
	  void runGame(hero& fighter)//runs the exploration phase of the game
	  {
		  

		  char UserMove = ' '; //This is used to store the users input
		  do {
			   system("cls"); //Clear the screen before printing anything
			   cout << "Welcome to TRP mini." << endl; //Program intro
			   Print(); //Print the grid out
			   cout << "What direction would you like to move in? \n(Move using the arrow keys, see the hero sheet by pressing c or type q to quit.)"; //Instructions to the user

			   UserMove = _getche(); //Get one character from the user (Visual Studio 2010 "_getche()" is the new version of "getche()")
			   Move(UserMove, fighter); //Process the users input
          } while (UserMove != 'Q' && UserMove != 'q'); //Keep running the program until the user types in a Q or q
          {
              
              exit(0);
          }

		  system("cls"); //Clear the screen
		  cout << endl;
		  Print(); //Print the final grid out to the user
		  cout << endl;

		  system("PAUSE");
		

	  }

};
