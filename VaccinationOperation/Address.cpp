#include "Address.h"
#include <iostream>
using namespace std;

Address::Address(const char* district, const char* street, int houseNum) 
{
	this->district = new char[strlen(district) + 1]; 
	strcpy(this->district, district);

	this->street = new char[strlen(street) + 1];
	strcpy(this->street, street);

	this->houseNum = houseNum;
}

Address::Address(const Address& other) : district(NULL), street(NULL)
{
	district = new char[strlen(other.district) + 1];
	strcpy(district, other.district);
	street = new char[strlen(other.street) + 1];
	strcpy(street, other.street);
	houseNum = other.houseNum;
}

Address::Address(Address&& other) 
{
	this->district = other.district;
	other.district = nullptr;

	this->street = other.street;
	other.street = nullptr;

	this->houseNum = other.houseNum;
}


const char* Address::getDistrict() const
{
	return this->district;
}



const char* Address::getStreet() const
{
	return this->street;
}



const int Address::getHouseNum() const
{
	return this->houseNum;
}


const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		if (district != nullptr)
		{
			delete[] district;
		}
		if (street != nullptr)
		{
			delete[] street;
		}
		this->district = other.district;
		this->street = other.street;
		this->houseNum = other.houseNum;
	}
	return *this; 
}

const Address& Address::operator=(Address&& other)
{
	if (this != &other)
	{
		std::swap(this->district, other.district);
		std::swap(this->street, other.street);
		this->houseNum = other.houseNum;
	}

	return *this;
}


Address::~Address()
{
	delete[] this->district;
	delete[] this->street;
}
