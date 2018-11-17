#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;

template<typename T>
class stack {
    public:
        queue<T> *q1, *q2;
        stack()
            :q1(new queue<T>), q2(new queue<T>)
        {
        }
        ~stack()
        {
            delete q1;
            delete q2;
        }
        void push(T val)
        {
            q1->push(val);
        }
        T pop()
        {
            // Nothing to pop. Return 0
            if(q1->empty()) return 0;

            // Remove all the elements from q1 except 1
            while(q1->size() != 1)
            {
                q2->push(q1->front());
                q1->pop();
            }
            // front now has last element inserted
            int front = q1->front();
            q1->pop();

            // swap q1 and q2. This will be faster than copying
            queue<T> *temp = q1;
            q1 = q2;
            q2 = temp;

            return front;
        }
        T top()
        {
            // Nothing to pop. Return 0
            if(q1->empty()) return 0;

            // Remove all the elements from q1 except 1
            while(q1->size() != 1)
            {
                q2->push(q1->front());
                q1->pop();
            }
            // front now has last element inserted
            int front = q1->front();
            q1->pop();
            q2->push(front); // This is only extra statement in top()

            // swap q1 and q2. This will be faster than copying
            queue<T> *temp = q1;
            q1 = q2;
            q2 = temp;

            return front;
        }
        int getSize() const
        {
            return q1->size();
        }
};

template<typename T>
class Node{
public:
    T data;
    Node * next;
    Node(T data){
        this->data=data;
        this->next=NULL;
    }
};
Node<int>* NextLargeNumber(Node<int> *head) {
    if(head==nullptr) return;
    Node<int> *last=head;
    int len=1;
    while(last->next != nullptr)
    {
        last = last->next;
        len++;
    }
}

void changeLL(Node<int>* head) {
    if(head==nullptr) return;
    int maximum = head->data;
    Node<int>* curr=head;
    while(curr!=nullptr)
    {
        if(curr->data > maximum)
            maximum = curr->data;
        curr = curr->next;
    }
    unordered_set<int> s;
    curr = head;
    s.insert(curr->data);
    curr = curr->next;
    while(curr!=nullptr)
    {
        if(s.find(curr->data) != s.end())
            curr->data = ++maximum;
        s.insert(curr->data);
        curr = curr->next;
    }
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.getSize() << endl;
}
