#include <iostream>
#include <memory>
#include <vector>

#ifndef CLASSDAO_H_
#define CLASSDAO_H_

#include "../../include/dto/ClassDTO.h"
#include "AbstractDAO.h"

using namespace std;

class ClassDAO: public AbstractDAO<ClassDTO> {

    public: 
        void add(const ClassDTO& classDTO) override;
        void addProfessorToClass(const string semesterId, const string subjectCode, const string teacherId);
        void addStudentToClass(const string semesterId, const string subjectCode, const string studentRA);

        shared_ptr<ClassDTO> verifyClassExistence(const string semesterId, const string subjectCode);
};

#endif