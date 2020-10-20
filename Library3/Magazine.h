#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <iostream>
#include "Book.h"
#include <string>

using namespace std;

class Magazine :public Book
{
private:
	string area;
public:
	Magazine();
	//2 z parametramy
	Magazine(string a, string t, string ar, int y, bool av);

	//3 kopiuvannya
	Magazine(const Magazine& b);

	void print();
	string ToString();
	//перевантаження оператора виводу
	friend ostream& operator<<(ostream& os, Magazine& b)
	{
		//os could be cout could ofstream file
		os << b.author << "\n" << b.title << "\n" << b.year << "\n" << b.available << "\n" << b.area;
		return os;

	}
};


#endif
