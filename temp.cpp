#include<iostream>
using namespace std;

int fun(int a=10, int b=20);
int main()
{
  /*
  while(1)
  {
    new int;
  }
  */
  /* Increment check */
  int a,b;
    char c, d;
  int arr[100];
  for(int i = 0; i<100; i++)
    arr[i] = 2*i;
  const int *p = arr+10;

  cout << &a << endl;
  cout << &b << endl;
  cout << (void*)&c << endl;
  cout << (void*)&d << endl;
  cout << arr << endl;
  cout << &p << endl;
  
  /******************
  //int arr[2][3] = { {1,2}, {3,4}, {5,6}};  Incorrect
  int arr[2][3] = { {1,2}, {3,4,6} };  // Correct
  //int arr[2][3] = { 1,2,3, 3,4,6,7 };  // Correct
  for (int i=0; i<2; i++)
    for (int j=0; j<3; j++)
      cout << arr[i][j] << ' ' ;
  cout << endl;
  *****************/
  return 0;
}
