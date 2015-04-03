#include "Def.h"
#include <iostream>
using namespace std;

void Run (supermario &man)
{cout << "Run fn is called for the supermario at ( " << man.pos.x << " , " << man.pos.y << " )\n";

	// constraints not handled
	man.pos.x += 1;
	man.pos.y += 1;
}