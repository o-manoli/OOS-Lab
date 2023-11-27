#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Person
{
	string name;
	int _check_out_duration;

	public:

	Person(string name, int check_out_duration = 0);
	string get_name() const;
	int get_check_out_duration() const;
	void print() const;
};

Person::Person(string name, int check_out_duration)
	: name(name), _check_out_duration(check_out_duration) {}

string Person::get_name() const
{
	return name;
}

int Person::get_check_out_duration() const
{
	return _check_out_duration;
}

void Person::print() const
{
	cout << name;
}

class Lecturer : public Person
{
	int _examiner_id;

	public:

	Lecturer(
		string name, int examiner_id
	) : Person(name, 90), _examiner_id(examiner_id) {}

	void print() const {
		Person::print();
		cout << "prfrNr" << _examiner_id << endl;
	}
};

class Student : public Person
{
	int _matriculation_number;

	public:

	Student(
		string name, int matriculation_number
	) : Person(name, 30), _matriculation_number(matriculation_number) {}

	void print() const {
		Person::print();
		cout << "matNr" << _matriculation_number;
	}
};


class Date
{
	int _day, _month, _year;

	public:

	Date(int = 0, int = 0, int = 0);

	Date(const string &);

	Date(const char *);
	Date operator+(int);
	friend ostream &operator<<(ostream &, const Date &);
};

Date::Date(
	int t, int m, int j
) : _day(t), _month(m), _year(j) {}

Date::Date(const string &str)
{
	char c;
	stringstream S(str);
	S >> _day >> c >> _month >> c >> _year;
}

Date::Date(const char *cStr) : Date(string(cStr)) {}

Date Date::operator+(int days)
{
	int abs_date = _day + _month * 30 + _year * 360;
	abs_date += days;
	int y = abs_date / 360;
	abs_date = abs_date % 360;
	int m = abs_date / 30;
	abs_date = abs_date % 30;
	int d = abs_date;

	return Date(d, m, y);
}

ostream& operator<<(ostream& os, const Date& d)
{
	os << d._day << "." << d._month << "." << d._year;
	return os;
}

class Medium
{

	protected:
	const string _titel;
	const string _publisher;
	const int _year_of_publication;
	Date _date_of_check_out;
	Date _date_of_return;
	Person *_lender;

public:
	Medium(
		string titel = "", string publisher = "", int year = 0
	) : _titel(titel), _publisher(publisher),
	_year_of_publication(year),
	_lender(nullptr) {}

	virtual ~Medium() {}
	string get_title() const { return _titel; }
	Person *get_lender() const {return _lender;}
	void check_out(Person &, Date, Date);
	virtual void print() const;
	virtual Medium *clone() const;
};


void Medium::check_out(Person &p, Date date_of_check_out, Date date_of_return)
{
	_lender = &p;
	this->_date_of_check_out = date_of_check_out;
	this->_date_of_return = date_of_return;
}

void Medium::print() const
{
	cout << "Titel:         " << _titel << endl;
	cout << "Verlag:        " << _publisher << endl;
	cout << "Jahr:          " << _year_of_publication << endl;
	cout << "Ausleiher:     ";
	if (_lender != nullptr)
	{
		cout << _lender->get_name();
		cout << " von: " << _date_of_check_out << " bis: " << _date_of_return << endl;
	}
	else
	{
		cout << "-" << endl;
	}
}

Medium *Medium::clone() const
{
	return new Medium(*this);
}


class Book : public Medium
{
	string _author;

public:
	Book(
		string author = "", string titel = "",
		string publisher = "", int year = 0
	) : Medium(titel, publisher, year), _author(author) {}

	void print() const;
	Medium *clone() const override;
};


void Book::print() const
{
	cout << "Autor:         " << _author << endl;
	Medium::print();
	cout << endl;
}

Medium *Book::clone() const
{
	return new Book(*this);
}

class DVD : public Medium
{
	const int _c_play_time;

	public:

	DVD(
		string title = "", string publisher = "",
		int year_of_publication = 0, int play_time = 0
	) : Medium(title, publisher, year_of_publication), _c_play_time(play_time) {}

	void print() const;
	Medium *clone() const override;
};


void DVD::print() const
{
	Medium::print();
	if (_c_play_time > 0)
	{
		cout << "Dauer:         " << _c_play_time << endl;
	}
	cout << endl;
}

