#ifndef VACOP_MEDICALWORKER_H
#define VACOP_MEDICALWORKER_H

#include <ostream>
#include "Person.h"
using namespace std;

class Clinic;

class Appointment;

class MedicalWorker : virtual public Person 
{

private:
    const MedicalWorker& operator=(const MedicalWorker& other);
    
protected:
    Appointment** appointmentsArr;
    Clinic* clinic;
    int appointmentsCount;
    int appointmentsCapacity;

public:
    MedicalWorker(const char* name, Clinic* clinic = nullptr);

    MedicalWorker(const MedicalWorker& base);

    const MedicalWorker& operator=(MedicalWorker&& other);

    MedicalWorker(MedicalWorker&& other);

    virtual ~MedicalWorker();

    bool addAppointment(Appointment* appointment);

    bool removeAppointment(const int appointmentId);

    Appointment** getAppointmentsArr() const;

    Clinic* getClinic() const;

    void setClinic(Clinic* clinic);

    void setAppointmentsCount(const int newAppointmentsCount);

    void setAppointmentsArr(Appointment** newAppointmentsArr);

    int getAppointmentsCount() const;

    virtual void toOs(ostream& os) const override 
    {
    
        os << " ,number of appointments: " << appointmentsCount ;
        if (this->clinic != nullptr)
        {}
        else
            os << ", is unemployed";
        os << endl;
        
    }

  

};


#endif //VACOP_MEDICALWORKER_H
