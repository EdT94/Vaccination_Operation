#include "MedicalWorker.h"
#include "Appointment.h"
#include "Clinic.h"

MedicalWorker::MedicalWorker(const char* name, Clinic* clinic) : Person(name)
{
	this->appointmentsCapacity = 2;
	this->appointmentsCount = 0;

	appointmentsArr = new Appointment * [appointmentsCapacity];
	this->setClinic(clinic);
}

MedicalWorker::MedicalWorker(const MedicalWorker& base) : Person(base.getName())
{
	this->appointmentsCapacity = base.appointmentsCapacity;
	this->appointmentsCount = base.appointmentsCount;

	this->appointmentsArr = new Appointment * [this->appointmentsCapacity];

	for (int i = 0; i < base.getAppointmentsCount(); i++)
		this->appointmentsArr[i] = base.appointmentsArr[i];
	
	this->setClinic(base.getClinic());
}

MedicalWorker::MedicalWorker(MedicalWorker&& other) : Person(other.name)
{
	this->name = other.name;
	other.name = nullptr;

	this->appointmentsArr = other.appointmentsArr;
	other.appointmentsArr = nullptr;

	this->clinic = other.clinic;
	other.clinic = nullptr;

	this->appointmentsCount = other.appointmentsCount;
	this->appointmentsCapacity = other.appointmentsCapacity;
}

void MedicalWorker::setClinic(Clinic* clinic) 
{
	if (this->clinic != clinic)
	{
		this->clinic = clinic;
		if (this->clinic != nullptr)
			this->clinic->addMedicalWorker(*this);
	}
}


bool MedicalWorker::addAppointment(Appointment* appointment)
{
	for (int i = 0; i < appointmentsCount; i++)
	{
		if (appointmentsArr[i] == appointment)
			return false;
	}

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
	else 
	{
		for (int i = 0; i < this->appointmentsCapacity; i++)
		{
			if (appointmentsArr[i] == nullptr)
			{
				this->appointmentsArr[i] = appointment;
				this->appointmentsCount++;
				return true;
			}
			this->appointmentsArr[this->appointmentsCount] = appointment;
		}
	}
	this->appointmentsCount++;
	appointment->setMedicalWorker(this);
	return true;
}

void MedicalWorker::setAppointmentsCount(const int newAppointmentsCount)
{
	this->appointmentsCount = newAppointmentsCount;
}

bool MedicalWorker::removeAppointment(const int appointment)
{

	for (int i = 0; i < this->appointmentsCount; i++)
	{
		if (this->appointmentsArr[i]->getId() == appointment)
		{
			this->appointmentsCount--;
			this->appointmentsArr[i] = nullptr;
			return true;
		}
	}
	return false;
}



Appointment** MedicalWorker::getAppointmentsArr() const
{
	return this->appointmentsArr;
}

void MedicalWorker::setAppointmentsArr(Appointment** newAppointmentsArr)
{
	this->appointmentsArr = newAppointmentsArr;
}

Clinic* MedicalWorker::getClinic() const
{
	return this->clinic;
}

int MedicalWorker::getAppointmentsCount() const
{
	return this->appointmentsCount;
}

const MedicalWorker& MedicalWorker::operator=(MedicalWorker&& other)
{
	if (this != &other)
	{
		std::swap(this->name, other.name);
		std::swap(this->appointmentsArr, other.appointmentsArr);
		std::swap(this->clinic, other.clinic);
		this->appointmentsCount = other.appointmentsCount;
		this->appointmentsCapacity = other.appointmentsCapacity;
	}
	return *this;
}

MedicalWorker::~MedicalWorker()
{
	if (this->appointmentsArr != nullptr)
		delete[] this->appointmentsArr;
}