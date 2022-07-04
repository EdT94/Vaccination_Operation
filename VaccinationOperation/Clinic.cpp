#include "Clinic.h"
#include "Appointment.h"
#include "MedicalWorker.h"

int Clinic::current_id = 0;

Clinic::Clinic(const char* name, const Address& address) : id(++current_id), address(address)
{
	this->appointmentsArrCapacity = 2;
	this->medicalWorkersArrCapacity = 2;

	this->appointments = new Appointment* [appointmentsArrCapacity];
	this->medicalWorkers = new MedicalWorker* [medicalWorkersArrCapacity];
	this->appointments[0] = nullptr;
	this->appointments[1] = nullptr;
	this->appointmentsCount = 0;
	this->medicalWorkersCount = 0;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}


Clinic::Clinic(Clinic&& other) : address(other.address)
{
	this->name = other.name;
	other.name = nullptr;

	this->appointments = other.appointments;
	other.appointments = nullptr;

	this->medicalWorkers = other.medicalWorkers;
	other.medicalWorkers = nullptr;

	this->id = other.id;
	this->appointmentsCount = other.appointmentsCount;
	this->medicalWorkersCount = other.medicalWorkersCount;
	this->appointmentsArrCapacity = other.appointmentsArrCapacity;
	this->medicalWorkersArrCapacity = other.medicalWorkersArrCapacity;
}

int Clinic::getId() const
{
	return this->id;
}


const char* Clinic::getName() const
{
	return this->name;
}


char* Clinic::getName() 
{
	return this->name;
}


bool Clinic::setName(const char* name)
{
	delete[] this->name;
	this->name = strdup(name);
	return name == nullptr ? false : true;
}


const Address& Clinic:: getAddress() const
{
	return this->address;
}


int Clinic::getAppointmentsCount() const
{
	return this->appointmentsCount;
}

int Clinic::getAppointmentsCapacity() const
{
	return appointmentsArrCapacity;
}


int Clinic::getMedicalWorkersCount() const
{
	return this->medicalWorkersCount;
}


Appointment** Clinic::getAppointments() const
{
	return this->appointments;
}


MedicalWorker** Clinic::getMedicalWorkers() const
{
	return this->medicalWorkers;
}

bool Clinic::addAppointment(Appointment* appointment)
{
	for (int i = 0; i < appointmentsCount; i++)
		if (this->appointments[i] == appointment)
			return false;

	if (this->appointmentsCount == this->appointmentsArrCapacity)
	{
		this->appointmentsArrCapacity *= 2;
		Appointment** appointmentsTemp;
		appointmentsTemp = new Appointment * [this->appointmentsArrCapacity];
		for (int i = 0; i < this->appointmentsArrCapacity; i++)
			if (i < this->appointmentsCount)
			{
				if (this->appointments[i] != nullptr)
					appointmentsTemp[i] = this->appointments[i];
			}	
			else
				appointmentsTemp[i] = nullptr;

		for (int i = 0; i < this->appointmentsArrCapacity; i++)
		{
			if (appointmentsTemp[i] == nullptr)
				appointmentsTemp[i] = appointment;
			break;
		}
		appointmentsTemp[this->appointmentsCount] = appointment;
		delete[] this->appointments;

		this->appointments = appointmentsTemp;
		this->appointmentsCount++;
		return true;
	}
	else
	{
		for (int i = 0; i < this->appointmentsArrCapacity; i++)
		{
			if (this->appointments[i] == nullptr) 
			{
				this->appointments[i] = appointment;
				this->appointmentsCount++;
				return true;
			}
		}
		this->appointments[this->appointmentsCount] = appointment;
	}
		
	this->appointmentsCount++;
	return true;
	
}

void Clinic::setAppointments(Appointment** newAppointments)
{
	this->appointments = newAppointments;
}


