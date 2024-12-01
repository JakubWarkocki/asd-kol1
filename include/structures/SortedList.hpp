#ifndef SLIST_HPP 
#define SLIST_HPP

#include "structures/DataStruct.hpp"

class SortedList : public DataStruct
{

public:
    
    void insert(int val, int key=0) override; // O(n)
    int delMax() override; // O(1)

    ~SortedList() override;

};

#endif