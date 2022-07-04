#ifndef VACOP_CLINIC_H
#define VACOP_CLINIC_H

#include <ostream>
#include "Address.h"
#include "MedicalWorker.h"


using namespace std;

class Appointment;

class Clinic 
{

private:
    Clinic(const Clinic& other);

    const Clinic& operator=(const Clinic& other);


protected:
    static int current_id;
    int id;
    char* name;
    Address address;
    Appointment** appointments;
    MedicalWorker** medicalWorkers;
    int appointmentsCount;
    int medicalWorkersCount;
    int appointmentsArrCapacity;
    int medicalWorkersArrCapacity;

public:
    Clinic(const char* name, const Address& address);

    Clinic(Clinic&& other);

    const Clinic& operator=(Clinic&& other);

    int getId() const;

    bool addAppointment(Appointment* appointment);

    bool addMedicalWorker(MedicalWorker& medicalWorker);

    bool removeAppointment(const int appointmentId);

    bool removeMedicalWorker(MedicalWorker& medicalWorker);

    const char* getName() const;

    char* getName() ;

    bool setName(const char* name);

    const Address& getAddress() const;

    Appointment** getAppointments() const;

    void setAppointments(Appointment** newAppointments);

    MedicalWorker** getMedicalWorkers() const;

    virtual void toOs(ostream& os) const {}

    friend std::ostream& operator<<(std::ostream& os, const Clinic& clinic)
    {
        os << "Clinic id: " << clinic.id << ", name: " << clinic.name << ", address: " << clinic.address <<  endl;
        if (clinic.medicalWorkersCount != 0)
        {
            os << clinic.medicalWorkersCount << " medical workers:" << endl;
            for (int i = 0; i < clinic.medicalWorkersCount; i++)
                os << *clinic.medicalWorkers[i] << endl;
        }

        clinic.toOs(os);
        return os;
    }

    int getAppointmentsCount() const;

    int getAppointmentsCapacity() const;

    int getMedicalWorkersCount() const;

    bool operator<(const Clinic& other) const;

    bool operator>(const Clinic& other) const;

    bool operator<=(const Clinic& other) const;

    bool operator>=(const Clinic& other) const;

    bool operator==(const Clinic& other) const;

    bool operator!=(const Clinic& other) const;

    virtual ~Clinic();
};


#endif //VACOP_CLINIC_H
