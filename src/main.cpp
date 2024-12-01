#include <tests/Tester.hpp>
#include <structures/List.hpp>
#include <structures/SortedList.hpp>
#include <iostream>

int main(){

    List pq1 = *(new List());

    for(int i =0; i<10000; i++){
        if(!Tester::testPriorityQueue(pq1, i)){
            Tester::testPriorityQueue(pq1, i, true, "LIST");
        }
    }

    Tester::testPriorityQueue(pq1, 2137, true, "LIST");
    
    std::cout << std::endl;

    SortedList pq2 = *(new SortedList());

    for(int i =0; i<10000; i++){
        if(!Tester::testPriorityQueue(pq2, i)){
            Tester::testPriorityQueue(pq2, i, true, "LIST");
        }
    }

    Tester::testPriorityQueue(pq2, 2137, true, "SORTED LIST");


}