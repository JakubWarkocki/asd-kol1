#include <tests/Tester.hpp>
#include <structures/List.hpp>
#include <structures/SortedList.hpp>
#include <structures/Heap.hpp>
#include <iostream>

int main(){

    List pq1 = *(new List());

    for(int i =0; i<10000; i++){
        if(!Tester::testPriorityQueue(pq1, i)){
            Tester::testPriorityQueue(pq1, i, true, "LIST");
            return 1;
        }
    }

    Tester::testPriorityQueue(pq1, 2137, true, "LIST");
    
    std::cout << std::endl;

    SortedList pq2 = *(new SortedList());

    for(int i =0; i<10000; i++){
        if(!Tester::testPriorityQueue(pq2, i)){
            Tester::testPriorityQueue(pq2, i, true, "SORTED LIST");
            return 1;
        }
    }

    Tester::testPriorityQueue(pq2, 2137, true, "SORTED LIST");

    std::cout << std::endl;

    Heap pq3 = *(new Heap());
    
    for(int i =0; i<10000; i++){
        if(!Tester::testPriorityQueue(pq3, i)){
            Tester::testPriorityQueue(pq3, i, true, "HEAP");
            return 1;
        }
    }
    
    Tester::testPriorityQueue(pq3, 2137, true, "HEAP");

}