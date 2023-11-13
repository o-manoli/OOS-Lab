#include <iostream>
#include <sstream>

using namespace std;

string join(const string joiner, const string repeated, int repeat){
	// repetitive string joiner

	if (repeat < 1)			return "";

	ostringstream S;

	S << repeated;

	while (--repeat)
		S << joiner << repeated;

	return S.str();
}

void print_rectangle(int width, int height){
	string line = join(" ", "X", width);
	cout << join("\n", line, height) << '\n' <<endl;
}

void print_rectangle(int dimension){
	print_rectangle(dimension, dimension);
}

int main(int argc, char *argv[])
{
	cout << "x = 2, y = 5: " << endl;
	print_rectangle(2, 5);

	cout << "x = 3, y = 3: " << endl;
	print_rectangle(3, 3);

	cout << "x = 4: " << endl;
	print_rectangle(4);

	return 0;
};

