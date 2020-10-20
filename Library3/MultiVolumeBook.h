#ifndef MUTIVOLUMEBOOK_H
#define MUTIVOLUMEBOOK_H

#include <iostream>
#include "Book.h"
#include <string>

using namespace std;

class MultiVolumeBook :public Book
{
private:
	int num_vol;//nomer tomu
public:
	MultiVolumeBook();
	//2 z parametramy
	MultiVolumeBook(string a, string t, int n_v, int y, bool av);

	//3 kopiuvannya
	MultiVolumeBook(const MultiVolumeBook& b);

	void print();
	string ToString();
	//перевантаження оператора виводу
	friend ostream& operator<<(ostream& os, MultiVolumeBook& b)
	{
		//os could be cout could ofstream file
		os << b.author << "\n" << b.title << "\n" << b.year << "\n" << b.available << "\n" << b.num_vol;
		return os;

	}
};


#endif

