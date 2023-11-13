#include <string>
#include <ctime>
#include <iostream>
#include <array>

using std::cout, std::cin, std::endl;
using std::string, std::array;

enum class Object
{
	ROCK,
	SCISSORS,
	PAPER
};

enum class Result
{
	PLAYER_ONE_WINS,
	PLAYER_TWO_WINS,
	DRAW
};

struct Player
{
	string name;
	Object choice;
};

string insert_name()	//TODO
{
	cout << "Name des Spielers: ";

	string name;

	cin >> name;

	return name;
}

Object determine_choice(string choice)
{
	if (choice.compare("CoderunnerTestValueROCK") == 0)
	{
		return Object::ROCK;
	}
	else if (choice.compare("CoderunnerTestValueSCISSORS") == 0)
	{
		return Object::SCISSORS;
	}
	else if (choice.compare("CoderunnerTestValuePAPER") == 0)
	{
		return Object::PAPER;
	}
	else
	{
		srand(static_cast<int>(time(nullptr)));
		int choice = rand() % 3;
		return static_cast<Object>(choice);
	}
}

array<string, 3> Labels = {"Stein", "Schere", "Papier"};

string get_name(Object object)	//TODO
{
	return ::Labels.at(static_cast<int>(object));
}

void print_choice(Player player)	//TODO
{
	cout << player.name << " hat das Objekt " << get_name(player.choice) << " gewählt" << endl;
}

Object chose()	//TODO
{
	cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier): ";

	string choice;

	while (1)
	{
		cin >> choice;

		if (choice.length() == 1)
		{
			switch (choice[0])
			{
			case '1':
				return Object::ROCK;
			case '2':
				return Object::SCISSORS;
			case '3':
				return Object::PAPER;
			default:
				break;
			}
		}
	}
}

Result determine_result(Player player_1, Player player_2)	//TODO
{
	if (player_1.choice == player_2.choice)
		return Result::DRAW;

	// at this point the player will either win or lose

	if (player_1.choice == Object::ROCK)
	{
		if (player_2.choice == Object::SCISSORS)
			return Result::PLAYER_ONE_WINS;
		return Result::PLAYER_TWO_WINS; // player 2 chose chose paper
	}

	if (player_1.choice == Object::SCISSORS)
	{
		if (player_2.choice == Object::PAPER)
			return Result::PLAYER_ONE_WINS;
		return Result::PLAYER_TWO_WINS;
	}

	if (player_2.choice == Object::ROCK)
		return Result::PLAYER_ONE_WINS;

	return Result::PLAYER_TWO_WINS;	// at last admit defeat

}

void print_result(Player player_1, Player player_2)	//TODO
{
	Result result = determine_result(player_1, player_2);

	switch (result)
	{
		case Result::PLAYER_ONE_WINS:
			cout << "Spieler " << player_1.name << " hat gewonnen." << endl;
			break;

		case Result::PLAYER_TWO_WINS:
			cout << "Spieler " << player_2.name << " hat gewonnen." << endl;
			break;

		case Result::DRAW:
			cout << "Unentschieden" << endl;
			break;
	}
}

int main(int argc, char *argv[])
{
	Player player_1, player_2;
	player_1.name = "Computer";
	player_2.name = insert_name();
	player_1.choice = determine_choice(player_2.name);
	cout << "Der Computer hat seine Wahl getroffen." << endl;
	player_2.choice = chose();
	print_choice(player_1);
	print_choice(player_2);
	print_result(player_1, player_2);

	return 0;
}

