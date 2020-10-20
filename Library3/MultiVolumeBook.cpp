#include <iostream>
#include <string>
#include "MultiVolumeBook.h"
#include "Book.h"
using namespace std;


MultiVolumeBook::MultiVolumeBook() :Book()
{
	num_vol = 0;
}
MultiVolumeBook::MultiVolumeBook(string a, string t, int n_v, int y, bool av) : Book(a, t, y, av)
{
	num_vol = n_v;
}
MultiVolumeBook::MultiVolumeBook(const MultiVolumeBook& b) : Book(b)
{
	num_vol = b.num_vol;
}

void MultiVolumeBook::print()
{
	cout << author << " " << title << " " << num_vol << " " << year << " " << available << endl;
}
string MultiVolumeBook::ToString()
{

	return "multivol\n" + author + "\n" + title + "\n" + std::to_string(num_vol) + "\n" + std::to_string(year) + "\n" + std::to_string(available);
}