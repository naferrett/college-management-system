#ifndef STUDENTDTO_H_
#define STUDENTDTO_H_

#include "Person.h"
#include <string>

using namespace std;

class StudentDTO : public Person {

private:
    string ra;
    string course;

public:
    // Construtor
    StudentDTO(string name, int age, string phone, string ra, string course);

    // Getters
    string getRa() const;
    string getCourse() const;

    // Setters
    void setRa(const string& ra);
    void setCourse(const string& course);
};

#endif