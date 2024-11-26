#ifndef PQ_HPP
#define PQ_HPP

/*

    PriorityQueue

    Abstrakcyjna klasa bazowa do implementacji kolejek priorytetowych

*/

class PriorityQueue
{

public:
    
    virtual void insert(int val);
    virtual int delMax();

    virtual ~PriorityQueue();

}

#endif