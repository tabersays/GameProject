#include <iostream>
//#include "mainMenu.h"

using namespace std;
//////////////////////////////////////////////////////////////////////
/********************************************************************
 * Class: levelSelecter
 * Purpose: get the user to the correct level. 
 ********************************************************************/
class levelSelecter
{
protected:

public:
	void levelDecide(hero& fighter)
	{
		int on;
		if(fighter.showLevel() == 1)
		{
			levelOne level;
			level.runGame(fighter);
		}
		else if(fighter.showLevel() == 2)
		{
			levelTwo level;
			level.runGame(fighter);
		}
		else
		{

		}
		
	}

};