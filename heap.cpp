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
        if(size<=0) return;
        if(size==1)
        {
            size--;
            return;
        }
        heap[0] = heap[--size];
        int index = 0, child1 = 2*index+1, child2 = child1+1;
        while(child2<size)
        {
            /* Index has both child nodes */
            int swapIndex = heap[child1]<heap[child2] ? child1 : child2;
            if(heap[index]<heap[swapIndex]) return;
            /* Swap index & swapIndex */
            int temp = heap[index];
            heap[index] = heap[swapIndex];
            heap[swapIndex] = temp;
            index = swapIndex;
            child1 = 2*index+1;
            child2 = child1+1;
        }
        /* Here: index does not have 2 children but may have left child */
        if(child1<size && heap[index]>heap[child1])
        {
            int temp = heap[index];
            heap[index] = heap[child1];
            heap[child1] = temp;
        }
    }
    int min() const
    {
        return heap[0];
    }
    int currSize() const
    {
        return size;
    }
    int currCapacity() const
    {
        return capacity;
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
    int choice, value;
    cin >> choice;
    while(choice)
    {
        switch(choice)
        {
            case 1:
                // insert the value
                cin >> value;
                h.insert(value);
                break;
            case 2:
                h.removeMin();
        }
        h.print();
        cin >> choice;
    }
}

