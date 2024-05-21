#include "../../include/dao/TeacherDAO.h"

using namespace std;


void TeacherDAO::add(const TeacherDTO& teacherDTO) {

    pair<string, shared_ptr<Person>> teacherMap(teacherDTO.getId(), make_shared<TeacherDTO>(teacherDTO));
    College::getTeachers().insert(teacherMap);
}

/*
void TeacherDAO::update(const string teacherId, int attributeNum) {

    switch(attributeNum) {
        case 1:
            {
                string newName;
                cout << "Digite o novo nome: ";
                cin >> newName;
                
            }
            break;
        case 2:
            {
                int newAge;
                cout << "Digite a nova idade: ";
                cin >> newAge;
                
            }
            break;
        case 3:
            {
                string newPhone;
                cout << "Digite o novo telefone: ";
                cin >> newPhone;
                
            }
            break;
        case 4:
            {
                string newId;
                cout << "Digite o novo identificador: ";
                cin >> newId;
                // Atualizar o departamento do professor com o ID fornecido
                // Exemplo:
                // teacherRepository.updateDepartment(teacherId, newDepartment);
            }
            break;
        case 5:
            {
                string newSalary;
                cout << "Digite o novo salário: ";
                cin >> newSalary;
                // Atualizar o departamento do professor com o ID fornecido
                // Exemplo:
                // teacherRepository.updateDepartment(teacherId, newDepartment);
            }
            break;
        
        default:
            cout << "Opção inválida. Tente novamente." << endl;
    }
}
*/

void TeacherDAO::updateName(const string teacherId, string newName) {

    try {
        auto& teachersMap = College::getTeachers();
        auto teacherFound = teachersMap.find(teacherId);

        if (teacherFound == teachersMap.end()) {
            throw runtime_error("Não há nenhum professor com esse identificador.");
        }

        shared_ptr<Person> teacherObject = teacherFound->second;
        shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
        teacherPtr->setName(newName);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void TeacherDAO::updateAge(const string teacherId, int newAge) {

    try {
        auto& teachersMap = College::getTeachers();
        auto teacherFound = teachersMap.find(teacherId);

        if (teacherFound == teachersMap.end()) {
            throw runtime_error("Não há nenhum professor com esse identificador.");
        }

        shared_ptr<Person> teacherObject = teacherFound->second;
        shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
        teacherPtr->setAge(newAge);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void TeacherDAO::updatePhone(const string teacherId, string newPhone) {

    try {
        auto& teachersMap = College::getTeachers();
        auto teacherFound = teachersMap.find(teacherId);

        if (teacherFound == teachersMap.end()) {
            throw runtime_error("Não há nenhum professor com esse identificador.");
        }

        shared_ptr<Person> teacherObject = teacherFound->second;
        shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
        teacherPtr->setPhone(newPhone);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void TeacherDAO::updateId(const string teacherId, string newId) {

    try {
        auto& teachersMap = College::getTeachers();
        auto teacherFound = teachersMap.find(teacherId);

        if (teacherFound == teachersMap.end()) {
            throw runtime_error("Não há nenhum professor com esse identificador para alteração.");
        }

        auto teacherExists = teachersMap.find(newId);
        if (teacherExists->first == newId) {
            throw runtime_error("O identificador inserido já está em uso. Tente novamente.");
        }

        shared_ptr<Person> teacherObject = teacherFound->second;
        shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
        teacherPtr->setName(newName);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void TeacherDAO::updateSalary(const string teacherId, double newSalary) {

    try {
        auto& teachersMap = College::getTeachers();
        auto teacherFound = teachersMap.find(teacherId);

        if (teacherFound == teachersMap.end()) {
            throw runtime_error("Não há nenhum professor com esse identificador para alteração.");
        }

        shared_ptr<Person> teacherObject = teacherFound->second;
        shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
        teacherPtr->setSalary(newSalary);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}