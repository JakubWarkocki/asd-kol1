#include <structures/SortedList.hpp>

void SortedList::insert(int val, int data){

    ListNode* newnode =  new ListNode(val);

    if(!this->head_){
        this->head_ = newnode;
        return;
    }

    if(val>this->head_->value){
        ListNode* n  = newnode;
        n->next = head_;
        head_ = n;
        return;
    }

    ListNode* i = this->head_->next;
    ListNode* prev = this->head_;
    while (i)
    {
        if(val>i->value){
            prev->next = newnode;
            prev->next->next = i;
            return;
        }
        prev=i;
        i=i->next;
    }
    prev->next = newnode;
}

int SortedList::delMax(){

    if(!this->head_){
        return NEGATIVE_INFINITY;
    }

    ListNode* h = this->head_;
    int v = this->head_->value;

    this->head_ = this->head_->next;

    delete h;
    return v;

}

SortedList::SortedList(): head_(nullptr) {};

SortedList::~SortedList(){
    while(this->head_){
        this->delMax();
    }
}