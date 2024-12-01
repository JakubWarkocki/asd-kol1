#ifndef SLIST_HPP 
#define SLIST_HPP

#include "structures/DataStruct.hpp"
#include "nodes/ListNode.hpp"

class SortedList : public DataStruct
{

public:
    
    void insert(int val, int data=0) override; // O(n)
    int delMax() override; // O(1)

    SortedList();
    ~SortedList() override;

    // not a dictionary
    int search(int key) override {return NEGATIVE_INFINITY;};
    void delElement(int key) override {return;};

private:

    ListNode* head_;

};

#endif