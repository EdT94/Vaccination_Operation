#ifndef VACOP_VACCINATIONOPERATION_H
#define VACOP_VACCINATIONOPERATION_H

#include "Clinic.h"
#include "Vaccinee.h"
#include "MedicalWorker.h"


class VaccinationOperation 
{
private:
    Clinic** clinicsArr;
    Vaccinee** vaccineesArr;
    MedicalWorker** medicalWorkersArr;

    int clinicsCount;
    int vaccineesCount;
    int medicalWorkersCount;

    int clinicsArrCapacity;
    int vaccineesArrCapacity;
    int medicalWorkersArrCapacity;

    VaccinationOperation(const VaccinationOperation& other);

    VaccinationOperation& operator=(const VaccinationOperation& other);

public:
    VaccinationOperation();

    VaccinationOperation(VaccinationOperation&& other);

    ~VaccinationOperation();

    VaccinationOperation &operator=(VaccinationOperation&& other);

    void addClinic(Clinic& clinic);

    void addVaccinee(Vaccinee& vaccinee);

    void addMedicalWorker(MedicalWorker& medicalWorker); 

    bool removeClinic(const int clinicId);

    bool removeVaccinee(const int vaccineeId);

    bool removeMedicalWorker(const int medicalWorkerId);

    Clinic* getClinic(const int clinicId);

    Vaccinee* getVaccinee(const int vaccineeId);

    MedicalWorker* getMedicalWorker(const int medicalWorkerId);

    void setAppointment(Appointment* appointment) ;

    bool cancelAppointment(const int appointmentId);

    void showAllAppointments() const;

    void showAllMedicalWorkers() const;

    void showAllVaccinees() const;

    void showAllClinics() const;

    void showAppointmentsForVaccinee(const int vaccineeId) const;

    void showAppointmentsForMedicalWorker(const int medicalWorkerId) const;

    void showAppointmentsForClinic(const int clinicId) const;

    bool replaceWorkerForAppointment(const int appointmentId, const int newWorkerId);

    void showWorkersForClinic(const int clinicId) const;

    void showVaccineesOfRiskGroup(Vaccinee::eRiskGroup riskGroup) const;

    void showVaccineesWithNoAppointments() const;

    MedicalWorker* getMedicalWorkerFromClinic(int appointmentWorkerId, int appointmentClinicId);

    Clinic** getClinicsArr();

    Vaccinee** getVaccineesArr();

    MedicalWorker** getMedicalWorkersArr();

    int getClinicsCount() const;

    int getVaccineesCount() const;

    int getMedicalWorkersCount() const;


};


#endif //VACOP_VACCINATIONOPERATION_H
