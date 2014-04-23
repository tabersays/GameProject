#ifndef MONSTERS_H
#define MONSTERS_H 
#include <iostream>

/********************************************************************
 * Class: monsterBoss, monsterMagic, monsterSword
 * Purpose: stores information about the monster character and checks to
 * see if he dies from damage. also uses inheritence
 ********************************************************************/
class monsterSword 
{

protected:
	int health, attack, swordDefence, magicDefence;//variables that will be used
public:
	monsterSword() : health(5), attack(1), swordDefence(1), magicDefence(2)//initialize variables
	{
		
	}
	////////////////////////////////////////////////
	~monsterSword()//destructer
	{
	}
	///////////////////////////////////////////////////
	/***********************************************
	* Function: hurtSword(int, bool&)
	* Furpose: deals sword damage to monster and
	* checks if the monster is dead
	**************************************************/
	void hurtSword(int damage, bool& monsterIsDead)//deals sword damage to the monster and checks to see if he died
	{
		health = health - swordDefence * damage;//recalculates health when recieving damage and increases damage when vulnerable
		if(health <= 0)// if the health is less than or equal to 0 they are dead
		{
			monsterIsDead = true;//make them dead
		}
		
	}
	/////////////////////////////////////////////////////
	/***********************************************
	* Function: hurtMagic(int, bool&)
	* Furpose: deals magic damage to monster and
	* checks if the monster is dead
	**************************************************/
	void hurtMagic(int damage, bool& monsterIsDead)//deals magic damage to the monster and checks to see if he died
	{
		health = health - magicDefence * damage;//recalculates health when recieving damage and increases damage when vulnerable
		if(health <= 0)// if the health is less than or equal to 0 they are dead
		{
			monsterIsDead = true;//make them dead
		}
		
	}
	/////////////////////////////////////////////////
	/***********************************************
	* Function: mAttack()
	* Furpose: returns attack
	**************************************************/
	int mAttack()//gets monster attack stat
	{
		return(attack);// returns it to be used outside
	}
	//////////////////////////////////////////////////
	/***********************************************
	* Function: showHealth()
	* Furpose: returns health
	**************************************************/
	int showHealth()//gets monster health stat
	{
		return(health);// returns it to be outside
	}
};
////////////////////////////////////////////////////
/********************************************************************
 * Class: monsterBoss, monsterMagic, monsterSword
 * Purpose: stores information about the monster character and checks to
 * see if he dies from damage. also uses inheritence
 ********************************************************************/
class monsterBoss : public monsterSword
{
public:
	monsterBoss(): monsterSword() 
	{
		health = 10, magicDefence = 1, swordDefence = 1 ;
	}
};
///////////////////////////////////////////////////
/********************************************************************
 * Class: monsterBoss, monsterMagic, monsterSword
 * Purpose: stores information about the monster character and checks to
 * see if he dies from damage. also uses inheritence
 ********************************************************************/
class monsterMagic : public monsterSword
{
public:
	monsterMagic(): monsterSword()
	{
		health = 5, magicDefence = 1, swordDefence = 2;
	}
};
#endif