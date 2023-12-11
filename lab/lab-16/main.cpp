
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Join{
   string J;
   vector<T> V;

   public:

   Join(
      string Joiner, vector<T> &Iterable
   ) : J{Joiner}, V{Iterable} {}

   friend ostream& operator<<(ostream& S , const Join<T>& Obj)
   {
      if (Obj.V.size()){
         S << Obj.V[0];

         for (size_t i = 1; i < Obj.V.size(); i++)
            S << Obj.J << Obj.V[i];
      }
      return S;
   }
};

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

   friend ostream& operator<<(ostream& S, const Point& P)
   {
      return S << "(" << P._x << ", " << P._y << ")";
   }

   void print(bool NLine = true){
      cout << *this;
      if (NLine) cout << endl;
   }

};

class Polygonline{

   vector<Point> _points;

   public:

   Polygonline() = default;

   Polygonline(Point& p) {_points.push_back(p);}

   Polygonline& add_point(Point p)
   {
      _points.push_back(p);
      return *this;
   }

   void append_polygonline(Polygonline& pl)
   {
      for (auto p : pl._points)
         add_point(p);
   }

   void move(double dx, double dy)
   {
      for (auto &p: _points)
         p.move(dx, dy);
   }

   void print(bool NLine = true)
   {
      cout << "|" << Join(" - ", _points) << "|";

      if (NLine) cout << endl;
   }
};

int main(int argc, char *argv[])
{
   Point p1(1, 1), p2(2, 2), p3(3, 3), p4(4, 4), p5(5, 5);
   Polygonline l1;
   Polygonline l2(p3);
   cout << "Ausgabe 1:" << endl;
   l1.print();
   l2.print();
   l1.add_point(p1).add_point(p2);
   l2.add_point(p4).add_point(p5);
   cout << "Ausgabe 2:" << endl;
   l1.print();
   l2.print();
   p2.move(0.5, 0.5);
   cout << "Ausgabe 3:" << endl;
   p2.print();
   l1.print();
   l2.print();
   l1.append_polygonline(l2);
   cout << "Ausgabe 4:" << endl;
   l1.print();
   l2.print();
   l1.move(0, 0.5);
   cout << "Ausgabe 5:" << endl;
   l1.print();
   l2.print();
   return 0;
}

