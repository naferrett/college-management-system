#include <iostream>
#include <memory>
#include <map>

#include "../../include/dto/StudentDTO.h"
#include "../../include/dao/AbstractDAO.h"

#ifndef STUDENTDAO_H_
#define STUDENTDAO_H_

using namespace std;

class StudentDAO : public AbstractDAO<StudentDTO> {

    public:    
        void add(const StudentDTO& studentDTO) override;
};

#endif