#include <iostream>

using namespace std;

void print_rectangle(int width, int height){
	if (width < 1 || height < 0) // safeguard
		return;

	int line;		char X = 'X';

	while (height--){
		line = width;
		cout << X;
		while (--line){
			cout << ' ' << X;
		}
		cout << '\n';
	}
	cout << '\n';
}

void print_rectangle(int width){
	print_rectangle(width, width);
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

