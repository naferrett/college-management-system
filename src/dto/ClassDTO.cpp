#include "../../include/dto/ClassDTO.h"

ClassDTO::ClassDTO(string semesterId, int semesterYear, int semesterNumber, string subjCode, string subjName, string subjSyllabus)
    : Semester(semesterId, semesterYear, semesterNumber), Subject(subjCode, subjName, subjSyllabus), code(semesterId, subjCode) {
    this->studentsRAs = studentsRAs;
    this->studentGrades = studentGrades;
}


string ClassDTO::getTeacherId() {
    return teacherId;
}

void ClassDTO::setTeacherId(string teacherId) {
    this->teacherId = teacherId;
}

vector<string>& ClassDTO::getStudentsRAs() {
    return studentsRAs;
}

void ClassDTO::setStudentsRAs(vector<string>& studentsRAs) {
    this->studentsRAs = studentsRAs;
}

map<string, double>& ClassDTO::getStudentGrades() {
    return studentGrades;
}

void ClassDTO::setStudentGrades(map<string, double>& studentGrades) {
    this->studentGrades = studentGrades;
}

SemesterSubject ClassDTO::getSemesterSubjectCode() {
    return code;
}

void ClassDTO::setSemesterSubjectCode(SemesterSubject code) {
    this->code = code;
}

ClassDTO::~ClassDTO() {}