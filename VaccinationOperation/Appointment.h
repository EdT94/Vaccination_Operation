#ifndef VACOP_APPOINTMENT_H
#define VACOP_APPOINTMENT_H

#include <ostream>
#include "Date.h"
#include "Clinic.h"
#include "Vaccinee.h"
#include "MedicalWorker.h"

class MedicalWorker;

class Clinic;

class Vaccinee;

class Appointment 
{
private:
    static int current_id; 
    int id;
    Date date;
    Clinic& clinic;
    Vaccinee& vaccinee;
    MedicalWorker *medicalWorker;

public:
    Appointment(Date& date, Clinic& clinic, Vaccinee& vaccinee, MedicalWorker* medicalWorker = nullptr);

    const int getId() const;

    MedicalWorker* getMedicalWorker() const;

    void setMedicalWorker(MedicalWorker * medicalWorker);

    const Date &getDate() const;

    Clinic &getClinic() const;

    Vaccinee &getVaccinee() const;


    friend std::ostream& operator<<(std::ostream& os, const Appointment& appointment)
    {
        os << "Appointment id: " << appointment.id << ", date: " << appointment.date << ", clinic id: " << appointment.clinic.getId() << ", vaccinee id: "
            << appointment.vaccinee.getId();
        if (appointment.getMedicalWorker() == nullptr)
            os << ", no medical worker for this appointment" << endl;
        else
            os << ", medical worker id: " << appointment.medicalWorker->getId() << endl;
        return os;
    }

    
};


#endif //VACOP_APPOINTMENT_H
