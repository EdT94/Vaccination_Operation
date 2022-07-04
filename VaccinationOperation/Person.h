#ifndef VACOP_PERSON_H
#define VACOP_PERSON_H


#include <ostream>

using namespace std;

class Person
{
private:
    Person(const Person &other);
    Person(Person&& other);
    const Person& operator=(Person&& other);
    const Person& operator=(const Person &other);

protected:
    static int current_id; 
    const int id;
    char* name;

    virtual ~Person();

   
public:
    Person(const char* name);
    const int getId() const;

    const char* getName() const;

    bool setName(const char* name);

   virtual void toOs(ostream& os) const {}

    friend ostream& operator<<(ostream& os, const Person& person)
    {
        os << "id: " << person.id << ", name: " << person.name;
        person.toOs(os);
        return os;
    }
};



#endif //VACOP_PERSON_H
