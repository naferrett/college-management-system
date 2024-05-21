#include <iostream>
#include <vector>
#include <memory>

#ifndef ABSTRACTDAO_H_
#define ABSTRACTDAO_H_

#include "../../include/database/College.h"

using namespace std;


template <typename T>
class AbstractDAO {

    public: 
        virtual void add(const T& dto) = 0;
        virtual ~AbstractDAO() = default;
};

#endif
