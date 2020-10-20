#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "Collection.h"
using namespace std;

class Library :public Collection
{
	//data is a vector of books
public:
	Library();
	Library(string file);
	Library(const Library& lib);

	bool TakeBook(string author, string title);
	bool ReturnBook(string author, string title);

	void AddBook(string author, string title, int year, bool av);
	void DeleteByAuthorandTitle(string author, string title);
	int GetCount();

	void ChangeAvailable(int i, bool av);
	int CountAvailable();

	void FindFromPeriod(int y1, int y2);
	bool CreateFromFile(string path);

	void PrintToFile(string path);
	void print();
};


#endif
