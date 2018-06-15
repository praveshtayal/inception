#include <iostream>
#include <string>
#include <map>
using namespace std;

class minHeap
{
  int *heap;
  int capacity;
  int size;
public:
  minHeap(int _capacity=128)
    : capacity(_capacity), size(0)
  {
    heap = new int[capacity];
  }
  ~minHeap()
  {
    delete [] heap;
  }
  void insert(int value)
  {
    if(size==capacity)
    {
      /* Re-size Heap */
      int *oldheap = heap;
      int oldCapacity = capacity;
      capacity *=2;
      heap = new int[capacity];
      for(int i=0; i<oldCapacity; i++)
        heap[i] = oldheap[i];
      delete [] oldheap;
    }
    int index = size;
    heap[size++] = value;
    while(index>0 && heap[index]<heap[(index-1)/2])
    {
      heap[index] = heap[(index-1)/2];
      heap[(index-1)/2] = value;
      index = (index-1)/2;
    }
  }
  void removeMin()
  {
    /* TODO: Implement */
    if(size==0) return;
    heap[0] = heap[--size];
    int index = 0, child1 = 2*index+1, child2 = child1+1;
    while(child1<size && heap[index]>heap[(index-1)/2])
    {
      heap[index] = heap[(index-1)/2];
      //heap[(index-1)/2] = value;
      index = (index-1)/2;
    }
  }
  int min()
  {
    return heap[0];
  }
  void print() const
  {
    for(int i=0; i<size; i++)
      cout << heap[i] << ' ';
    cout << endl;
  }
};

int main()
{
  minHeap h;
  int nElements, value;
  cin >> nElements;
  for(int i=0; i<nElements; i++)
  {
    cin >> value;
    h.insert(value);
    h.print();
  }
}

