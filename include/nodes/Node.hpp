#ifndef NODE_HPP
#define NODE_HPP

/*

    Node

    Klasa bazowa do implementacji węzłów

*/

class Node
{

public:

    int value;

    Node(int val);
    virtual ~Node() {}

};

#endif