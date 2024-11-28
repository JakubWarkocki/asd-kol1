#ifndef LIST_HPP 
#define LIST_HPP

#include "structures/DataStruct.hpp"

class List : public DataStruct
{

public:
    
    void insert(int val, int key=0) override; // O(1)
    int delMax() override; // O(n)

    ~List() override;

}

#endif