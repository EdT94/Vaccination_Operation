#include "VaccinationOperation.h"
#include "Appointment.h"
#include "Vaccinee.h"
#include "MedicalWorker.h"



VaccinationOperation::VaccinationOperation()
{
	this->clinicsCount = 0;
	this->vaccineesCount = 0;
	this->medicalWorkersCount = 0;
	this-> clinicsArrCapacity = 2;
	this->vaccineesArrCapacity = 2;
	this->medicalWorkersArrCapacity = 2;
	this->clinicsArr = new Clinic* [this->clinicsArrCapacity];
	this->clinicsArr[0] = nullptr; 
	this->clinicsArr[1] = nullptr;
	this->vaccineesArr= new Vaccinee * [this->vaccineesArrCapacity];
	this->vaccineesArr[0] = nullptr;
	this->vaccineesArr[1] = nullptr;
	this->medicalWorkersArr= new MedicalWorker * [this->medicalWorkersArrCapacity];
	this->medicalWorkersArr[0] = nullptr;
	this->medicalWorkersArr[1] = nullptr;
}

VaccinationOperation::VaccinationOperation(VaccinationOperation&& other)
{
	this->clinicsArr = other.clinicsArr;
	other.clinicsArr = nullptr;

	this->vaccineesArr = other.vaccineesArr;
	other.vaccineesArr = nullptr;

	this->medicalWorkersArr = other.medicalWorkersArr;
	other.medicalWorkersArr = nullptr;

	this->clinicsCount = other.clinicsCount;
	this->vaccineesCount = other.vaccineesCount;
	this->medicalWorkersCount = other.medicalWorkersCount;
	this->clinicsArrCapacity = other.clinicsArrCapacity;
	this->vaccineesArrCapacity = other.vaccineesArrCapacity;
	this->medicalWorkersArrCapacity = other.medicalWorkersArrCapacity;
}

VaccinationOperation& VaccinationOperation::operator=(VaccinationOperation&& other)
{
	if (this != &other)
	{
		std::swap(this->clinicsArr, other.clinicsArr);
		std::swap(this->vaccineesArr, other.vaccineesArr);
		std::swap(this->medicalWorkersArr, other.medicalWorkersArr);
		this->clinicsCount = other.clinicsCount;
		this->vaccineesCount = other.vaccineesCount;
		this->medicalWorkersCount = other.medicalWorkersCount;
		this->clinicsArrCapacity = other.clinicsArrCapacity;
		this->vaccineesArrCapacity = other.vaccineesArrCapacity;
		this->medicalWorkersArrCapacity = other.medicalWorkersArrCapacity;
	}
	return *this;
}

void VaccinationOperation::addClinic(Clinic& clinic)
{
	if (this->clinicsCount == this->clinicsArrCapacity)
	{
		this->clinicsArrCapacity *= 2;
		Clinic** clinicsTemp;
		clinicsTemp = new Clinic * [this->clinicsArrCapacity];
		for (int i = 0; i < this->clinicsCount; i++)
			if (this->clinicsArr[i] != nullptr)
				clinicsTemp[i] = this->clinicsArr[i];
			
		clinicsTemp[this->clinicsCount] = &clinic;

		delete[]this->clinicsArr;

		this->clinicsArr = clinicsTemp;
	}
	else
	{
		for (int i = 0; i < this->clinicsArrCapacity; i++)
		{
			if (this->clinicsArr[i] == nullptr)
				this->clinicsArr[i] = &clinic;
		}
		this->clinicsArr[this->clinicsCount] = &clinic;
	}


	this->clinicsCount++;
}


void VaccinationOperation::addVaccinee(Vaccinee& vaccinee)
{
	if (this->vaccineesCount == this->vaccineesArrCapacity)
	{
		this->vaccineesArrCapacity *= 2;
		Vaccinee** vaccineesTemp;
		vaccineesTemp = new Vaccinee * [this->vaccineesArrCapacity];
		for (int i = 0; i < this->vaccineesCount; i++)
			if (this->vaccineesArr[i] != nullptr)
				vaccineesTemp[i] = this->vaccineesArr[i];
		vaccineesTemp[this->vaccineesCount] = &vaccinee;

		delete[] this->vaccineesArr;

		this->vaccineesArr = vaccineesTemp;
	}
	else
	{
		for (int i = 0; i < this->vaccineesArrCapacity; i++)
		{
			if (this->vaccineesArr[i] == nullptr)
			{
				this->vaccineesArr[i] = &vaccinee;
				break;
			}	
		}
		this->vaccineesArr[this->vaccineesCount] = &vaccinee;
	}

	this->vaccineesCount++;
}


