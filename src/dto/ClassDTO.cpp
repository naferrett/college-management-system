#include "../../include/dto/ClassDTO.h"

ClassDTO::ClassDTO(string semesterId, int semesterYear, int semesterNumber, string subjCode, string subjName, string subjSyllabus, string teacherId, vector<string>& studentsRAs, map<string, double>& studentGrades) : Semester(id, year, semesterNumber), Subject(code, name, syllabus) {
    this->teacherId = teacherId;
    this->studentsRAs = studentsRAs;
    this->studentGrades = studentGrades;
}

string ClassDTO::getTeacherId() {
    return teacherId;
}

void ClassDTO::setTeacherId(string teacherId) {
    this->teacherId = teacherId;
}

vector<string> ClassDTO::getStudentsRAs() {
    return studentsRAs;
}

void ClassDTO::setStudentsRAs(vector<string>& studentsRAs) {
    this->studentsRAs = studentsRAs;
}

map<string, double> ClassDTO::getStudentGrades() {
    return studentGrades;
}

void ClassDTO::setStudentGrades(map<string, double>& studentGrades) {
    this->studentGrades = studentGrades;
}
