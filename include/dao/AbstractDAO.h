#include <iostream>
#include <vector>
#include <memory>

#ifndef ABSTRACTDAO_H_
#define ABSTRACTDAO_H_

#include "../../include/database/College.h"

using namespace std;


template <typename T, typename K>
class AbstractDAO {

    public: 
        virtual void add(const T& dto) = 0;
        virtual void read() = 0;
        virtual shared_ptr<T> search(K key) = 0;
        virtual void update(int option, K key) = 0;
        virtual void remove(K key) = 0;
        virtual ~AbstractDAO() = default;
};

#endif
