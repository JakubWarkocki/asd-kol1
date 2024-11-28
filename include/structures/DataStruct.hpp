#ifndef DS_HPP
#define DS_HPP

#define INFINITY 2147483648 
#define NEGATIVE_INFINITY -2147483648 

/*

    DataStruct

    Abstrakcyjna klasa bazowa do implementacji słowników i kolejek priorytetowych
    search i delMax zwracają int, możliwa implemntacja jako wrapper do funkcji 
    zwracających wskaźnik lub wskaźnik na wskaźnik

*/

class DataStruct
{

public:
    
    virtual void insert(int val, int key=0); // Parametr key tylko dla słowników
    virtual int delMax(); // W przypadku pustej kolejki zwraca NEGATIVE_INFINTY
    virtual int search(int val); // W przypadku nieznalezienia elementu zwraca NEGATIVE_INFINTY


    virtual ~DataStruct();

}

#endif