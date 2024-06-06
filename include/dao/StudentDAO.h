#include <iostream>
#include <memory>
#include <map>

#include "../../include/dto/StudentDTO.h"
#include "../../include/dao/AbstractDAO.h"

#ifndef STUDENTDAO_H_
#define STUDENTDAO_H_

using namespace std;

class StudentDAO : public AbstractDAO<StudentDTO, string> {

    public:    
        void add(const StudentDTO& studentDTO) override;
        void read() override;
        shared_ptr<StudentDTO> search(string studentRA) override;
        void update(int option, string studentRA) override;
        void remove(string studentRA) override;

        void updateName(const string studentRA, string newName);
        void updateAge(const string studentRA, int newAge);
        void updatePhone(const string studentRA, string newPhone);
        void updateRA(const string studentRA, string newRA);
        void updateCourse(const string studentRA, string newCourse);
};

#endif