void VaccinationOperation::addMedicalWorker(MedicalWorker& medicalWorker)
{
	if (this->medicalWorkersCount == this->medicalWorkersArrCapacity)
	{
		this->medicalWorkersArrCapacity *= 2;
		MedicalWorker** medicalWorkersTemp;
		medicalWorkersTemp = new MedicalWorker * [this->medicalWorkersArrCapacity];
		for (int i = 0; i < this->medicalWorkersCount; i++)
			if (this->medicalWorkersArr[i] != nullptr)
				medicalWorkersTemp[i] = this->medicalWorkersArr[i];
		medicalWorkersTemp[this->medicalWorkersCount] = &medicalWorker;

		delete[]this->medicalWorkersArr;

		this->medicalWorkersArr = medicalWorkersTemp;
	}
	else
	{
		for (int i = 0; i < this->medicalWorkersArrCapacity;i++)
		{
			if (this->medicalWorkersArr[i] == nullptr)
			{
				this->medicalWorkersArr[i] = &medicalWorker;
				break;
			}
		}
		this->medicalWorkersArr[this->medicalWorkersCount] = &medicalWorker;
	}

	this->medicalWorkersCount++;
}



bool VaccinationOperation::removeClinic(const int clinicId)
{
	for (int i = 0; i < this->clinicsCount; i++)
	{
		if (this->clinicsArr[i]->getId() == clinicId)
		{
			this->clinicsArr[i] = nullptr;
			this->clinicsCount--;
			return true;
		}
	}
	return false;
}

bool VaccinationOperation::removeVaccinee(const int vaccineeId)
{
	for (int i = 0; i < this->vaccineesCount; i++)
	{
		if (this->vaccineesArr[i]->getId() == vaccineeId)
		{
			this->vaccineesArr[i] = nullptr;
			this->vaccineesCount--;
			return true;
		}
	}
	return false;
}


bool VaccinationOperation::removeMedicalWorker(const int medicalWorkerId)
{
	for (int i = 0; i < this->medicalWorkersCount; i++)
	{
		if (this->medicalWorkersArr[i]->getId() == medicalWorkerId)
		{
			this->medicalWorkersArr[i] = nullptr;
			this->medicalWorkersCount--;
			return true;
		}
	}
	return false;
}

Clinic* VaccinationOperation::getClinic(const int clinicId)
{
	for (int i = 0; i < this->clinicsCount; i++)
	{
		if (this->clinicsArr[i]->getId() == clinicId)
			return this->clinicsArr[i];
	}

	return nullptr;
}


Vaccinee* VaccinationOperation::getVaccinee(const int vaccineeId)
{
	for (int i = 0; i < this->vaccineesCount; i++)
	{
		if (this->vaccineesArr[i]->getId() == vaccineeId)
			return this->vaccineesArr[i];
	}

	return nullptr;
}


MedicalWorker* VaccinationOperation::getMedicalWorker(const int medicalWorkerId)
{
	for (int i = 0; i < this->medicalWorkersCount; i++)
	{
		if (this->medicalWorkersArr[i]->getId() == medicalWorkerId)
			return this->medicalWorkersArr[i];
	}

	return nullptr;
}

MedicalWorker* VaccinationOperation::getMedicalWorkerFromClinic(int appointmentWorkerId, int appointmentClinicId) 
{
	Clinic* clinic = this->getClinic(appointmentClinicId);
	if (clinic == nullptr)
		return nullptr;
	for (int i = 0; i < clinic->getMedicalWorkersCount(); i++)
		if (clinic->getMedicalWorkers()[i]->getId() == appointmentWorkerId)
			return clinic->getMedicalWorkers()[i];

	return nullptr;
}


