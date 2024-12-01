#ifndef BASIC_TESTER_HPP
#define BASIC_TESTER_HPP

#include <string>

class DataStruct;

/*

    BasicTester

    Klasa do realizacji testów na strukturach danych

*/

class Tester
{

public: 

    static bool testPriorityQueue(DataStruct& pq, unsigned seed=2137, bool verbose = false, std::string name="PriorityQueue");
    
    /*

    testPriorityQueue:

    pq - pusta kolejka priotytetowa
    seed - ziarno do liczb losowych w testach
    verbose - wypisywanie informacji na stdout
    name - wybrana nazwa struktury

    Funkcja do testowania podstawowych kolejek priorytetowych
    realizujących funkcję insert, delMax oraz posiadających
    zabezpieczenie przed użyciem delMax na pustej liście 
    zgodnie ze specyfikacją

    */

    static bool testDictionary(DataStruct& dc, unsigned seed=2137, bool verbose = false, std::string name="Dictionary");
    
    /*

    testDictionary:

    dc - pusty słownik
    seed - ziarno do liczb losowych w testach
    verbose - wypisywanie informacji na stdout
    name - wybrana nazwa struktury

    Funkcja do testowania podstawowych słowników
    realizujących funkcję insert i search
    search powinna zwracać negative infinity dla nieistniejących elementów

    */

   // TODO union

};


#endif