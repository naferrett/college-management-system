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

void Person::setName(const string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setPhone(const string& phone) {
    this->phone = phone;
}

Person::~Person() {}