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
		cout<<"\toof we where close, Supermario jumped over the hole\n";
	}
}
