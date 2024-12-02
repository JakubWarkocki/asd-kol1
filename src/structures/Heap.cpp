#include "structures/Heap.hpp"
#include <algorithm>
#include <iostream>
int Heap::parent(int i){
    return i/2;
}

int Heap::leftChild(int i){
    return i*2;
}

int Heap::rightChild(int i){
    return i*2+1;
}

void Heap::DownHeap(int i){
    int downstream;
    while ( leftChild(i)<=size)
    {   
        downstream = leftChild(i);

        if(rightChild(i)<=size && elems[rightChild(i)]>=elems[leftChild(i)]){
            downstream = rightChild(i);
        }
        if(elems[downstream]<=elems[i]){
            break;
        }
        std::swap(elems[i],elems[downstream]);
        i=downstream;
    }
}

void Heap::UpHeap(int i){
    while(elems[parent(i)]<elems[i]){
        std::swap(elems[parent(i)],elems[i]);
        i = parent(i);
    }
}

void Heap::insert(int value, int key){
    size++;
    elems[size]=value;
    UpHeap(size);
}

int Heap::delMax(){

    if(size == 0){
        return NEGATIVE_INFINITY;
    }
    
    int value = elems[1];
    if(size == 1){
        size--;
        return value;
    }

    elems[1] = elems[size];
    size--;
    DownHeap(1);
    return value;
}


Heap::Heap(){
    elems[0]=SENTINEL;
    size = 0;
}

Heap::~Heap(){
}