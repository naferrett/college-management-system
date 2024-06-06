#include "../../include/dao/StudentDAO.h"

using namespace std;

void StudentDAO::add(const StudentDTO& studentDTO) {

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
        cout << "O estudante foi excluído com sucesso." << endl;

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}