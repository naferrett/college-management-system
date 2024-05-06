#include <iostream>
#include <memory>
#include <vector>

#include "../../include/dto/Subject.h"
#include "../../include/dao/AbstractDAO.h"

#ifndef SUBJECTSDAO_H_
#define SUBJECTSDAO_H_

using namespace std;

class SubjectDAO: public AbstractDAO<Subject> {

    public: 
        void add(const Subject& subject) override;
};

#endif