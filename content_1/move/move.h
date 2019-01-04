//move.h
#ifndef MOVE_H_
#define MOVE_H_

class Move
{
private:
	double x;
	double y;
public:
	Move(double a=0, double b=0);	//sers x, y to a, b
	void showmove(void) const;		//shows current x, y values
	Move moveadd(Move &m) const;
	//this function adds x of m to x of invoking object to get a new x
	//adds y of m to y of invoking object to get a new y
	// creates a new Move object initialized by new x and new y and return it
	void reset(double a=0, double b=0);	//reset x, y to a, b
};

#endif