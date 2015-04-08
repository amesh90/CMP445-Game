#include "Def.h"
#include <iostream>
#include <cmath>
using namespace std;


void Run (supermario &man)
{cout << "Run fn is called for the supermario at ( " << man.pos.x << " , " << man.pos.y << " )\n";

	// constraints not handled
	man.pos.x += 1;
	man.pos.y += 1;


}

// to kill the enemy (affect the power of the enemy, and the points of the supermario )
// to kill supermario (affect the health of the supermario)
void fire (supermario &man,Enemy &Enemy1,holes &h)
{  
	
	// statues of supermario ==3 supermario is fire on the enemy
	if (man.status==3)  
	{
	man.points  +=10; //decrese power of enemy 10 
    Enemy1.power -=10;  //increse points of the supermario 10 point
	if (Enemy1.power==0)
	Enemy1.status=0; //Enemy dead 
	 cout << "Enemy Kill at ( " << Enemy1.pos.x << " , " << Enemy1.pos.y << " )\n";
	}
	//// statues of enemy ==3 enemy is fire on the supermario
	if (Enemy1.status ==3) 
	{
         man.health -=10;  //decrese power supermario 10 point
		 if(man.health==0)
		 man.status=0; //supermario dead
		cout << "supermario Kill at ( " << man.pos.x << " , " << man.pos.y << " )\n";
	}
	

}

void Jump (supermario &man, const holes &hole) {
	cout<<"Jump fn is called for supermario at ("<<man.pos.x<<","<<man.pos.y<<")\n";
	cout<<"\tHole at "<<hole.pos.x<<","<<hole.pos.y<<"\n";
	
	if(hole.pos.x+hole.width < man.pos.x) {
		cout<<"\tDon't worry the hole is behind you\n";
		return;
	}
	
	//distance between supermario and the hole
	int dist = abs(hole.pos.x - man.pos.x);
	
	//the first ground position after the hole
	int safepointdist = man.pos.x + dist + hole.width;
	
	//Health value is the distance supermario can jump 
	int landingpos = man.pos.x + man.health;
	
	man.pos.x = landingpos;
	
	if(landingpos < safepointdist)
	{
		cout<<"\tYOU LOSE! falling in a black hole\n";
		man.status = 0; //dead
	}else {
		cout<<"\toof that was close, Supermario jumped over the hole\n";
	}
}

void CollectPoints (supermario &man, const Enemy &enemy) {
	//Make sure enemy is dead
	if (enemy.status==0)
	{	//Must be standing at the points to collect them
		if (enemy.pos.x==man.pos.x)
		{
			if(enemy.pos.y==man.pos.y)
			{
				man.points++;
				cout<<man.points;
			}
			else
			cout<<"\tJump to collect your rewards!\n";	
		}
		else
			cout<<"\tMove to collect your rewards!\n";				
	}
}

// Feature GetBonus when eating a mushroom :)
void GetBonus(supermario &man, int numMushroom)
{
	// The number of points of eating mushrooms ... Assume that each mushroom 100 points
	int MushroomPoints = 100;
	if (numMushroom > 0)
		cout << "Wow Wow Wow >>> You did a great job" << endl;
	// score of points
	man.points = man.points + (MushroomPoints * numMushroom);
	// Show score of points 
	cout << "Congratulations :)   score of points : " << man.points << endl;
}
