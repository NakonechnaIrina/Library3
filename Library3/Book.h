#ifndef BOOK_H
#define BOOK_H

#include <iostream>

#include <string>
#include "Entity.h"

using namespace std;

class Book :public Entity
{
	
protected:
	string author;
	string title;
	int year;
	bool available;
	//methods - functions to work data
public:
	
	Book();
	
	Book(string a, string t, int y, bool av);

	
	Book(const Book& b);

	virtual string ToString();
	virtual void print();
	//to get data
	string getAuthor();
	string getTitle();
	//to set new data
	void setAuthor(string new_);
	void setAvailable(bool av);
	bool is_available();
	
	friend ostream& operator<<(ostream& os, Book& b)
	{
		
		os << b.author << "\n" << b.title << "\n" << b.year << "\n" << b.available;
		return os;
	}

};



#endif
