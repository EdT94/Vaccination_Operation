#include "VaccineeWorker.h"

VaccineeWorker::VaccineeWorker(const MedicalWorker& medicalWorker, const Vaccinee& vaccinee, bool allowedToWork)
	: Person(medicalWorker.getName()), MedicalWorker(medicalWorker), Vaccinee(vaccinee), allowedToWork(allowedToWork) {}

bool VaccineeWorker::isAllowedToWork() const
{
	return this->allowedToWork;
}

void VaccineeWorker::setAllowedToWork(const bool isAllowedToWork)
{
	this->allowedToWork = isAllowedToWork;
}