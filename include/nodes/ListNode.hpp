#ifndef LNODE_HPP
#define LNODE_HPP

#include <nodes/Node.hpp>

/*

    Node

    Klasa bazowa do implementacji węzłów

*/

class ListNode : public Node
{

public:

    ListNode(int val);
    ~ListNode() {}

    ListNode* next;

};

#endif