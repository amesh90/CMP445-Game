#include "Def.h"
#include <iostream>
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
