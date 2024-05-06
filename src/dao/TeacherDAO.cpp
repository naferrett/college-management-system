#include "../../include/dao/TeacherDAO.h"

using namespace std;


void TeacherDAO::add(const TeacherDTO& teacherDTO) {

    pair<string, shared_ptr<Person>> teacherMap(teacherDTO.getId(), make_shared<TeacherDTO>(teacherDTO));
    College::getTeachers().insert(teacherMap);
}

