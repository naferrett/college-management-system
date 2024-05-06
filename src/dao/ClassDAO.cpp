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

        auto findTeacher = College::getTeachers().find(teacherId);
        shared_ptr<Person> teacherObject = findTeacher->second;

        if(findTeacher == College::getTeachers().end()) {
            throw runtime_error("Não foi encontrado um professor com o ID correspondente.");
        }

        classDTO->setTeacherId(teacherId);
        
        shared_ptr<TeacherDTO> teacherPtr = dynamic_pointer_cast<TeacherDTO>(teacherObject);
        teacherPtr->addSubject(subjectCode);

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


shared_ptr<ClassDTO> ClassDAO::verifyClassExistence(const string semesterId, const string subjectCode) {
    vector<shared_ptr<ClassDTO>> classesVector = College::getClasses();

    for(auto& it : classesVector) { 
        if (it->getCode() == subjectCode && it->getId() == semesterId) { 
            return it;
        }
    }

    return nullptr; 
}
