
#include <iostream>
using namespace std;

// Klasse Point und Circle implementieren

class Point{

	double _x, _y;

	public:

	Point (double x = 0, double y = 0) : _x{x}, _y{y} {}

	void set_x(double x){ _x = x; }
	double get_x(){ return _x; }
	void set_y(double y){ _y = y; }
	double get_y(){ return _y; }

	void move(double dx, double dy){
		_x += dx;
		_y += dy;
	}

	friend ostream& operator<< (ostream&, const Point &);

	void print(bool NLine = true){
		cout << *this;
		if (NLine) cout << endl;
	}

};

ostream& operator<<(ostream& S, const Point& P)
{
	return S << "(" << P._x << ", " << P._y << ")";
}

class Circle{

	Point _center;
	double _radius;

	public:

	Circle(Point center = Point(0, 0), double radius = 1) :
	_center{center}, _radius{radius} {}

	void set_center(Point center){ _center = center; }

	void set_radius(double radius){ _radius = radius; }
	double get_radius(){ return _radius; }

	void move(double dx, double dy){ _center.move(dx, dy); }

	void print(bool NLine = true)
	{
		cout << "[" << _center << ", " << _radius << "]";
		if (NLine)	cout << endl;
	}

};

// Hauptprogramm
int main(int argc, char *argv[])
{
	Point p;
	Circle c(p);
	cout << "Ausgabe 1:" << endl;
	p.print();
	c.print();
	p.set_x(1.1);
	p.set_y(2.2);
	c.set_center(p);
	c.set_radius(3.3);
	cout << "Ausgabe 2:" << endl;
	p.print(false);
	cout << " == (" << p.get_x() << ", " << p.get_y() << ")"
		<< endl;
	c.print();
	p.move(1.0, 1.0);
	c.move(2.0, 2.0);
	cout << "Ausgabe 3:" << endl;
	p.print();
	c.print();
	return 0;
}

