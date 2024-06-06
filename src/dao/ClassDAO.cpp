#include "../../include/dao/ClassDAO.h"
#include "../../include/dao/StudentDAO.h"
#include "../../include/dao/TeacherDAO.h"
#include "../../include/dto/TeacherDTO.h"
#include "../../include/dto/Person.h"

using namespace std;

void ClassDAO::add(const ClassDTO& classDTO) {

    string semesterId = classDTO.getId();
    string subjectCode = classDTO.getCode();

    vector<shared_ptr<ClassDTO>>& classesVector = College::getClasses();

    for (auto& it : classesVector) { 
        if (it->getSemesterSubjectCode().getSubjectCode() == subjectCode && it->getSemesterSubjectCode().getSemesterId() == semesterId) { 
            throw runtime_error("Já existe uma classe registrada com esse código.");
        }
    }

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

void ClassDAO::remove(SemesterSubject code) {
    
    try {
        shared_ptr<ClassDTO> classPtr = search(code);
        auto findClass = find(College::getClasses().begin(), College::getClasses().end(), classPtr);

        if (findClass == College::getClasses().end()) {
            throw runtime_error("A classe não foi removida, pois não foi encontrada."); 
        }

        College::getClasses().erase(findClass);
        cout << "A classe foi removida com sucesso." << endl;

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ClassDAO::update(int option, SemesterSubject code) {
    switch(option) {
        case 1:
            {
                string newSemesterId;
                cout << "Digite o novo identificador do semestre: ";
                cin >> newSemesterId;
                updateSemesterId(code, newSemesterId);
            }
            break;
        case 2:
            {
                int newSemesterYear;
                cout << "Digite o novo ano do semestre: ";
                cin >> newSemesterYear;
                updateSemesterYear(code, newSemesterYear);
            }
            break;
        case 3:
            {
                int newSemesterNumber;
                cout << "Digite o novo número do semestre: ";
                cin >> newSemesterNumber;
                updateSemesterNumber(code, newSemesterNumber);
            }
            break;
        case 4:
            {
                string newSubjCode;
                cout << "Digite o novo código da matéria: ";
                cin >> newSubjCode;
                updateSubjCode(code, newSubjCode);
            }
            break;
        case 5:
            {
                string newSubjName;
                cout << "Digite o novo nome da matéria: ";
                cin >> newSubjName;
                updateSubjName(code, newSubjName);
            }
            break;
        case 6:
            {
                string newSubjSyllabus;
                cout << "Digite a nova ementa da matéria: ";
                cin >> newSubjSyllabus;
                updateSubjSyllabus(code, newSubjSyllabus);
            }
            break;
        case 7:
            {
                string newTeacherId;
                cout << "Digite o identificador do novo professor da matéria: ";
                cin >> newTeacherId;
                updateTeacherId(code, newTeacherId);
            }
            break;
        
        default:
            cout << "Opção inválida." << endl;
    }
}

void ClassDAO::updateSemesterId(SemesterSubject code, string newSemesterId) {

    try {
        shared_ptr<ClassDTO> classPtr = search(code);

        SemesterSubject codeExists(newSemesterId, code.getSubjectCode());
        if(search(codeExists)) {
            throw runtime_error("O identificador inserido já está em uso com essa mesma matéria. Tente novamente.");
        }
        classPtr->setId(newSemesterId);
        //classPtr->getSemesterSubjectCode().setSemesterId(newSemesterId);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ClassDAO::updateSemesterYear(SemesterSubject code, int newSemesterYear) {

    try {
        shared_ptr<ClassDTO> classPtr = search(code);
        classPtr->setYear(newSemesterYear);
        //classPtr->getSemesterSubjectCode().setSemesterId(newSemesterId);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ClassDAO::updateSemesterNumber(SemesterSubject code, int newSemesterNumber) {

    try {
        shared_ptr<ClassDTO> classPtr = search(code);
        classPtr->setYear(newSemesterNumber);
        //classPtr->getSemesterSubjectCode().setSemesterId(newSemesterId);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ClassDAO::updateSubjCode(SemesterSubject code, string newSubjCode) {

    try {
        shared_ptr<ClassDTO> classPtr = search(code);

        SemesterSubject codeExists(code.getSemesterId(), newSubjCode);
        if(search(codeExists)) {
            throw runtime_error("O identificador inserido já está em uso com essa mesma matéria. Tente novamente.");
        }
        classPtr->setCode(newSubjCode);
        //classPtr->getSemesterSubjectCode().setSemesterId(newSemesterId);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ClassDAO::updateSubjName(SemesterSubject code, string newSubjName) {

    try {
        shared_ptr<ClassDTO> classPtr = search(code);
        classPtr->setName(newSubjName);
        //classPtr->getSemesterSubjectCode().setSemesterId(newSemesterId);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ClassDAO::updateSubjSyllabus(SemesterSubject code, string newSyllabus) {

    try {
        shared_ptr<ClassDTO> classPtr = search(code);
        classPtr->setSyllabus(newSyllabus);
        //classPtr->getSemesterSubjectCode().setSemesterId(newSemesterId);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
    }
}

void ClassDAO::updateTeacherId(SemesterSubject code, string newTeacherId) {

    try {
        shared_ptr<ClassDTO> classPtr = search(code);
        string oldTeacherId = classPtr->getTeacherId();
        
        removeProfessorFromClass(code, oldTeacherId);
        addProfessorToClass(code, newTeacherId);

    } catch (const exception& e) {
        cout << "Erro: " << e.what() << endl;
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

void ClassDAO::removeProfessorFromClass(SemesterSubject code, const string teacherId) {

    try {
        auto classDTO = search(code);
         
        TeacherDAO teacherdao;
        shared_ptr<TeacherDTO> teacherPtr = teacherdao.search(teacherId);
      
        teacherPtr->removeSubject(code.getSemesterId(), code.getSubjectCode());

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

