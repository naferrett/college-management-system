#include "../../include/dto/Semester.h"

Semester::Semester(string id, int year, int semesterNumber) {
    this->id = id;
    this->year = year;
    this->semesterNumber = semesterNumber;
}

string Semester::getId() {
    return id;
}

void Semester::setId(string id){
    this->id = id;
}

int Semester::getYear() {
    return year;
}

void Semester::setYear(int year) {
    this->year = year;
}

int Semester::getSemesterNumber() {
    return semesterNumber;
}

void Semester::setSemesterNumber() {
    this->semesterNumber = semesterNumber;
}

bool Semester::isValidSemesterId(string id) {
     for (auto& semesterId : semestersID) {
        if (id == semesterId) {
            return true;
        }
    }
    return false;
}
