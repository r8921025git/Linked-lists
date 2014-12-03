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

// @include
shared_ptr<ListNode<int>> ReverseLinkedList( shared_ptr<ListNode<int>> list ) {
    // boundary condition: 
    
        
    
    // get first node
    shared_ptr<ListNode<int>> first_node = list;
    
    // reverse nodes beyond first node
    if (first_node->next->next != nullptr) {
        shared_ptr<ListNode<int>> reversed_beyond_first = ReverseLinkedList(first_node->next);
        shared_ptr<ListNode<int>> tmp = reversed_beyond_first;
        
        while (tmp->next != nullptr) {
            //tmp2 = tmp;
            tmp = tmp->next;
        }
        shared_ptr<ListNode<int>> last = tmp;
            
    
        // reverse first node
        last->next = first_node;
        first_node->next = nullptr;
    
        return reversed_beyond_first;
    }
    else {
        shared_ptr<ListNode<int>> output = first_node->next;
        first_node->next->next = first_node;
        first_node->next = nullptr;
        return output;
    }
}
// @exclude

void Print(shared_ptr<ListNode<int>> head) {
  if (head) {
    cout << "(" << head->data << ")" << endl;
    Print(head->next);
  }
}

int main(int argc, char* argv[]) {
  shared_ptr<ListNode<int>> L1 =
      make_shared<ListNode<int>>(ListNode<int>{1, nullptr});
  shared_ptr<ListNode<int>> L2 =
      make_shared<ListNode<int>>(ListNode<int>{2, nullptr});
  L1->next = L2;
  shared_ptr<ListNode<int>> L3 =
      make_shared<ListNode<int>>(ListNode<int>{3, nullptr});
  L2->next = L3;

  cout << "before reverse" << endl;
  Print(L1);
  shared_ptr<ListNode<int>> newhead = ReverseLinkedList(L1);
  assert(newhead->data == 3 && newhead->next->data == 2 && newhead->next->next->data == 1);
  cout << endl << "after reverse" << endl;
  Print(newhead);
  newhead = ReverseLinkedList(newhead);
  assert(newhead->data == 1 && newhead->next->data == 2 && newhead->next->next->data == 3);
  cout << endl << "after another reverse" << endl;
  Print(newhead);
  return 0;
}
