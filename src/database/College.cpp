#include "../../include/database/College.h"

map<string, shared_ptr<Person>> College::students;
map<string, shared_ptr<Person>> College::teachers;
vector<shared_ptr<ClassDTO>> College::classes;
vector<shared_ptr<Subject>> College::subjects;
vector<shared_ptr<Semester>> College::semesters = {
    make_shared<Semester>("24S1", 2024, 1),
    make_shared<Semester>("24S2", 2024, 2),
    make_shared<Semester>("25S1", 2025, 1),
    make_shared<Semester>("25S2", 2025, 2),
    make_shared<Semester>("26S1", 2026, 1),
    make_shared<Semester>("26S2", 2026, 2),
    make_shared<Semester>("27S1", 2027, 1),
    make_shared<Semester>("27S2", 2027, 2),
    make_shared<Semester>("28S1", 2028, 1),
    make_shared<Semester>("28S2", 2028, 2)
};


map<string, shared_ptr<Person>>& College::getStudents() {
    return students;
}

void College::setStudents(map<string, shared_ptr<Person>> students) {
    this->students = students;
}

map<string, shared_ptr<Person>>& College::getTeachers() {
    return teachers;
}

void College::setTeachers(map<string, shared_ptr<Person>> teachers) {
    this->teachers = teachers;
}

vector<shared_ptr<ClassDTO>>& College::getClasses() {
    return classes;
}

void College::setClasses(vector<shared_ptr<ClassDTO>>& classes) {
    this->classes = classes;
}

vector<shared_ptr<Subject>>& College::getSubjects() {
    return subjects;
}

void College::setSubjects(vector<shared_ptr<Subject>>& subjects) {
    this->subjects = subjects;
}

vector<shared_ptr<Semester>>& College::getSemesters() {
    return semesters;
}

void College::setSemesters(vector<shared_ptr<Semester>>& semesters) {
    this->semesters = semesters;
}
