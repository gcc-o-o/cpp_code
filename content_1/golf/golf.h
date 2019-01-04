const int Len=40;
struct golf
{
	char fullname[Len];
	int handicap;
};

//non-interactive version
//function sets golf structure to provided fullname and handicap
//using values passed as arguments to the function
void setgolf(golf &g, char* name, int hc);

//interactive version
//function solicits name and handicap from users
//and sets member of golf to value entered
//return 1 if name is entered , 0 if name is empty
int setgolf(golf &g);

//function reset handicap to new value
void handicap(golf &g, int hc);

//function display contents of golf structure
void showgolf(const golf &g);