#include <iostream>
#include <string>
#include "Magazine.h"
#include "Book.h"
using namespace std;


Magazine::Magazine() : Book()
{
	area = "";
}
Magazine::Magazine(string a, string t, string ar, int y, bool av) : Book(a, t, y, av)
{
	area = ar;
}
Magazine::Magazine(const Magazine& b) : Book(b)
{
	area = b.area;
}

void Magazine::print()
{
	cout << author << " " << title << " " << area << " " << year << " " << available << endl;
}
string Magazine::ToString()
{


	return "magazine\n" + author + "\n" + title + "\n" + area + "\n" + std::to_string(year) + "\n" + std::to_string(available);
}