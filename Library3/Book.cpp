#include <iostream>

#include <string>
#include "Book.h"
using namespace std;


Book::Book()
{
	author = "";
	title = "";
	year = 0;
	available = false;
}

Book::Book(string a, string t, int y, bool av)
{
	author = a;
	title = t;
	year = y;
	available = av;
}


Book::Book(const Book& b)//Copy
{
	
	author = b.author;
	title = b.title;
	year = b.year;
	available = b.available;
}
void Book::print()
{
	cout << author << " " << title << " " << year << " " << available << endl;
}
string Book::getAuthor()
{
	return author;
}
string Book::getTitle()
{
	return title;
}
void Book::setAuthor(string new_)
{
	author = new_;
}
void Book::setAvailable(bool av)
{
	available = av;
}
bool Book::is_available()
{
	return available;
}
string Book::ToString()
{


	return "book\n" + author + "\n" + title + "\n" + std::to_string(year) + "\n" + std::to_string(available);
}