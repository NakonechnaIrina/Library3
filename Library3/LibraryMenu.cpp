#include <iostream>
#include <string>
#include"LibraryMenu.h"

using namespace std;

LibraryMenu::LibraryMenu()
{
	cout << "Welcome to Library!" << endl;
}
void LibraryMenu::Go()
{
	int menu = 0;
	do
	{
		cout << "press item number from menu to do the next:" << endl;
		cout << "1 create library from file" << endl;
		cout << "2 read new from file" << endl;
		cout << "3 print books" << endl;
		cout << "4 write books to file" << endl;
		cout << "5 add book" << endl;
		cout << "6 delete by author and title" << endl;//clear
		cout << "7 get count of books" << endl;
		cout << "8 take by author and title" << endl;
		cout << "9 return by author and title" << endl;
		cout << "10 count available" << endl;
		cout << "0 exit" << endl;

		cin >> menu;
		string path;
		string author, title;
		int year;
		bool av;
		int i, y1, y2;
		switch (menu)
		{
		case 1:
			cout << "input path to file (e.g. data.txt or D:\data.txt)";
			cin >> path;
			if (lib.CreateFromFile(path))
			{
				cout << "success" << endl;
			}
			else
			{
				cout << "smth wrong" << endl;
			}
			break;
		case 2:
			cout << "input path to file (e.g. data.txt or D:\data.txt)";
			cin >> path;
			if (lib.CreateFromFile(path))
			{
				cout << "success" << endl;
			}
			else
			{
				cout << "smth wrong" << endl;
			}
			break;
		case 3:
			lib.print();
			break;
		case 4:
			cout << "input path to file (e.g. data.txt or D:\data.txt)";
			cin >> path;
			lib.PrintToFile(path);
			break;
		case 5:
			cout << "input author" << endl;
			cin >> author;
			cout << "input title" << endl;
			cin >> title;
			cout << "input year" << endl;
			cin >> year;
			cout << "input available" << endl;
			cin >> av;
			lib.AddBook(author, title, year, av);
			break;
		case 6:
			cout << "input author" << endl;
			cin >> author;
			cout << "input title" << endl;
			cin >> title;
			lib.DeleteByAuthorandTitle(author, title);
			break;
		case 7:
			cout << "count of books: " << lib.GetCount() << endl;
			break;

		case 8:
			cout << "input author" << endl;
			cin >> author;
			cout << "input title" << endl;
			cin >> title;
			if (lib.TakeBook(author, title))
			{
				cout << "success!" << endl;
			}
			else
			{
				cout << "cannot find this book" << endl;
			}
			break;
		case 9:
			cout << "input author" << endl;
			cin >> author;
			cout << "input title" << endl;
			cin >> title;
			if (lib.ReturnBook(author, title))
			{
				cout << "success!" << endl;
			}
			else
			{
				cout << "cannot find this book" << endl;
			}
			break;
		case 10:
			cout << "available: " << lib.CountAvailable() << " books" << endl;
			break;
		case 0:
			cout << "goodbye!" << endl;
			break;
		default:
			cout << "invalid number of menu item!!!";
			break;
		}
	} while (menu != 0);



}