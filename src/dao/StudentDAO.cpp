#include "../../include/dao/StudentDAO.h"

using namespace std;

void StudentDAO::add(const StudentDTO& studentDTO) {

    pair<string, shared_ptr<Person>> studentMap(studentDTO.getRa(), make_shared<StudentDTO>(studentDTO));
    College::getStudents().insert(studentMap);
}

