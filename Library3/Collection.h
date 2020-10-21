#ifndef REPOSITORY_H	
#define REPOSITORY_H	
#include "Entity.h"
#include <string>
#include <vector>

class Collection//abstract class
	//Repository
{
protected:
	vector<Entity*> data;

public:
	virtual void print() = 0;
	//no implementation
	virtual bool CreateFromFile(string path) = 0;
	virtual void PrintToFile(string path) = 0;
	//path 
};
#endif
