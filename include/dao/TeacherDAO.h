#include <iostream>
#include <memory>

#ifndef TEACHERDAO_H_
#define TEACHERDAO_H_

#include "../../include/dto/TeacherDTO.h"
#include "../../include/dao/TeacherDAO.h"
#include "AbstractDAO.h"

using namespace std;

class TeacherDAO : public AbstractDAO<TeacherDTO> {

    public: 
        void add(const TeacherDTO& teacherDTO) override;

};

#endif