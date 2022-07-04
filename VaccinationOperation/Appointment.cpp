#include "Appointment.h"
#include "MedicalWorker.h"
#include "Clinic.h"
#include "Vaccinee.h"

int Appointment::current_id = 0;

Appointment::Appointment(Date& date, Clinic& clinic, Vaccinee& vaccinee, MedicalWorker* medicalWorker) : id(++current_id), date(date), clinic(clinic), vaccinee(vaccinee)
{
	clinic.addAppointment(this);
	vaccinee.addAppointment(this);

	this->setMedicalWorker(medicalWorker);
}


const int Appointment::getId() const
{
	return this->id;
}


MedicalWorker* Appointment::getMedicalWorker() const
{
	return this->medicalWorker;
}

void Appointment::setMedicalWorker(MedicalWorker* medicalWorker)
{
	if (this->medicalWorker != medicalWorker)
	{
		if (this->medicalWorker != nullptr)
			medicalWorker->removeAppointment(this->id);
		
		this->medicalWorker = medicalWorker;

		if (this->medicalWorker != nullptr)
			medicalWorker->addAppointment(this);
	}

}

const Date& Appointment::getDate() const
{
	return this->date;
}

Clinic& Appointment::getClinic() const 
{
	return this->clinic;
}

Vaccinee& Appointment::getVaccinee() const
{
	return this->vaccinee;
}