void VaccinationOperation::setAppointment(Appointment* appointment) 
{
	int workerId;
	int clinicId = appointment->getClinic().getId();
	int vaccineeId = appointment->getVaccinee().getId();
	if(appointment->getMedicalWorker() == nullptr)
		workerId = -1;
	else if (appointment->getMedicalWorker()->getId() == NULL)
		workerId = -1;
	else
		workerId = appointment->getMedicalWorker()->getId();

	for (int i = 0; i < this->clinicsCount; i++)
		if (this->clinicsArr[i]->getId() == clinicId)
			this->clinicsArr[i]->addAppointment(appointment);

	for (int i = 0; i < this->vaccineesCount; i++)
		if (this->vaccineesArr[i]->getId() == vaccineeId)
			this->vaccineesArr[i]->addAppointment(appointment);

	for (int i = 0; i < this->medicalWorkersCount; i++)
		if (this->medicalWorkersArr[i]->getId() == workerId)
			this->medicalWorkersArr[i]->addAppointment(appointment);

}


bool VaccinationOperation::cancelAppointment(const int appointmentId)
{
	Appointment** currentAppointments = nullptr;

	for (int i = 0; i < this->clinicsCount; i++)
	{
		currentAppointments = this->clinicsArr[i]->getAppointments();
		for (int j = 0; j < this->clinicsArr[i]->getAppointmentsCapacity(); j++)
		{
			if (currentAppointments[j] != nullptr)
			{
				if (currentAppointments[j]->getId() == appointmentId)
				{
					if (this->clinicsArr[i]->removeAppointment(appointmentId))
					{
						currentAppointments[j] = nullptr;
						cout << "Appointment was canceled." << endl;
						return true;
					}
					else
						return false;
				}
			}
		}
		return false;
	}
}

void VaccinationOperation::showAllAppointments() const
{
	cout << "All appointments:\n";
	Appointment** currentAppointments;
	for (int i = 0; i < this->clinicsCount; i++)
	{
		currentAppointments = this->clinicsArr[i]->getAppointments();
		for (int j = 0; j < this->clinicsArr[i]->getAppointmentsCapacity(); j++)
			if (currentAppointments[j] != nullptr)
				cout << *currentAppointments[j];
			else
				continue;
	}
	cout << "\n";
}

void VaccinationOperation::showAllMedicalWorkers() const
{
	if (this->medicalWorkersCount == 0)
	{
		cout << "There is no medical workers" << endl;
		return;
	}

	cout << "\n\nAll medical workers:\n";
	for (int i = 0; i < this->getMedicalWorkersCount(); ++i)
		cout << *this->medicalWorkersArr[i];
}

void VaccinationOperation::showAllVaccinees() const
{
	if (this->vaccineesCount == 0)
	{
		cout << "There is no vaccinees" << endl;
		return;
	}

	cout << "\n\nAll vaccinees:\n";
	for (int i = 0; i < this->getVaccineesCount(); ++i)
		cout << *this->vaccineesArr[i];
}

void VaccinationOperation::showAllClinics() const
{
	if (this->clinicsCount == 0)
	{
		cout << "There is no clinics" << endl;
		return;
	}

	cout << "\n\nAll clinics:\n";
	for (int i = 0; i < this->getClinicsCount(); ++i)
		cout << *this->clinicsArr[i];
}


void VaccinationOperation::showAppointmentsForVaccinee(const int vaccineeId) const
{
	
	Appointment** currentAppointments = nullptr;
	int numOfAppointments = -1;

	for (int i = 0; i < this->vaccineesCount; i++)
	{
		if (this->vaccineesArr[i]->getId() == vaccineeId)
		{
			currentAppointments = this->vaccineesArr[i]->getAppointmentsArr();
			numOfAppointments = this->vaccineesArr[i]->getAppointmentsCount();
			break;
		}
	}
	if (numOfAppointments == -1 || numOfAppointments == 0)
	{
		cout << "There is no appointments for this vaccinee" << endl;
		return;
	}
		

	cout << "All appointments for vaccinee id " << vaccineeId << " are:\n";
	for (int i = 0; i < numOfAppointments; i++)
		cout << *currentAppointments[i];
	
	cout << "\n";	
	return ;
}


