#include "../../include/dto/TeacherDTO.h"

TeacherDTO::TeacherDTO(string name, int age, string phone, string id, double salary): Person(name, age, phone) {
    this->name = name;
    this->age = age;
    this->phone = phone;
    this->id = id;
    this->salary = salary;
}

string TeacherDTO::getId() const {
    return id;
}

void TeacherDTO::setId(const string& id) {
    this->id = id;
}

double TeacherDTO::getSalary() const {
    return salary;
}

void TeacherDTO::setSalary(const double& salary) {
    this->salary = salary;
}

vector<string> TeacherDTO::getSubjectsTaught() const {
    return subjectsTaught;
}

void TeacherDTO::addSubject(const string subjectCode)
{
    this->subjectsTaught.push_back(subjectCode);
}