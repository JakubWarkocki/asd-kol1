#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "tests/BasicTester.hpp"
#include "structures/PriorityQueue.hpp"

bool Tester::sanityTest(PriorityQueue& pq, string name="PriorityQueue")
{
    int value;
    bool ok = false;

    std::cout << "BASIC TEST FOR " << name << std::endl;
    std::cout << "ADDING ELEMENTS: " << std::endl;

    for(int i = 0; i < 25; i++)
    {
        value = rand()%100;
        std::cout << value << " ";
        pq.insert(value);
    }

    std::cout  << std::endl;
    std::cout << "RETRIEVING ELEMENTS: " << std::endl;

    value = 100;
    for(int i = 0; i < 25; i++)
    {
        value = pq.delMax();
        std::cout << value << " ";
        pq.insert(value);
    }    

}
