#include "../../include/dto/Subject.h"

Subject::Subject(string code, string name, string syllabus) {
    this->code = code;
    this->name = name;
    this->syllabus = syllabus;
}

string Subject::getCode() {
    return code;
}

void Subject::setCode(string code) {
    this->code = code;
}

string Subject::getName() {
    return name;
}

void Subject::setName(string name) {
    this->name = name;
}

string Subject::getSyllabus() {
    return syllabus;
}

void Subject::setSyllabus(string syllabus) {
    this->syllabus = syllabus;
}