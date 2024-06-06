#include "../../include/dto/SemesterSubject.h"

SemesterSubject::SemesterSubject(string semesterId, string subjectCode) {
    this->semesterId = semesterId;
    this->subjectCode = subjectCode;
}

string SemesterSubject::getSemesterId(){
    return semesterId;
}

void SemesterSubject::setSemesterId(string semesterId) {
    this->semesterId = semesterId;
}

string SemesterSubject::getSubjectCode() {
    return subjectCode;
}

void SemesterSubject::setSubjectCode(string subjectCode) {
    this->subjectCode = subjectCode;
}