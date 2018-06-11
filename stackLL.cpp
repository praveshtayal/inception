/*****************************************************************************
You need to implement a Stack class using linked list.
The data members should be private.
Implement the following public functions :
1. Constructor - Initialises the data member (i.e. head to null).
2. push : This function should take one argument of type int and has return type
void. This function should insert an element in the stack. Time complexity 
should be O(1).
3. pop : This function takes no input arguments and has return type int. This 
should removes the last element which is entered and return that element as an 
answer. Return 0 if stack is empty. Time complexity should be O(1).
4. top : This function takes no input arguments and has return type int. This 
should return the last element which is entered and return that element as an 
answer. Return 0 if stack is empty.  Time complexity should be O(1).
5. size : Return the size of stack i.e. count of elements which are present 
ins stack right now. Time complexity should be O(1).
6. isEmpty : Checks if the stack is empty or not. Return true or false.
*****************************************************************************/
#include <iostream>

 class Node {
    public :
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        next = nullptr;
    }
};

class Stack {
    Node *head;
    int size;		// number of elements present in stack

public :

    Stack()
      : head(nullptr), size(0)
    {
    }

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size==0;
    }

    void push(int element) {
      Node *p=new Node(element);
      p->next = head;
      head = p;
      size++;
    }

    int pop() {
        // Return 0 if stack is empty. Don't display any other message
        if(head==nullptr)
          return 0;
        int result=head->data;
        Node *curr=head;
        head = head->next;
        delete curr;
        size--;
        return result;
    }

    int top() {
        // Return 0 if stack is empty. Don't display any other message
        if(size==0)
          return 0;
        return head->data;
    }
};
