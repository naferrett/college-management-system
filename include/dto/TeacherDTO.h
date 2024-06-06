#ifndef TEACHERDTO_H_
#define TEACHERDTO_H_

#include "Person.h"
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class TeacherDTO : public Person {
        
    private:
        string id;
        double salary; 

    public:
        TeacherDTO(string name, int age, string phone, string id, double salary);

        string getId() const;
        void setId(const string& id);

        double getSalary() const;
        void setSalary(const double& salary);

        ~TeacherDTO();
};

#endif 
