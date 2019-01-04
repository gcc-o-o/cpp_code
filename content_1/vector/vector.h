//vector.h Vector class with << , mode state
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:
		enum Mode {RECT, POL};
		//RECT: rectangular mode, POL: polar mode.
	private:
		double x;		//horizontal value
		double y;		//vertical value
		double mag;	//magnitude of vector
		double ang;	//direction of vector in degrees
		Mode mode;	//RECT or POL
	//private methods for setting values
		void set_x();
		void set_y();
		void set_mag();
		void set_ang();
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		~Vector();
		void reset(double n1, double n2, Mode form = RECT);
		double xval() const {return x;} 	//return x value
		double yval() const {return y;} 	//return y value
		double magval() const {return mag;}	//return mag value
		double angval() const {return ang;} 	//return ang value
		void rect_mode();			//set mode to RECT
		void polar_mode();			//set mode to POL
	//operator overloading
		Vector operator+(const Vector & v) const;
		Vector operator-(const Vector & v) const;
		Vector operator-() const;
		Vector operator*(const double n) const;
	//friends
		friend Vector operator*(const double n, const Vector & v);
		friend std::ostream & operator<<(std::ostream & os, const Vector & v);
	};
}

#endif