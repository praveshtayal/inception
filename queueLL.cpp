/*****************************************************************************
You need to implement a Queue class using linked list.
All the required data members should be private.
Implement the following public functions :
1. Constructor -
Initialises the data members.
2. enqueue :
This function should take one argument of type T and has return type void. This function should insert an element in the queue. Time complexity should be O(1).
3. dequeue :
This function takes no input arguments and has return type T. This should removes the first element which is entered and return that element as an answer. Time complexity should be O(1).
4. front :
This function takes no input arguments and has return type T. This should return the first element which is entered and return that element as an answer. Time complexity should be O(1).
5. size :
Return the size of stack i.e. count of elements which are present ins stack right now. Time complexity should be O(1).
6. isEmpty :
Checks if the queue is empty or not. Return true or false.
*****************************************************************************/
#include <iostream>

template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;

    Node(T data) {
        this -> data = data;
        next = nullptr;
    }
};

template<typename T>
class Queue {
  Node<T> *pfront;
  Node<T> *pback;
  int size;
public :
    Queue()
      :pfront(nullptr), pback(nullptr), size(0)
    {
    }

    void enqueue(T data) {
      Node<T> *curr=new Node<T>(data);
      curr->next = nullptr;
      size++;
      if(size==1)
      {
        pfront = pback = curr;
        return;
      }
      pback->next = curr;
      pback = curr;
    }

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size==0;
    }

    T dequeue() {
        // Return 0 if queue is empty
        if(size==0)
          return 0;
        int result=pfront->data;
        Node<T> *curr=pfront;
        pfront = pfront->next;
        delete curr;
        size--;
        return result;
    }

    T front()  {
        // Return 0 if queue is empty
        if(size==0)
          return 0;
        return pfront->data;
    }
};
