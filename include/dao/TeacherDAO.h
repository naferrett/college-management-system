#include <iostream>
#include <memory>

#ifndef TEACHERDAO_H_
#define TEACHERDAO_H_

#include "../../include/dto/TeacherDTO.h"
#include "../../include/dao/TeacherDAO.h"
#include "AbstractDAO.h"

using namespace std;

class TeacherDAO : public AbstractDAO<TeacherDTO, string> {

    public: 
        void add(const TeacherDTO& teacherDTO) override;
        void read() override;
        shared_ptr<TeacherDTO> search(string teacherId) override;
        void update(int option, string teacherId) override;
        void remove(string teacherId) override;

        void updateName(const string teacherId, string newName);
        void updateAge(const string teacherId, int newAge);
        void updatePhone(const string teacherId, string newPhone);
        void updateId(const string teacherId, string newId);
        void updateSalary(const string teacherId, double newSalary);
};

#endif

