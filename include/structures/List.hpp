#ifndef LIST_HPP 
#define LIST_HPP

#include "structures/DataStruct.hpp"
#include "nodes/ListNode.hpp"

class List : public DataStruct
{

public:
    
    void insert(int val, int key=0) override; // O(1)
    int delMax() override; // O(n)
    List();
    ~List() override;

    // not a dictionary
    int search(int key) override {return NEGATIVE_INFINITY;};
    void delElement(int key) override {return;};

private:

    ListNode* head_;

};

#endif