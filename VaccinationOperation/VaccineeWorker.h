#ifndef VACOP_VACCINEEWORKER_H
#define VACOP_VACCINEEWORKER_H


#include <ostream>
#include "MedicalWorker.h"
#include "Vaccinee.h"

class VaccineeWorker : public MedicalWorker, public Vaccinee 
{
protected:
    bool allowedToWork;

public:
    VaccineeWorker(const MedicalWorker& medicalWorker, const Vaccinee& vaccinee, bool allowedToWork = true);

    bool isAllowedToWork() const;

    void setAllowedToWork(const bool isAllowedToWork);

    virtual void toOs(ostream& os) const override
    {
        os <<", Allowed to work : " << (allowedToWork==true? "allowed" : "not allowed");
    }

  

};


#endif //VACOP_VACCINEEWORKER_H
