#include "../../include/dao/TeacherDAO.h"

using namespace std;


void TeacherDAO::add(const TeacherDTO& teacherDTO) {

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

    try {
        auto findTeacher = College::getTeachers().find(teacherId);

        if(findTeacher == College::getTeachers().end()) {
            throw runtime_error("Não foi encontrado um professor com o ID correspondente.");
        }

        //no controller, quando retornar o professor, precisa armazenar em um objeto e ir dando teacherobject.getname(), getRa()... pra mostrar essas informações do professor
        //fazer isso aqui não faz sentido, tem que ser no controller
        shared_ptr<Person> teacherObject = findTeacher->second;
        shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
        
        return teacherPtr;
    } catch (const exception& e) {
        throw;
    }
}

void TeacherDAO::remove(string teacherId) {
    
    try {
        shared_ptr<TeacherDTO> teacherPtr = search(teacherId);
        College::getTeachers().erase(teacherId);
        cout << "O professor foi removido com sucesso." << endl;

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}