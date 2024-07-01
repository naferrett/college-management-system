#include "../../include/dao/TeacherDAO.h"

using namespace std;


void TeacherDAO::add(const TeacherDTO& teacherDTO) {
    auto findTeacher = College::getTeachers().find(teacherDTO.getId());

    if(findTeacher != College::getTeachers().end()) {
        throw runtime_error("Já existe um professor com o identificador correspondente.");
    }

    pair<string, shared_ptr<Person>> teacherMap(teacherDTO.getId(), make_shared<TeacherDTO>(teacherDTO));
    College::getTeachers().insert(teacherMap);
}

void TeacherDAO::read() {
    map<string, shared_ptr<Person>>& teachersMap = College::getTeachers();
    for (auto& it : teachersMap) {
        cout << "ID: " << it.first << " | Nome: " << it.second->getName() << endl;
    }
}

shared_ptr<TeacherDTO> TeacherDAO::search(string teacherId) {
    auto findTeacher = College::getTeachers().find(teacherId);

    if(findTeacher == College::getTeachers().end()) {
        throw runtime_error("Não foi encontrado um professor com o ID correspondente.");
    }

    shared_ptr<Person> teacherObject = findTeacher->second;
    shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
    
    return teacherPtr;
}

void TeacherDAO::remove(string teacherId) {
    shared_ptr<TeacherDTO> teacherPtr = search(teacherId);
    College::getTeachers().erase(teacherId);
    cout << "O professor foi removido com sucesso." << endl;
}

void TeacherDAO::update(int option, string teacherId) {
    switch(option) {
        case 1:
            {
                string newName;
                cout << "Digite o novo nome: ";
                cin >> newName;
                updateName(teacherId, newName);
            }
            break;
        case 2:
            {
                int newAge;
                cout << "Digite a nova idade: ";
                cin >> newAge;
                updateAge(teacherId, newAge);
            }
            break;
        case 3:
            {
                string newPhone;
                cout << "Digite o novo telefone: ";
                cin >> newPhone;
                updatePhone(teacherId, newPhone);
            }
            break;
        case 4:
            {
                string newId;
                cout << "Digite o novo identificador: ";
                cin >> newId;
                updateId(teacherId, newId);
            }
            break;
        case 5:
            {
                double newSalary;
                cout << "Digite o novo salário: ";
                cin >> newSalary;
                updateSalary(teacherId, newSalary);
            }
            break;
        
        default:
            cout << "Opção inválida." << endl;
    }
}

void TeacherDAO::updateName(string teacherId, string newName) {
    shared_ptr<TeacherDTO> teacherPtr = search(teacherId);
    teacherPtr->setName(newName);
}

void TeacherDAO::updateAge(const string teacherId, int newAge) {
    shared_ptr<TeacherDTO> teacherPtr = search(teacherId);
    teacherPtr->setAge(newAge);
}

void TeacherDAO::updatePhone(const string teacherId, string newPhone) {
    shared_ptr<TeacherDTO> teacherPtr = search(teacherId);
    teacherPtr->setPhone(newPhone);
}

void TeacherDAO::updateId(const string teacherId, string newId) {
    shared_ptr<TeacherDTO> teacherPtr = search(teacherId);

    auto teacherExists = College::getTeachers().find(newId);
    if (teacherExists->first == newId) {
        throw runtime_error("O identificador inserido já está em uso. Tente novamente.");
    }

    teacherPtr->setId(newId);
}

void TeacherDAO::updateSalary(const string teacherId, double newSalary) {
    shared_ptr<TeacherDTO> teacherPtr = search(teacherId);
    teacherPtr->setSalary(newSalary);
}