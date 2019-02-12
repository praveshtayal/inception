#include <iostream>
using namespace std;

struct s1 {
    int a;
    char b, c;
    int arr[0];
};

int main()
{
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(s1) << endl;
}

