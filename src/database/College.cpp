#include "../../include/database/College.h"

map<string, shared_ptr<Person>> College::students;
map<string, shared_ptr<Person>> College::teachers;
vector<shared_ptr<ClassDTO>> College::classes;

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
