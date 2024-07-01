#ifndef STUDENTDTO_H_
#define STUDENTDTO_H_

#include "Person.h"
#include <string>
#include <vector>

using namespace std;

class StudentDTO : public Person {

private:
    string ra;
    string course;
    vector<double> grades;

public:
    StudentDTO(string name, int age, string phone, string ra, string course);

    string getRa() const;
    string getCourse() const;
    vector<double>& getGrades();

    void setRa(const string& ra);
    void setCourse(const string& course);

    ~StudentDTO();
};

#endif