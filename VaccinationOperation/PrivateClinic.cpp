#include "PrivateClinic.h"

PrivateClinic::PrivateClinic(Clinic&& base, int premiumPrice) : Clinic(std::move(base))
{

	this->premiumPrice = premiumPrice;
}

int PrivateClinic::getPremiumPrice() const
{
	return this->premiumPrice;
}
