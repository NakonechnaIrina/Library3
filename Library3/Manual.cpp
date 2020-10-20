#include <iostream>
#include <string>
#include "Manual.h"
#include "Book.h"
using namespace std;


Manual::Manual() :Book()
{
	area = "";
}
Manual::Manual(string a, string t, string ar, int y, bool av) : Book(a, t, y, av)
{
	area = ar;
}
Manual::Manual(const Manual& b) : Book(b)
{
	area = b.area;
}

void Manual::print()
{
	cout << author << " " << title << " " << area << " " << year << " " << available << endl;
}
string Manual::ToString()
{


	return "manual\n" + author + "\n" + title + "\n" + area + "\n" + std::to_string(year) + "\n" + std::to_string(available);
}