#ifndef LIST_HPP 
#define LIST_HPP

#include "structures/PriorityQueue.hpp"
#include "structures/PriorityQueue.hpp"

class List : public PriorityQueue
{

public:
    
    void insert(int val) override; // O(1)
    int delMax() override; // O(n)

    List(); 
    ~List() override;

}

#endif