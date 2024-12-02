#ifndef BEAP_HPP
#define BEAP_HPP

#define MAX_BEAP_SIZE 4096

#include <utility>
#include <structures/DataStruct.hpp>

class Beap : public DataStruct
{

    public:

    void insert(int val, int data=0) override; // O(sqrt(n))
    int delMax() override; // O(sqrt(n))
    
    // not a dictionary
    int search(int key) override {return NEGATIVE_INFINITY;};
    void delElement(int key) override {return;};

    Beap();
    ~Beap() override;

    private:

    static int ij2k(int i, int j);
    static std::pair<int, int> k2ij(int k);


    void DownBeap(int node);
    void UpBeap(int node);

    int size;
    int elems[MAX_BEAP_SIZE];  
};

#endif