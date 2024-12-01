#include <tests/Tester.hpp>
#include <structures/List.hpp>

int main(){
    List ll = *(new List());
    Tester::testPriorityQueue(ll, 2137, true, "LIST");
}