#ifndef VACOP_PRIVATECLINIC_H
#define VACOP_PRIVATECLINIC_H

using namespace std;
#include <ostream>
#include "Clinic.h"

class PrivateClinic : public Clinic {
protected:
    int premiumPrice;

public:
    PrivateClinic(Clinic&& base, int premiumPrice);

    int getPremiumPrice() const;

    virtual void toOs(ostream& os) const override
    {
        os<< "premium price: " << premiumPrice << endl << endl;
    }

    
};


#endif //VACOP_PRIVATECLINIC_H
