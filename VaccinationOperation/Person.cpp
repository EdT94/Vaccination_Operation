#include "Person.h"


int Person::current_id = 0;

Person::Person(const char * name): id(++current_id)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}


const int Person::getId() const
{
	return this->id;
}

const char* Person::getName() const
{
	return this->name;
}

bool Person::setName(const char* name)
{
	delete[]this->name;
	this->name = strdup(name);
	return name == nullptr ? false : true;
}

Person::~Person()
{
	delete[] this->name;
}