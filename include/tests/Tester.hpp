#ifndef BASIC_TESTER_HPP
#define BASIC_TESTER_HPP

class DataStruct;

/*

    BasicTester

    Klasa do realizacji testów na strukturach danych

*/

class Tester
{

public: 
    
    enum Result {
        OK,
        LOGIC_ERROR,
        INSERT_RUNTIME_ERROR,
        DEL_MAX_RUNTIME_ERROR,
        SEARCH_RUNTIME_ERROR
    };

    static Result testPriorityQueue(DataStruct& pq, bool verbose = false, std::string name="PriorityQueue");
    
    /*

    testPriorityQueue:

    pq - pusta kolejka priotytetowa
    verbose - wypisywanie informacji na stdout
    name - wybrana nazwa struktury

    Funkcja do testowania podstawowych kolejek priorytetowych
    realizujących funkcję insert, delMax oraz posiadających
    zabezpieczenie przed użyciem delMax na pustej liście 
    zgodnie ze specyfikacją

    */

    static Result testDictionary(DataStruct& dc, bool verbose = false, std::string name="Dictionary");
    
    /*

    testDictionary:

    dc - pusty słownik
    verbose - wypisywanie informacji na stdout
    name - wybrana nazwa struktury

    Funkcja do testowania podstawowych słowników
    realizujących funkcję insert i search
    search powinna zwracać negative infinity dla nieistniejących elementów

    */

   // TODO: testy dla specyficznych struktur

};


#endif