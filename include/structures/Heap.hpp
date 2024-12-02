#ifndef HEAP_HPP
#define HEAP_HPP

#define MAX_HEAP_SIZE 4096

#include <structures/DataStruct.hpp>

class Heap : public DataStruct
{

    public:

    void insert(int val, int key=0) override; // O(log n)
    int delMax() override; // O(log n)

    Heap();
   // Heap(int arr[]);

    ~Heap() override;

    // not a dictionary
    int search(int key) override {return NEGATIVE_INFINITY;};
    void delElement(int key) override {return;};

    private:

    static int parent(int i);
    static int leftChild(int i);
    static int rightChild(int i);

    void DownHeap(int node);
    void UpHeap(int node);

    int size;
    int elems[MAX_HEAP_SIZE];  
};

#endif