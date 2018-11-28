#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>
using namespace std;

class Dummy {
    public:
        Dummy(int _i=0)
            : i(_i)
        {
            cout << "Executing Constructor for Dummy " << i << endl;
        }
        ~Dummy()
        {
            cout << "Executing Desctructor for Dummy " << i << endl;
        }
        friend ostream& operator<<(ostream& cout,const Dummy& d);
    private:
        int i;
};

ostream& operator<<(ostream& cout,const Dummy& d)
{
    cout << d.i;
    return cout;
}

int main()
{
    int i = 10;
    int *ptr = &i;
    cout << *ptr << endl;

    // auto_ptr
    auto_ptr<Dummy> ap1 = auto_ptr<Dummy> (new Dummy(51));
    auto_ptr<Dummy> ap2 = ap1;
    cout << *ap2 << endl;
    if(ap1.get()==nullptr) cout << "ap1 is nullptr" << endl;
    auto_ptr<Dummy> ap3 = auto_ptr<Dummy> (new Dummy(61));
    ap2 = ap3; // This should release ap2 resource which is 51

    // We should not use new to create unique_ptr
    unique_ptr<Dummy> up1 = unique_ptr<Dummy> (new Dummy(101));
    shared_ptr<Dummy> sp1 = shared_ptr<Dummy> (new Dummy(102));
    shared_ptr<Dummy> sp2 = sp1;
    shared_ptr<Dummy> sp3 = sp2;
    // unique_ptr<int> up2 = up1;
    // unique_ptr<int> up2 = up1; This is invalid
    cout << *up1 << endl;
    cout << *sp1 << endl;
    cout << *sp2 << endl;
    cout << *sp3 << endl;

    // make_unique is C++14 feature and not provided on my machine
    //unique_ptr<int> up2 = std::make_unique<int>;


}

