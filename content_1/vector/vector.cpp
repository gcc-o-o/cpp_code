//vector.cpp implementing methods in class Vector
#include "vector.h"
#include <cmath>
using std::atan;
using std::atan2;
using std::sin;
using std::cos;
using std::sqrt;
using std::pow;
using std::cout;
using std::endl;

namespace VECTOR
{
//compute degrees in one radian  
	const double DEG_PER_RAD = 45.0 / atan(1.0);

//private methods
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}

	void Vector::set_y()
	{
		y = mag * sin (ang);
	}

	void Vector::set_mag()
	{
		mag = sqrt(pow(x, 2) + pow(y, 2));
	}

	void Vector::set_ang()
	{
		ang = atan2(y ,x);
	}
//public methods
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
	}

	//construct vector from rectangular coordinates if form is RECT (the default)
	//or else from polar coordinates if form is POL
	Vector::Vector(double n1, double n2, Mode form)
	{
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_ang();
			set_mag();
			mode = RECT;
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2 / DEG_PER_RAD;
			set_x();
			set_y();
			mode = POL;
		}
		else
		{
			cout << "invalid third mode parameter for Vector()" << endl;
			cout << "vector set to 0" << endl;
			x = y = mag = ang = 0;
			mode = RECT;
		}
	}

	Vector::~Vector(){};

	//reset vector from rectangular coordinates if form is RECT
	//or else from polar coordinates if form if POL
	void Vector::reset(double n1, double n2, Mode form)
	{
		if (form == RECT)
		{
			x = n1;
			y = n2;
			set_mag();
			set_ang();
			mode = RECT;
		}
		else if (form == POL)
		{
			mag = n1;
			ang = n2;
			set_x();
			set_y();
			mode = POL;
		}
		else
		{
			cout << "incorrect third arguement for reset()" <<endl;
			cout << "operation isn't performed" <<endl;
		}
	}

	void Vector::rect_mode()
	{
		mode = RECT;
	}

	void Vector::polar_mode()
	{
		mode = POL;
	}

//operation overloading
	Vector Vector::operator+(const Vector & v) const
	{
		return Vector(x + v.x, y + v.y);
	}

	Vector Vector::operator-(const Vector & v) const
	{
		return Vector(x - v.x, y - v.y);
	}

	Vector Vector::operator-() const
	{
		return Vector(- x, - y);
	}

	Vector Vector::operator*(const double n) const
	{
		return Vector(x * n, y * n);
	}

//frineds
	Vector operator*(const double n, const Vector & v)
	{
		return v * n;
	}

	//display Vector object in rectangular coordinates if mode is RECT
	//or else in polar coordinates if mode if POL
	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		if (v.mode == Vector::RECT)
			os << "{x, y} = {" << v.x << ", " << v.y << "}" << endl;
		else if (v.mode == Vector::POL)
			os << "{magnitude, angle} = {" << v.mag << ", "
			<< v.ang << "}" <<endl;
		else
			os << "invalid mode of Vector object" <<endl;
	}
}