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
        //virtual void read(const T& dto) = 0; get do College
        virtual void update(const string key) = 0;
        virtual ~AbstractDAO() = default;
};

#endif
