#include "structures/Beap.hpp"
#include <cmath>
#include <algorithm>

int Beap::ij2k(int i, int j){
    if(i==0 || j==0 || j>i){
        return 0;
    }
    int k = ((i)*(i-1)/2)+j;
}

std::pair<int,int> Beap::k2ij(int k){
    std::pair<int,int> p;
    p.first = int(ceil(0.5*(-1+sqrt(1.0+8*k))));
    p.second = int(k-0.5*p.first*(p.first-1));
    return p;
}

void Beap::UpBeap(int k){
    auto [i, j] = k2ij(k); // C++ 17 :)
    int upstream;

    while(true){
        upstream = ij2k(i-1,j);
        if(j==i){
            upstream--;
            j--;
        }
        else if(j>1){
            if(elems[upstream-1]<elems[upstream]){
                j--;
                upstream--;
            }
        }
        i--;
        if(elems[upstream]<elems[k]){
            std::swap(elems[upstream],elems[k]);
            k=upstream;           
        }
        else{
            return;
        }
    }
}

void Beap::DownBeap(int k){
    auto [i, j] = k2ij(k); // C++ 17 :)
    int downstream;

    while(ij2k(i+1,j)>=size){
        downstream = ij2k(i+1,j);
        if(downstream+1>=size && elems[downstream+1]>elems[downstream]){
            downstream++;
            j++;
        }
        i++;
        if(elems[downstream]>elems[k]){
            std::swap(elems[downstream],elems[k]);
            k=downstream;
        }
        else{
            return;
        }
    }
}

void Beap::insert(int val, int data){
    size++;
    elems[size]=val;
    UpBeap(val);
}

int Beap::delMax(){
    if(size == 0){
        return NEGATIVE_INFINITY;
    }
    int val = elems[1];
    if(size == 1){
        size--;
        return val;
    }
    
    elems[1]=elems[size];
    size--;
    DownBeap(1);
    return val;

}

Beap::Beap(){
    elems[0]=SENTINEL;
    size = 0;
}

Beap::~Beap(){}