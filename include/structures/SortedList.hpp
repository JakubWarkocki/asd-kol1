#ifndef SORTED_LIST_HPP 
#define SORTED_LIST_HPP 

class SortedList : public PriorityQueue
{

public:
    
    void insert(int val) override; // O(n)
    int delMax() override; // O(1)

    SortedList(); 
    ~SortedList() override;

}

#endif