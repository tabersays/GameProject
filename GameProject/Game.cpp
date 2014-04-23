
#include <iostream>
#include "mainMenu.h"
#include <string>
using namespace std;
/***********************************************
* Function: main()
* Furpose: program starts here
**************************************************/
int main()
{
	
	mainMenu menu; //create the menu object
	menu.titleScreen();//activates the menu screen which displays new game, load game, or quit
	return(0);
}
