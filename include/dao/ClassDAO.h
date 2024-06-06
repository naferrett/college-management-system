#include <iostream>
#include <memory>
#include <vector>

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
        //void remove(SemesterSubject code) override;

        void addProfessorToClass(SemesterSubject code, const string teacherId);
        void addStudentAndGradeToClass(SemesterSubject code, const string studentRA, const double studentGrade);
};

#endif