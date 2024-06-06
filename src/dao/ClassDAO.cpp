#include "../../include/dao/ClassDAO.h"
#include "../../include/dao/StudentDAO.h"
#include "../../include/dao/TeacherDAO.h"
#include "../../include/dto/TeacherDTO.h"
#include "../../include/dto/Person.h"

using namespace std;

void ClassDAO::add(const ClassDTO& classDTO) {

    shared_ptr<ClassDTO> ptrClassDTO = make_shared<ClassDTO>(classDTO);

    College::getClasses().push_back(ptrClassDTO);
}

void ClassDAO::read() {
    vector<shared_ptr<ClassDTO>>& classesVector = College::getClasses();    
    
    for (auto& it : classesVector) {
        cout << "Código da matéria: " << it->getSemesterSubjectCode().getSubjectCode() << " | Semestre: " << it->getSemesterSubjectCode().getSemesterId() << endl;
    }
}

//Verifica se existe uma classe de acordo com as chaves (Id do semestre e código da matéria)
shared_ptr<ClassDTO> ClassDAO::search(SemesterSubject code) {
    try {
        string semesterId = code.getSemesterId();
        string subjectCode = code.getSubjectCode();

        vector<shared_ptr<ClassDTO>>& classesVector = College::getClasses();

        for(auto& it : classesVector) { 
            if (it->getSemesterSubjectCode().getSubjectCode() == subjectCode && it->getSemesterSubjectCode().getSemesterId() == semesterId) { 
                return it;
            }
        }

        throw runtime_error("Não há nenhuma classe com esses dados.");

    } catch(const exception &e) {
        throw;
    }
}

void ClassDAO::addProfessorToClass(SemesterSubject code, const string teacherId) {
    
    try {
        auto classDTO = search(code);
         
        TeacherDAO teacherdao;
        shared_ptr<TeacherDTO> teacherPtr = teacherdao.search(teacherId);

        //Adiciona um professor a classe
        classDTO->setTeacherId(teacherId);
      
        //O método addSubject adiciona a matéria e o semestre ao map de matérias lecionadas pelo professor na classe TeacherDTO
        teacherPtr->addSubject(code.getSemesterId(), code.getSubjectCode());

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ClassDAO::addStudentAndGradeToClass(SemesterSubject code, const string studentRA, const double studentGrade) {
    
    try {
        auto classDTO = search(code);

        StudentDAO studentdao;
        shared_ptr<StudentDTO> studentPtr = studentdao.search(studentRA);

        classDTO->getStudentsRAs().push_back(studentRA);
        
        //Adiciona a nota e RA do aluno ao map de ra e nota
        pair<string, double> RaAndGrade(studentRA, studentGrade);
        classDTO->getStudentGrades().insert(RaAndGrade);

        //Adiciona a matéria ao vetor de disciplinas matriculadas
        studentPtr->addSubject(code.getSemesterId(), code.getSubjectCode());

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}
