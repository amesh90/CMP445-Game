struct Position 
{
	int x ;
	int y ;
Position() : x(0), y(0)
		   {}

};
struct Enemy
{
	static int ID;
	int status;
	int power;
	Position pos;
};

struct supermario
{
	int status;
	int health;
	Position pos;
	int points;
	int level_ID;
};

struct holes
{
	Position pos;
	int width;
};
struct Dragon
{
	static int ID;
	int status;
	int power;
	Position pos;
	int level_ID;
};