Medium *DVD::clone() const
{
	return new DVD(*this);
}

class Library
{
	const unsigned int _c_maximal_number_of_media;
	vector<Medium*> media;

public:
	// Standardkonstruktor
	Library(
		const unsigned int maximal_number_of_media = 1000
	) : _c_maximal_number_of_media{maximal_number_of_media} {}

	void procure_medium(Medium &);

	void search_medium(string);

	void check_out_medium(int, Person &, Date);

	void print() const;
};

void Library::procure_medium(Medium &M)
{
	if (media.size() < _c_maximal_number_of_media)
		media.push_back(M.clone());

	else
		cout << "voll" << endl;
}

// alle Medien auf der Konsole ausgeben,
// die im Titel das Suchwort enthalten
void Library::search_medium(string search_word)
{
	cout << endl
		 << "Suche nach \"" << search_word << "\" Ergebnis:" << endl;
	cout << "---------------------------------------" << endl
		 << endl;
	for (size_t i = 0; i < media.size(); i++)
	{
		auto *p = media[i];
		if (p->get_title().find(search_word) != string::npos)
		{
			cout << "Medium " << i << ":" << endl;
			p->print();
		}
	}
	cout << "---------------------------------------" << endl;
}

void Library::check_out_medium(int nr, Person &p, Date d)
{
	if (media[nr] != nullptr)
	{
		if (media[nr]->get_lender() == nullptr)
			media[nr]->check_out(p, d, d + p.get_check_out_duration());
		else
			cout << "Bereits ausgeliehen" << endl;
	}
	else
	{
		cout << "nicht vorhanden!" << endl;
	}
}

void Library::print() const
{
	cout << endl
		 << "Bibliothekskatalog:" << endl;
	cout << "---------------------------------------" << endl
		 << endl;

	for (size_t i = 0; i < media.size(); i++)
	{
		cout << "Medium " << i << ":" << endl;
		media[i]->print();
	}
	cout << "---------------------------------------" << endl;
}

int main(int argc, char *argv[])
{
	// Umlaute etc. in der Konsole zulassen
	setlocale(LC_ALL, "");
	// Bibliothek mit 100 Plätzen initialisieren
	Library library(100);
	// Bücher und DVDs erstellen
	Book b1("U. Breymann", "C++ - Eine Einführung", "Hanser", 2016);
	Book b2("U. Breymann", "Der C++ Programmierer", "Hanser", 2017);
	Book b3("Rainer Grimm", "C++20, Get the details", "Leanpub", 2021);
	Book b4("Bartłomiej Filipek", "C++17 in detail", "Leanbub", 2018);
	Book b5("Timothy Gallwey", "The Inner Game of Tennis", "Pan", 2015);
	Book b6("Brad Gilbert", "Winning Ugly – Mentale Kriegsführung im Tennis", "riva", 2021);
	DVD d1("The IT Crowd", "2entertain", 2016, 600);
	DVD d2("Mr. Robot", "Universal Pictures UK", 2020, 2106);
	DVD d3("Chuck", "Warner Bros (Universal Pictures)", 2013, 3774);
	// Ein Buch und eine DVD ausgeben
	b1.print();
	d1.print();
	// Kopien der Bücher und DVDs (Medien) in die Bibliothek
	// einfügen
	library.procure_medium(b1);
	library.procure_medium(b2);
	library.procure_medium(b3);
	library.procure_medium(b4);
	library.procure_medium(b5);
	library.procure_medium(b6);
	library.procure_medium(d1);
	library.procure_medium(d2);
	library.procure_medium(d3);
	// Bestand der Bibliothek ausgeben
	library.print();
	// Personen anlegen
	Student p1("Peter", 12345678);
	Student p2("Lisa", 87654321);
	Lecturer p3("Prof Miller", 4711);
	// Suchen im Bibliotheksbestand durchführen
	library.search_medium("C++");
	library.search_medium("Tennis");
	library.search_medium("The");
	// Medien ausleihen
	library.check_out_medium(1, p1, "4.5.2023");
	library.check_out_medium(7, p2, "25.05.2023");
	library.check_out_medium(4, p3, "12.10.2023");
	// Bestand der Bibliothek ausgeben
	library.print();
}
