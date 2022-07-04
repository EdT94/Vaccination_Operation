#ifndef VACOP_VACCINEE_H
#define VACOP_VACCINEE_H

#include <ostream>
#include "Person.h"
using namespace std;
class Appointment;

static const char* riskGroups[5] = { "Regular", "High", "Max"," RiskGroupCount", "Invalid" };

class Vaccinee : virtual public Person 
{


private: 
    const Vaccinee &operator=(const Vaccinee &other);

public:
    enum eRiskGroup {
        Regular, High, Max,
        RiskGroupCount,
        Invalid
    };
    

protected:
    int phasesComplete;
    Appointment** appointmentsArr;
    eRiskGroup riskGroup;
    int appointmentsCount;
    int appointmentsCapacity;

public:
    Vaccinee(const char *name, int phasesComplete = 0, eRiskGroup riskGroup = Regular);

    Vaccinee(const Vaccinee& other);

    Vaccinee(Vaccinee&& other) ;

    const Vaccinee& operator=(Vaccinee &&other);

    int getPhasesComplete() const;

    void setPhasesComplete(const int phasesComplete);

    bool addAppointment(Appointment* appointment);

    bool removeAppointment(const int appointmentId);

    Appointment** getAppointmentsArr() const;

    eRiskGroup getRiskGroup() const { return this->riskGroup;}

    void setRiskGroup(eRiskGroup riskGroup);

    void setAppointmentsArr(Appointment** newAppointmentsArr);

    int getAppointmentsCount() const;

    void setAppointmentsCount(const int newAppointmentsCount);

    virtual void toOs2(ostream& os) const {}

    virtual void toOs(ostream& os) const override
    {
        os<< ", risk group: " << riskGroups[riskGroup] << ", phases complete : " << phasesComplete
            << ", appointments count: " <<appointmentsCount <<endl;
    }

    
};


#endif //VACOP_VACCINEE_H
