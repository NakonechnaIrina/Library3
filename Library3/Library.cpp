#include <iostream>
#include <fstream>
#include "Library.h"
#include "Book.h"
#include "BookReader.h"
#include "Collection.h"
#include <vector>
#include <string>

using namespace std;

Library::Library()
{
}
Library::Library(string file)
{
	CreateFromFile(file);
}
Library::Library(const Library& lib)
{
	//?? 
	//if books: Book *books=new Book[10];
	//!!!!!!!!!!!problem 

	//but books: vector<Book> books;
	//this->books=lib.books;

	for (int i = 0; i < lib.data.size(); i++)
	{
		//??
		data.push_back(lib.data[i]);
	}
}

void Library::AddBook(string author, string title, int year, bool av)
{
	Book* b = new Book(author, title, year, av);
	data.push_back(b);
}

int Library::GetCount()
{
	return data.size();
}

void Library::DeleteByAuthorandTitle(string author, string title)
{
	for (int i = 0; i < data.size(); i++)
	{
		if ((((Book*)(data[i]))->getAuthor() == author) && (((Book*)(data[i]))->getTitle() == title))
			data.erase(data.begin() + i);//c++ iterator using
	}
}

void Library::ChangeAvailable(int i, bool av)
{
	//!!!! index out range
	//TRY CATCH EXCEPTION!!!!

	((Book*)(data[i]))->setAvailable(av);

}
void Library::FindFromPeriod(int y1, int y2)
{
	//...
}
void Library::print()
{
	for (int i = 0; i < data.size(); i++)
	{
		//cout<<books[i]<<endl;
		data[i]->print();
	}
}
bool Library::CreateFromFile(string path)
{
	try
	{
		BookReader br(path);
		data.clear();//clear previous data
		bool result = false;
		if (br.IsOpen())
		{
			while (br.CanRead())
			{
				result = true;
				//Book item=br.ReadBook();
				//??
				data.push_back(br.ReadBook());
			}
		}
		else
			throw 1;

		br.CloseFile();
		return result;
	}
	catch (int e)
	{
		cout << "invalid file!" << endl;
	}
}

void Library::PrintToFile(string path)
{
	ofstream fout(path);

	if (fout.is_open())
	{
		for (int i = 0; i < data.size() - 1; i++)
		{
			//books[i] is Book*			
			//fout<<*(books[i])<<endl;		
			//викликали поліморфізм - віртуальний метод перетворення інф про обєкт у стрічку (окремо книжка\підручник\томник)
			fout << ((Book*)(data[i]))->ToString() << endl;
		}
		//fout<<*(books[books.size()-1]);
	}
	fout.close();
}
bool Library::TakeBook(string author, string title)
{
	bool flag = false;
	for (int i = 0; i < data.size(); i++)
	{
		if ((((Book*)(data[i]))->getAuthor() == author) && (((Book*)(data[i]))->getTitle() == title))
		{
			((Book*)(data[i]))->setAvailable(false);
			flag = true;
		}

	}
	return flag;
}
bool Library::ReturnBook(string author, string title)
{
	bool flag = false;
	for (int i = 0; i < data.size(); i++)
	{
		if ((((Book*)(data[i]))->getAuthor() == author) && (((Book*)(data[i]))->getTitle() == title))
		{
			((Book*)(data[i]))->setAvailable(true);
			flag = true;
		}

	}
	return flag;
}
int Library::CountAvailable()
{
	int k = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if (((Book*)(data[i]))->is_available())
			k++;
	}
	return k;
}