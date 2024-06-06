#include <iostream>
#include <memory>
#include <vector>
#include <algorithm> 

#ifndef CLASSDAO_H_
#define CLASSDAO_H_

#include "../../include/dto/ClassDTO.h"
#include "AbstractDAO.h"

using namespace std;

class ClassDAO: public AbstractDAO<ClassDTO, SemesterSubject> {

    public: 
        void add(const ClassDTO& classDTO) override;
        void read() override;
        shared_ptr<ClassDTO> search(SemesterSubject code) override;
        void update(int option, SemesterSubject code) override;
        void remove(SemesterSubject code) override;

        void addProfessorToClass(SemesterSubject code, const string teacherId);
        void removeProfessorFromClass(SemesterSubject code, const string teacherId);
        void addStudentAndGradeToClass(SemesterSubject code, const string studentRA, const double studentGrade);

        void updateSemesterId(SemesterSubject code, string newSemesterId);
        void updateSemesterYear(SemesterSubject code, int newSemesterYear);
        void updateSemesterNumber(SemesterSubject code, int newSemesterNumber);
        void updateSubjCode(SemesterSubject code, string newSubjCode);
        void updateSubjName(SemesterSubject code, string newSubjName);
        void updateSubjSyllabus(SemesterSubject code, string newSyllabus);
        void updateTeacherId(SemesterSubject code, string newTeacherId);
        
};

#endif