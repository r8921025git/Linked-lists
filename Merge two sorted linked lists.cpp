// Copyright (c) 2013 Elements of Programming Interviews. All rights reserved.

#include <cassert>
#include <iostream>
#include <memory>



using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;

template <typename T>
struct ListNode {
T data;
shared_ptr<ListNode<T>> next;
};

shared_ptr<ListNode<int>> MergeTwoSortedLists(shared_ptr<ListNode<int>> L,
                                              shared_ptr<ListNode<int>> R) 
{
    shared_ptr<ListNode<int>> head;
    shared_ptr<ListNode<int>> curr;
    shared_ptr<ListNode<int>> opp;
    shared_ptr<ListNode<int>> tmp;
    if (L->data < R->data) {
        head = L;
        curr = L;
        opp  = R;
    }
    else {
        head = R;
        curr = R;
        opp = L;
    }
    while (...) {
        if (opp->data < curr->next->data) {
            tmp = curr->next;
            curr->next = opp;
            curr->next->next = tmp;
            opp = opp->next;
        }
    }

}                        

void Print(shared_ptr<ListNode<int>> head) {
if (head) {
cout << "(" << head->data << ")" << endl;
Print(head->next);
}
}

int main(int argc, char* argv[]) {
  shared_ptr<ListNode<int>> L1 ( new ListNode<int> );
  L1->data = 1;   L1->next = nullptr;
  shared_ptr<ListNode<int>> L2  ( new ListNode<int> );
  L2->data = 3;   L2->next = nullptr;
  L1->next = L2;
  shared_ptr<ListNode<int>> L3 ( new ListNode<int> );
  L3->data = 5;   L3->next = nullptr;
  L2->next = L3;
  
  shared_ptr<ListNode<int>> R1 ( new ListNode<int> );
  R1->data = 2;   R1->next = nullptr;
  shared_ptr<ListNode<int>> R2  ( new ListNode<int> );
  R2->data = 4;   R2->next = nullptr;
  R1->next = R2;
  shared_ptr<ListNode<int>> R3 ( new ListNode<int> );
  R3->data = 6;   R3->next = nullptr;
  R2->next = R3;  

  Print(L1);
  Print(R1);
  return 0;
}
