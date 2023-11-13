# AUFGABE 1 (BIS 05.10.2023, 13:30 UHR)

## THEMEN:

> Ein- und Ausgabe, Aufzählungstypen, Schleifen, bedingte Abfragen, Casts

## IHRE AUFGABE:

Das Spiel Schere-Stein-Papier, kann auch am Computer gespielt werden. Schreiben Sie ein Programm, so dass Sie mit dem Computer Stein-Schere- Papier spielen können. Nutzen Sie das bereitgestellte Programmgerippe.

Die Ausgabe des Programms soll folgendermaßen aussehen:

```bash
Der Computer hat seine Wahl getroffen.
Name des Spielers:
[Eingabe: z.B. Max]
Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier):
[Eingabe: z.b. 1]
Computer hat das Objekt Schere gewaehlt.
Max hat das Objekt Stein gewaehlt.
Max hat gewonnen!
```

```cpp

#include <string>
#include <ctime>
#include <iostream>

using namespace std;

// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2
enum class Object
{
    ROCK,
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge
enum class Result
{
    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player
{
    string name;
    Object choice;
};

// Name des Spielers eingeben
string insert_name()
{

    // HIER programmieren:
    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"

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
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:
        // Was bewirkt die funktion srand?
        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // Wie funktioniert die funktion rand?
        // Warum wird hier modulo 3 verwendet?

        srand(static_cast<int>(time(nullptr)));
        int choice = rand() % 3;
        return static_cast<Object>(choice);
    }
}

// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object)
{

    // HIER programmieren:
    // Abhängig vom vorliegenden Object einen entsprechenden String zurückgeben.
    // z.B: Wenn Object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben

}

// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player)
{

    // HIER programmieren:
    // Auf der Konsole ausgeben, für welches Object sich der Spieler entschieden hat.
    // z.B.: "Computer hat das Object Schere gewählt"
    // TIP: Nutzen sie hierzu die Funktion get_name

}

// Die Wahl des Spielers abfragen
Object choose()
{

    // HIER programmieren:
    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    // Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"

}

Result determine_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    // TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"

}

void print_result(Player player_1, Player player_2)
{

    // HIER programmieren:
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.
    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.
    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"

}

int main(int argc, char *argv[])
{
    Player player_1, player_2;
    player_1.name = "Computer";
    player_2.name = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = choose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}


```

## ANS

```cpp
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

```

