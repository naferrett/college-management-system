#include "../../include/dto/Person.h"


Person::Person(string name, int age, string phone) {
	this->name = name;
	this->age = age;
	this->phone = phone;
}

string Person::getName() const {
	return name;
}

int Person::getAge() const {
	return age;
}

string Person::getPhone() const {
	return phone;
}

map<string, set<string>>& Person::getSubjects() {
    return this->subjects;
}

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setPhone(const string& phone) {
    this->phone = phone;
}

set<string> Person::findSubjects(const string semesterId) {
    auto it = subjects.find(semesterId);

    if (it != subjects.end()) {
        return it->second;
    } else {
        cout << "Nenhuma disciplina está registrada no semestre especificado." << endl;
        return {};
    }
}

void Person::addSubject(const string semesterId, const string subjectCode) {
    this->subjects[semesterId].insert(subjectCode);
}


void Person::removeSubject(const string semesterId, const string subjectCode) {
    auto& subjectVec = subjects[semesterId];
    auto it = find(subjectVec.begin(), subjectVec.end(), subjectCode);
    if (it != subjectVec.end()) {
        subjectVec.erase(it);
    }
}

Person::~Person() {}