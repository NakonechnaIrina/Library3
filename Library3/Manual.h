#ifndef MANUAL_H
#define MANUAL_H

#include <iostream>
#include "Book.h"
#include <string>

using namespace std;

class Manual :public Book
{
private:
	string area;
public:
	Manual();
	//2 z parametramy
	Manual(string a, string t, string ar, int y, bool av);

	//3 kopiuvannya
	Manual(const Manual& b);

	void print();
	string ToString();
	//перевантаження оператора виводу
	friend ostream& operator<<(ostream& os, Manual& b)
	{
		//os could be cout could ofstream file
		os << b.author << "\n" << b.title << "\n" << b.year << "\n" << b.available << "\n" << b.area;
		return os;

	}
};


#endif
