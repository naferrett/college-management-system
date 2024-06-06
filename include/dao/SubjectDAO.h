#include <iostream>
#include <memory>
#include <vector>

#include "../../include/dto/Subject.h"
#include "../../include/dao/AbstractDAO.h"

#ifndef SUBJECTSDAO_H_
#define SUBJECTSDAO_H_

using namespace std;

class SubjectDAO: public AbstractDAO<Subject, string> {

    public: 
        void add(const Subject& subject) override;
        void read() override;
        virtual void remove(string key);
        shared_ptr<Subject> search(string key);

};

#endif