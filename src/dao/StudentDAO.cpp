#include "../../include/dao/StudentDAO.h"

using namespace std;

void StudentDAO::add(const StudentDTO& studentDTO) {

    auto findStudent = College::getStudents().find(studentDTO.getRa());

    if(findStudent != College::getStudents().end()) {
        throw runtime_error("Já existe um aluno com o RA correspondente.");
    }

    pair<string, shared_ptr<Person>> studentMap(studentDTO.getRa(), make_shared<StudentDTO>(studentDTO));
    College::getStudents().insert(studentMap);
}

void StudentDAO::read() {

    map<string, shared_ptr<Person>>& studentsMap = College::getStudents();
    for (auto& it : studentsMap) {
        cout << "RA: " << it.first << " | Nome: " << it.second->getName() << endl;
    }
}

shared_ptr<StudentDTO> StudentDAO::search(string studentRA) {
    
    auto findStudent = College::getStudents().find(studentRA);

    if(findStudent == College::getStudents().end()) {
        throw runtime_error("Não foi encontrado um aluno com o RA correspondente.");
    }

    //no controller, quando retornar o estudante, precisa armazenar em um objeto e ir dando studentobject.getname(), getra()... pra mostrar essas informações do estudante
    //fazer isso aqui não faz sentido, tem que ser no controller
    shared_ptr<Person> studentObject = findStudent->second;
    shared_ptr<StudentDTO> studentPtr = dynamic_pointer_cast<StudentDTO>(studentObject);
    
    return studentPtr;
}

void StudentDAO::remove(string studentRA) {
    
    try {
        shared_ptr<StudentDTO> studentPtr = search(studentRA);
        College::getStudents().erase(studentRA);
        cout << "O estudante foi removido com sucesso." << endl;

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void StudentDAO::update(int option, string studentRA) {
    switch(option) {
        case 1:
            {
                string newName;
                cout << "Digite o novo nome: ";
                cin >> newName;
                updateName(studentRA, newName);
            }
            break;
        case 2:
            {
                int newAge;
                cout << "Digite a nova idade: ";
                cin >> newAge;
                updateAge(studentRA, newAge);
            }
            break;
        case 3:
            {
                string newPhone;
                cout << "Digite o novo telefone: ";
                cin >> newPhone;
                updatePhone(studentRA, newPhone);
            }
            break;
        case 4:
            {
                string newRA;
                cout << "Digite o novo RA: ";
                cin >> newRA;
                updateRA(studentRA, newRA);
            }
            break;
        case 5:
            {
                string newCourse;
                cout << "Digite o novo curso: ";
                cin >> newCourse;
                updateCourse(studentRA, newCourse);
            }
            break;
        
        default:
            cout << "Opção inválida." << endl;
    }
}

void StudentDAO::updateName(const string studentRA, string newName) {

    try {
        shared_ptr<StudentDTO> studentPtr = search(studentRA);
        studentPtr->setName(newName);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void StudentDAO::updateAge(const string studentRA, int newAge) {

    try {
        shared_ptr<StudentDTO> studentPtr = search(studentRA);
        studentPtr->setAge(newAge);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void StudentDAO::updatePhone(const string studentRA, string newPhone) {

    try {
        shared_ptr<StudentDTO> studentPtr = search(studentRA);
        studentPtr->setPhone(newPhone);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void StudentDAO::updateRA(const string studentRA, string newRA) {

    try {
        shared_ptr<StudentDTO> studentPtr = search(studentRA);

        auto studentExists = College::getStudents().find(newRA);
        if (studentExists->first == newRA) {
            throw runtime_error("O identificador inserido já está em uso. Tente novamente.");
        }

        studentPtr->setRa(newRA);
    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void StudentDAO::updateCourse(const string studentRA, string newCourse) {

    try {
        shared_ptr<StudentDTO> studentPtr = search(studentRA);
        studentPtr->setCourse(newCourse);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}