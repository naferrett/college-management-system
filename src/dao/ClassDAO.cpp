#include "../../include/dao/ClassDAO.h"
#include "../../include/dto/TeacherDTO.h"

using namespace std;

void ClassDAO::add(const ClassDTO& classDTO) {

    shared_ptr<ClassDTO> ptrClassDTO = make_shared<ClassDTO>(classDTO);

    College::getClasses().push_back(ptrClassDTO);
}

void ClassDAO::addProfessorToClass(const string semesterId, const string subjectCode, const string teacherId) {
    
    try {
        auto classDTO = verifyClassExistence(semesterId, subjectCode);
        
        if (classDTO == nullptr) {
            throw runtime_error("Não há nenhuma classe com esses dados.");
        }

        //O second é usado para pegar apenas o objeto no par findTeacher, o qual é armazenado na variável teacherObject
        auto findTeacher = College::getTeachers().find(teacherId);
        shared_ptr<Person> teacherObject = findTeacher->second;

        if(findTeacher == College::getTeachers().end()) {
            throw runtime_error("Não foi encontrado um professor com o ID correspondente.");
        }

        //Adiciona um professor a classe
        classDTO->setTeacherId(teacherId);
        
        //Passa o teacherObject do tipo Person para o tipo TeacherDTO, de forma a poder usar o método addSubject
        //O método addSubject adiciona a matéria e o semestre ao map de matérias lecionadas pelo professor na classe TeacherDTO
        shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
        teacherPtr->addSubject(semesterId, subjectCode);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}


void ClassDAO::addStudentToClass(const string semesterId, const string subjectCode, const string studentRA) {
    
    try {
        auto classDTO = verifyClassExistence(semesterId, subjectCode);

        if (classDTO == nullptr) {
            throw runtime_error("Não há nenhuma classe com esses dados.");
        }

        auto findStudent = College::getStudents().find(studentRA); 

        if(findStudent == College::getStudents().end()) {
            throw runtime_error("Não foi encontrado um aluno com o RA correspondente.");
        }

        classDTO->getStudentsRAs().push_back(studentRA);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

//Verifica se existe uma classe de acordo com as chaves (Id do semestre e código da matéria)
shared_ptr<ClassDTO> ClassDAO::verifyClassExistence(const string semesterId, const string subjectCode) {
    vector<shared_ptr<ClassDTO>> classesVector = College::getClasses();

    for(auto& it : classesVector) { 
        if (it->getCode() == subjectCode && it->getId() == semesterId) { 
            return it;
        }
    }

    return nullptr; 
}
