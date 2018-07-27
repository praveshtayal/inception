/*****************************************************************************
You need to implement a Queue class using Arrays.
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

template<typename T>
class Queue {
  T *arr;
  int _front;
  int back;
  int size;
  unsigned int capacity;
public :
    Queue(unsigned int _capacity=10)
      :_front(0), back(0), size(0), capacity(_capacity)
    {
      arr = new T[capacity];
    }
    ~Queue()
    {
      delete [] arr;
    }

    void enqueue(T data) {
      if(size==capacity) return;
      size++;
      if(size==1) _front = back;
      arr[back++] = data;
      back %= capacity;
    }

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size==0;
    }

    T dequeue() {
        // Return 0 if queue is empty
        if(size==0) return 0;
        size--;
        int result=arr[_front++];
        _front %= capacity;
        return result;
    }

    T front()  {
        // Return 0 if queue is empty
        if(size==0) return 0;
        return arr[_front];
    }
};
