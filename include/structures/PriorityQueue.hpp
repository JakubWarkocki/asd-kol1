#ifndef PQ_HPP
#define PQ_HPP

class PriorityQueue
{

public:
    
    void insert(int val);
    int delMax();

    PriorityQueue(); 
    virtual ~PriorityQueue();

}

#endif