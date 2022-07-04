#ifndef VACOP_ADDRESS_H
#define VACOP_ADDRESS_H


#include <ostream>

class Address 
{
private:
    char *district;
    char *street;
    int houseNum;

public:
    Address(const char *district, const char *street, const int houseNum);

    Address(const Address& other);

    Address(Address&& other);

    const char* getDistrict() const;

    const char* getStreet() const;
    
    const int getHouseNum() const;

    const Address& operator=(const Address & other);

    const Address& operator=(Address&& other) ;

    
    friend std::ostream& operator<<(std::ostream& os, const Address& address)
    {
        os << "district: " << address.district << ", street: " << address.street << ", house number: " << address.houseNum;
        return os;
    }


    ~Address();
};


#endif //VACOP_ADDRESS_H
