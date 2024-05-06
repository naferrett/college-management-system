#include "../../include/dto/StudentDTO.h"

StudentDTO::StudentDTO(string name, int age, string phone, string ra, string course): Person(name, age, phone) {
    this->name = name;
    this->age = age;
    this->phone = phone;
    this->ra = ra;
    this->course = course;
}

string StudentDTO::getRa() const {
    return ra;
}

void StudentDTO::setRa(const string& ra) {
    this->ra = ra;
}

string StudentDTO::getCourse() const {
    return course;
}

void StudentDTO::setCourse(const string& course) {
    this->course = course;
}

