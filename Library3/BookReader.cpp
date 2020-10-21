#include <iostream>
#include <fstream>
#include <string>
#include"BookReader.h"
#include"Book.h"
#include"Manual.h"
#include"Magazine.h"
#include "MultiVolumeBook.h"
using namespace std;

BookReader::BookReader(string path)
{
	fin.open(path);

}
Book* BookReader::ReadBook()
{
	string type;
	getline(fin, type);
	Book* b;
	string author;
	string title;
	int year;
	bool avail;

	if (type == "book")
	{
		getline(fin, author);
		getline(fin, title);
		fin >> year;
		fin >> avail;
		b = new Book(author, title, year, avail);
		getline(fin, author);
		return b;
	}
	else
	{
		if (type == "manual")
		{
			//fin>>s; do pershogo probilu
			getline(fin, author);//full string to enter
			//fin>>s; do pershogo probilu
			getline(fin, title);//full string to enter
			string area;
			getline(fin, area);

			fin >> year;
			fin >> avail;

			b = new Manual(author, title, area, year, avail);
			getline(fin, author);
			return b;
		}
		else
		{
			if (type == "multivol")
			{
				
				getline(fin, author);
			
				getline(fin, title);
				int num;
				fin >> num;

				fin >> year;
				fin >> avail;

				b = new MultiVolumeBook(author, title, num, year, avail);
				getline(fin, author);
				return b;
			}

			else {
				if (type == "magazine")
				{
					
					getline(fin, author);
					
					getline(fin, title);
					string area;
					getline(fin, area);

					fin >> year;
					fin >> avail;

					b = new Magazine(author, title, area, year, avail);
					getline(fin, author);
					return b;
				}
			}
		}

	}
	//return b;
}
bool BookReader::CanRead()
{
	return !fin.eof();//true if we can read, false if the end of file
}
bool BookReader::IsOpen()
{
	return fin.is_open();//true if we can read, false if the end of file
}
void BookReader::CloseFile()
{
	fin.close();
}




