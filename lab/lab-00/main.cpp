#include <iostream>
#include <array>

using std::cout, std::cin, std::endl;
using std::array;

#define MAX_SIZE 10

int main(int argc, char* argv[]){

	int size;

	do {
		cout << "Anzahl eingeben:" << endl;
		cin >> size;
	} while (size > MAX_SIZE || size < 0);

	array<int, MAX_SIZE> A;

	int i = 0;

	while (i < size){
		cout << "Zahl eingeben:" << endl;
		cin >> A[i++];
	}

	int sum = 0;

	for (i = 0; i < size; i++){
		cout << "Zahl["<< i << "]: " << A[i] << "\n";
		sum += A[i];
	}

	float average = static_cast<float>(sum) / static_cast<float>(size);

	cout << "Durchschnitt: " << average << endl;

	return 0;
}

