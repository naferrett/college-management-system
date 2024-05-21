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
        map<string, set<string>> subjectsTaught;

    public:
        TeacherDTO(string name, int age, string phone, string id, double salary);

        string getId() const;
        void setId(const string& id);

        double getSalary() const;
        void setSalary(const double& salary);

        map<string, set<string>>& getSubjectsTaught();

        void addSubject(const string semesterId, const string subjectCode);
        set<string> findSubjectsTaught(const string semesterId) const;

        ~TeacherDTO();
};

#endif 
