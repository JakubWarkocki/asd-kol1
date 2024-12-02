#ifndef DS_HPP
#define DS_HPP

#define NEGATIVE_INFINITY -2147483648 
#define SENTINEL 2147483647
 
/*

    DataStruct

    Abstrakcyjna klasa bazowa do implementacji słowników i kolejek priorytetowych
    search i delMax zwracają int, możliwa implemntacja jako wrapper do funkcji 
    zwracających wskaźnik lub wskaźnik na wskaźnik

*/

class DataStruct
{

public:
    
    virtual void insert(int val, int data=0) = 0; // W przypadku słownika val jest kluczem a data ukrytym elementem
    virtual int delMax() = 0; // W przypadku pustej kolejki zwraca NEGATIVE_INFINTY
    virtual int search(int key) = 0; // W przypadku nieznalezienia elementu zwraca NEGATIVE_INFINTY
    virtual void delElement(int key) = 0;
    virtual ~DataStruct() {}
    
};

#endif