bool Clinic::addMedicalWorker(MedicalWorker& medicalWorker)
{
	for (int i = 0; i < medicalWorkersCount; i++)
		if (medicalWorkers[i]->getId() == medicalWorker.getId())
			return false;
		
	
	if (this->medicalWorkersCount == this->medicalWorkersArrCapacity)
	{
		this->medicalWorkersArrCapacity *= 2;
		MedicalWorker** medicalWorkersTemp;
		medicalWorkersTemp = new MedicalWorker* [this->medicalWorkersArrCapacity];
		for (int i = 0; i < this->medicalWorkersCount; i++)
			if(this->medicalWorkers[i] !=nullptr)
				medicalWorkersTemp[i] = this->medicalWorkers[i];
		medicalWorkersTemp[this->medicalWorkersCount] = &medicalWorker;

		delete[]this->medicalWorkers;

		this->medicalWorkers = medicalWorkersTemp;
		this->medicalWorkersCount++;
		return true;
	}
	else
	{
		for (int i = 0; i < this->medicalWorkersArrCapacity; i++)
		{
			if (this->medicalWorkers[i] == nullptr) {
				this->medicalWorkers[i] = &medicalWorker;
				this->medicalWorkersCount++;
				return true;
			}	
		}
		this->medicalWorkers[this->medicalWorkersCount] = &medicalWorker;
		

	}
	this->medicalWorkersCount++;

	medicalWorker.setClinic(this);
	return true;

}



bool Clinic::removeAppointment(const int appointmentId)
{
	for (int i = 0; i < this->appointmentsCount ; i++)
	{
		if (this->appointments[i] != nullptr && this->appointments[i]->getId() == appointmentId)
		{
			
			if (this->appointments[i]->getVaccinee().removeAppointment(appointmentId))
			{
				if (this->appointments[i]->getMedicalWorker() != nullptr)
				{
					if (this->appointments[i]->getMedicalWorker()->removeAppointment(appointmentId)) {
						delete[] this->appointments[i];
						this->appointmentsCount--;
						return true;
					}
					else
						return false;
				}
				else
					return true;
			}
			else
				return false;
		}
	}
}


bool Clinic::removeMedicalWorker(MedicalWorker& medicalWorker)
{
	int idToRemove = medicalWorker.getId();

	for (int i = 0; i < this->medicalWorkersCount; i++)
	{
		if (this->medicalWorkers[i]->getId() == idToRemove)
		{
			this->medicalWorkers[i] = nullptr;
			this->medicalWorkersCount--;
			return true;
		}
	}
}


const Clinic& Clinic::operator=(Clinic&& other)
{
	if (this != &other)
	{
		std::swap(this->name, other.name);
		std::swap(this->address, other.address);
		std::swap(this->appointments, other.appointments);
		std::swap(this->medicalWorkers, other.medicalWorkers);
		this->appointmentsCount = other.appointmentsCount;
		this->medicalWorkersCount = other.medicalWorkersCount;
		this->appointmentsArrCapacity = other.appointmentsArrCapacity;
		this->medicalWorkersArrCapacity = other.medicalWorkersArrCapacity;
	}
	return *this;
}

bool Clinic::operator<(const Clinic& other) const
{
	return this->appointmentsCount < other.getAppointmentsCount();
}


bool Clinic::operator>(const Clinic& other) const
{
	return !(*this < other);
}


bool Clinic::operator<=(const Clinic& other) const
{
	return *this < other || *this == other;
}


bool Clinic::operator>=(const Clinic& other) const
{
	return *this > other || *this == other;

}


bool Clinic::operator==(const Clinic& other) const
{
	return this->appointmentsCount == other.getAppointmentsCount();
}


bool Clinic::operator!=(const Clinic& other) const
{
	return !(*this == other);
}


Clinic::~Clinic()
{
	delete[] this->name;
	
	for (int i = 0; i < this->appointmentsCount; i++)
		delete[] this->appointments[i];

	if (this->appointments != nullptr)
		delete[] this->appointments;

	for (int i = 0; i < this->medicalWorkersCount; i++)
		delete[] this->medicalWorkers[i];

	if (this->medicalWorkers != nullptr)
		delete[] this->medicalWorkers;
}