# AUFGABE 8 (BIS 26.10.2023, 13:30 UHR)

## THEMEN:

> Komposition

## IHRE AUFGABE:

Das Programm, das sie entwickeln werden, kann grafische Objekte (Punkte, Kreise, ...) als Objekte von Klassen darstellen. Sie können sich die Objekte als Datenrepräsentationen von grafischen Objekten in einem Zeichenprogramm vorstellen. Die grafischen Objekte sind definiert über Koordinaten und könnten (später) Eigenschaften haben wie z.B. eine Strichstärke und -art.

Sie sollen zwei Klassen definieren: Point und Circle.

(a) Die Klasse Point repräsentiert das geometrische Objekt Punkt.

(b) Die Klasse hat die Instanzvariablen '_x' und '_y' vom Typ double. Diese beiden Instanzvariablen repräsentieren die x- und y-Koordinaten eines Punktes.

(c) Die Klasse Circle repräsentiert einen Kreis.

(d) Sie hat die Instanzvariablen '_centre' vom Typ 'Point' und '_radius' vom Typ double. Die Variable '_centre' steht also für den Mittelpunkt des Kreises.

(e) In beiden Klassen sollen die Instanzvariablen vor Zugriff von außerhalb der Klasse geschützt sein.

(f) Schreiben Sie für beide Klassen Konstruktoren mit geeigneten Defaultparametern.

(g) Schreiben sie get- und set-Methoden für alle Instanzvariablen.

(h) Die Instanzfunktion 'move(double dx, double dy)' verschiebt einen Punkt bzw. einen Kreis um die Werte 'dx' und 'dy' in x- bzw. y-Richtung.

(i) Beide Klassen sollen eine Funktion 'print' besitzen, welche die Koordinaten eines Punktes bzw. die Koordinaten des Mittelpunktes und den Radius eines Kreises auf dem Bildschirm ausgibt. Die Funktion 'print' besitzt einen Parameter vom Typ 'bool', der steuert, ob nach der Ausgabe ein Zeilenvorschub (endl) durchgeführt wird oder nicht. Der Defaultwert für diesen Parameter soll 'true' sein. Die Ausgabe des gegebenen Hauptprogrammes ist unten angegeben:

Ausgabe:

```bash
Ausgabe 1:
(0, 0)
[(0, 0), 1]
Ausgabe 2:
(1.1, 2.2) == (1.1, 2.2)
[(1.1, 2.2), 3.3]
Ausgabe 3:
(2.1, 3.2)
[(3.1, 4.2), 3.3]
```


```cpp


#include <iostream>
using namespace std;

// Klasse Point und Circle implementieren

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
	c.set_centre(p);
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

```

## ANS:

```cpp

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


```