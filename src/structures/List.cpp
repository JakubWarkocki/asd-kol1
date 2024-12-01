#include <structures/List.hpp>

void List::insert(int val, int data){

    ListNode* new_node = new ListNode(val);
    ListNode** i = &this->head_;

    while(*i){
        i = &((*i)->next);
    }

    *i = new_node;

}

int List::delMax(){

    int val;
    ListNode* max;
    ListNode* max_prev;
    ListNode* current;
    ListNode* prev;

    if(!head_){
        return NEGATIVE_INFINITY;
    }
    
    val = head_ -> value;
    max_prev = nullptr;
    max = head_;
    prev = nullptr;
    current = head_;

    while (current->next){
        if(current->next->value > val){
            val = current->next->value;
            max = current->next;
            max_prev = current;
        }
        prev = current;
        current = current->next;

    }

    if(max_prev){
        max_prev->next=max->next;
    }
    else{
        head_ = max->next;
    }

    delete max;
    return val;
}

List::List(): head_(nullptr) {};

List::~List(){
    while(this->head_){
        this->delMax();
    }
}