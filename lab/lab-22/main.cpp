#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
   double d = 1.234;
   cout << " Nr Oct  Hex String  Fixed     Scientific " << endl;
   for (int k = 1; k < 11; k++)
   {
      cout << setw(3) << dec
         << k;

      cout << setw(4) << showbase << oct
         << k;

      cout << setw(5) << nouppercase << hex
         << k;

      cout << " " << setw(7) << left << setfill('+')
         << string(k % 5 + 1, '*') << " "; // repeat '*' (k % 5 + 1) times

      cout << setw(9) << internal << showpos
         << setfill(' ') // reset fill
         << setprecision(3) << fixed
         << d;

      cout << setw(11) << right // rest to right alignment
         << setprecision(3) << scientific
         << noshowpos << uppercase
         << d;

      d = d * -2;

      cout << endl;
   }
   return 0;
}

