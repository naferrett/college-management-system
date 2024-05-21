#include "../../include/dao/StudentDAOtDAO.h"

using namespace std;

void StudentDAOtDAO::add(const StudentDAOtDTO& StudentDAOtDTO) {

    pair<string, shared_ptr<Person>> StudentDAOtMap(StudentDAOtDTO.getRa(), make_shared<StudentDAOtDTO>(StudentDAOtDTO));
    College::getStudentDAOts().insert(StudentDAOtMap);
}

void StudentDAO::updateName(const string studentRA, string newName) {

    try {
        auto& studentsMap = College::getStudents();
        auto studentFound = studentsMap.find(studentRA);

        if (studentFound == studentsMap.end()) {
            throw runtime_error("Não há nenhum aluno com esse identificador.");
        }

        shared_ptr<Person> studentObject = studentFound->second;
        shared_ptr<StudentDTO> studentPtr = dynamic_pointer_cast<StudentDTO>(studentObject);
        studentPtr->setName(newName);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void StudentDAO::updateAge(const string studentRA, int newAge) {

    try {
        auto& studentsMap = College::getStudents();
        auto studentFound = studentsMap.find(studentRA);

        if (studentFound == studentsMap.end()) {
            throw runtime_error("Não há nenhum aluno com esse identificador.");
        }

        shared_ptr<Person> studentObject = studentFound->second;
        shared_ptr<StudentDTO> studentPtr = dynamic_pointer_cast<StudentDTO>(studentObject);
        studentPtr->setAge(newAge);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void StudentDAO::updatePhone(const string studentRA, string newPhone) {

    try {
        auto& studentsMap = College::getStudents();
        auto studentFound = studentsMap.find(studentRA);

        if (studentFound == studentsMap.end()) {
            throw runtime_error("Não há nenhum aluno com esse identificador.");
        }

        shared_ptr<Person> studentObject = studentFound->second;
        shared_ptr<StudentDTO> studentPtr = dynamic_pointer_cast<StudentDTO>(studentObject);
        studentPtr->setPhone(newPhone);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void StudentDAO::updateId(const string studentRA, string newRA) {

    try {
        auto& studentsMap = College::getStudents();
        auto studentFound = studentsMap.find(studentRA);

        if (studentFound == studentsMap.end()) {
            throw runtime_error("Não há nenhum aluno com esse identificador.");
        }

        auto studentExists = teachersMap.find(newRA);

        //arrumarrrrr em teacher tbb
        if (studentExists = newRa) {
            throw runtime_error("O identificador inserido já está em uso. Tente novamente.");
        }

        shared_ptr<Person> studentObject = studentFound->second;
        shared_ptr<StudentDTO> studentPtr = dynamic_pointer_cast<StudentDTO>(studentObject);
        studentPtr->setAge(newAge);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}