void VaccinationOperation::showAppointmentsForMedicalWorker(const int medicalWorkerId) const
{
	
	Appointment** currentAppointments = nullptr;
	int numOfAppointments = -1;

	for (int i = 0; i < this->medicalWorkersCount; i++)
	{
		if (this->medicalWorkersArr[i]->getId() == medicalWorkerId)
		{
			currentAppointments = this->medicalWorkersArr[i]->getAppointmentsArr();
			numOfAppointments = this->medicalWorkersArr[i]->getAppointmentsCount();
			break;
		}
	}
	if (numOfAppointments == -1 || numOfAppointments == 0)
	{
		cout << "There is no appointments for this medical worker" << endl;
		return;
	}
		
	cout << "All appointments for medical worker's id " << medicalWorkerId << " are:\n";
	for (int i = 0; i < numOfAppointments; i++)
		cout << *currentAppointments[i] << endl;
	
	cout << endl;
	return;
}


void VaccinationOperation::showAppointmentsForClinic(const int clinicId) const
{
	
	Appointment** currentAppointments = nullptr;
	int numOfAppointments = -1;

	for (int i = 0; i < this->clinicsCount; i++)
	{
		if (this->clinicsArr[i]->getId() == clinicId)
		{
			currentAppointments = this->clinicsArr[i]->getAppointments();
			numOfAppointments = this->clinicsArr[i]->getAppointmentsCount();
			break;
		}
	}
	if (numOfAppointments == -1 || numOfAppointments == 0)
	{
		cout << "There is no appointments for this clinic" << endl;
		return;
	}
		
	cout << "All appointments for clinic id " << clinicId << " are:\n";
	for (int i = 0; i < numOfAppointments; i++)
		cout << *currentAppointments[i] << endl;

	cout << "\n";
	return;
}



bool VaccinationOperation::replaceWorkerForAppointment(const int appointmentId, const int newWorkerId)
{
	if (!getMedicalWorker(newWorkerId))
		return false;
	Appointment** currentAppointments;
	for (int i = 0; i < this->medicalWorkersCount; i++)
	{
		currentAppointments = this->medicalWorkersArr[i]->getAppointmentsArr();
		for (int j = 0; this->medicalWorkersArr[i]->getAppointmentsCount(); j++)
			if (currentAppointments[j]->getId() == appointmentId)
			{
				currentAppointments[j]->setMedicalWorker(getMedicalWorker(newWorkerId));
					return true;
			}				
	}
	return false;
}

void VaccinationOperation::showWorkersForClinic(const int clinicId) const
{
	cout << "All medical workers for clinic id " << clinicId << " are:\n";
	MedicalWorker** medicalWorkers;
	for (int i = 0; i < this->clinicsCount; i++)
	{
		if (this->clinicsArr[i]->getId() == clinicId)
		{
			medicalWorkers = this->clinicsArr[i]->getMedicalWorkers();
			for (int j = 0; j < this->clinicsArr[i]->getMedicalWorkersCount(); j++)
				cout << *medicalWorkers[j];
		break;
		}	
	}
}


void VaccinationOperation::showVaccineesOfRiskGroup(Vaccinee::eRiskGroup riskGroup) const
{
	cout << "All vaccinees of risk group: " << riskGroups[riskGroup] << " are:\n";

	for (int i = 0; i < this->vaccineesCount; i++)
		if (this->vaccineesArr[i]->getRiskGroup() == riskGroup)
			cout << *this->vaccineesArr[i];
}

void VaccinationOperation::showVaccineesWithNoAppointments() const
{
	cout << "All vaccinees with no appointments are: \n";
	for (int i = 0; i < this->vaccineesCount; i++)
		if (this->vaccineesArr[i]->getAppointmentsCount() == 0)
			cout << *this->vaccineesArr[i];
}

Clinic** VaccinationOperation::getClinicsArr()
{
	return this->clinicsArr;
}


Vaccinee** VaccinationOperation::getVaccineesArr()
{
	return this->vaccineesArr;
}


MedicalWorker** VaccinationOperation::getMedicalWorkersArr()
{
	return this->medicalWorkersArr;
}


int VaccinationOperation::getClinicsCount() const
{
	return this->clinicsCount;
}


int VaccinationOperation::getVaccineesCount() const
{
	return this->vaccineesCount;
}


int VaccinationOperation::getMedicalWorkersCount() const
{
	return this->medicalWorkersCount;
}


VaccinationOperation::~VaccinationOperation()
{
	for (int i = 0; i < this->clinicsCount; i++)
		delete[] this->clinicsArr[i];

	if (this->clinicsArr != nullptr)
		delete[] this->clinicsArr;

	if (this->vaccineesArr != nullptr)
		delete[] this->vaccineesArr;

}
