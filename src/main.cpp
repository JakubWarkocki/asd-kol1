#include <tests/Tester.hpp>
#include <structures/List.hpp>

int main(){
    List ll = *(new List());

    for(int i =0; i<10000; i++){
        if(!Tester::testPriorityQueue(ll, i)){
            Tester::testPriorityQueue(ll, i, true, "LIST");
        }
    }
    Tester::testPriorityQueue(ll, 2137, true, "LIST");
    
}