#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include "tests/Tester.hpp"
#include "structures/DataStruct.hpp"

Tester::Result Tester::testPriorityQueue(DataStruct& pq, bool verbose, std::string name){
    
    int value;
    bool ok = true;
    std::vector<int> reference_values;

    if(verbose){
        std::cout << "PRIORITY QUEUE TEST FOR " << name << std::endl;
        std::cout << "TESTING EMPTY QUEUE SAFEGUARDS..." << std::endl;
    }

    value = pq.delMax();

    if(value != NEGATIVE_INFINITY){
        if(verbose){
            std::cout << "EMPTY QUEUE SHOULD YIELD NEGATIVE INFINITY " << std::endl;
        }
        return Tester::LOGIC_ERROR;
    }

    if(verbose){
        std::cout << "OK" << std::endl;
    }

    if(verbose){
        std::cout << "TESTING PROPER ELEMENT ORDER..." << std::endl;
    }

    for(int i = 0; i < 25; i++){
        value = rand()%100;
        pq.insert(value);
        reference_values.push_back(value);

        if(verbose){
            std::cout << value << " ";
        }
    }

    std::sort(reference_values.begin(), reference_values.end(), std::greater<int>());

    if(verbose){
        std::cout << std::endl;
        std::cout << "RETRIEVING ELEMENTS: " << std::endl;
    }
;
    for(int i = 0; i < 25; i++){
        value = pq.delMax();

        if(value != reference_values[i]){
            ok = false;
        }

        if(verbose){
            std::cout << value << " ";
        }
    }    

    if(verbose){
        std::cout << std::endl;
    }

    if(ok){

        if(verbose){
            std::cout << "OK" << std::endl;
        }

        return Tester::OK;
    }

    if(verbose){
        std::cout << "WRONG ORDER" << std::endl;    
    }  

    return Tester::LOGIC_ERROR;
}
