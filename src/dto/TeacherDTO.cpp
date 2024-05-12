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

map<string, set<string>>& TeacherDTO::getSubjectsTaught() {
    return this->subjectsTaught;
}

set<string> TeacherDTO::findSubjectsTaught(const string semesterId) const {
    auto it = subjectsTaught.find(semesterId);

    if (it != subjectsTaught.end()) {
        return it->second;
    } else {
        cout << "Nenhuma matéria foi lecionada no semestre especificado." << endl;
        return {};
    }
}

void TeacherDTO::addSubject(const string semesterId, const string subjectCode) {
    this->subjectsTaught[semesterId].insert(subjectCode);
}