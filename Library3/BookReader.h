#ifndef BOOKREADER_H
#define BOOKREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include"Book.h"

using namespace std;

class BookReader
{
private:
	ifstream fin;
public:
	BookReader(string path);//open file
	Book* ReadBook();
	bool CanRead();
	void CloseFile();
	bool IsOpen();
};


#endif

