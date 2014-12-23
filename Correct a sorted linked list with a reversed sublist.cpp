/*
============================================================================
Author         : James Chen
Email          : a.james.chen@gmail.com
Description    : Correct a sorted linked list with a reversed sublist  
Created Date   : 3-July-2013
Last Modified  :
============================================================================
*/

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <memory> // for shared_ptr

using std::shared_ptr;

typedef struct LinkedNode{
    int data;
    //struct LinkedNode* next;
    shared_ptr<LinkedNode> _next;
} LINKEDNODE;

using namespace std;

void DeleteList(shared_ptr<LinkedNode> head)
{
    while(head){
        //LINKEDNODE *node = head;
        shared_ptr<LinkedNode> node = head;
        head = head->_next;
        //delete node;
    }
}

//void PrintList(LINKEDNODE *head)
void PrintList(shared_ptr<LinkedNode> head)
{
    while(head){
        cout << setw(3) << left << head->data;
        head = head->_next;
    }
    cout << endl;
}

void CorrectSortedLinkedList(shared_ptr<LinkedNode> head)
{
    if(!head){
        cout << "The list is empty" << endl;
        return;
    }

    //LINKEDNODE *node = head;
    shared_ptr<LinkedNode> node = head;
    
    if(! node->_next){
        cout << "Only one node in the list" << endl;
        return;
    }
    
    stack<int> s;
    //LINKEDNODE *start(NULL), *end(NULL);
    shared_ptr<LinkedNode> start;
    shared_ptr<LinkedNode> end;
    while(node->_next){
        if(start == nullptr && node->data > node->_next->data){
            start = node;
        }
        else if(start != nullptr && node->_next->data > start->data){
            end = node;
            s.push(node->data);
            break;
        }

        if(start){
            s.push(node->data);
        }
        
        node = node->_next;
    }

    if(!end){
        s.push(node->data);
    }

    while(!s.empty()){  
        start->data = s.top();
        s.pop();
        start = start->_next;
    }
}



//void AddNode(LINKEDNODE **head, int data)
void AddNode(shared_ptr<LinkedNode> & head, int data)
{
    shared_ptr<LinkedNode> ln(new LinkedNode);
    ln->data = data;
    ln->_next = nullptr;
    if(!head){
        cout<<"head is null"<<endl;
        head = ln;
        return;
    }
    shared_ptr<LinkedNode> node = head;
    while(node->_next != nullptr){
        node = node->_next;
    }
    node->_next = ln;
}


void DoTest(int* arr, int len)
{
    //LINKEDNODE *head = NULL;
    //shared_ptr<LinkedNode> head(new LinkedNode);
    //head->_next=nullptr;
    shared_ptr<LinkedNode> head;
    
    for(int i = 0; i <len; ++i){
        AddNode(head, arr[i]);
    }

    cout << "Before correcting" << endl;
    PrintList(head);
    CorrectSortedLinkedList(head);
    cout << "After correcting" << endl;
    PrintList(head);
    DeleteList(head);

    cout << "-------------------------------" << endl;

}

int main(int argc, char* argv[])
{
    int array[] = {1, 2, 3, 4, 8, 7, 6, 5, 9, 10};
    DoTest(array, sizeof(array)/sizeof(array[0]));

return 0;
}
