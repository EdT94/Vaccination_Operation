#include "Vaccinee.h"
#include "Appointment.h"
using namespace std;

Vaccinee::Vaccinee(const char* name, int phasesComplete, eRiskGroup riskGroup) : Person(name)
{
	this->phasesComplete = phasesComplete;
	this->riskGroup = riskGroup;

	this->appointmentsCapacity = 2;
	this->appointmentsCount = 0;

	this->appointmentsArr = new Appointment * [appointmentsCapacity];
}

Vaccinee::Vaccinee(const Vaccinee& other) : Person(other.name)
{
	this->appointmentsCount = other.appointmentsCount;
	this->appointmentsCapacity = other.appointmentsCapacity;
	this->phasesComplete = other.phasesComplete;
	this->riskGroup = other.riskGroup;

	this->appointmentsArr = new Appointment * [appointmentsCapacity];
	for (int i = 0; i < other.appointmentsCount; i++)
		this->appointmentsArr[i] = other.appointmentsArr[i];
}


Vaccinee::Vaccinee(Vaccinee&& other) : Person(other.name) 
{
	this->name = other.name;
	other.name = nullptr;

	this->appointmentsArr = other.appointmentsArr;
	other.appointmentsArr = nullptr;

	this->riskGroup = other.riskGroup;
	this->phasesComplete = other.phasesComplete;
	this->appointmentsCount = other.appointmentsCount;
	this->appointmentsCapacity = other.appointmentsCapacity;
}



bool Vaccinee::removeAppointment(const int appointmentId)
{
	for (int i = 0; i < this->appointmentsCount; i++)
	{
		if (this->appointmentsArr[i]->getId() == appointmentId)
		{
			this->appointmentsCount--;
			this->appointmentsArr[i] = nullptr;
			return true;
		}
	}
	return false;
}

void Vaccinee::setAppointmentsArr(Appointment** newAppointmentsArr) 
{
	this->appointmentsArr = newAppointmentsArr;
}


int Vaccinee::getPhasesComplete() const
{
	return this->phasesComplete;
}


Appointment** Vaccinee::getAppointmentsArr() const
{
	return this->appointmentsArr;
}


void Vaccinee::setRiskGroup(eRiskGroup riskGroup)
{
	this->riskGroup = riskGroup;
}

int Vaccinee::getAppointmentsCount() const
{
	return this->appointmentsCount;
}


void Vaccinee::setPhasesComplete(const int phasesComplete)
{
	this->phasesComplete = phasesComplete;
}

void Vaccinee::setAppointmentsCount(const int newAppointmentsCount)
{
	this->appointmentsCount = newAppointmentsCount;
}

bool Vaccinee::addAppointment(Appointment* appointment)
{
	for (int i = 0; i < appointmentsCount; i++)
		if (appointmentsArr[i] == appointment)
			return false;

	if (this->appointmentsCount == this->appointmentsCapacity)
	{
		this->appointmentsCapacity *= 2;
		Appointment** appointmentsTemp;
		appointmentsTemp = new Appointment * [this->appointmentsCapacity];
		for (int i = 0; i < this->appointmentsCount; i++)
			if (appointmentsArr[i] != nullptr)
				appointmentsTemp[i] = appointmentsArr[i];
		appointmentsTemp[this->appointmentsCount] = appointment;

		delete[] appointmentsArr;

		this->appointmentsArr = appointmentsTemp;
		this->appointmentsCount++;
		return true;
	}
	else {
		for (int i = 0; i < this->appointmentsCapacity; i++)
		{
			if (appointmentsArr[i] == nullptr)
			{
				this->appointmentsArr[i] = appointment;
				this->appointmentsCount++;
				return true;
			}
				
		}
		this->appointmentsArr[this->appointmentsCount] = appointment;
	}
		

	this->appointmentsCount++;
	return true;
}


const Vaccinee& Vaccinee::operator=(Vaccinee&& other)
{
	if (this != &other)
	{
		std::swap(this->name, other.name);
		std::swap(this->appointmentsArr, other.appointmentsArr);
		this->riskGroup = other.riskGroup;
		this->phasesComplete = other.phasesComplete;
		this->appointmentsCount = other.appointmentsCount;
		this->appointmentsCapacity = other.appointmentsCapacity;
	}
	return *this;
}

